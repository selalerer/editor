
#include <iostream>

#include "gtkw/App.hpp"
#include "gtkw/IAppBuilder.hpp"
#include "gtkw/Window.hpp"
#include "gtkw/Utils.hpp"

namespace gtkw
{

App::App()
{
    this->pApp = gtk_application_new("com.selalerer.editor", G_APPLICATION_FLAGS_NONE);
}

namespace 
{
    struct ActivateParam
    {
        ActivateParam(App& app, IAppBuilder& appBuilder):app(app),appBuilder(appBuilder) {}
        App& app;
        IAppBuilder& appBuilder;
    };
}

int App::run(IAppBuilder& appBuilder, int argc, char* argv[])
{
    //std::cerr << "Connecting activate to App::activate()" << std::endl;
    g_signal_connect (this->pApp, "activate", G_CALLBACK (&App::activate), new ActivateParam(*this, appBuilder));
    return g_application_run (G_APPLICATION (this->pApp), argc, argv);
}

void App::activate(GtkApplication* unused, gpointer user_data)
{
    //std::cerr << "activate() called" << std::endl;

    ActivateParam* pParam = (ActivateParam*)user_data;
    App& app = pParam->app;
    IAppBuilder& appBuilder = pParam->appBuilder;
    delete pParam;
    
    appBuilder.Build(app);
}

Window* App::createWindow()
{
    auto pWin = new Window(gtk_application_window_new(this->pApp));
    children.push_front(pWin);
    return pWin;
}

void App::destroyWindow(Window* pWin)
{
    auto sizeBefore = children.size();
    children.remove(pWin);
    auto sizeAfter = children.size();
    if (sizeAfter != sizeBefore - 1)
        throw std::runtime_error("App::destroyWindow(Window*): Cannot destory a Window that isn't part of this App.");
    delete pWin;
}

App::~App()
{
    for (auto pChild : children)
    {
        delete pChild;
    }
    children.clear();

    Utils::unrefGObject(this->pApp);
    this->pApp = 0;
}

} // namespace gtkw


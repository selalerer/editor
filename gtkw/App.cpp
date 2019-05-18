
#include <iostream>

#include "gtkw/App.hpp"
#include "gtkw/IAppBuilder.hpp"
#include "gtkw/Window.hpp"

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
	return new Window(gtk_application_window_new(this->pApp));
}

App::~App()
{
	g_object_unref(this->pApp);
}

}

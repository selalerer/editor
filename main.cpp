
#include <memory>
#include <iostream>

#include "gtkw/App.hpp"
#include "gtkw/IAppBuilder.hpp"
#include "gtkw/Window.hpp"

class AppBuilder : public gtkw::IAppBuilder
{
public:
	virtual void Build(gtkw::App& app)
	{
		gtkw::Window* pWindow = app.createWindow();
        pWindow->setTitle("sela / editor");
        pWindow->maximize();
		pWindow->show();
		//std::cerr << "Showed window" << std::endl;
	}
};

int main(int argc, char* argv[])
{
	gtkw::App app;
	AppBuilder appBuilder;

	return app.run(appBuilder, argc, argv);
}





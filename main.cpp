
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
		std::unique_ptr<gtkw::Window> pWindow(app.createWindow());
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





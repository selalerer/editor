
#ifndef GTKW_APP
#define GTKW_APP

#include <gtk/gtk.h>

namespace gtkw
{

class Window;
class IAppBuilder;

class App
{
private:
	GtkApplication* pApp;
public:
	App();
	~App();
	int run(IAppBuilder& appBuilder, int argc, char* argv[]);
	Window* createWindow();
private:
	static void activate (GtkApplication* app, gpointer user_data);
};

} // namespace gtkw

#endif // GTKW_APP


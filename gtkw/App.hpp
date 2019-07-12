
#ifndef GTKW_APP
#define GTKW_APP

#include <list>
#include <gtk/gtk.h>

namespace gtkw
{

class Window;
class IAppBuilder;

class App
{
private:
    GtkApplication* pApp;
    std::list<Window*> children;
public:
    App();
    ~App();
    int run(IAppBuilder& appBuilder, int argc, char* argv[]);
    Window* createWindow();
    void destroyWindow(Window* pWin);
private:
    static void activate (GtkApplication* app, gpointer user_data);
};

} // namespace gtkw

#endif // GTKW_APP


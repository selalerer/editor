
#ifndef GTKW_WINDOW
#define GTKW_WINDOW

#include <gtk/gtk.h>

namespace gtkw
{

class App;

class Window
{
    friend class App;
private:
    Window(GtkWidget* pWin);
    GtkWidget* pWin;
public:
    void show();
    void maximize();
    void setTitle(const gchar* title);
    virtual ~Window();
};

} // namespace gtkw

#endif // GTKW_WINDOW


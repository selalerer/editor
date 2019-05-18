
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
};

} // namespace gtkw

#endif // GTKW_WINDOW


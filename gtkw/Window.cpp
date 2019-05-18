
#include "gtkw/Window.hpp"

namespace gtkw
{

Window::Window(GtkWidget* pWin): pWin(pWin)
{
	gtk_window_set_title (GTK_WINDOW (GTK_WINDOW(pWin)), "Window");
	gtk_window_set_default_size (GTK_WINDOW (GTK_WINDOW(pWin)), 200, 200);
}

void Window::show()
{
	gtk_widget_show_all(pWin);
}

} // namespace

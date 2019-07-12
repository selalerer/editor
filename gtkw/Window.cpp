
#include "gtkw/Window.hpp"

#include "gtkw/Utils.hpp"

namespace gtkw
{

Window::Window(GtkWidget* pWin): pWin(pWin)
{
}

Window::~Window()
{
    //Utils::destroyWidget(pWin);
    pWin = 0;
}

void Window::maximize()
{
    gtk_window_maximize(GTK_WINDOW(pWin));
}

void Window::setTitle(const gchar* title)
{
    gtk_window_set_title(GTK_WINDOW(pWin), title);
}

void Window::show()
{
	gtk_widget_show_all(pWin);
}

} // namespace


#include "gtkw/Utils.hpp"

#include <stdexcept>
#include <iostream>

namespace gtkw
{

void Utils::unrefGObject(gpointer object)
{
    // std::cerr << "Utils::unrefGObject(gpointer): Deleting " << object << std::endl;
    if (!G_IS_OBJECT(object))
        throw std::runtime_error("Utils::unrefGObject(gpointer): G_IS_OBJECT() returned false.");
    g_object_unref(object);
}

void Utils::destroyWidget(GtkWidget* widget)
{
    if (!GTK_IS_WIDGET(widget))
        throw std::runtime_error("Utils::destroyWidget(GtkWidget*): GTK_IS_WIDGET() returned false.");
    gtk_widget_destroy(widget);
}

} // namespace gtkw


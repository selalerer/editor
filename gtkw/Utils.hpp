
#ifndef GTKW_UTILS
#define GTKW_UTILS

#include <gtk/gtk.h>

namespace gtkw 
{

class Utils
{
public:
    static void unrefGObject(gpointer object);
    static void destroyWidget(GtkWidget* widget);
};

} // namespace gtkw

#endif // GTKW_UTILS



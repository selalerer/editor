
#ifndef GTKW_IAPPBUILDER
#define GTKW_IAPPBUILDER

namespace gtkw
{

class App;

class IAppBuilder
{
public:
    virtual void Build(App& app) = 0;
};

} // namespace gtkw

#endif // GTKW_IAPPBUILDER


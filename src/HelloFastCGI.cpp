#include <fastcgi2/component.h>
#include <fastcgi2/component_factory.h>
#include <fastcgi2/handler.h>
#include <fastcgi2/request.h>

#include <iostream>
#include <sstream>

class HelloFastCGI : virtual public fastcgi::Component, virtual public fastcgi::Handler
{
    public:
        HelloFastCGI(fastcgi::ComponentContext *context) :
                fastcgi::Component(context)
        {

        }

        virtual void onLoad()
        {

        }

        virtual void onUnload()
        {

        }

        virtual void handleRequest(fastcgi::Request *request, fastcgi::HandlerContext *context)
        {
                request->setContentType("text/plain");
                std::stringbuf buffer("Hello " + (request->hasArg("name") ? request->getArg("name") : "stranger"));
                request->write(&buffer);
        }
};

FCGIDAEMON_REGISTER_FACTORIES_BEGIN()
FCGIDAEMON_ADD_DEFAULT_FACTORY("HelloFastCGIFactory", HelloFastCGI)
FCGIDAEMON_REGISTER_FACTORIES_END()
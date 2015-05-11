#ifndef __CPX_PLUGINPRODUCER_H__
#define __CPX_PLUGINPRODUCER_H__

#include "AbstractProducer.hpp"
#include "PluginFactory.hpp"

#include <string>

namespace cpx
{

template<class INTERFACE, class... ARGS>
class PluginProducer:
    public AbstractProducer
{
    protected:
    public:
        
        PluginProducer()
        {
        }
        virtual std::string getInterfaceName() const
        {
            return INTERFACE::getInterfaceName();
        }
        virtual Version getInterfaceVersion() const
        {
            return INTERFACE::getInterfaceVersion();
        }
        
        virtual INTERFACE* create(ARGS... args) const = 0;
        
        
        template<class PLUGINCLASS>
        class ConcretePluginProducer:
            public PluginProducer<INTERFACE,ARGS...>
        {
            public:
                ConcretePluginProducer()
                { 
                    PluginFactory& f = PluginFactory::getInstance(); 
                    f.registerProducer(this);
                }
                virtual std::string getPluginName() const
                { 
                    return PLUGINCLASS::getPluginName();
                }
                virtual Version getPluginVersion() const
                { 
                    return Version(0,0);
                }
                virtual std::string getPluginDescription() const
                {
                    return "";
                }
                virtual INTERFACE* create(ARGS... args) const
                {
                    return new PLUGINCLASS(args...);
                }
        };
};

}


#define REGISTER_PLUGIN(PRODUCER, PLUGINCLASS) \
static PRODUCER::ConcretePluginProducer<PLUGINCLASS> _plugin ## PRODUCER ## PLUGINCLASS;

#endif


#ifndef __CPX_PLUGINPRODUCER_H__
#define __CPX_PLUGINPRODUCER_H__

#include "cpx/AbstractProducer.hpp"
#include "cpx/PluginFactory.hpp"

#include <string>
#include <iostream>
#include <tuple>

namespace cpx
{

template<unsigned int N>
struct Builder
{
    template<class PLUGINCLASS, class TUPLE, class... CARGS> PLUGINCLASS* create(TUPLE& tuple, CARGS... args)
    {
        typedef typename std::tuple_element<N-1,TUPLE>::type ARG;
        return Builder<N-1>().template create<PLUGINCLASS,TUPLE,CARGS...,ARG>(tuple,args...,std::get<N-1>(tuple));
    }
};

template<>
struct Builder<0>
{
    template<class PLUGINCLASS, class TUPLE, class... CARGS> PLUGINCLASS* create(TUPLE& tuple, CARGS... args)
    {
        return new PLUGINCLASS(args...);
    }
};


template<class... ARGS>
class Signature
{
    protected:
        std::tuple<ARGS...> _arguments;
    public:
        Signature(ARGS... args):
            _arguments(args...)
        {
        }
        
        template<class PLUGINCLASS>
        PLUGINCLASS* create()
        {
            Builder<std::tuple_size<std::tuple<ARGS...>>::value> builder;
            return builder.template create<PLUGINCLASS,std::tuple<ARGS...>>(_arguments);
        }
        
        
};

template<class INTERFACE, class SIGNATURE=cpx::Signature<>>
class PluginProducer:
    public AbstractProducer
{
    protected:
    public:
        typedef INTERFACE Interface;
        typedef SIGNATURE Signature;
        
        PluginProducer()
        {
        }
        virtual std::string getInterfaceName() const
        {
            return Interface::getInterfaceName();
        }
        virtual Version getInterfaceVersion() const
        {
            return Interface::getInterfaceVersion();
        }
        
        virtual Interface* create(Signature signature=cpx::Signature<>()) const = 0;
        
};




template<class PRODUCER, class PLUGINCLASS>
class ConcretePluginProducer:
    public PRODUCER
{
    public:
        ConcretePluginProducer(PluginFactory* pluginFactory)
        {
            pluginFactory->registerProducer(this);
        }

        virtual typename PRODUCER::Interface* create(typename PRODUCER::Signature signature) const
        {
            return signature.template create<PLUGINCLASS>();
        }
        
        virtual std::string getPluginName() const
        { 
            return PLUGINCLASS::getPluginName();
        }
        virtual Version getPluginVersion() const
        { 
            return PLUGINCLASS::getVersion();
        }
        virtual std::string getPluginDescription() const
        {
            return PLUGINCLASS::getDescription();
        }

        virtual ~ConcretePluginProducer()
        {
        } 
};
    
}

#define cpx_setup_interface(NAME,MAJOR,MINOR) \
    static std::string getInterfaceName() { return NAME; } \
    static cpx::Version getInterfaceVersion() { return cpx::Version(MAJOR,MINOR); }
    
#define cpx_setup_plugin(NAME,MAJOR,MINOR,DESCRIPTION) \
    static std::string getPluginName() { return NAME; } \
    static cpx::Version getVersion() { return cpx::Version(MAJOR,MINOR); } \
    static std::string getDescription() { return DESCRIPTION; }

#define cpx_init_module() \
    extern "C" void cpx_shared init(cpx::PluginFactory* pluginFactory) 

#define cpx_register_plugin(PRODUCER, PLUGINCLASS) \
    static cpx::ConcretePluginProducer<PRODUCER,PLUGINCLASS> producer(pluginFactory)


#endif


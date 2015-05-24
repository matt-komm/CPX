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
        //auto i = std::get<N-1>(tuple);
        //return nullptr;
        return Builder<N-1>().template create<PLUGINCLASS,TUPLE,CARGS...,ARG>(tuple,args...,std::get<N-1>(tuple));
    }
};

template<>
struct Builder<0>
{
    template<class PLUGINCLASS, class TUPLE, class... CARGS> PLUGINCLASS* create(TUPLE& tuple, CARGS... args)
    {
        //return nullptr;
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
        
        /*
        template<class PLUGINCLASS>
        class ConcretePluginProducer:
            public PluginProducer<INTERFACE,ARGS...>
        {
            public:
                ConcretePluginProducer()
                { 
                   
                }
                
        };
        */
};




template<class PRODUCER, class PLUGINCLASS>
class ConcretePluginProducer:
    public PRODUCER
{
    public:
        ConcretePluginProducer(PluginFactory* pluginFactory)
        {
            std::cout<<"register plugin "<<this<<" in factory "<<pluginFactory<<std::endl;
            //PluginFactory& f = PluginFactory::getInstance(); 
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
            return Version(0,0);
        }
        virtual std::string getPluginDescription() const
        {
            return "";
        }

        virtual ~ConcretePluginProducer()
        {
            std::cout<<"destroy producer "<<this<<std::endl;
        } 
};
    
}
/*
#define REGISTER_PLUGIN(PRODUCER, PLUGINCLASS) \
static PRODUCER::ConcretePluginProducer<PLUGINCLASS> _plugin ## PRODUCER ## PLUGINCLASS;
*/
#endif


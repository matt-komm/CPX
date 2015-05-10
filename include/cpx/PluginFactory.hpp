#ifndef __CPX_PLUGINFACTORY_H__
#define __CPX_PLUGINFACTORY_H__

#include "AbstractProducer.hpp"

#include <unordered_map>
#include <vector>

class PluginFactory
{
    protected:
        PluginFactory() {}
        
        std::unordered_map<std::string,AbstractProducer*> _producers;
    public:
        static PluginFactory& getInstance()
        {
            static PluginFactory pluginFactory;
            return pluginFactory;
        }
        void registerProducer(AbstractProducer* producer)
        {
            _producers[producer->getPluginName()]=producer;
        }
        std::vector<std::string> getRegisteredPluginNames()
        {
            std::vector<std::string> keys(_producers.size());
            for (std::unordered_map<std::string,AbstractProducer*>::iterator it = _producers.begin(); it!=_producers.end(); ++it)
            {
                keys[std::distance(it,_producers.begin())]=it->first;
            }
            return keys;
        }
        template<class PRODUCER> PRODUCER* getProducer(const std::string& name)
        {
            std::unordered_map<std::string,AbstractProducer*>::iterator it = _producers.find(name);
            if (it!=_producers.end())
            {
                PRODUCER* producer = dynamic_cast<PRODUCER*>(it->second);
                if (producer)
                {
                    return producer;
                }
            }
            return nullptr;
        }  
                
        
        /*
        Class(const Class& c);
        Class(Class&& c);
        Class& operator=(const Class& c);
        Class& operator=(Class&& c);
        ~Class();
        */
};

#endif


#ifndef __CPX_PLUGINFACTORY_H__
#define __CPX_PLUGINFACTORY_H__

#include "AbstractProducer.hpp"
#include "LibraryLoader.hpp"

#include <unordered_map>
#include <vector>

namespace cpx
{

class PluginFactory
{
    protected:
        AbstractLibraryLoader* _libLoader;
        std::unordered_map<std::string,AbstractProducer*> _producers;
    
        PluginFactory();
    public:
        static PluginFactory& getInstance()
        {
            static PluginFactory pluginFactory;
            return pluginFactory;
        }
        void registerProducer(AbstractProducer* producer);
        std::vector<std::string> getRegisteredPluginNames();
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
        void loadLibrary(const std::string& path);
};

}

#endif


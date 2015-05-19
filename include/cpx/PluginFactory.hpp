#ifndef __CPX_PLUGINFACTORY_H__
#define __CPX_PLUGINFACTORY_H__

#include "cpx/AbstractProducer.hpp"
#include "cpx/LibraryLoader.hpp"
#include "cpx/Exception.hpp"

#include <unordered_map>
#include <vector>

namespace cpx
{

class PluginFactory
{
    protected:
        AbstractLibraryLoader* _libLoader;
        std::unordered_map<std::string,AbstractProducer*> _producers;
    
        
    public:
        PluginFactory();

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
                else
                {
                    cpx_throw("Atempting wrong cast. Producer is of type '",it->second->getInterfaceName(),"'");
                }
            }
            return nullptr;
        }  
        void loadLibrary(const std::string& path);
};

}

#endif


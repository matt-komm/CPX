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
        cpx::AbstractLibraryLoader* _libLoader;
        std::unordered_map<std::string,cpx::AbstractProducer*> _producers;
    
        
    public:
        PluginFactory();

        void registerProducer(cpx::AbstractProducer* producer);
        std::vector<std::string> getRegisteredPluginNames() const;
        
        inline bool hasPluginRegistered(const std::string& name) const
        {
            return _producers.find(name)!=_producers.end();
        }
        
        std::string toString() const;
        
        template<class PRODUCER=cpx::AbstractProducer> PRODUCER* getProducer(const std::string& name) const
        {
            std::unordered_map<std::string,cpx::AbstractProducer*>::const_iterator it = _producers.find(name);
            if (it!=_producers.cend())
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
        
        ~PluginFactory();
};

}

#endif


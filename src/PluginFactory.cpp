#include "cpx/PluginFactory.hpp"

namespace cpx
{

PluginFactory::PluginFactory():
    _libLoader(new LibraryLoader(this))
{
}

void PluginFactory::registerProducer(AbstractProducer* producer)
{
    _producers[producer->getPluginName()]=producer;
}

std::vector<std::string> PluginFactory::getRegisteredPluginNames()
{
    std::vector<std::string> keys(_producers.size());
    for (std::unordered_map<std::string,AbstractProducer*>::iterator it = _producers.begin(); it!=_producers.end(); ++it)
    {
        keys[std::distance(it,_producers.begin())]=it->first;
    }
    return keys;
}

void PluginFactory::loadLibrary(const std::string& path)
{
    _libLoader->loadLibrary(path);
}

PluginFactory::~PluginFactory()
{
    delete _libLoader;
}

}




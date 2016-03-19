#include "cpx/PluginFactory.hpp"

#include <sstream>

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

std::vector<std::string> PluginFactory::getRegisteredPluginNames() const
{
    std::vector<std::string> keys(_producers.size());
    for (std::unordered_map<std::string,AbstractProducer*>::const_iterator it = _producers.cbegin(); it!=_producers.cend(); ++it)
    {
        keys[std::distance(it,_producers.begin())]=it->first;
    }
    return keys;
}

std::string PluginFactory::toString() const
{
    std::stringstream ss;
    ss << "CPX Plugin" <<std::endl;
    for (const std::string& name: getRegisteredPluginNames())
    {
        ss << name << " ("<<getProducer(name)->toString()<<std::endl;
    }
    return ss.str();
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




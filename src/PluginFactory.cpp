#include "cpx/PluginFactory.hpp"

#include <sstream>
#include <iostream>

namespace cpx
{

PluginFactory::PluginFactory():
    _libLoader(new LibraryLoader(this))
{
}

void PluginFactory::registerProducer(AbstractProducer* producer)
{
    if (_producers.find(producer->getPluginName())!=_producers.end())
    {
        cpx_throw("Plugin ",producer->toString()," already registered");
    }
    _producers[producer->getPluginName()]=producer;
}

std::vector<std::string> PluginFactory::getRegisteredPluginNames() const
{
    std::vector<std::string> keys;
    for (std::unordered_map<std::string,AbstractProducer*>::const_iterator it = _producers.cbegin(); it!=_producers.cend(); ++it)
    {
        keys.push_back(it->first);
    }
    return std::move(keys);
}

std::string PluginFactory::toString() const
{
    std::stringstream ss;
    ss << "CPX Plugin" <<std::endl;
    for (const std::string& name: getRegisteredPluginNames())
    {
        ss << name << " ("<<getProducer(name)->toString()<<std::endl;
    }
    return std::move(ss.str());
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




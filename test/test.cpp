
#include "cpx/PluginFactory.hpp"

//#include "TestPlugin.cpp"

#include <iostream>
#include <string>

int main()
{
    cpx::PluginFactory::getInstance().loadLibrary("test/libcpx-test-plugin.so");
    
    for (const std::string& pName: cpx::PluginFactory::getInstance().getRegisteredPluginNames())
    {
        cpx::AbstractProducer* producer = cpx::PluginFactory::getInstance().getProducer<cpx::AbstractProducer>(pName);
        std::cout<<"plugin: "<<producer->toString()<<std::endl;
    }
    //TestProducer* pluginProducer = cpx::PluginFactory::getInstance().getProducer<TestProducer>("TestPlugin");
    //std::cout<<pluginProducer->info()<<std::endl;
    //TestPluginInterface* t = pluginProducer->create("blublb");
    //(void)t;
    return 0;
}


#include "cpx/PluginFactory.hpp"

#include "TestPluginInterface.hpp"

#include <iostream>
#include <string>

int main()
{
    std::cout<<"start..."<<&cpx::PluginFactory::getInstance()<<std::endl;
    cpx::PluginFactory::getInstance().loadLibrary("test/libcpx-test-plugin.dll");
    
    for (const std::string& pName: cpx::PluginFactory::getInstance().getRegisteredPluginNames())
    {
        cpx::AbstractProducer* producer = cpx::PluginFactory::getInstance().getProducer<cpx::AbstractProducer>(pName);
        std::cout<<"loaded plugins: "<<producer->toString()<<std::endl;
    }
    /*
    TestPluginProducer* pluginProducer = cpx::PluginFactory::getInstance().getProducer<TestPluginProducer>("TestPlugin");
    std::cout<<pluginProducer->toString()<<std::endl;
    TestPluginInterface* t = pluginProducer->create("blublb");
    (void)t;
    */
    return 0;
}



#include "cpx/PluginFactory.hpp"

#include "TestPlugin.cpp"

#include <iostream>
#include <string>

int main()
{
    //CPPPS_throw("blub");
    //CPPPS::PluginFactory::getInstance()->loadPluginsFromFile("test/libcppps-test-plugin.so");
    /*
    for (const std::string& pName: PluginFactory::getInstance().getRegisteredPluginNames())
    {
        std::cout<<"plugin: "<<pName<<std::endl;
    }*/
    TestProducer* pluginProducer = cpx::PluginFactory::getInstance().getProducer<TestProducer>("TestPlugin");
    std::cout<<pluginProducer->info()<<std::endl;
    TestPluginInterface* t = pluginProducer->create("blublb");
    (void)t;
    return 0;
}


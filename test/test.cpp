#include "cpx/PluginFactory.hpp"

#include "TestPluginInterface.hpp"

#include <iostream>
#include <string>

int main()
{
    cpx::PluginFactory pluginFactory;

    try
    {
        pluginFactory.loadLibrary("test/test-plugin.cpx");
    } 
    catch (const std::runtime_error& e)
    {
        std::cerr << e.what() <<std::endl;
        return 1;
    }
    
    
    if (pluginFactory.getRegisteredPluginNames().size()!=1)
    {
        std::cerr << "Error: plugin not registered" <<std::endl;
        return 1;
    }
    
    
    std::cout << pluginFactory.toString();
    
    TestPluginProducer* pluginProducer = pluginFactory.getProducer<TestPluginProducer>("TestPlugin");
    
    
    
    //std::cout<<pluginProducer->toString()<<std::endl;
    std::string s("Test Plugin Argument");
    TestPluginInterface* t = pluginProducer->create(s);
    (void)t;
    
    return 0;
}


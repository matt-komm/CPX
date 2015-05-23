#include "cpx/PluginFactory.hpp"

#include "TestPluginInterface.hpp"

#include <iostream>
#include <string>

int main()
{
    cpx::PluginFactory pl;
    std::cout<<"start..."<<&pl<<std::endl;
    pl.loadLibrary("test/test-plugin.cpx");
    
    
    for (const std::string& pName: pl.getRegisteredPluginNames())
    {
        //cpx::AbstractProducer* producer = pl.getProducer<cpx::AbstractProducer>(pName);
        //std::cout<<"loaded plugins: "<<producer->toString()<<std::endl;
    }
    
    /*
    TestPluginProducer* pluginProducer = cpx::PluginFactory::getInstance().getProducer<TestPluginProducer>("TestPlugin");
    std::cout<<pluginProducer->toString()<<std::endl;
    TestPluginInterface* t = pluginProducer->create("blublb");
    (void)t;
    */
    return 0;
}


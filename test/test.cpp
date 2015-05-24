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
    
    
    TestPluginProducer* pluginProducer = pl.getProducer<TestPluginProducer>("TestPlugin");
    std::cout<<pluginProducer->toString()<<std::endl;
    std::string s("blublb");
    TestPluginInterface* t = pluginProducer->create(s);
    std::cout<<s<<std::endl;
    //(void)t;
    
    return 0;
}


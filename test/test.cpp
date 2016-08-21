#include "cpx/PluginFactory.hpp"

#include "TestPluginInterface.hpp"

#include "minitest.h"

#include <iostream>
#include <string>

/*
If filename contains a slash ("/"), then it is interpreted as a (relative or absolute) pathname. 
Otherwise, the dynamic linker searches for the library as follows (see ld.so(8) for further details)
*/

void test_loading_default()
{
    cpx::PluginFactory pluginFactory;
    pluginFactory.loadLibrary("./test-plugin.cpx");
    ASSERT_EQ(pluginFactory.getRegisteredPluginNames().size(),1);
    pluginFactory.loadLibrary("./test-plugin-other.cpx");
    ASSERT_EQ(pluginFactory.getRegisteredPluginNames().size(),2);
}

void test_loading_nosingleton()
{
    cpx::PluginFactory pluginFactory;
    cpx::PluginFactory pluginFactory2;
    pluginFactory.loadLibrary("./test-plugin.cpx");
    ASSERT_EQ(pluginFactory.getRegisteredPluginNames().size(),1);
    ASSERT_EQ(pluginFactory2.getRegisteredPluginNames().size(),0);
    pluginFactory2.loadLibrary("./test-plugin-copy.cpx");
    pluginFactory2.loadLibrary("./test-plugin-other.cpx");
    ASSERT_EQ(pluginFactory.getRegisteredPluginNames().size(),1);
    ASSERT_EQ(pluginFactory2.getRegisteredPluginNames().size(),2);
}

void test_loading_error()
{
    cpx::PluginFactory pluginFactory;
    ASSERT_RAISE(pluginFactory.loadLibrary("./test-plugin.cp"));
}

void test_loading_twice()
{
    cpx::PluginFactory pluginFactory;
    pluginFactory.loadLibrary("./test-plugin.cpx");
    ASSERT_RAISE(pluginFactory.loadLibrary("./test-plugin.cpx"));
}

void test_loading_copy()
{
    cpx::PluginFactory pluginFactory;
    pluginFactory.loadLibrary("./test-plugin.cpx");
    ASSERT_RAISE(pluginFactory.loadLibrary("./test/test-plugin-copy.cpx"));
}


int main()
{
    
    RUN_TEST(test_loading_default);
    RUN_TEST(test_loading_nosingleton);
    RUN_TEST(test_loading_error);
    RUN_TEST(test_loading_twice);
    RUN_TEST(test_loading_copy);
 
    /*
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
    */
    return 0;
}


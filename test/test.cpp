#include "cpx/PluginFactory.hpp"

#include "TestPluginInterface.hpp"

#include "minitest.h"

#include <iostream>
#include <string>

/*
dlopen:
If filename contains a slash ("/"), then it is interpreted as a (relative or absolute) pathname. 
Otherwise, the dynamic linker searches for the library as follows (see ld.so(8) for further details)
  o   (ELF only) If the executable file for the calling program
       contains a DT_RPATH tag, and does not contain a DT_RUNPATH tag,
       then the directories listed in the DT_RPATH tag are searched.

   o   If, at the time that the program was started, the environment
       variable LD_LIBRARY_PATH was defined to contain a colon-separated
       list of directories, then these are searched.  (As a security
       measure this variable is ignored for set-user-ID and set-group-ID
       programs.)

   o   (ELF only) If the executable file for the calling program
       contains a DT_RUNPATH tag, then the directories listed in that
       tag are searched.

   o   The cache file /etc/ld.so.cache (maintained by ldconfig(8)) is
       checked to see whether it contains an entry for filename.

   o   The directories /lib and /usr/lib are searched (in that order).
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


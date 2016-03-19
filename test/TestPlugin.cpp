#include "cpx/Version.hpp"

#include "TestPluginInterface.hpp"

#include <string>
#include <iostream>
#include <memory>

class TestPlugin:
    public TestPluginInterface
{
    protected:
        std::string _testArgument;
    public:
        cpx_setup_plugin("TestPlugin",1,0,"TestPlugin Description")
    
        TestPlugin(std::string& testArgument):
            _testArgument(testArgument)
        {
        }
        
        TestPlugin()
        {
        }
        
        virtual std::string testArgument() const
        {
            return _testArgument;
        }
        
};


cpx_init_module()
{
    cpx_register_plugin(TestPluginProducer,TestPlugin);
}



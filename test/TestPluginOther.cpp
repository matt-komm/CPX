#include "cpx/Version.hpp"

#include "TestPluginInterface.hpp"

#include <string>
#include <iostream>
#include <memory>

class TestPluginOther:
    public TestPluginInterface
{
    protected:
        std::string _testArgument;
    public:
        cpx_setup_plugin("TestPluginOther",1,0,"TestPluginOther Description")
    
        TestPluginOther(std::string& testArgument):
            _testArgument(testArgument)
        {
        }
        
        virtual std::string testArgument() const
        {
            return _testArgument;
        }
        
};


cpx_init_module()
{
    cpx_register_plugin(TestPluginProducer,TestPluginOther);
}



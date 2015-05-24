#include "cpx/Version.hpp"

#include "TestPluginInterface.hpp"

#include <string>
#include <iostream>
#include <memory>

class TestPlugin:
    public TestPluginInterface
{
    protected:
    public:
        TestPlugin(std::string& name)
        {
            
            std::cout<<name<<std::endl;
            name = "huhluu";
        }
        
        TestPlugin()
        {
            
            
        }
        
        virtual std::string testString() const
        {
            return "TestPlugin";
        }
        
        static std::string getPluginName()
        {
            return "TestPlugin";
        }
        
        static cpx::Version getVersion()
        {
            return cpx::Version(1,0);
        }
        
        static std::string getDescription()
        {
            return "blub";
        }
};


cpx_init_module()
{
    cpx_register_plugin(TestPluginProducer,TestPlugin);
    return 0;
}



#include "cpx/Version.hpp"

#include "TestPluginInterface.hpp"

#include <string>
#include <iostream>
#include <tuple>

class TestPlugin:
    public TestPluginInterface
{
    protected:
    public:
        TestPlugin(std::string name)
        {
            std::cout<<name<<std::endl;
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

static cpx::ConcretePluginProducer<TestPluginProducer,TestPlugin> testplugin;

//REGISTER_PLUGIN(TestPluginProducer,TestPlugin)


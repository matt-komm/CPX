#include "cpx/PluginProducer.hpp"
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
        
        static Version getVersion()
        {
            return Version(1,0);
        }
        
        static std::string getDescription()
        {
            return "blub";
        }
        /*
        Class(const Class& c);
        Class(Class&& c);
        Class& operator=(const Class& c);
        Class& operator=(Class&& c);
        ~Class();
        */
};

typedef PluginProducer<TestPluginInterface,std::string> TestProducer;
REGISTER_PLUGIN(TestProducer,TestPlugin)

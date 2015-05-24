#ifndef __CPPPS_TESTPLUGININTERFACE_H__
#define __CPPPS_TESTPLUGININTERFACE_H__

#include "cpx/PluginProducer.hpp"
#include "cpx/Version.hpp"

#include <string>

class TestPluginInterface
{
    protected:
    public:
        static std::string getInterfaceName()
        {
            return "TestPluginInterface";
        }
        
        static cpx::Version getInterfaceVersion()
        {
            return cpx::Version(0,0);
        }
        
        virtual std::string testString() const = 0;
};

typedef cpx::PluginProducer<TestPluginInterface,cpx::Signature<std::string&>> TestPluginProducer;



#endif


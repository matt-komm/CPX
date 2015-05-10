#ifndef __CPPPS_TESTPLUGININTERFACE_H__
#define __CPPPS_TESTPLUGININTERFACE_H__

#include <cpx/Version.hpp>

#include <string>

class TestPluginInterface
{
    protected:
    public:
        TestPluginInterface()
        {
        }
        
        static std::string getInterfaceClassName()
        {
            return "TestPluginInterface";
        }
        
        static std::string getInterfaceName()
        {
            return "TestPluginInterface";
        }
        
        static Version getInterfaceVersion()
        {
            return Version(0,0);
        }
        
        virtual std::string testString() const = 0;
        /*
        Class(const Class& c);
        Class(Class&& c);
        Class& operator=(const Class& c);
        Class& operator=(Class&& c);
        ~Class();
        */
};

#endif


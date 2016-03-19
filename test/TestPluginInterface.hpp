#ifndef __CPX_TESTPLUGININTERFACE_H__
#define __CPX_TESTPLUGININTERFACE_H__

#include "cpx/PluginProducer.hpp"
#include "cpx/Version.hpp"

#include <string>

class TestPluginInterface
{
    protected:
    public:
        cpx_setup_interface("TestPluginInterface",0,0)
        
        virtual std::string testArgument() const = 0;
};

typedef cpx::PluginProducer<TestPluginInterface,cpx::Signature<std::string&>> TestPluginProducer;

#endif


#ifndef __CPX_ABSTRACTPRODUCER_H__
#define __CPX_ABSTRACTPRODUCER_H__

#include "cpx/Version.hpp"
#include "cpx/shared.h"

#include <string>
#include <sstream>

namespace cpx
{

class cpx_shared AbstractProducer
{
    protected:
    public:

        virtual std::string getInterfaceName() const = 0;
        virtual cpx::Version getInterfaceVersion() const = 0;
        
        virtual std::string getPluginName() const = 0;
        virtual cpx::Version getPluginVersion() const = 0;
        
        virtual std::string getPluginDescription() const = 0;
        
        virtual std::string toString() const
        {
            std::stringstream ss;
            ss<<"Plugin = "<<getPluginName()<<"@"<<getPluginVersion().toString();
            ss<<", Interface = "<<getInterfaceName()<<"@"<<getInterfaceVersion().toString();
            return ss.str();
        }
};

}

#endif


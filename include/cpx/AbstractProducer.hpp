#ifndef __CPX_ABSTRACTPRODUCER_H__
#define __CPX_ABSTRACTPRODUCER_H__

#include "cpx/Version.hpp"

#include <string>
#include <sstream>

class AbstractProducer
{
    protected:
    public:

        virtual std::string getInterfaceName() const = 0;
        virtual Version getInterfaceVersion() const = 0;
        
        virtual std::string getPluginName() const = 0;
        virtual Version getPluginVersion() const = 0;
        
        virtual std::string getPluginDescription() const = 0;
        
        virtual std::string info() const
        {
            std::stringstream ss;
            ss<<"Plugin = "<<getPluginName()<<", Interface = "<<getInterfaceName();
            return ss.str();
        }
};

#endif


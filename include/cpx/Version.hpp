#ifndef __CPX_VERSION_H__
#define __CPX_VERSION_H__

#include "cpx/shared.h"

#include <string>
#include <sstream>

namespace cpx
{

class cpx_shared Version
{
    protected:
        unsigned int _vmajor;
        unsigned int _vminor;
        
    public:
    
        Version(unsigned int vmajor=0, unsigned int vminor=0):
            _vmajor(vmajor), _vminor(vminor)
        {
        }
        
        bool operator<(const Version& v) const
        {
            return _vmajor<v._vmajor || ((_vmajor==v._vmajor) && (_vminor<v._vminor));
        }
        
        bool operator>(const Version& v) const
        {
            return _vmajor>v._vmajor || ((_vmajor==v._vmajor) && (_vminor>v._vminor));
        }
        
        bool operator==(const Version& v) const
        {
            return (_vmajor==v._vmajor) && (_vminor==v._vminor);
        }
        
        bool operator!=(const Version& v) const
        {
            return (_vmajor!=v._vmajor) || (_vminor!=v._vminor);
        }
        
        std::string toString() const
        {
            std::stringstream ss;
            ss<<"v"<<_vmajor<<"."<<_vminor;
            return ss.str();
        }
};

}

#endif


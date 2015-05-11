#ifndef __CPX_VERSION_H__
#define __CPX_VERSION_H__

namespace cpx
{

struct Version
{
    protected:
        unsigned int major;
        unsigned int minor;
        
    public:
        Version(unsigned int major, unsigned int minor):
            major(major), minor(minor)
        {
        }
};

}

#endif


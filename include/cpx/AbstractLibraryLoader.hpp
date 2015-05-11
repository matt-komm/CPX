#ifndef __CPX_ABSTRACTLIBRARYLOADER_H__
#define __CPX_ABSTRACTLIBRARYLOADER_H__

#include <string>

namespace cpx
{

class AbstractLibraryLoader
{
    protected:
    public:

        virtual void loadLibrary(std::string file) = 0;
        
        virtual ~AbstractLibraryLoader()
        {
        }
};

}

#endif

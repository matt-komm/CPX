#ifndef __CPX_ABSTRACTLIBRARYLOADER_H__
#define __CPX_ABSTRACTLIBRARYLOADER_H__

#include "cpx/shared.h"

#include <string>

namespace cpx
{

class cpx_shared AbstractLibraryLoader
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

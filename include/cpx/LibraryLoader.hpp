#ifndef __CPX_LIBRARYLOADER_H__
#define __CPX_LIBRARYLOADER_H__

#include "cpx/AbstractLibraryLoader.hpp"
#include "cpx/shared.h"

namespace cpx
{

//hides casts from the compiler
template<typename INPTR, typename OUTPTR>
class cpx_shared SharedMemory
{
    private:
        union Memory
        {
            INPTR iptr;
            OUTPTR optr;
        } _memory;

    public:
        SharedMemory(INPTR inptr)
        {
            _memory.iptr=inptr;
        }

        OUTPTR get()
        {
            return _memory.optr;
        }
};


}


#ifdef OS_LINUX
#define LIBLOADERHEADERFOUND

#include "cpx/LinuxLibraryLoader.hpp"
namespace cpx
{
    typedef LinuxLibraryLoader LibraryLoader;
}

#endif
#ifdef OS_WINDOWS
#define LIBLOADERHEADERFOUND

#include "cpx/WindowsLibraryLoader.hpp"
namespace cpx
{
    typedef WindowsLibraryLoader LibraryLoader;
}

#endif

#ifndef LIBLOADERHEADERFOUND
#error "no suited library loader found or system not recognized"
#endif


#endif



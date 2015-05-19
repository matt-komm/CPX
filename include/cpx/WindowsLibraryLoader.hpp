#ifndef __CPX_WINDOWSLIBRARYLOADER_H__
#define __CPX_WINDOWSLIBRARYLOADER_H__

#include "cpx/AbstractLibraryLoader.hpp"

#include <string>
#include <map>

#include <windows.h>


namespace cpx
{

class WindowsLibraryLoader:
    public AbstractLibraryLoader
{
    protected:
        std::map<std::string,HINSTANCE> _loadedLibHandles;
    public:
        WindowsLibraryLoader();
        virtual ~WindowsLibraryLoader();
        virtual void loadLibrary(std::string file);
};

}

#endif


#ifndef __CPX_WINDOWSLIBRARYLOADER_H__
#define __CPX_WINDOWSLIBRARYLOADER_H__

#include "cpx/AbstractLibraryLoader.hpp"

#include <string>
#include <map>


namespace cpx
{

class WindowsLibraryLoader:
    public AbstractLibraryLoader
{
    protected:
        typedef void (*init_function_type)(void);

        std::map<std::string,void*> _loadedLibHandles;
    public:
        WindowsLibraryLoader();
        virtual ~WindowsLibraryLoader();
        virtual void loadLibrary(std::string file);
};

}

#endif


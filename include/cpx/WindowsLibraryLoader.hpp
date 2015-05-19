#ifndef __CPX_WINDOWSLIBRARYLOADER_H__
#define __CPX_WINDOWSLIBRARYLOADER_H__

#include "cpx/AbstractLibraryLoader.hpp"

#include <string>
#include <map>

#include <windows.h>


namespace cpx
{

class PluginFactory;

class WindowsLibraryLoader:
    public AbstractLibraryLoader
{
    protected:
        std::map<std::string,HINSTANCE> _loadedLibHandles;
        PluginFactory* _pluginFactory;
    public:
        WindowsLibraryLoader(PluginFactory* pluginFactory);
        virtual ~WindowsLibraryLoader();
        virtual void loadLibrary(std::string file);
};

}

#endif


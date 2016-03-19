#ifndef __CPX_LINUXLIBRARYLOADER_H__
#define __CPX_LINUXLIBRARYLOADER_H__

#include "cpx/AbstractLibraryLoader.hpp"
#include "cpx/shared.h"

#include <string>
#include <map>


namespace cpx
{

class PluginFactory;

class cpx_shared LinuxLibraryLoader:
    public AbstractLibraryLoader
{
    protected:

        std::map<std::string,void*> _loadedLibHandles;
        PluginFactory* _pluginFactory;
    public:
        LinuxLibraryLoader(PluginFactory* pluginFactory);
        virtual ~LinuxLibraryLoader();
        virtual void loadLibrary(std::string file);
};

}

#endif


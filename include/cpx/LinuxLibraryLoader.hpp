#ifndef __CPX_LINUXLIBRARYLOADER_H__
#define __CPX_LINUXLIBRARYLOADER_H__

#include "cpx/AbstractLibraryLoader.hpp"

#include <string>
#include <map>


namespace cpx
{

class PluginFactory;

class LinuxLibraryLoader:
    public AbstractLibraryLoader
{
    protected:
        typedef void (*init_function_type)(void);

        std::map<std::string,void*> _loadedLibHandles;
        PluginFactory* _pluginFactory;
    public:
        LinuxLibraryLoader(PluginFactory* pluginFactory);
        virtual ~LinuxLibraryLoader();
        virtual void loadLibrary(std::string file);
};

}

#endif

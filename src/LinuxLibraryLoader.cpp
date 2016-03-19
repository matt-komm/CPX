#include "cpx/LinuxLibraryLoader.hpp"
#include "cpx/PluginFactory.hpp"

#include <dlfcn.h>

namespace cpx
{

LinuxLibraryLoader::LinuxLibraryLoader(PluginFactory* pluginFactory):
    _pluginFactory(pluginFactory)
{
}

void LinuxLibraryLoader::loadLibrary(std::string file)
{
    typedef void (*InitFct)(cpx::PluginFactory*);
    if (_loadedLibHandles.find(file)==_loadedLibHandles.end())
    {
        void* lib_handle;
        char *error;
        lib_handle = dlopen(file.c_str(), RTLD_LAZY);
        if (!lib_handle)
        {
            cpx_throw("Error while opening file: '",file,"': ",dlerror());
        }
        _loadedLibHandles[file]=lib_handle;
        
        //hides object-to-function cast from the compiler
        SharedMemory<void*,InitFct> smemory(dlsym(lib_handle, "init"));
        InitFct initFct = smemory.get();
        if ((error = dlerror()) != NULL)
        {
            cpx_throw("Error while initializing file: '",file,"': ",dlerror());
        }
        (*initFct)(_pluginFactory);
    }
    else
    {
        cpx_throw("Plugin file ",file," already loaded");
    }
}

LinuxLibraryLoader::~LinuxLibraryLoader()
{
    for (auto handle: _loadedLibHandles)
    {
        dlclose(handle.second);
    }
}

}

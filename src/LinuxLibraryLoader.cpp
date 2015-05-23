#include "cpx/LinuxLibraryLoader.hpp"

#include <dlfcn.h>

namespace cpx
{

LinuxLibraryLoader::LinuxLibraryLoader(PluginFactory* pluginFactory):
    _pluginFactory(pluginFactory)
{
}

void LinuxLibraryLoader::loadLibrary(std::string file)
{
    if (_loadedLibHandles.find(file)==_loadedLibHandles.end())
    {
        void* lib_handle;
        //char *error;
        lib_handle = dlopen(file.c_str(), RTLD_LAZY);
        if (!lib_handle)
        {
            //CPPPS_throw("Error while opening file: '",file,"': ",dlerror());
        }
        _loadedLibHandles[file]=lib_handle;
        /*
        //hides object-to-function cast from the compiler
        SharedMemory<void*,init_function_type> smemory(dlsym(lib_handle, "initialize"));
        init_function_type fn = smemory.get();
        if ((error = dlerror()) != NULL)
        {
            CPPPS_throw("Error while initializing file: '",file,"': ",dlerror());
        }
        (*fn)();
        */
    }
}

LinuxLibraryLoader::~LinuxLibraryLoader()
{
    //dlclose(lib_handle);
}

}

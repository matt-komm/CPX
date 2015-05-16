#include "cpx/WindowsLibraryLoader.hpp"



namespace cpx
{

WindowsLibraryLoader::WindowsLibraryLoader()
{

}

void WindowsLibraryLoader::loadLibrary(std::string file)
{
    /*
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
        
    }
    */
}

WindowsLibraryLoader::~WindowsLibraryLoader()
{
    //dlclose(lib_handle);
}

}

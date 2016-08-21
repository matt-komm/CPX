#include "cpx/WindowsLibraryLoader.hpp"

#include "cpx/Exception.hpp"
#include "cpx/PluginFactory.hpp"

#include <iostream>
#include <algorithm>

namespace cpx
{

WindowsLibraryLoader::WindowsLibraryLoader(cpx::PluginFactory* pluginFactory):
    _pluginFactory(pluginFactory)
{

}

void WindowsLibraryLoader::loadLibrary(std::string file)
{
    typedef void (__cdecl *InitFct)(cpx::PluginFactory*);
    
    std::replace( file.begin(), file.end(), '/', '\\');
    
    if (_loadedLibHandles.find(file)==_loadedLibHandles.end())
    {
        HINSTANCE lib_handle = LoadLibraryEx(file.c_str(),NULL,LOAD_LIBRARY_SEARCH_DEFAULT_DIRS);
        if (!lib_handle)
        {
            DWORD dwLastError = GetLastError();
            const unsigned int N = 256;
            TCHAR lpBuffer[N];
            if(dwLastError != 0)
            {
                FormatMessage(
                    FORMAT_MESSAGE_FROM_SYSTEM,                 // It's a system error
                    NULL,                                      // No string to be formatted needed
                    dwLastError,                               // Hey Windows: Please explain this error!
                    MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT),  // Do it in the standard language
                    lpBuffer,              // Put the message here
                    N-1,                     // Number of bytes to store the message
                    NULL
                );
                cpx_throw("Error while opening file: '",file,"': ",lpBuffer);
            }
        }
        InitFct initFct = (InitFct) GetProcAddress(lib_handle, "init");
        if (!initFct)
        {
            DWORD dwLastError = GetLastError();
            const unsigned int N = 256;
            TCHAR lpBuffer[N];
            if(dwLastError != 0)
            {
                FormatMessage(
                    FORMAT_MESSAGE_FROM_SYSTEM,                 // It's a system error
                    NULL,                                      // No string to be formatted needed
                    dwLastError,                               // Hey Windows: Please explain this error!
                    MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT),  // Do it in the standard language
                    lpBuffer,              // Put the message here
                    N-1,                     // Number of bytes to store the message
                    NULL
                );
                cpx_throw("Error while initializing file: '",file,"': ",lpBuffer);
            }
        }
        (initFct)(_pluginFactory);
        _loadedLibHandles[file]=lib_handle;
    }
    else
    {
        cpx_throw("Plugin file '",file,"' already loaded");
    }
}

WindowsLibraryLoader::~WindowsLibraryLoader()
{
    for (auto handle: _loadedLibHandles)
    {
        FreeLibrary(handle.second);
    }
}

}

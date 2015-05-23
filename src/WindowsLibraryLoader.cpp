#include "cpx/WindowsLibraryLoader.hpp"

#include "cpx/Exception.hpp"
#include "cpx/PluginFactory.hpp"

#include <iostream>

namespace cpx
{

WindowsLibraryLoader::WindowsLibraryLoader(cpx::PluginFactory* pluginFactory):
    _pluginFactory(pluginFactory)
{

}

void WindowsLibraryLoader::loadLibrary(std::string file)
{
    typedef int (__cdecl *InitFct)(cpx::PluginFactory*); 
    std::cout<<"loading lib: "<<file<<std::endl;
    if (_loadedLibHandles.find(file)==_loadedLibHandles.end())
    {
        HINSTANCE lib_handle = LoadLibrary(file.c_str());
        if (!lib_handle)
        {
            DWORD dwLastError = GetLastError();
            const unsigned int N = 256;
            TCHAR lpBuffer[N];
            if(dwLastError != 0)
            {
                FormatMessage(
                    FORMAT_MESSAGE_FROM_SYSTEM,                 // It´s a system error
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
                    FORMAT_MESSAGE_FROM_SYSTEM,                 // It´s a system error
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
    
}

WindowsLibraryLoader::~WindowsLibraryLoader()
{
    for (auto handle: _loadedLibHandles)
    {
        FreeLibrary(handle.second);
    }
}

}

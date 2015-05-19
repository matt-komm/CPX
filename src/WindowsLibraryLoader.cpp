#include "cpx/WindowsLibraryLoader.hpp"

#include "cpx/Exception.hpp"

#include <iostream>

namespace cpx
{

WindowsLibraryLoader::WindowsLibraryLoader()
{

}

void WindowsLibraryLoader::loadLibrary(std::string file)
{

    std::cout<<"loading lib: "<<file<<std::endl;
    if (_loadedLibHandles.find(file)==_loadedLibHandles.end())
    {
        HINSTANCE lib_handle = LoadLibrary(file.c_str());
        if (!lib_handle)
        {
            DWORD   dwLastError = ::GetLastError();
            const unsigned int N = 256;
            TCHAR   lpBuffer[N];
            if(dwLastError != 0)    // Don't want to see a "operation done successfully" error ;-)
                ::FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,                 // It´s a system error
                                 NULL,                                      // No string to be formatted needed
                                 dwLastError,                               // Hey Windows: Please explain this error!
                                 MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT),  // Do it in the standard language
                                 lpBuffer,              // Put the message here
                                 N-1,                     // Number of bytes to store the message
                                 NULL);
            cpx_throw("Error while opening file: '",file,"': ",lpBuffer);
        }
        else
        {
            _loadedLibHandles[file]=lib_handle;
        }
        
    }
    
}

WindowsLibraryLoader::~WindowsLibraryLoader()
{
    //dlclose(lib_handle);
}

}

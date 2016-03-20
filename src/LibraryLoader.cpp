#ifdef OS_LINUX
#define LIBLOADERSRC
#include "LinuxLibraryLoader.cpp"
#endif

#ifdef OS_MACOSX
#define LIBLOADERSRC
#include "LinuxLibraryLoader.cpp"
#endif
    
#ifdef OS_WINDOWS
#define LIBLOADERSRC
#include "WindowsLibraryLoader.cpp"
#endif

#ifndef LIBLOADERSRC
#error "no suited library loader found or system not recognized"
#endif


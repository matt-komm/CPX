#ifdef OS_LINUX
#define LIBLOADERSRC

#include "LinuxLibraryLoader.cpp"

#else
//....
#endif

#ifndef LIBLOADERSRC
#error "no suited library loader found or system not recognized"
#endif


#ifndef __CPX_EXPORT_H__
#define __CPX_EXPORT_H__

#ifdef OS_LINUX
#define cpx_shared
#endif
#ifdef OS_MACOSX
#define cpx_shared
#endif
#ifdef OS_WINDOWS
#define cpx_shared __declspec(dllexport)
#endif

#endif


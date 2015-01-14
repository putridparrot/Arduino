#ifndef __EXPORT_H
#define __EXPORT_H

#ifdef EXPORT_LIB
#define API _declspec(dllexport)
#else
#define API
#endif

#endif
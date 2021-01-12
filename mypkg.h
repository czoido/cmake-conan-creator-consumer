#pragma once

#ifdef WIN32
  #define mypkg_EXPORT __declspec(dllexport)
#else
  #define mypkg_EXPORT
#endif

mypkg_EXPORT void mypkg();

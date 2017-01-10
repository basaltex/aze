/*
* Pal.hpp
* git-analyze Pal
* author: Force.Charlie
* Date: 2016.08
* Copyright (C) 2017. OSChina.NET. All Rights Reserved.
*/
#ifndef GIT_ANALYZE_PAL_HPP
#define GIT_ANALYZE_PAL_HPP
#include <cstdint>
#include <cstddef>
#include <string>

#ifdef __GNUC__
// int BaseBufferPrint(char *buf, size_t maxlen, const char *format, ...)
//     __attribute__((format(printf, 3, 4)));
int BaseErrorMessagePrint(const char *format, ...)
    __attribute__((format(printf, 1, 2)));
int BaseWarningMessagePrint(const char *format, ...)
    __attribute__((format(printf, 1, 2)));
int BaseConsoleWrite(const char *format, ...)
    __attribute__((format(printf, 1, 2)));
#elif defined(_MSC_VER) && _MSC_VER > 1600
#include <Sal.h>
int BaseErrorMessagePrint(_Printf_format_string_ const char *format, ...);
int BaseWarningMessagePrint(_Printf_format_string_ const char *format, ...);
int BaseConsoleWrite(_Printf_format_string_ const char *format, ...);
#else
int BaseErrorMessagePrint(const char *format, ...);
int BaseWarningMessagePrint(const char *format, ...);
int BaseConsoleWrite(const char *format, ...);
#endif

//// WIN32 use wchar_t ,buf
template <typename charT> class PalEnvironmentT {
public:
  PalEnvironmentT() {}
  PalEnvironmentT(const PalEnvironmentT &) = delete;
  bool Boolean(const charT *key);
  std::basic_string<charT> Strings(const charT *key);
  // const char *StringsU(const_pointer key);
  int32_t Integer(const charT *key, int32_t defva_);
  uint32_t Integer(const charT *key, uint32_t defva_);
  int64_t Integer(const charT *key, int64_t defva_);
  uint64_t Integer(const charT *key, uint64_t defva_);
};
#if defined(_WIN32) && !defined __CYGWIN__
typedef PalEnvironmentT<wchar_t> PalEnvironment;
#define _X(x) L##x
#else
typedef PalEnvironmentT<char> PalEnvironment;
#define _X(x) x
#endif

#endif

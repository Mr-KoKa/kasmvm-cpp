#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <locale>
#include <codecvt>
#include <cassert>

extern std::string UnicodeToUTF8(int32_t *arrayBegin, int32_t *arrayEnd);
extern std::string UnicodeToUTF8(int32_t codePoint);

extern std::string UnicodeToUTF8(int32_t *array, int32_t size);
extern std::u32string UTF8ToUnicode(std::string s);

template <typename R, typename ... Types> 
constexpr std::integral_constant<unsigned, sizeof ...(Types)> GetArgumentCount( R(*f)(Types ...)){
   return std::integral_constant<unsigned, sizeof ...(Types)>{};
}

bool to_int(std::string s, int32_t *i);
#endif
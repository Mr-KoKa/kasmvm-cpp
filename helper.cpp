#include "helper.h"

std::string UnicodeToUTF8(int32_t *arrayBegin, int32_t *arrayEnd){
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
    std::string u8str = converter.to_bytes(reinterpret_cast<char32_t*>(arrayBegin), reinterpret_cast<char32_t*>(arrayEnd));

    return u8str;
}

std::string UnicodeToUTF8(int32_t codePoint){
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
    std::string u8str = converter.to_bytes(static_cast<char32_t>(codePoint));

    return u8str;
}

std::string UnicodeToUTF8(int32_t *array, int32_t size){
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
    std::string u8str = converter.to_bytes(reinterpret_cast<char32_t*>(array), reinterpret_cast<char32_t*>(array + size));

    return u8str;
}

std::u32string UTF8ToUnicode(std::string s){
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
    return converter.from_bytes(s.data());
}

bool to_int(std::string s, int32_t *i){
    size_t pos;

    try {
        *i = std::stoi(s, &pos, 10);
        return (pos == s.length());
    } catch(std::invalid_argument &iae){
        //...
    } catch(std::out_of_range &oore){
        //...
    }

    return false;
}

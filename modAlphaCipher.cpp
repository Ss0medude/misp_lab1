#include "modAlphaCipher.h"
modAlphaCipher::modAlphaCipher(const string& skey)
{
    locale loc("ru_RU.UTF-8"); // русская локаль для корректной смены регистра
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec; //кодек UTF-8
    wstring ws = codec.from_bytes(numAlpha); // перекодируем
    for (unsigned i=0; i<ws.size(); i++) {
        alphaNum[ws[i]]=i;
    }
    key = convert(skey);
}

string modAlphaCipher::encrypt(const string& open_text)
{
    vector<int> work = convert(open_text);
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}

string modAlphaCipher::decrypt(const string& cipher_text)
{
    vector<int> work = convert(cipher_text);
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}

inline vector<int> modAlphaCipher::convert(const string& s)
{
    vector<int> result;
    locale loc("ru_RU.UTF-8"); // русская локаль для корректной смены регистра
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec; //кодек UTF-8
    wstring ws = codec.from_bytes(s); // перекодируем
    for (unsigned i=0; i<ws.size(); i++) {
        result.push_back(alphaNum[ws[i]]);
    }
    return result;
}

inline string modAlphaCipher::convert(const vector<int>& v)
{
    string result;
    locale loc("ru_RU.UTF-8"); // русская локаль для корректной смены регистра
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec; //кодек UTF-8
    wstring ws = codec.from_bytes(numAlpha);
    wstring result_s = codec.from_bytes("");
    for (unsigned i=0; i<v.size(); i++) {
        result_s.push_back(ws[v[i]]);
    }
    result = codec.to_bytes(result_s);
    return result;
}

std::string result;
locale loc("ru_RU.UTF-8"); // русская локаль для корректной смены регистра
wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec; //кодек UTF-8
wstring ws = codec.from_bytes(numAlpha);
wstring result_s = codec.from_bytes("");
for (unsigned i=0; i<v.size(); i++)
{
    result_s.push_back(ws[v[i]]);
}
result = codec.to_bytes(result_s);
return result;
}

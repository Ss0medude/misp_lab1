#include "modAlphaCipher.h"
bool isValid(const string& s)
{
    std::locale loc("ru_RU.UTF-8");
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
    std::wstring ws = codec.from_bytes(s);
    std::string numAlpha = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    std::wstring wA = codec.from_bytes(numAlpha);
    for(unsigned int i = 0; i < ws.size(); i++) {
        if (wA.find(ws[i]) == string::npos) {
            return false;
        }
    }
    return true;
}
int main(int argc, char **argv)
{
    string key;
    string text;
    unsigned op;
    cout<<"Шифр готов, введите текст";
    cin>>key;
    if (!isValid(key)) {
        cerr<<"Ключ не подходит\n";
        return 1;
    }
    cout<<"Ключ подошел\n";
    modAlphaCipher cipher(key);
    do {
        cout<<"Ключ подошел. Выберите операцию(0-выход, 1-шифрование, 2-расшифрование): ";
        cin>>op;
        if (op > 2) {
            cout<<"Незаконная операция\n";
        } else if (op >0) {
            cout<<"Шифр готов, введите текст: ";
            cin>>text;
            if (isValid(text)) {
                if (op==1) {
                    cout<<"Шифрованный текст: "<<cipher.encrypt(text)<<endl;
                } else {
                    cout<<"Расшифрованный текст: "<<cipher.decrypt(text)<<endl;
                }
            } else {
                cout<<"Операция прекращена: неверный формат текста\n";

            }
        }
//    } while (op!=0);
//    Console.ReadLine();
//    return 0;
}

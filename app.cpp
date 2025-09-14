#include <iostream>
using namespace std;

class String {
    char* str;
    int len;
public:
    String(const char* txt = "") {
        len = 0;
        while (txt[len]) len++;
        str = new char[len + 1];
        for (int idx = 0; idx <= len; idx++) str[idx] = txt[idx];
    }
    String(const String& copy) {
        len = copy.len;
        str = new char[len + 1];
        for (int idx = 0; idx <= len; idx++) str[idx] = copy.str[idx];
    }
    ~String() {
        delete[] str;
    }
    int getLen() {
        return len;
    }
    char* getStr() {
        return str;
    }
    const char* getConstStr() {
        return str;
    }
    String operator+(const String& other) {
        String res;
        delete[] res.str;
        res.len = len + other.len;
        res.str = new char[res.len + 1];
        int pos = 0;
        for (int idx = 0; idx < len; idx++) res.str[pos++] = str[idx];
        for (int idx = 0; idx <= other.len; idx++) res.str[pos++] = other.str[idx];
        return res;
    }
};

int main() {
    setlocale(0, "");
    String str1("hello ");
    String str2("ne znau ");
    cout << "Длина первого: " << str1.getLen() << endl;
    cout << "Первый: " << str1.getStr() << endl;
    cout << "Первый (const): " << str1.getConstStr() << endl;
    String str3 = str1 + str2;
    cout << "Конкатенация: " << str3.getStr() << endl;
    String str4 = str3;
    cout << "Копия: " << str4.getStr() << endl;
    return 0;
}

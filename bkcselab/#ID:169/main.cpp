#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>

using namespace std;

class String {
	char* textBuffer;
public:
    void print() { cout << this->textBuffer; };
	~String();
    String();
    String(char* text);

    char* getText();
    char* operator + (String text);
//    char* toUpper();
//    char* toLower();
//    int length();
//    char operator [](int x);
    operator char*() {
        return this->textBuffer;
    }
};

String::~String() { delete[] this->textBuffer; }

String::String() { this->textBuffer = new char[0]; }

String::String(char* text) {
    int len = strlen(text);
    char* x = new char [len];
    for (int i = 0; i < len; i++) x[i] = text[i];
    this->textBuffer = x;
}



char* String::getText() {
    return this->textBuffer;
}

char* String::operator + (String text) {
    strcat(this->textBuffer, text.getText());
    String a(this->textBuffer);
    return a;
}

//char* String::toLower() {
//    char* lText = new char [length() + 1];
//    for (int i = 0; i < length(); i++) lText[i] = tolower(this->textBuffer[i]);
//    lText[length()] = '\0';
//    return lText;
//}

//char* String::toUpper() {
//    char* uText = new char [length() + 1];
//    for (int i = 0; i < length(); i++) uText[i] = toupper(this->textBuffer[i]);
//    uText[length()] = '\0';
//    return uText;
//}

//int String::length() { return sizeof(this->textBuffer)/sizeof(char); }

//char String::operator [] (int x) {
//    return this->textBuffer[x];
//}

String toString(const char* x) {
    char* ptr = NULL;
    *ptr = *x;
    String a = ptr;
    return a;
}

int main()
{
    char* fn = new char [3];
    fn[0] = '1';
    fn[1] = '2';
    char* ln = new char [4];
    ln[0] = 'a';
    ln[1] = ' ';
    ln[2] = 'b';
    //process(fn, ln);
    String b = fn;
    String c = ln;
    b + toString(" ") + c;
    b.print();
}

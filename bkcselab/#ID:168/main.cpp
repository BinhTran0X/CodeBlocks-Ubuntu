#include <iostream>

using namespace std;

class CaesarMessage {
	char* textBuffer;
public:
	CaesarMessage();
	CaesarMessage(CaesarMessage& obj);
	~CaesarMessage();
	void encode(const char* _message, int _shift);
	void decode(int _shiftKey, char*& _textContainer);
	void print() {
        cout << textBuffer;
	}
};

CaesarMessage::CaesarMessage() {
    textBuffer = NULL;
}

CaesarMessage::CaesarMessage(CaesarMessage& obj) {
    int len = 0;
    for (int i = 0; (obj.textBuffer)[i] != '\0'; i++) {
        len += 1;
    }
    if (this->textBuffer != NULL) delete this->textBuffer;
    this->textBuffer = new char [len + 1];
    for (int i = 0 ; i < len; i++) {
        textBuffer[i] = obj.textBuffer[i];
    }
    textBuffer[len] = '\0';
}

CaesarMessage::~CaesarMessage() {
	/* You have to tidy the dynamic memory, right?
	But, wait! What will happen if the textBuffer has been deleted already?
	Can that problem happen? When, why? And what is the solution? */
	delete[] this->textBuffer;
	this->textBuffer = NULL;
}

void CaesarMessage::encode(const char* _message, int _shift) {
    int len = 0;
    for (int i = 0; _message[i] != '\0'; i++) {
        if ((int(_message[i] - 'a') >= 0 && int(_message[i] - 'a') < 26) || (int(_message[i] - 'A') >= 0 && int(_message[i] - 'A') < 26)) len += 1;
    }
    int len1 = 0;
    for (int i = 0; _message[i] != '\0'; i++) {
        len1 += 1;
    }
    textBuffer = new char [len + 1];
    int Count = 0;
    for (int i = 0; i < len1; i++, Count++) {
        if (!(int(_message[i] - 'a') >= 0 && int(_message[i] - 'a') < 26) && !(int(_message[i] - 'A') >= 0 && int(_message[i] - 'A') < 26)) {
            Count--;
            continue;
        }
        int diff1 = _message[i] - 'A';
        if (diff1 < 26 && diff1 >= 0) {
            textBuffer[Count] = char(_message[i] - 'A' + 'a' + _shift);
            if (textBuffer[Count] - 'a' >= 26) textBuffer[Count] = char(textBuffer[Count] - 26);
        }
        int diff2 = _message[i] - 'a';
        if (diff2 < 26 && diff2 >= 0) {
            textBuffer[Count] = _message[i] + _shift;
            if (textBuffer[Count] - 'a' >= 26) textBuffer[Count] = char(textBuffer[Count] - 26);
        }
    }
    textBuffer[len] = '\0';
}

void CaesarMessage::decode(int _shiftKey, char*& _textContainer) {
    int len = 0;
    for (int i = 0; textBuffer[i] != '\0'; i++) {
        len += 1;
    }
    _textContainer = new char[len + 1];
    for (int i = 0; i < len; i++) {
        _textContainer[i] = char(textBuffer[i] - _shiftKey);
        int diff = _textContainer[i] - 'a';
        if (diff < 0) _textContainer[i] = char(_textContainer[i] + 26);
    }
    _textContainer[len] = '\0';
}

int main()
{
    char* x = new char [5];
    x[0] = 'a';
    x[1] = '!';
    x[2] = 'y';
    x[3] = 'z';
    x[4] = '\0';
    CaesarMessage a;
    char* con = NULL;
    a.encode(x, 2);
    a.decode(2, con);
    cout << x << endl;
    a.print();
    cout << endl << con;
}

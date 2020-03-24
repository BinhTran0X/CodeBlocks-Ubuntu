#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#include <vector>


using namespace std;

struct Person {
    char* Name;
    int ID, Salary;
    Person(){};
    Person(const char* _Name, int _ID, int _Salary) {
        Name = new char[strlen(_Name) + 1];
        strcpy(Name, _Name);
        ID = _ID;
        Salary = _Salary;
    }
};
bool Check(Person A, Person B) {
    if (A.Salary != B.Salary) return A.Salary > B.Salary;
    return A.ID > B.ID;
}



void process(const char* fileName) {
    // TODO
fstream input(fileName, ios::in);
if (input.is_open()) {
    vector <Person> A;
    while (!input.eof()) {
        string name = "";
        int SL = 0;
        int ID = 0;
        int Salary = 0;
        string s;
        getline(input, s);
        int m = (int)s.size();
        for (int i = 0; i < m; i++) {
            if (s[i] == ',') {
                SL++;
                continue;
            }
            if (SL != 0) {
                if (s[i] < '0' || s[i] > '9') continue;
            }
            if (SL == 0) name.push_back(s[i]);
            if (SL == 1) ID = ID * 10 + (s[i] - '0');
            if (SL == 2) Salary = Salary * 10 + (s[i] - '0');
        }
        A.push_back(Person(name.c_str(), ID, Salary));
    }
    int n = (int)A.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!Check(A[i], A[j])) {
                Person tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }
    cout << "--------------------" << '\n';
    for (int i = 0; i < n; i++) {
        cout << "Fullname: " << A[i].Name << '\n';
        cout << "ID: " << A[i].ID << '\n';
        cout << "Salary: " << A[i].Salary << '\n';
        if (i < n - 1) {
            cout << "--------------------" << '\n';
            cout << "--------------------" << '\n';
        }
        else {
            cout << "--------------------";
        }
    }
    input.close();
}
}

int main()
{
    process("newfile.txt");
}

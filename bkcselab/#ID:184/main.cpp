#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>

using namespace std;

void process(const char* fileName) {
    fstream fs(fileName, ios::in);
    if (fs.is_open()) {
        vector <string> nameList;
        vector <int> IDList;
        vector <int> salaryList;
        while(!fs.eof()) {
            string name = "";
            int ID = 0;
            int salary = 0;
            string line;
            getline(fs, line);
            int isName = 1, isID = 0, isSalary = 0;
            int len = line.size();
            for (int i  = 0; i < len; i++) {
                if (line[i] == ',') {
                    if (isName == 1) {
                        isName = 0;
                        isID = 1;
                    }
                    else if (isID == 1) {
                        isID = 0;
                        isSalary = 1;
                    }
                }
                else {
                    if (isName) name += line[i];
                    if (isID) ID = (ID*10) + (line[i] - '0');
                    if (isSalary) salary = (salary*10) + (line[i] - '0');
                }
            }
            IDList.push_back(ID);
            salaryList.push_back(salary);
            nameList.push_back(name);
        }

        int len = nameList.size();

        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j <len; j++) {
                if ((salaryList[i] < salaryList[j]) || ((salaryList[i] == salaryList[j]) && (IDList[i] < IDList[j]))) {
                    string name = nameList[i];
                    int ID = IDList[i];
                    int salary = salaryList[i];
                    nameList[i] = nameList[j];
                    IDList[i] = IDList[j];
                    salaryList[i] = salaryList[j];
                    salaryList[j] = salary;
                    IDList[j] = ID;
                    nameList[j] = name;
                }
            }
        }

        for (int i = 0; i < len; i++) {
            cout << "--------------------" << '\n';
            cout << "Fullname: " << nameList[i] << '\n';
            cout << "ID: " << IDList[i] << '\n';
            cout << "Salary: " << salaryList[i] << '\n';
            cout << "--------------------";
            if (i != len - 1) cout << endl;
        }
        fs.close();
    }
}

int main()
{
    process("newfile.txt");
}

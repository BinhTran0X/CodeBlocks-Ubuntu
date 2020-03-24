#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>


using namespace std;

class Student {
	int id;
	char* name;
	float gpa;
public:
	Student(int _id, const char* _name, float _gpa);
	Student(const Student& obj);
	Student& operator=(const Student& obj);
	~Student();
	void print();
	friend void binWrite(const Student& s, const char* fileName);
};

Student::Student(int _id, const char* _name, float _gpa) {
	this->id = _id;
	this->gpa = _gpa;
	this->name = new char[strlen(_name) + 1];
	strcpy(this->name, _name);
}

Student::Student(const Student& obj) {
	this->id = obj.id;
	this->gpa = obj.gpa;
	this->name = new char[strlen(obj.name) + 1];
	strcpy(this->name, obj.name);
}

Student& Student::operator=(const Student& obj) {
	this->id = obj.id;
	this->gpa = obj.gpa;
	this->name = new char[strlen(obj.name) + 1];
	strcpy(this->name, obj.name);
	return *this;
}

Student::~Student() {
	delete[] this->name;
}

void Student::print() {
	cout << "------------------------------" << endl;
	cout << "ID: " << this->id << endl;
	cout << "Name: " << this->name << endl;
	cout << "GPA: " << this->gpa << endl;
	cout << "------------------------------";
}

Student textRead(const char* fileName) {
    fstream fs(fileName, ios::in);
    if(fs.is_open()) {
        string strid;
        getline(fs, strid, ',');
        int id = stoi(strid);
        string strname;
        getline(fs, strname, ',');
        int len = strname.size();
        char *name = new char [len + 1];
        for (int i = 0; i < len; i++) name[i] = strname[i];
        name[len] = '\0';
        string strgpa;
        getline(fs, strgpa, ',');
        float gpa = strtof(strgpa.c_str(), 0);
        Student student(id, name, gpa);
        fs.close();
        return student;
    }
    Student student(0, NULL, 0);
    return student;
}

void binWrite(const Student& s, const char* fileName) {

}

Student binRead(const char* fileName) {
	fstream ifs;
	ifs.open(fileName, ios::in|ios::binary);
	if (ifs.fail()) throw "File not found.";
	int id;
	int nameLen;
	float gpa;
	char* name;
	ifs.read((char*)&id, sizeof(int));
	ifs.read((char*)&nameLen, sizeof(int));
	name = new char[nameLen + 1];
	ifs.read(name, nameLen * sizeof(char));
	name[nameLen] = '\0';
	ifs.read((char*)&gpa, sizeof(float));
	ifs.close();
	Student res(id, name, gpa);
	delete[] name;
	return res;
}

void process(const char* fileName) {
    Student s = textRead(fileName);
    binWrite(s, "student.bin");
    binRead("student.bin").print();
}

int main()
{
    Student a = textRead("newfile.txt");
    a.print();
    //process("newfile.txt");
}

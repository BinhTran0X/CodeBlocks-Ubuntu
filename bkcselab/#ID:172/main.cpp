#include <iostream>

using namespace std;

class Employee {
protected:
	const int id;
	char* name;
	int paidAmount;
	enum JobType { technician, engineer } jobType;
public:
	Employee(int _id, const char* _name, int _paidAmount);
	Employee(Employee& obj);
	~Employee();
	int getID();
	int getPaidAmount();
	void getName(char*& _container);
	JobType getJobType();
	bool pay(int _amountOfPayment);
	virtual int haveToPay() = 0;
};

//TODO
Employee::Employee(int _id, const char* _name, int _paidAmount) : id(_id) {
    this->paidAmount = _paidAmount;
    int len = sizeof(_name)/sizeof(char);
    this->name = new char [len + 1];
    for (int i = 0; i < len; i++) this->name[i] = _name[i];
    this->name[len] = '\0';
}

Employee::~Employee() {
    if (this->name != NULL) delete[] this->name;
    this->name = NULL;
}

int Employee::getID() { return this->id; }

int Employee::getPaidAmount() { return this->paidAmount; }

void Employee::getName(char*& _container) {
    int len = sizeof(this->name)/sizeof(char);
    _container = new char [len];
    for (int i = 0; i < len; i++) _container[i] = this->name[i];
}

Employee::JobType Employee::getJobType() {
    return this->jobType;
}

Employee::Employee(Employee& obj) : id(obj.getID()) {
    this->paidAmount = obj.getPaidAmount();
    obj.getName(this->name);
    this->jobType = obj.getJobType();
}

//

bool Employee::pay(int _amountOfPayment) {
	if (_amountOfPayment <= this->haveToPay()) {
		this->paidAmount += _amountOfPayment;
		return true;
	}
	return false;
}

class Technician: public Employee {
	int payPerHour;
	int workHours;
public:
	Technician(int _id, const char* _name, int _payPerHour, int _workHour, int _paidAmount);
	Technician(Technician& obj);
	int haveToPay();
};

// TODO
Technician::Technician(int _id, const char* _name, int _payPerHour, int _workHour, int _paidAmount) : Employee::Employee(_id, _name, _paidAmount) {
    this->payPerHour = _payPerHour;
    this->workHours = _workHour;
}

Technician::Technician(Technician& obj) : Employee::Employee(obj) {
    this->payPerHour = obj.payPerHour;
	this->workHours = obj.workHours;
	this->paidAmount = obj.paidAmount;
}

int Technician::haveToPay() {
    return payPerHour*workHours;
}
//

class Engineer : public Employee {
	int basicPayPerHour;
	int overTimePayPerHour;
	int basicWorkHour;
	int overtimeWorkHour;
public:
    Engineer(int _id, const char* _name, int _basicPayPerHour, int _basicWorkHour, int _overTimePayPerHour, int _overtimeWorkHour, int _paidAmount);
	Engineer(Engineer& obj);
	int haveToPay();
};

//TODO
Engineer::Engineer(int _id, const char* _name, int _basicPayPerHour, int _basicWorkHour, int _overTimePayPerHour, int _overtimeWorkHour, int _paidAmount) : Employee::Employee(_id, _name, _paidAmount) {
    this->basicPayPerHour = _basicPayPerHour;
    this->basicWorkHour = _basicWorkHour;
    this->overTimePayPerHour = _overTimePayPerHour;
    this->overtimeWorkHour = _overtimeWorkHour;
}

Engineer::Engineer(Engineer& obj) : Employee::Employee(obj) {
    this->basicPayPerHour = obj.basicPayPerHour;
	this->basicWorkHour = obj.basicWorkHour;
	this->overTimePayPerHour = obj.overTimePayPerHour;
	this->overtimeWorkHour = obj.overtimeWorkHour;
	this->paidAmount = obj.paidAmount;
}

int Engineer::haveToPay() {
    return (basicPayPerHour*basicWorkHour + overtimeWorkHour*overTimePayPerHour);
}
//

//TODO
int totalAmountHaveToPay(Employee** employeeList, int numberOfEmployees) {
    int res = 0;
    for (int i = 0; i < numberOfEmployees; i++) {
        res += employeeList[i]->haveToPay();
    }
    return res;
}

//

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

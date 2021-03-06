#include <iostream>

using namespace std;

class Coordinator {
protected:
	class SmartPointer {
		Coordinator* ptr;
		int callStackIndex;
	public:
		SmartPointer();
		SmartPointer(const SmartPointer& _obj);
		SmartPointer(Coordinator* _ptr);
		Coordinator* operator=(Coordinator* _ptr);
		bool operator==(Coordinator* _ptr);
		Coordinator* operator->();
		Coordinator& operator*();
		operator Coordinator*();
		~SmartPointer();
	};
	static SmartPointer instancePtr;
	bool* availableServiceSlot;
	int numberOfServiceSlot;
	Coordinator();
	Coordinator(const Coordinator& obj) = delete;
	Coordinator& operator=(const Coordinator& obj) = delete;
public:
	static Coordinator* getInstance();
	~Coordinator();
	void init(int _numberOfServiceSlot);
	int getSlot();
	void giveBack(int _slotNumber);
};

Coordinator::SmartPointer Coordinator::instancePtr = NULL;

/* This default constructor initializes the member "this->ptr" with NULL value and denotes that
this object is the original one, the destructor has to delete the data at the memory block
that the "this->ptr" pointer point to. */
Coordinator::SmartPointer::SmartPointer() {
    this->ptr = NULL;
}

/* This copy constructor DOES NOT perform a deep copy operation, the "this->ptr" pointer is initialized
to the same value with the "_obj.ptr". Because this is a copy constructor, the created object is a copy of
another object, so the destructor MUST NOT delete the memory that the "this->ptr" pointer point to. */
Coordinator::SmartPointer::SmartPointer(const SmartPointer& _obj) {
    this->ptr = _obj.ptr;
}

/* This constructor initializes the member "this->ptr" to the same value with  "_ptr" and denotes
 that this object is the original one, the destructor has to delete the data at the memory block
that the "this->ptr" pointer point to. */
Coordinator::SmartPointer::SmartPointer(Coordinator* _ptr) {
    this->ptr = _ptr;
}

/* This assign operator first deletes the memory block that the "this->ptr" pointer point to
and then assigns the passed value to "this->ptr" pointer. */
Coordinator* Coordinator::SmartPointer::operator=(Coordinator* _ptr) {
    if (this->ptr != NULL) delete this->ptr;
    this->ptr = _ptr;
    return this->ptr;
}

/* This operator is the same with the copy constructor, it is implicitly called when initializing
an object using the assign operator. So you just simply copy the body of the copy constructor to this
Todo segment */
Coordinator* Coordinator::SmartPointer::operator=(const SmartPointer& _obj) {
    this->ptr = _obj.ptr;
}

/* This operator simply checks if the passed value is equal to the value stored in "this->ptr" pointer. */
bool Coordinator::SmartPointer::operator==(Coordinator* _ptr) {
    return (*_ptr == *(this->ptr));
}

Coordinator* Coordinator::SmartPointer::operator->() {
	return this->ptr;
}

/* Pointer dereference operator */
Coordinator& Coordinator::SmartPointer::operator*() {
	return *this->ptr;
}

/* Typecast operator */
Coordinator::SmartPointer::operator Coordinator*() {
	return this->ptr;
}

/* This destructor checks if it has to delete the memory block that the "this->ptr" pointer point to.
If yes, it deletes that memory block and then set the "this->ptr" pointer" to NULL. */
Coordinator::SmartPointer::~SmartPointer() {
    if(this->ptr != NULL) delete this->ptr;
    this->ptr = NULLL;
}

/* The default constructor initializes the "instancePtr" pointer to NULL
and sets the "recentlyGot" member to -1 (the value indicating that no service slot has been allocated) */
Coordinator::Coordinator() {
	Coordinator::instancePtr = NULL;
	this->recentlyGot = -1;
}

/* This class destructor deletes the dynamic memory block that is pointed to
by the "this->availableServiceSlot" pointer. */
Coordinator::~Coordinator() {
    if (this->availableServiceSlot != NULL)
        delete this->availableServiceSlot;
}

/* "Coordinator::instancePtr" is a smart pointer, it can be used as a usual pointer.
Write the code to check if it is NULL or not. If it is NULL, create a new Coordinator
and then return the pointer pointing to it. If it is not NULL,  just simply return its value.
This helps control that only one object of the "Coordinator" class is created during the runtime */
Coordinator* Coordinator::getInstance() {
    if (Coordinator::instancePtr == NULL)
        Coordinator::instancePtr = new Coordinator();
    return Coordinator::instancePtr;
}

/* Allocate an array of boolean with the size of "_numberOfServiceSlot" and then
assign its address to the "this->availableServiceSlot" pointer.
Please note that all the service slots are available at first. */
void Coordinator::init(int _numberOfServiceSlot) {

}

/* Return the nearest available slot from the recently got */
int Coordinator::getSlot() {
	for (int i = this->recentlyGot + 1; i < this->numberOfServiceSlot; i++) {
		if (this->availableServiceSlot[i]) {
			this->availableServiceSlot[i] = false;
			this->recentlyGot = i;
			return i;
		}
	}
	for (int i = 0; i <= this->recentlyGot; i++) {
		if (this->availableServiceSlot[i]) {
			this->availableServiceSlot[i] = false;
			this->recentlyGot = i;
			return i;
		}
	}
	return -1;
}

/* Mark that the slot indexed _slotNumber is available */
void Coordinator::giveBack(int _slotNumber) {
	if (_slotNumber < 0 || _slotNumber > this->numberOfServiceSlot - 1) return;
	this->availableServiceSlot[_slotNumber] = true;
}

class TimePoint {
public:
    const int timeStamp;
    int* const eventList;
    const int numberOfEvents;
    TimePoint(int _timeStamp, int _numberOfEvents): timeStamp(_timeStamp), eventList(new int[_numberOfEvents]), numberOfEvents(_numberOfEvents) {}
    TimePoint(const TimePoint& _obj): timeStamp(_obj.timeStamp), eventList(new int[_obj.numberOfEvents]), numberOfEvents(_obj.numberOfEvents) {
        for (int i = 0; i < _obj.numberOfEvents; i++) this->eventList[i] = _obj.eventList[i];
    }
    TimePoint& operator=(const TimePoint& _obj) = delete;
    ~TimePoint() { delete[] eventList; }
};

void process(int _numberOfTimeSlot, vector<TimePoint> _timePoint) {
    int numberOfTimePoints = _timePoint.size();
    if (numberOfTimePoints == 0) return;
    Coordinator& coordinator = *(Coordinator::getInstance());
    coordinator.init(_numberOfTimeSlot);
    for (int i = 0; i < numberOfTimePoints; i++) {
        for (int j = 0; j < _timePoint[i].numberOfEvents; j++) {
            if ( _timePoint[i].eventList[j] == -1 ) coordinator.getSlot();
            else coordinator.giveBack(_timePoint[i].eventList[j]);
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

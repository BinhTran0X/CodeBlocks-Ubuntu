#include <iostream>
using namespace std;

class Integer {
    int value;
public:
    Integer(int d) {
        this -> value = d;
    }
    int GetValue() {
        return value;
    }
    bool operator > (Integer a) {
        return this -> value > a.GetValue();
    }
    bool operator < (Integer d) {
        return this -> value < d.GetValue();
    }
    Integer operator + (int d) {
        return this -> value += d;
    }
    bool operator == (int d) {
        return this -> value == d;
    }
    Integer operator = (Integer a) {
        return this -> value = a.GetValue();
    }
    operator int() {
        return value;
    }
};

Integer max(Integer* arr, Integer numberOfElements) {
	if (arr == NULL || numberOfElements == 0) return Integer(-1);
	Integer max = arr[0];
	for (Integer i = 0; i < numberOfElements; i = i + 1) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}

int main() {
	cout<<"GfG!";
	return 0;
}

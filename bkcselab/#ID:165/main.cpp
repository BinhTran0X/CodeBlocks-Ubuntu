#include <iostream>
using namespace std;

class Champion {
	int id;
	int heath;
	int damage;
	static int numberOfAliveChampions;
public:
	Champion(int _id, int _health, int _damage);
	~Champion();
	bool attack(Champion& _victim);
	int getHeath();
	static int getNumberOfAliveChampions();
};
Champion::Champion(int _id, int _health, int _damage) {
    this->id = _id;
    this->heath = _health;
    this->damage = _damage;
    Champion::numberOfAliveChampions += 1;
}
Champion::~Champion() {
    Champion::numberOfAliveChampions -= 1;
}
bool Champion::attack(Champion& _victim) {
    if (this->damage >= _victim.getHeath()) {
        return true;
    }
    else {
        _victim.heath -= this->damage;
        return false;
    }
}
int Champion::getHeath() {
    return this->heath;
}
int Champion::getNumberOfAliveChampions() {
    return Champion::numberOfAliveChampions;
}
int Champion::numberOfAliveChampions = 0;
int fight(Champion*& a, Champion*& b, bool* eventList, int numberOfEvent) {
    for (int i = 0; i < numberOfEvent; i++) {
        if (eventList[i] == true) {
            if ((*a).attack(*b) == true) {
                delete b;
                b = NULL;
                return 1;
            }
        }
        else {
            if ((*b).attack(*a) == true) {
                delete a;
                a = NULL;
                return -1;
            }
        }
    }
    return 0;
}

int main() {
	Champion a = {1, 2, 5};
	Champion b = {2, 2, 3};
	if (a.attack(b)) {
        cout << b.getHeath();
	}
}

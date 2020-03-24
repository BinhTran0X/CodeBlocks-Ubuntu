#include "core.h"

/* Start block: DO NOT CHANGE
    * Please do not change anything in this code block (including whitespace, empty lines)
    * If changes, your submission is marked as zero.
*/

/*
    * Default constructor for Battle class
*/
Battle::Battle(MemoryManager* manager) {
    this->musketeers = NULL;
    this->events = NULL;
    this->manager = manager;
}

/*
    * Default destructor for Battle class
*/
Battle::~Battle() {
    this->finalize();
}

/*
    * Method: read data from input file and assign values to musketeers
    * Input:
    * - filename: the name of input file
    * Output:
    * - Returns true if read file successfully, otherwise returns false
*/
bool Battle::readDataFromFile(string filename) {
    fstream fs(filename, ios::in);

    if (!fs.is_open()) return false;

    this->musketeers = new Musketeer[NUM_OF_MUSKETEERS];

    int* cystalPointer = NULL;
    int cystal = 0;

    for (int i = 0; i < NUM_OF_MUSKETEERS; i++) {
        this->musketeers[i].setMemoryManger(this->manager);
        this->musketeers[i].setTeam(this->musketeers);

        for (int j = 0; j < NUM_OF_CYSTAL; j++) {
            fs >> cystal;

            if (cystal > 0) {
                manager->allocate(cystalPointer);
                *cystalPointer = cystal;
                this->musketeers[i].setCystalPointer(j + 1, cystalPointer);
            }
        }
    }

    fs >> this->firstMusketeer;

    string eventsInText = "";
    fs.ignore();
    getline(fs, eventsInText);

    int numOfSpaces = 0;
    for (int i = 0; i < eventsInText.length(); i++) {
        if (eventsInText.at(i) == ' ') numOfSpaces++;
    }

    int numOfEvents = numOfSpaces + 1;

    this->events = new int[numOfEvents];

    stringstream ss(eventsInText);

    for (int i = 0; i < numOfEvents; i++)
        ss >> this->events[i];

    this->numOfEvents = numOfEvents;

    return true;
}

void Battle::display() {
    for (int i = 0; i < NUM_OF_MUSKETEERS; i++) {
        cout << this->musketeers[i].getHP() << " ";

        for (int j = 0; j < NUM_OF_CYSTAL; j++) {
            if (this->musketeers[i].getCystalPointer(j + 1) != NULL)
                cout << *(this->musketeers[i].getCystalPointer(j + 1));
            else cout << 0;
            if (j < NUM_OF_CYSTAL - 1) cout << " ";
        }

        cout << endl;
    }

    cout << this->manager->getNumOfAllocation();
}
/* End block: DO NOT CHANGE */

/* Start block: TO DO
    * You have to complete only one method of Battle class
*/

/*
    * Method: Emulate this battle
    * Input: None
    * Output: None
*/
void Battle::struggle() {
    // TO-DO
    this->musketeers[0].setHP(999);
    this->musketeers[1].setHP(900);
    this->musketeers[2].setHP(888);
    this->musketeers[3].setHP(777);
    int oldHP[] = {999, 900, 888, 777};
    for (int i = 0; i < this->numOfEvents; i++) {
        for (int j = 0; j < 3; j++) {
            if (j != firstMusketeer) {
                musketeers[j].setHP(min(musketeers[j].getHP() + (4 - j)*50, oldHP[j]));
            }
        }
        int event = abs(events[i]);
        if (event/10 < 10) {
            int index = event/10;
            if (musketeers[firstMusketeer].getCystalPointer(index) == NULL) {
                int* newCrystal = NULL;
                manager->allocate(newCrystal);
                *newCrystal = event%10;
                musketeers[firstMusketeer].setCystalPointer(index, newCrystal);
            }
            else {
                int isUsedByOthers = 0;
                for (int j = 1; j < 4; j++) {
                    if (musketeers[firstMusketeer].getCystalPointer(index) == musketeers[(firstMusketeer + j)%4].getCystalPointer(index)) {
                        isUsedByOthers = 1;
                        break;
                    }
                }
                if (isUsedByOthers == 1) {
                    int* newCrystal;
                    manager->allocate(newCrystal);
                    *newCrystal = event%10;
                    musketeers[firstMusketeer].setCystalPointer(index, newCrystal);
                }
                else {
                    if (event%10 > *(musketeers[firstMusketeer].getCystalPointer(index))) {
                        manager->deallocate(musketeers[firstMusketeer].getCystalPointer(index));
                        int* newCrystal;
                        manager->allocate(newCrystal);
                        *newCrystal = event%10;
                        musketeers[firstMusketeer].setCystalPointer(index, newCrystal);
                    }
                }
            }
        }
        else {
            float fE;
            int e = event%100;
            if (e == 11) fE = 0.65;
            if (e == 12) fE = 0.95;
            if (e == 21) fE = 0.85;
            if (e == 22) fE = 0.9;
            if (e == 31) fE = 0.4;
            if (e == 32) fE = 1.0;
            int crystalType = e/10;
            int Count = 0;
            if (musketeers[firstMusketeer].getCystalPointer(crystalType) != NULL) { // TH co crystal
                (*musketeers[firstMusketeer].getCystalPointer(crystalType))--;
                if (*musketeers[firstMusketeer].getCystalPointer(crystalType) == 0) {
                    musketeers[firstMusketeer].setCystalPointer(crystalType, NULL);
                    manager->deallocate(musketeers[firstMusketeer].getCystalPointer(crystalType));
                }
            }
            else { // TH dung chung crystal
                for (int j = 1; j < 3; j++) {
                    int nextMusketeer = (firstMusketeer + j)%4;
                    if (musketeers[nextMusketeer].getCystalPointer(crystalType) != NULL) {
                        *musketeers[firstMusketeer].getCystalPointer(crystalType) = --*musketeers[firstMusketeer].getCystalPointer(crystalType);
                        if (*musketeers[nextMusketeer].getCystalPointer(crystalType) == 0) {
                            musketeers[nextMusketeer].setCystalPointer(crystalType, NULL);
                            manager->deallocate(musketeers[nextMusketeer].getCystalPointer(crystalType));
                        }
                        else {
                            musketeers[firstMusketeer].setCystalPointer(crystalType, musketeers[nextMusketeer].getCystalPointer(crystalType));
                        }
                    break;
                    }
                    Count++;
                }
            }
            if (Count == 3) { // TH khong co crystal
                if (firstMusketeer == 3) {
                    for (int k = 0; k < 4; k++) {
                        for (int j = 1; j <= 3; j++) {
                            if (*musketeers[(3 + k)%4].getCystalPointer(crystalType + j) >= 2
                                && *(musketeers[(3 + k)%4].getCystalPointer(crystalType + j))*10 < musketeers[3].getHP()) {
                                musketeers[3].setCystalPointer(crystalType, musketeers[(3 + k)%4].getCystalPointer(crystalType + j));
                                (*musketeers[3].getCystalPointer(crystalType))--;
                                (*musketeers[3].getCystalPointer(crystalType))--;
                                musketeers[3].setHP(musketeers[3].getHP() - *(musketeers[(3 + k)%4].getCystalPointer(crystalType + j))*10);
                                if (*(musketeers[3].getCystalPointer(crystalType)) <= 0) {
                                    musketeers[3].setCystalPointer(crystalType, NULL);
                                    manager->deallocate(musketeers[3].getCystalPointer(crystalType));
                                }
                                musketeers[(3 + i)%4].setCystalPointer(crystalType + j, NULL);
                            }
                        }
                    }
                }
                else {
                    int K;
                    for (int k = event - 1; k > 1; k--) {
                        int isPrime = 1;
                        for (int j = 2; j <= event/2; j++) {
                            if (k%j == 0) {
                                isPrime = 0;
                                break;
                            }
                        }
                        if (isPrime == 1) {
                            K = k;
                            break;
                        }
                    }
                    int newHP = musketeers[firstMusketeer].getHP() - (int)floor(event*fE + pow(fE, firstMusketeer + 1)*K)%100;
                    if (newHP <= 0) {
                        musketeers[firstMusketeer].setHP(0);
                        firstMusketeer = (firstMusketeer + 1)%4;
                    }
                    else musketeers[firstMusketeer].setHP(newHP);
                    if (fE == 0.65) {
                        firstMusketeer = (firstMusketeer + 1)%4;
                    }
                }
            }
        }
    }
}

/*
    * Method: finalize a battle, deallocate any dynamic memories.
    * Input: None
    * Output: None
*/
void Battle::finalize() {
    // TO-DO
//    for (int i = 0; i < 4; i++) {
//        musketeers[i].finalize();
//        for (int i = 0; i < numOfEvents; i++) {
//            manager->deallocate(events + i);
//        }
//    }
}
/* End block: TO DO */

/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : processData.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : Implementation of main features in the assignment
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "processData.h"
#include "dbLib.h"
#include "dsaLib.h"
#include <vector>

/* TODO: You can implement methods, functions that support your data structures here.
 * */
using namespace std;

void Initialization() {
    // If you use global variables, please initialize them explicitly in this function.
}

void Finalization() {
    // Release your data before exiting
}

void ProcessRequest(const char* pRequest, void* pData, void* &pOutput, int &N) {
    // TODO: Implement this function for processing a request
    // NOTE: You can add other functions to support this main process.
    //       pData is a pointer to a data structure that manages the dataset
    //       pOutput is a pointer reference. It is set to nullptr and student must allocate data for it in order to save the required output
    //       N is the size of output, must be a non-negative number
    TDataset* Data = static_cast<TDataset*>(pData);
    string inp = "";
    for (int i = 0; i < (int)strlen(pRequest); i++) inp += pRequest[i];
    stringstream ss(inp);
    string one = "", two = "", three = "", four = "";
    getline(ss, one, ' ');
    N = 1;
    if (one == "CL") {
        getline(ss, two);
        if (two == "") {
            L1List<TLine>* Line = Data->lineL1List;
            L1Item<TLine>* tmp;
            tmp = Line->_pHead;
            int* CL = new int();

            while (tmp != NULL) {
                tmp = tmp->pNext;
                (*CL)++;
            }
            pOutput = CL;
            cout << *CL << '\n';
            return;
        }
        L1List<TCity>* City = Data->cityL1List;
        L1Item<TCity>* tmp = City->_pHead;
        int id = -1;
        while (tmp != NULL && (tmp->data).name != two) {
            tmp = tmp->pNext;
        }
        if (tmp == NULL) {
            int *CL = new int(-1);
            pOutput = CL;
            return;
        }
        id = (tmp->data).id;
        //cout << id << '\n';
        L1List<TLine>* Line = Data->lineL1List;
        L1Item<TLine>* temp = Line->_pHead;
        int *CL = new int(0);
        while(temp != NULL) {
            //cout << (temp->data).city_id << '\n';
            if ((temp->data).cityId == id) (*CL)++;
            temp = temp->pNext;
        }
        pOutput = CL;
    }
    if (one == "LSC") {
        getline(ss, two);
        vector<int> arr;
        L1List<TCity>* City = Data->cityL1List;
        L1Item<TCity>* tmp = City->_pHead;
        int id = -1;
        while (tmp != NULL && (tmp->data).name != two) {
            tmp = tmp->pNext;
        }
        id = (tmp->data).id;
        L1List<TStation>* Station = Data->stationL1List;
        L1Item<TStation>* temp = Station->_pHead;
        while (temp != NULL) {
            if ((temp->data).cityId == id) arr.push_back((temp->data).id);
            temp = temp->pNext;
        }
        int Size = arr.size();
        int* res = new int[Size];
        for (int i = 0; i < Size; i++) res[i] = arr[i];
        pOutput = res;
        N = Size;
    }
    if (one == "LLC") {
        getline(ss, two);
        vector<int> arr;
        L1List<TCity>* City = Data->cityL1List;
        L1Item<TCity>* tmp = City->_pHead;
        int id = -1;
        while (tmp != NULL && (tmp->data).name != two) {
            tmp = tmp->pNext;
        }
        id = (tmp->data).id;
        L1List<TLine>* Line = Data->lineL1List;
        L1Item<TLine>* temp = Line->_pHead;
        while (temp != NULL) {
            if ((temp->data).cityId == id) arr.push_back((temp->data).id);
            temp = temp->pNext;
        }
        int Size = arr.size();
        int* res = new int[Size];
        for (int i = 0; i < Size; i++) res[i] = arr[i];
        pOutput = res;
        N = Size;
    }
    if (one == "LSL") {
        getline(ss, two);
        int id = toInt(two);
        vector<int> arr;
        L1List<TStationLine>* StationLine = Data->stationLineL1List;
        L1Item<TStationLine>* temp = StationLine->_pHead;
        while (temp != NULL) {
            if ((temp->data).lineId == id) arr.push_back((temp->data).id);
            temp = temp->pNext;
        }
        int Size = arr.size();
        int* res = new int[Size];
        for (int i = 0; i < Size; i++) res[i] = arr[i];
        pOutput = res;
        N = Size;
    }
    if (one == "FC") {
        getline(ss, two);
        L1List<TCity>* City = Data->cityL1List;
        L1Item<TCity>* tmp = City->_pHead;
        int id = -1;
        while (tmp != NULL && (tmp->data).name != two) {
            tmp = tmp->pNext;
        }
        if (tmp != NULL) id = (tmp->data).id;
        int *FC = new int(id);
        pOutput = FC;
    }
    if (one == "FS") {
        getline(ss, two);
        int id = -1;
        L1List<TStation>* Station = Data->stationL1List;
        L1Item<TStation>* tmp = Station->_pHead;
        while (tmp != NULL && (tmp->data).name != two) {
            tmp = tmp->pNext;
        }
        if (tmp != NULL) id = (tmp->data).id;
        int *FS = new int(id);
        pOutput = FS;
    }
    if (one == "SLP") {
        getline(ss, two, ' ');
        getline(ss, three);
        int stationId = toInt(two);
        int trackId = toInt(three);
        L1List<TStation>* Station = Data->stationL1List;
        L1Item<TStation>* tmpStation = Station->_pHead;
        while (tmpStation != NULL && (tmpStation->data).id != stationId) {
            tmpStation = tmpStation->pNext;
        }
        L1List<TTrack>* Track = Data->trackL1List;
        L1Item<TTrack>* tmpTrack = Track->_pHead;
        while (tmpTrack != NULL && (tmpTrack->data).id != trackId) {
            tmpTrack = tmpTrack->pNext;
        }
        if (tmpTrack == NULL || tmpStation == NULL) {
            int* pos = new int(-1);
            pOutput = pos;
            return;
        }
        stringstream lineString((tmpTrack->data).geometry);
        int* pos = new int(-1);
        string word;
        int x = 0;
        while (getline(lineString, word, ',')) {
            x++;
            if (word == (tmpStation->data).geometry) {
                *pos = x;
                break;
            }
        }
        pOutput = pos;
    }

}


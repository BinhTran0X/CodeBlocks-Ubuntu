/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dbLib.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "dbLib.h"

/* TODO: You can implement methods, functions that support your data structures here.
 * */

int toInt(string s) {
    int value = 0;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        value *= 10;
        value += (s[i] - '0');
    }
    return value;
 }

void LoadData(void* &pData) {
    TDataset *data = new TDataset();
    //Read "cities.csv" file
    data->cityL1List = new L1List<TCity>;
    fstream fs1("cities.csv", fstream::in);
    if (fs1.is_open()) {
        string line;
        getline(fs1, line);
        while (!fs1.eof()) {
            getline(fs1, line);
            stringstream ss(line);
            string word;
            TCity a;
            getline(ss, word, ',');
            a.id = toInt(word);
            getline(ss, word, ',');
            a.name = word;
            getline(ss, word, '(');
            getline(ss, word, ')');
            a.coord = word;
            getline(ss, word, ',');
            getline(ss, word, ',');
            a.startYear = toInt(word);
            getline(ss, word, ',');
            a.urlName = word;
            getline(ss, word, ',');
            a.country = word;
            getline(ss, word);
            a.countryState = word;
            data->cityL1List->push_back(a);
        }
        fs1.close();
    }
    //Read "lines.csv" file
    data->lineL1List = new L1List<TLine>;
    fstream fs2("lines.csv", fstream::in);
    if (fs2.is_open()) {
        string line;
        getline(fs2, line);
        while (!fs2.eof()) {
            getline(fs2, line);
            stringstream ss(line);
            string word;
            TLine a;
            getline(ss, word, ',');
            a.id = toInt(word);
            getline(ss, word, ',');
            a.cityId = toInt(word);
            getline(ss, word, ',');
            a.name = word;
            getline(ss, word, ',');
            a.urlName = word;
            getline(ss, word, ',');
            a.color = word;
            getline(ss, word, ',');
            a.systemId = toInt(word);
            getline(ss, word);
            a.transportModeId = toInt(word);
            data->lineL1List->push_back(a);
        }
        fs2.close();
    }
    //Read "tracks.csv" file
    data->trackL1List = new L1List<TTrack>;
    fstream fs3("tracks.csv", fstream::in);
    if (fs3.is_open()) {
        string line;
        getline(fs3, line);
        while (!fs3.eof()) {
            getline(fs3, line);
            stringstream ss(line);
            string word;
            TTrack a;
            getline(ss, word, ',');
            a.id = toInt(word);
            getline(ss, word, '(');
            getline(ss, word, ')');
            word;
            a.geometry = word;
            //cout << word << '\n';
            getline(ss, word, ',');
            getline(ss, word, ',');
            a.buildstart = toInt(word);
            getline(ss, word, ',');
            a.opening = toInt(word);
            getline(ss, word, ',');
            a.closure = toInt(word);
            getline(ss, word, ',');
            a.length = toInt(word);
            getline(ss, word);
            a.cityId = toInt(word);
            data->trackL1List->push_back(a);
        }
        fs3.close();
    }
    //Read "stations.csv" file
    data->stationL1List = new L1List<TStation>;
    fstream fs4("stations.csv", fstream::in);
    if (fs4.is_open()) {
        string line;
        getline(fs4, line);
        while (!fs4.eof()) {
            getline(fs4, line);
            stringstream ss(line);
            string word;
            TStation a;
            getline(ss, word, ',');
            a.id = toInt(word);
            getline(ss, word, ',');
            a.name = word;
            getline(ss, word, '(');
            getline(ss, word, ')');
            a.geometry = word;
            getline(ss, word, ',');
            getline(ss, word, ',');
            a.buildstart = toInt(word);
            getline(ss, word, ',');
            a.opening = toInt(word);
            getline(ss, word, ',');
            a.closure = toInt(word);
            getline(ss, word);
            a.cityId = toInt(word);
            data->stationL1List->push_back(a);
        }
        fs4.close();
    }
    //Read "systems.csv" file
    data->systemL1List = new L1List<TSystem>;
    fstream fs5("systems.csv", fstream::in);
    if (fs5.is_open()) {
        string line;
        getline(fs5, line);
        while (!fs5.eof()) {
            getline(fs5, line);
            stringstream ss(line);
            string word;
            TSystem a;
            getline(ss, word, ',');
            a.id = toInt(word);
            getline(ss, word, ',');
            a.cityId = toInt(word);
            getline(ss, word);
            a.name = word;
            data->systemL1List->push_back(a);
        }
        fs5.close();
    }
    //Read "station_lines.csv" file
    data->stationLineL1List = new L1List<TStationLine>;
    fstream fs6("station_lines.csv", fstream::in);
    if (fs6.is_open()) {
        string line;
        getline(fs6, line);
        while (!fs6.eof()) {
            getline(fs6, line);
            stringstream ss(line);
            string word;
            TStationLine a;
            getline(ss, word, ',');
            a.id = toInt(word);
            getline(ss, word, ',');
            a.stationId = toInt(word);
            getline(ss, word, ',');
            a.lineId = toInt(word);
            getline(ss, word, ',');
            a.createdAt = word;
            getline(ss, word);
            a.updatedAt = word;
            data->stationLineL1List->push_back(a);
        }
        fs6.close();
    }
    //Read "track_lines.csv" file
    data->trackLineL1List = new L1List<TTrackLine>;
    fstream fs7("track_lines.csv", fstream::in);
    if (fs7.is_open()) {
        string line;
        getline(fs7, line);
        while (!fs7.eof()) {
            getline(fs7, line);
            stringstream ss(line);
            string word;
            TTrackLine a;
            getline(ss, word, ',');
            a.id = toInt(word);
            getline(ss, word, ',');
            a.sectionId = toInt(word);
            getline(ss, word, ',');
            a.lineId = toInt(word);
            getline(ss, word, ',');
            a.createdAt = word;
            getline(ss, word, ',');
            a.updatedAt = word;
            getline(ss, word);
            a.cityId = toInt(word);
            data->trackLineL1List->push_back(a);
        }
        fs7.close();
    }
    pData = (void *) data;
}

void ReleaseData(void* &data) {
    TDataset *temp = (TDataset *) data;
//    temp->cityL1List->~L1List();
//    temp->trackL1List->~L1List();
//    temp->stationL1List->~L1List();
//    temp->systemL1List->~L1List();
//    temp->stationLineL1List->~L1List();
//    temp->trackLineL1List->~L1List();
//    delete temp->cityL1List;
//    temp->cityL1List = NULL;
//    delete temp->trackL1List;
//    temp->trackL1List = NULL;
//    delete temp->stationL1List;
//    temp->stationL1List = NULL;
//    delete temp->systemL1List;
//    temp->systemL1List = NULL;
//    delete temp->trackLineL1List;
//    temp->trackLineL1List = NULL;
//    delete temp->stationLineL1List;
//    temp->stationL1List = NULL;
    delete temp;
    temp = NULL;
    //delete data;
    data = NULL;
}

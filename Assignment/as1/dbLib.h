/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dbLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_DBLIB_H
#define DSA191_A1_DBLIB_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <math.h>
#include <vector>
#include "dsaLib.h"

/* TODO: Please design your data structure carefully so that you can work with the given dataset
 *       in this assignment. The below structures are just some suggestions.
 */
 struct Point {
    string x, y;
    Point() {
        x = " ";
        y = " ";
    }
    Point(string _x, string _y) {
        x = _x;
        y = _y;
    }
 };

struct TCity {
    // The structure to store city information
    int id;
    string name;
    string coord;
    int startYear;
    string urlName;
    string country;
    string countryState;
    TCity() {
        id = -1;
        name = "";
        coord = "";
        startYear = -1;
        urlName = "";
        country = "";
        countryState = "";
    };
    TCity(int _id, string _name, string _coord, int _startYear, string _urlName, string _country, string _countryState) {
        id = _id;
        name = _name;
        coord = _coord;
        startYear = _startYear;
        urlName = _urlName;
        country = _country;
        countryState = _countryState;
    };
};

struct TLine {
    // The structure to store line information
    int id, cityId;
    string name, urlName, color;
    int systemId, transportModeId;
    TLine() {
        id = -1;
        cityId = -1;
        name  = "";
        urlName = "";
        color  = "";
        systemId = -1;
        transportModeId = -1;

    };
    TLine(int _id, int _cityId, string _name, string _urlName, string _color, int _systemId, int _transportModeId) {
        id= _id;
        cityId = _cityId;
        name = _name;
        urlName = _urlName;
        color = _color;
        systemId = _systemId;
        transportModeId = _transportModeId;
    };
};

struct TTrack {
    // The structure to store track information
    int id;
    string geometry;
    int buildstart, opening, closure, length, cityId;
    TTrack() {
        id = -1;
        geometry = "";
        buildstart = -1;
        opening = -1;
        closure = -1;
        length = -1;
        cityId = -1;
    };
    TTrack(int _id, string _geometry, int _buildstart, int _opening, int _closure, int _length, int _cityId) {
        id = _id;
        geometry = _geometry;
        buildstart = _buildstart;
        opening = _opening;
        closure = _closure;
        length = _length;
        cityId = _cityId;
    };
};

struct TStation {
    int id;
    string name;
    string geometry;
    int buildstart, opening, closure, cityId;
    TStation() {
        id = -1;
        name = "";
        geometry = "";
        buildstart = -1;
        opening = -1;
        closure = -1;
        cityId = -1;
    };
    TStation(int _id, string _name, string _geometry, int _buildstart, int _opening, int _closure, int _cityId) {
        id = _id;
        name = _name;
        geometry = _geometry;
        buildstart = _buildstart;
        opening = _opening;
        closure = _closure;
        cityId = _cityId;
    };
};

struct TSystem {
    int id, cityId;
    string name;
    TSystem() {
        id = -1;
        cityId = -1;
        name = "";
    };
    TSystem(int _id, int _cityId, string _name) {
        id = _id;
        cityId = _cityId;
        name = _name;
    };
};

struct TStationLine {
    int id, stationId, lineId;
    string createdAt, updatedAt;
    TStationLine() {
        id = -1;
        stationId = -1;
        lineId = -1;
        createdAt = "";
        updatedAt = "";
    };
    TStationLine(int _id, int _stationId, int _lineId, string _createdAt, string _updatedAt) {
        id = _id;
        stationId = _stationId;
        lineId = _lineId;
        createdAt = _createdAt;
        updatedAt = _updatedAt;
    };
};

struct TTrackLine {
    int id, sectionId, lineId;
    string createdAt, updatedAt;
    int cityId;
    TTrackLine() {
        id = -1;
        sectionId = -1;
        lineId = -1;
        createdAt = "";
        updatedAt = "";
        cityId = -1;
    };
    TTrackLine(int _id, int _sectionId, int _lineId, string _createdAt, string _updatedAt, int _cityId) {
        id = _id;
        sectionId = _sectionId;
        lineId = _lineId;
        createdAt = _createdAt;
        updatedAt = _updatedAt;
        cityId = _cityId;
    };
};

class TDataset {
    // This class can be a container that help you manage your tables
public:
    L1List<TCity> *cityL1List;
    L1List<TLine> *lineL1List;
    L1List<TTrack> *trackL1List;
    L1List<TStation> *stationL1List;
    L1List<TStationLine> *stationLineL1List;
    L1List<TSystem> *systemL1List;
    L1List<TTrackLine> *trackLineL1List;
    TDataset () {
        cityL1List = NULL;
        lineL1List = NULL;
        trackL1List = NULL;
        stationLineL1List = NULL;
        stationL1List = NULL;
        systemL1List = NULL;
        trackLineL1List = NULL;
    }
    ~TDataset() {
        if (cityL1List != NULL) delete cityL1List;
        cityL1List = NULL;
        if (trackL1List != NULL) delete trackL1List;
        trackL1List = NULL;
        if (stationL1List != NULL) delete stationL1List;
        stationL1List = NULL;
        if (systemL1List != NULL) delete systemL1List;
        systemL1List = NULL;
        if (trackL1List != NULL) delete trackLineL1List;
        trackLineL1List = NULL;
        if (stationL1List != NULL) delete stationLineL1List;
        stationL1List = NULL;
    }
};

// Please add more or modify as needed

void LoadData(void* &);
void ReleaseData(void* &);
int toInt(string s);

#endif //DSA191_A1_DBLIB_H

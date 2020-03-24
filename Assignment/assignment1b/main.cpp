/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 1b
    * Programming Fundamentals CO1011 - Spring 2019
    * Author: Tran Ngoc Bao Duy
    * Date: 05.4.2019
    * Only write/edit in the body of combat function to complete this assignment
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

void combat(int hp1, int hp2, int d) {
    // TODO: You have to complete this function followed by requirements

    /*bool isAmicablePair (int a, int b) { // check amicable pair
        int sumA = 0;
        int sumB = 0;
        for (int i = 1; i < a; i++) {
            if (a%i == 0) sumA += i;
        }
        for (int i = 1; i < b; i++) {
            if (b%i == 0) sumB += i;
        }
        if (sumB == a && sumA == b) return true;
        else return false;
    }*/

    float p1, p2;
    int h1, h2;
    p1 = float(hp1)*(1000 - d)/1000;
    p2 = float(hp2)*d/1000;
    h1 = (hp1 + hp2)%100;
    h2 = (h1 * hp2)%100;
    float pR = 0;

    //pR = (h1*p1 - h2*p2)/(h1*p1 + h2*p2);

    if (h1*p1 + h2*p2 == 0) { // denominator == 0
        if (h1 == 0 && h2 == 0) pR = 0;
        else {
            if (p1 < p2) pR = 0;
            else pR = 1;
        }
    }
    else { // denominator != 0
        if (d != 987) {
            if (hp2 != 888) {
                if (hp1 == 777) {
                    if (p1 < p2 || h1 < h2) {
                        d = 1;
                        p1 = float(hp1)*(1000 - d)/1000;
                        p2 = float(hp2)*d/1000;
                        h1 = (hp1 + hp2)%100;
                        h2 = (h1 * hp2)%100;
                    }
                }
                else if (hp1 == 888) h1 *= 10;
            }

            pR = (h1*p1 - h2*p2)/(h1*p1 + h2*p2);
            if (hp1 == 900 && hp2 != 888) {
                if (pR < 0.5) pR = 0.5;
            }
            if (hp2 == 888) {
                if (hp1 != 777 && hp1 != 888 && hp1 != 900 && hp1 != 999) pR = 0.01;
                else if (hp1 == 999) pR = 1;
            }
            // check amicable pair
            int sum1 = 0;
            int sum2 = 0;
            for (int i = 1; i < hp1; i++) {
                if (hp1%i == 0) sum1 += i;
            }
            for (int i = 1; i < hp2; i++) {
                if (hp2%i == 0) sum2 += i;
            }
            if (sum2 == hp1 && sum1 == hp2) pR = 0.5;
        }
        else { //d == 987
            pR = (h1*p1 - h2*p2)/(h1*p1 + h2*p2);
            if (h1 + h2 != 99) {
                if (hp1 != 999) pR = 0;
            }
        }
    }
    if (pR < 0) pR = 0;
    else if (pR > 1) pR = 1;
    printf("%.2f", pR);
}

int readFile(string filename, int& hp1, int& hp2, int& d) {
    ifstream myfile(filename);
    if (myfile.is_open()) {
        myfile >> hp1 >> hp2 >> d;

        return 1;
    }
    else return 0;
}

int main(int argc, char** argv) {
    if (argc == 2) {
        int hp1 = 0;
        int hp2 = 0;
        int d = 0;

        int readInput = readFile(argv[1], hp1, hp2, d);

        if (readInput) combat(hp1, hp2, d);
        else cout << "Cannot read input file";
    }
    else cout << "Incorrect arguments format";
}

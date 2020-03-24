#include <iostream>

using namespace std;

int main()
{
    int numberOfStudents, numberOfQuestions;
    cin >> numberOfQuestions;
    cin >> numberOfStudents;
    char* key = new char[numberOfQuestions];
    for(int i = 0; i < numberOfQuestions; i++) {
        cin >> key[i];
    }

    char** answers = new char*[numberOfStudents];
    for (int i = 0; i < numberOfStudents; i++) {
        answers[i] = new char[numberOfQuestions];
        for (int j = 0; j < numberOfQuestions; j++) {
            cin >> answers[i][j];
        }
    }

    for (int i = 0; i < numberOfStudents; i++) {
        int result = 0;
        for (int j = 0; j < numberOfQuestions; j++) {
            if (answers[i][j] == key[j]) result += 1;
        }
        cout << result;
        if (i != numberOfStudents - 1) cout << " ";
    }
}



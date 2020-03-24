#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

void advanture(int R, int N, int ID, int M, int* E, int nEvents) {
	int result = 0;
	int HP;
	int meetGWS = 0;
    int meetJ = 0;
    int meetL = 0;
    int titanHelp = 0;
    float alpha = 1.0;
    int remain = N;


	if (ID == 1) HP = 999; // d'Artagnan
    if (ID == 2) HP = 900; // Athos
    if (ID == 3) HP = 888; //Porthos
    if (ID == 4) HP = 777; //Aramis

    int remainHP = HP;

    for (int i = 1; i <= nEvents && remain != 0; i++) {
        // event 0: nhat kim cuong
        if (E[i - 1] == 0) {
            remain -= 1;
        }

        // event 1: den nha tro hoi mau
        if (E[i - 1] == 1) {
            if (ID == 3 && R >= 3) { // truong hop rieng cua Porthos
                int P;
                if (R == 3) {
                    P = 2;
                    while (M >= 3 && remainHP < HP) {
                        M -= P;
                        remainHP += 1;
                    }
                }
                else {
                    for (int i = R - 1; i >= 3; i++) { //tim so nguyen to lon nhat nho hon R
                        int isPrime = 1;
                        for (int j = 2; j < i; j++) {
                            if (i%j == 0) {
                                isPrime = 0;
                                break;
                            }
                        }
                        if (isPrime == 1) {
                            P = i;
                            break;
                        }
                    }
                    while (M >= P && remainHP < HP) {
                        M -= P;
                        remainHP += 1;
                    }
                }
            }
            if (ID != 3) {
                if (remainHP + M <= HP) {
                    remainHP += M;
                    M = 0;
                }
                else {
                    M = M - (HP - remainHP);
                    remainHP = HP;
                }
            }
        }

        // event 1XX: ve binh mai phuc
        if (E[i - 1] >= 100 && E[i - 1] < 200) {
            int h1 = i%(100 + R);
            int h2 = E[i - 1]%(100 + R);
            if (ID == 2) { // truong hop rieng cua Athos
                if (h2 > M) {
                    int isPrime = 1;
                    for (int j = 2; j < h2; j++) {
                        if (i%j == 0) {
                            isPrime = 0;
                            break;
                        }
                    }
                    if (isPrime == 1) { // ve binh thang Athos
                        remainHP -= round(alpha*E[i - 1]);
                        if (remainHP <= 0) {
                            result = -1;
                            break;
                        }
                    }
                }
            }
            else if (ID != 3 || titanHelp == 0) { // cac truong hop khac truong hop Porthos co titan giup
                if (h1 >= h2) M = min(M + E[i - 1], 999);
                else {
                    remainHP -= round(alpha*E[i - 1]);
                    if (remainHP <= 0) {
                        if (ID == 4) {
                            remainHP += round(alpha*E[i - 1]);
                        }
                        else {
                            result = -1;
                            break;
                        }
                    }
                }
            }
        }

        // event 2XX: gap Nina de Rings
        if (E[i - 1] >= 200 && E[i - 1] < 300) {
            int h1 = i%(100 + R);
            int h2 = E[i - 1]%(100 + R);
            if (h1 >= h2) M = min(2*M, 999);
            else M /= 2;
        }

        // event 3XX: gap GWS
        if (E[i - 1] >= 300 && E[i - 1] < 400) {
            if (meetGWS == 0) {
                int h1 = i%(100 + R);
                int h2 = E[i - 1]%(100 + R);
                if (h1 >= h2) {
                    alpha = float(R + 10)/pow(2, R + 5);
                    meetGWS = 1;
                }
                else remain = N;
            }
        }

        // event 5XX: gap titan
        if (E[i - 1] >= 500 && E[i - 1] < 600) {
            if (ID == 3) {
                titanHelp = 1;
            }
            else {
                int h1 = i%(100 + R);
                int h2 = E[i - 1]%(100 + R);
                if (h1 < h2) {
                    remainHP -= round(alpha*E[i - 1]);
                    if (remainHP <= 0) {
                        if (ID == 4) {
                            remainHP += round(alpha*E[i - 1]);
                        }
                        else {
                            result = -1;
                            break;
                        }
                    }
                }
            }
            result = HP + M;
        }

        // event 666: gap Milady de Winter
        if (E[i - 1] == 666) {
            if (ID == 1) {
                result = -1;
                break;
            }
            if (ID == 2) M = 999;
            if (ID == 3 || ID == 4) {
                if (remainHP > 2) {
                    int F1 = 1, F2 = 1;
                    while (F2 < remainHP) {
                        F2 += F1;
                        F1 = F2 - F1;
                    }
                    remainHP = F1;
                }
            }
        }

        // event 777: gap Jeanne de La Motte
        if (E[i - 1] == 777) {
            if (meetJ == 0) {
                if (ID == 4 && remain < N) { // truong hop rieng cua Aramis
                    meetJ = 1;
                    int Q;
                    for (int i = R%100; i >= 2; i++) {
                        int isPrime = 1;
                        for (int j = 2; j*j <= i; j++) {
                            if (i%j == 0) {
                                isPrime = 0;
                                break;
                            }
                        }
                        if (isPrime == 1 && (R%100)%i == 0) {
                            Q = i;
                            break;
                        }
                    }
                    if (M >= Q) {
                        int h1 = i%(100 + R);
                        int h2 = E[i - 1]%(100 + R);
                            if (h1 < h2) {
                            remain += 1;
                            M -= Q;
                        }
                    }
                }
                else {
                    if (remain != N) {
                        remain += 1;
                        meetJ = 1;
                    }
                }
            }
        }

        // event 999: gap Paladin Lancelot
        if (E[i - 1] == 999 && meetL == 0) {
            meetL = 1;
            int F1 = 1, F2 = 1;
            int isFib = 0;
            while (F2 <= 1000) {
                if (F2 < i) {
                    F2 = F2 + F1;
                    F1 = F2 - F1;
                }
                if (F2 == i) {
                    isFib = 1;
                    break;
                }
                if (F2 > i) break;
            }
            if (isFib == 1) {
                int h1 = i%(100 + R);
                int h2 = E[i - 1]%(100 + R);
                if (h1 < h2) {
                    result = -1;
                    break;
                }
                else {
                    remainHP = HP;
                    M = 999;
                }
            }
            else {
                result = -1;
                break;
            }
        }
    }
	if (result == -1) cout << result;
	else {
        if (remain == 0) {
            result = remainHP + M;
            cout << result;
        }
        else cout << 0;
	}
}


int main() {
	int R, N, M, ID;
	cin >> R >> N;
	cin >> ID;
	cin >> M;
	int E[] = {0, 99};
	int nEvents = sizeof(E)/sizeof(0);
	advanture(R, N, ID, M, E, nEvents);
}





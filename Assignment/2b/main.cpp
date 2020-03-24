#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

bool isPrime(int x) {
    if (x == 2) return 1;
    else {
        for (int i = 2; i < x; i++) {
            if (x%i == 0) return 0;
        }
        return 1;
    }
}

bool isFibonacci(int x) {
    int F1 = 5*x*x - 4;
    int F2 = 5*x*x + 4;
    int sr1 = sqrt(F1);
    int sr2 = sqrt(F2);
    if (sr1*sr1 == F1 || sr2*sr2 == F2) return 1;
    else return 0;
}

void advanture(int R, int N, int ID, int M, int* E, int nEvents) {
    int result = 0;
	int HP;
	int meetGWS = 0;
    int meetJ = 0;
    int meetL = 0;
    int titanHelp = 0;
    float alpha = 1.0;
    int remain = N;
    int remainM = M;

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
            if (ID == 3) { // TH cua Porthos
                int P;
                if (R == 3) {
                    P = 2;
                    while (remainM >= 3 && remainHP < HP) {
                        remainM -= P;
                        remainHP += 1;
                    }
                }
                else if (R > 3) {
                    for (int i = R - 1; i > 2; i--) { // tim so nguyen to nho nhat be hon R
                        if (isPrime(i)) {
                            P = i;
                            break;
                        }
                    }
                    while (remainM >= P && remainHP < HP) {
                        remainM -= P;
                        remainHP += 1;
                    }
                }
            }
            else {
                if ((remainHP + remainM) <= HP) {
                    remainHP += remainM;
                    remainM = 0;
                }
                else {
                    remainM = remainM - (HP - remainHP);
                    remainHP = HP;
                }
            }
        }

        // event 1XX: ve binh mai phuc
        if (E[i - 1] >= 100 && E[i - 1] < 200) {
            int h1 = i%(100 + R);
            int h2 = E[i - 1]%(100 + R);
            if (ID == 2) { // truong hop rieng cua Athos
                if (isPrime(h2) && h2 > remainM)  { // ve binh thang Athos, remainM hay M ?? dieu kien h2 > h1 ??
                    remainHP -= round(alpha*E[i - 1]);
                    if (remainHP <= 0) {
                        result = -1;
                        break;
                    }
                }
            }
            else if (ID != 3 || titanHelp == 0) { // cac TH khac TH Porthos duoc Titan giup
                if (h1 >= h2) remainM = min(remainM + E[i - 1], 999);
                else {
                    remainHP -= round(alpha*E[i - 1]);
                    if (remainHP <= 0) {
                        if (ID == 4) { // Aramis khi mau bi giam xuong <= 0
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
            if (h1 >= h2) remainM = min(2*remainM, 999);
            else remainM /= 2;
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
                        if (ID == 4) { // Aramis khi mau bi giam xuong <= 0
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

        // event 666: gap Milady de Winter
        if (E[i - 1] == 666) {
            if (ID == 1) {
                result = -1;
                break;
            }
            if (ID == 2) remainM = 999;
            if (ID == 3 || ID == 4) {
                if (remainHP > 2) {
                    for (int i = remainHP - 1; i >= 2; i--) {
                        if (isFibonacci(i)) {
                            remainHP = i;
                            break;
                        }
                    }
                }
            }
        }

        // event 777: gap Jeanne de La Motte
        if (E[i - 1] == 777) {
            if (meetJ == 0) { // co the sua lai cho nay
                meetJ = 1;
                if (remain < N) {
                    //meetJ = 1;
                    remain += 1;
                    if (ID == 4) { // TH cua Aramis
                        int Q;
                        if (R >= 3) {
                            for (int i = R%100 - 1; i >= 2; i--) {
                                if ((R%100)%i == 0 && isPrime(i)) {
                                    Q = i;
                                    break;
                                }
                            }
                        }
                        else Q = 1;
                        if (remainM >= Q) {
                            int h1 = i%(100 + R);
                            int h2 = E[i - 1]%(100 + R);
                            if (h1 >= h2) remain -= 1;
                            else remainM -= Q;
                        }
                    }
                }
            }
        }

        // event 999: gap Paladin Lancelot
        if (E[i - 1] == 999 && meetL == 0) {
            meetL = 1;
            if (isFibonacci(i)) {
                int h1 = i%(100 + R);
                int h2 = E[i - 1]%(100 + R);
                if (h1 < h2) {
                    result = -1;
                    break;
                }
                else {
                    remainHP = HP;
                    remainM = 999;
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
            result = remainHP + remainM;
            cout << result;
        }
        else cout << 0;
	}
}

int main()
{
    int R, N, M, ID;
	cin >> R >> N;
	cin >> ID;
	cin >> M;
	int E[] = {108, 666, 0, 234, 345, 107};
	int nEvents = sizeof(E)/sizeof(0);
	advanture(R, N, ID, M, E, nEvents);
}

#include <bits/stdc++.h>
#define TASK "task"

using namespace std;

void rwFile() {
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
}

void solveA() {
    int arr[] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    int k; cin >> k;
    cout << arr[k - 1];
}

void solveB() {
    long long h, w; cin >> h >> w;
    if (h == 1 || w == 1) {
        cout << 1;
        return;
    }
    long long res = 0;
    if (h % 2 == 0 || w % 2 == 0) res = 1LL * h * w / 2;
    else res = (1LL * h * w + 1) / 2;
    cout << res;
}

string res = "";

void recSolveD(int n, int state) {
    if (n == 0) {
        cout << res << '\n';
        return;
    }
    for (int i = 0; i <= state; i++) {
        res += char('a' + i);
        if (i == state) recSolveD(n - 1, state + 1);
        else recSolveD(n - 1, state);
        res.pop_back();
    }
}

void solveD() {
    int n; cin >> n;
    recSolveD(n, 0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    solveD();
}

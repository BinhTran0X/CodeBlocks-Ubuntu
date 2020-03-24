#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

bool div3(string s) {
    int n = s.size();
    int tot = 0;
    for (int i = 0; i < n; i++) {
        tot += (s[i] - '0');
    }
    return (tot % 3 == 0);
}

int count0(string s) {
    int n = s.size();
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') c++;
    }
    return c;
}

void solveA() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (count0(s) < 1 || !div3(s)) {
            cout << "cyan\n";
        }
        else {
            if (count0(s) >= 2) cout << "red\n";
            else {
                int able = 0;

                for (int i = 0; i < (int)s.size(); i++) {
                    int tmp = s[i] - '0';
                    if (tmp % 2 == 0 && tmp != 0) {
                        cout << "red\n";
                        able = 1;
                        break;
                    }
                }
                if (able == 0) cout << "cyan\n";
            }
        }
    }
}

void solveB() {
    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        if (x <= 14) {
            cout << "NO\n";
            continue;
        }
        long long a = x % 14LL;
        if (a <= 6 && a >= 1) cout << "YES\n";
        else cout << "NO\n";
    }
}

void solveC() {
    int r, c;
    cin >> r >> c;
    if (r == 1 && c == 1) {
        cout << "0";
        return;
    }
    if (r == 1) {
        for (int i = 0; i < c; i++) cout << i + 2 << ' ';
        return;
    }
    if (c == 1) {
        for (int i = 0; i < r; i++) cout << i + 2 << '\n';
        return;
    }
    int arr[r + 1][c + 1];
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            arr[i][j] = (r + c  + 1 - i) * j;
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) cout << arr[i][j] << " ";
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    solveC();
}

#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void solveA() {
    int t; cin >> t;
    while (t--) {
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        bool done = false;
        int x;
        for (int i = 0; i < k1; i++) {
            cin >> x;
            if (x == n) done = true;
        }
        for (int i = 0; i < k2; i++) {
            cin >> x;
        }
        if (done) cout << "YES\n";
        else cout << "NO\n";
    }
}

void solveB() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        int able = 0;
        int a, b;
        for (int i = 0; i < n - 1; i++) {
            if (abs(arr[i] - arr[i + 1]) >= 2) {
                able = 1;
                a = i + 1;
                b = i + 2;
                break;
            }
        }
        if (able) {
            cout << "YES\n";
            cout << a << ' ' << b << '\n';
        }
        else cout << "NO\n";
    }
}

void solveC() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        long long arr[n];
        long long s = 0, x = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            s += arr[i];
            x ^= arr[i];
        }
        cout << "2\n";
        cout << x << ' ' << s + x << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    solveC();
}

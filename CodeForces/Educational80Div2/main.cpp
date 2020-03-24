#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void solveA() {
    int t; cin >> t;
    while (t--) {
        int n, d; cin >> n >> d;
        int x = sqrt(d);
        if (d <= n) {
            cout << "YES\n";
            continue;
        }
        int able = 0;
        if (x + (d + x) / (x + 1) <= n) able = 1;
        if (x + 1 + (d + x + 1) / (x + 2) <= n) able = 1;
        if (x - 1 + (d + x - 1) / x <= n) able = 1;
        if (able == 1) cout << "YES\n";
        else cout << "NO\n";
    }
}

void solveB() {
    int arr[] = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999};
    int t; cin >> t;
    while (t--) {
        long long a, b, res, aa = 0, bb = 0;
        cin >> a >> b;
        for (int i = 0; i < 9; i++) {
            if (arr[i] <= b) bb++;
        }
        res = a * bb;
        cout << res << '\n';
    }
}

const long long MOD = 1e9 + 7;

long long Pow(long long b, int e = MOD - 2) {
    if (e == 0) return 1;
    long long x = Pow(b, e / 2);
    if (e % 2 == 0) return x * x % MOD;
    return (x * x % MOD) * b % MOD;
}

void solveC() {
    long long n, m; cin >> n >> m;
    long long fact[n + 2 * m];
    fact[0] = 1;
    for (int i = 1; i < n + 2 * m; i++) fact[i] = fact[i - 1] * i % MOD;
    long long res = fact[n + 2 * m - 1] * Pow(fact[2 * m]) % MOD;
    res = res * Pow(fact[n - 1]) % MOD;
    cout << res;
}

void solveD() {
    int n, m; cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> arr[i][j];
    }
    int check[n];
    memset(check, 1, sizeof(check));
    int res, l = 0, r = 1e9;
    while (l < r) {
        res = (l + r) / 2;
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (arr[i][j] < res) check[i][j] *= 0;
            }
        }
        vector<int> ans = 0;
        for (int i = 0; i < n; i++)
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    solveC();
}

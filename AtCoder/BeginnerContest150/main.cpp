#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void solveA() {
    int k, x;
    cin >> k >> x;
    if (k * 500 >= x) cout << "Yes";
    else cout << "No";
}

void solveB() {
    int n; cin >> n;
    string s; cin >> s;
    int res = 0;
    for (int i = 0; i + 2 < n; i++) {
        if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') res++;
    }
    cout << res;
}

void solveC() {
    int n; cin >> n;
    int p[n], q[n];
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n;i ++) cin >> q[i];
    int arr[n];
    int lim = 1;
    for (int i = 1; i <= n; i++) lim *= i;
    for (int i = 0; i < n; i++) arr[i] = i + 1;
    int a = 0, b = 0;
    for (int i = 0; i < lim; i++) {
        int isA = 1, isB = 1;
        for (int j = 0; j < n; j++) {
            if (arr[j] != q[j]) isB = 0;
            if (arr[j] != p[j]) isA = 0;
        }
        if (isA) a = i;
        if (isB) b = i;
        next_permutation(arr, arr + n);
    }
    cout << abs(a - b);
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int find2(long long x) {
    int res = 0;
    while (x % 2 == 0) {
        res++;
        x /= 2;
    }
    return res;
}

void solveD() {
    long long n, m; cin >> n >> m;
    long long arr[n];
    if (n == 1) {
        int x; cin >> x;
        if (x % 2 == 1) cout << 0;
        else {
            x /= 2;
            int res = m / x - m / (2 * x); //(m + x) / (2 * x);
            cout << ((res < 0) ? 0 : res);
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] /= 2;
    }
    int two = find2(arr[0]);
    for (int i = 1; i < n; i++) {
        if (find2(arr[i]) != two) {
            cout << 0;
            return;
        }
    }
    long long arrLcm = 1LL;
    for (int i = 0; i < n; i++) arrLcm = lcm(arrLcm, arr[i]);
    long long res = m / arrLcm - m / (2 * arrLcm); //(m + arrLcm) / (2 * arrLcm);
    cout << ((res < 0) ? 0 : res);
}

const long long MOD = 1e9 + 7;

long long modPow(long long b, int p = MOD - 2) {
    if (p == 0) return 1LL;
    long long x = modPow(b, p / 2);
    if (p % 2 == 0) return x * x % MOD;
    return (x * x % MOD) * b % MOD;
}

void solveE() {
    int n; cin >> n;
    long long c[n];
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(c, c + n);
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += c[i] * (n - i + 1) % MOD;
        res %= MOD;
    }
    res = res * modPow(4LL, n - 1) % MOD;
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///solveA();
    ///solveB();
    ///solveC();
    ///solveD();
    solveE();
}

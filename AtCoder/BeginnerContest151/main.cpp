#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void solveA() {
    char x; cin >> x;
    cout << char(x + 1);
}

void solveB() {
    int n, k, m;
    cin >> n >> k >> m;
    int S = 0;
    for (int i = 0; i < n - 1; i++) {
        int x; cin >> x;
        S += x;
    }
    if (m * n - S > k) cout << -1;
    else {
        if (m * n - S < 0) cout << 0;
        else cout << m * n - S;
    }
}

void solveC() {
    int n, m;
    cin >> n >> m;
    int arr[n + 1], check[n + 1];
    memset(arr, 0, sizeof(arr));
    memset(check, 0, sizeof(check));
    for (int i = 0; i < m; i++) {
        int p; cin >> p;
        string s; cin >> s;
        if (s == "AC") check[p] = 1;
        else {
            if (check[p] != 1) arr[p]++;
        }
    }
    int cor = 0, pen = 0;
    for (int i = 1; i <= n; i++) {
        if (check[i] == 1) {
            cor++;
            pen += arr[i];
        }
    }
    cout << cor << ' ' << pen;
}

void solveD() {
    int h, w; cin >> h >> w;
    string s[h];
    for (int i = 0; i < h; i++) cin >> s[i];
    int res = 0;
    for (int i = 0; i < h - 1; i++) {
        for (int j = 0; j < w - 1; j++) {
            for (int k = i + 1; k < h; k++) {
                for (int l = j + 1; l < w; l++) {
                    if (s[i][j] == '.' && s[k][l] == '.') {
                        res = max(res, k - i + l - j);
                    }
                }
            }
        }
    }
    cout << res;
}

const long long MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

long long Fact[MAXN];

long long Pow(int b, int e = MOD - 2) {
    if (e == 0) return 1LL;
    long long tmp = Pow(b, e / 2);
    if (e % 2 == 0) return tmp * tmp % MOD;
    return (tmp * tmp % MOD) * b % MOD;
}

long long Choose(int n, int k) {
    return (Fact[n] * Pow(Fact[k]) % MOD) * Pow(Fact[n - k]) % MOD;
}

void solveE() {
    int n, k; cin >> n >> k;
    long long arr[n];
    Fact[0] = 1;
    for (int i = 1; i <= n; i++) Fact[i] = Fact[i - 1] * i % MOD;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    long long res = 0;
    for (int i = k - 1; i < n; i++) {
        res += arr[i] * (Choose(i, k - 1)) % MOD;
        res %= MOD;
    }
    for (int i = 0; i <= n - k; i++) {
        res = (res + MOD - arr[i] * Choose(n - i - 1, k - 1) % MOD) % MOD;
    }
    cout << res;
}

struct Point {
    long double x, y;
    Point() {}
    Point(long double a, long double b) {
        x = a;
        y = b;
    }
};

long double Dist(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void solveF() {
    int n; cin >> n;
    Point X[n];
    for (int i = 0; i < n; i++) cin >> X[i].x >> X[i].y;
    long double R = 1e9;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            Point C = Point((X[i].x + X[j].x) / 2, (X[i].y + X[j].y) / 2);
            long double r = Dist(X[i], X[j]);
            int able = 1;
            for (int k = 0; k < n; k++) {
                if (Dist(X[k], C) * 4 > r) {
                    able = 0;
                    break;
                }
            }
            if (able == 1) R = min(R, sqrt(r / 4));
        }
    }
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                long double a2 = Dist(X[i], X[j]);
                long double b2 = Dist(X[j], X[k]);
                long double c2 = Dist(X[k], X[i]);
                long double bcA = a2 * (b2 + c2 - a2);
                long double bcB = b2 * (c2 + a2 - b2);
                long double bcC = c2 * (a2 + b2 - c2);
                long double Sum = bcA + bcB + bcC;
                long double xx = (X[k].x * bcA + X[i].x * bcB + X[j].x * bcC) / Sum;
                long double yy = (X[k].y * bcA + X[i].y * bcB + X[j].y * bcC) / Sum;
                Point O = Point(xx, yy);
                long double p = (sqrt(a2) + sqrt(b2) + sqrt(c2)) / 2;
                long double S = p * (p - sqrt(a2)) * (p - sqrt(b2)) * (p - sqrt(c2));
                long double r2 = a2 * b2 * c2 / 16 / S;
                int able = 1;
                for (int l = 0; l < n; l++) {
                    if (Dist(X[l], O) > r2) {
                        able = 0;
                        break;
                    }
                }
                if (able == 1) R = min(R, sqrt(r2));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        long double r2 = 0;
        for (int j = 0; j < n; j++) {
            r2 = max(r2, Dist(X[i], X[j]));
        }
        R = min(R, sqrt(r2));
    }
    cout << fixed << setprecision(20) << R;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    solveF();
}

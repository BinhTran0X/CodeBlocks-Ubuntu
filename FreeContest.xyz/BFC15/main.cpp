#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void CHAR() {
    char x;
    cin >> x;
    int t = (x - 'a' + 1) % 26;
    char r = 'a' + t;
    cout << r;
}

void TABWALK() {
    long long n; cin >> n;
    long long res = 1e18;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res = min(res, i + n / i - 2);
        }
    }
    cout << res;
}

void MDIST() {
    int n; cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            res= max(res, abs(x[i] - x[j]) + abs(y[i] - y[j]));
        }
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

void BINHLUAN() {
    long double x1, x2, x3, y1, y2, y3, r1, r2, r3;
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    cin >> x3 >> y3 >> r3;
    long double xe = (x1 * r2 - x2 * r1) / (r2 - r1);
    long double ye = (y1 * r2 - y2 * r1) / (r2 - r1);
    long double xd = (r2 * x1 + r1 * x2) / (r1 + r2);
    long double yd = (r2 * y1 + r1 * y2) / (r1 + r2);
    long double X1 = (xe + xd) / 2;
    long double Y1 = (ye + yd) / 2;
    long double R1 = sqrt((xe - xd) * (xe - xd) + (ye - yd) * (ye - yd)) / 2;
    xe = (x1 * r3 - x3 * r1) / (r3 - r1);
    ye = (y1 * r3 - y3 * r1) / (r3 - r1);
    xd = (r3 * x1 + r1 * x3) / (r1 + r3);
    yd = (r3 * y1 + r1 * y3) / (r1 + r3);
    long double X2 = (xe + xd) / 2;
    long double Y2 = (ye + yd) / 2;
    long double R2 = sqrt((xe - xd) * (xe - xd) + (ye - yd) * (ye - yd)) / 2;
    Point A = Point(X1, Y1);
    Point B = Point(X2, Y2);
    if ((R1 + R2) * (R1 + R2) < Dist(A, B)) {
        cout << -1;
        return;
    }
    if (abs((R1 + R2) * (R1 + R2) - Dist(A, B)) < 1e-3) {
        long double xh = A.x + R1 / (R1 + R2) * (B.x - A.x);
        long double yh = A.y + R1 / (R1 + R2) * (B.y - A.y);
        Point H = Point(xh, yh);
        cout << fixed << setprecision(10) << H.x << " " << H.y;
        return;
    }
    long double AB = Dist(A, B);
    long double p = (sqrt(AB) + R1 + R2) / 2;
    long double S = abs(p * (p - R1) * (p - R2) * (p - sqrt(AB)));
    long double h = sqrt(S * 4 / AB);
    long double AH = sqrt(R1 * R1 - S / AB * 4);
    long double xh = A.x + AH / sqrt(AB) * (B.x - A.x);
    long double yh = A.y + AH / sqrt(AB) * (B.y - A.y);
    Point H = Point(xh, yh);
    long double vectorX = (A.y - B.y) / sqrt(AB);
    long double vectorY = (B.x - A.x) / sqrt(AB);
    Point M = Point(H.x + h * vectorX, H.y + h * vectorY);
    Point N = Point(H.x - h * vectorX, H.y - h * vectorY);
    int res;
    Point one = Point(x1, y1);
    Point two = Point(x2, y2);
    Point three = Point(x3, y3);
    int m = 1, n = 1;
    if (Dist(M, one) < r1 * r1) m = 0;
    if (Dist(M, two) < r2 * r2) m = 0;
    if (Dist(M, three) < r3 * r3) m = 0;
    if (Dist(N, one) < r1 * r1) n = 0;
    if (Dist(N, two) < r2 * r2) n = 0;
    if (Dist(N, three) < r3 * r3) n = 0;
    if (m == 0) {
        if (n == 1) cout << fixed << setprecision(10) << N.x << " " << N.y;
        else cout << -1;
        return;
    }
    else {
        if (n == 0) {
            cout << fixed << setprecision(10) << M.x << " " << M.y;
            return;
        }
    }
    if (asin(r1 / Dist(one, M)) < asin(r2 / Dist(one, N))) res = 2;
    else res = 1;
    if (res == 1) {
        cout << fixed << setprecision(10) << M.x << " " << M.y;
    }
    else cout << fixed << setprecision(10) << N.x << " " << N.y;
}

void CPREFIX() {
    string s;
    cin >> s;
    int n = s.size();
    int res[n];
    memset(res, 0, sizeof(res));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int able = 1;
            for (int k = 0; k <= i; k++) {
                if (s[j - k] != s[i - k]) {
                    able = 0;
                    break;
                }
            }
            if (able) res[i]++;
        }
    }
    for (int i = 0; i < n; i++) cout << res[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    //rwFile();
    ///CHAR();
    ///TABWALK();
    ///MDIST();
    ///BINHLUAN();
    CPREFIX();
}

#include <bits/stdc++.h>
#define TASK "swap"
using namespace std;

void rwFile() {
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
}

void bronze1() {
    int n; cin >> n;
    const int maxN = 2e4 + 5;
    int diff = 1e4;
    int maxY[maxN], minY[maxN], maxX[maxN], minX[maxN];
    int X[100], Y[100];
    for (int i = 0; i < maxN; i++) {
        maxX[i] = maxY[i] = -maxN;
        minX[i] = minY[i] = maxN;
    }
    for (int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
        maxY[X[i] + diff] = max(maxY[X[i] + diff], Y[i]);
        minY[X[i] + diff] = min(minY[X[i] + diff], Y[i]);
        maxX[Y[i] + diff] = max(maxX[Y[i] + diff], X[i]);
        minX[Y[i] + diff] = min(minX[Y[i] + diff], X[i]);
    }
    long long S = 0;
    for (int i = 0; i < n; i++) {
        int xx = max(maxX[Y[i] + diff] - X[i], X[i] - minX[Y[i] + diff]);
        int yy = max(maxY[X[i] + diff] - Y[i], Y[i] - minY[X[i] + diff]);
        S = max(S, 1LL * xx * yy);
    }
    cout << S;
}

struct Matrix {
    int c[100][100];
    Matrix() {
        for (int i = 0; i < 100; i++) c[i][i] = 1;
    }
};

Matrix mult(Matrix a, Matrix b) {
    Matrix r;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            r.c[i][j] = 0;
            for (int k = 0; k < 100; k++) {
                r.c[i][j] += a.c[i][k] * b.c[k][j];
            }
        }
    }
    return r;
}

Matrix exp(Matrix a, int e) {
    if (e == 0) {
        Matrix r;
        return r;
    }
    Matrix r = exp(a, e / 2);
    r = mult(r, r);
    if (e % 2 == 0) return r;
    return mult(r, a);
}

void bronze3() {
    int n, k; cin >> n >> k;
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    Matrix a, b;
    a1--; a2--;
    b1--; b2--;
    for (int i = 0; i <= (a2 - a1) / 2; i++) {
        a.c[a1 + i][a1 + i] = 0;
        a.c[a1 + i][a2 - i] = 1;
        a.c[a2 - i][a2 - i] = 0;
        a.c[a2 - i][a1 + i] = 1;
    }
    for (int i = 0; i <= (b2 - b1) / 2; i++) {
        b.c[b1 + i][b1 + i] = 0;
        b.c[b1 + i][b2 - i] = 1;
        b.c[b2 - i][b2 - i] = 0;
        b.c[b2 - i][b1 + i] = 1;
    }
    Matrix M = mult(a, b);
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << b.c[i][j] << ' ';
        cout << '\n';
    }
    */
    Matrix R = exp(M, k);
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (R.c[i][j] == 1) cout << i + 1;
        }
        if (j != n - 1) cout << '\n';
    }
}

void bronze2() {
    int n; cin >> n;
    string a, b;
    cin >> a >> b;
    int res = 0;
    int same = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (same == 1) {
                same = 0;
                res++;
            }
        }
        if (a[i] == b[i]) {
            if (same == 0) {
                same = 1;
            }
        }
    }
    cout << res;
}

struct Vector {
    int c[100005];
    Vector() {
        for (int i = 0; i <= 100001; i++) c[i] = i;
    }
    Vector(int n) {
        for (int i = 0; i <= n; i++) c[i] = i;
    }
};

Vector mult(Vector a, Vector b) {
    Vector res;
    for (int i = 1; i < 100001; i++) {
        res.c[i] = a.c[b.c[i]];
    }
    return res;
}

Vector exp(Vector a, int e) {
    if (e == 0) {
        Vector r;
        return r;
    }
    Vector r = exp(a, e / 2);
    r = mult(r, r);
    if (e % 2 == 0) return r;
    return mult(r, a);
}

void silver1() {
    int n, m, k;
    cin >> n >> m >> k;
    Vector arr;
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        for (int j = 0; j < (r + 1 - l) / 2; j++)
            swap(arr.c[l + j], arr.c[r - j]);
    }
    //for (int i = 1; i <= n; i++) cout << arr.c[i] << ' ';
    Vector res = exp(arr, k);
    for (int i = 1; i <= n; i++) {
        cout << res.c[i];
        if (i != n) cout << '\n';
    }
}

void silver2() {
    int n; cin >> n;
    map<int, vector<int>> preSumX, sufSumX, CountX, arrX;
    map<int, vector<int>> preSumY, sufSumY, CountY, arrY;
    int X[n], Y[n];
    for (int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
        arrX[X[i]].push_back(Y[i]);
        arrY[Y[i]].push_back(X[i]);
    }
    for (int i = 0; i < n; i++) {
        sort(arrX[X[i]].begin(), arrX[X[i]].end());
        sort(arrY[Y[i]].begin(), arrY[Y[i]],end());
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///bronze3();
    ///bronze1();
    ///bronze2();
    silver1();
}

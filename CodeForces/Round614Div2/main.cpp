#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void solveA() {
    int t; cin >> t;
    while (t--) {
        int n, s, k; cin >> n >> s >> k;
        int arr[k];
        for (int i = 0; i < k; i++) cin >> arr[i];
        sort(arr, arr + k);
        int res = 0;
        for (res = 0; res <= n; res++) {
            if (s - res >= 1) {
                int p = lower_bound(arr, arr + k, s - res) - arr;
                if (p == k) break;
                if (arr[p] != s - res)  break;
            }
            if (s + res <= n) {
                int p = lower_bound(arr, arr + k, s + res) - arr;
                if (p == k) break;
                if (arr[p] != s + res)  break;
            }
        }
        cout << res << '\n';
    }
}

void solveB() {
    long double n; cin >> n;
    long double res = 0;
    while (n != 0) {
        res += 1 / n;
        n--;
    }
    cout << fixed << setprecision(10) << res;
}

void solveC() {
    int n, q; cin >> n >> q;
    int arr[2][n];
    memset(arr, 0, sizeof(arr));
    int pos = 0;
    int check[n];
    memset(check, 0, sizeof(check));
    while (q--) {
        int r, c; cin >> r >> c;
        if (arr[r - 1][c - 1] == 0) {
            arr[r - 1][c - 1] = 1;
            if (r == 1) {
                for (int i = -1; i <= 1; i++) {
                    if (c - 1 + i >= 0 && c - 1 + i < n - 1) {
                        if (arr[1][c - 1 + i] == 1) {
                            if(check[c - 1 + i] == 0) {
                                check[c - 1 + i] = 1;
                                pos++;
                            }
                        }
                    }
                }
            }
            else {
                for (int i = -1; i <= 1; i++) {
                    if (c - 1 + i >= 1 && c - 1 + i < n) {
                        if (arr[0][c - 1 + i] == 1) {
                            pos++;
                            check[c - 1] = 1;
                            break;
                        }
                    }
                }
            }
        }
        else {
            arr[r - 1][c - 1] = 0;
            if (r == 1) {
                if (arr[1][c - 1] == 1) {
                    int able = 1;
                    if (c >= 2 && arr[0][c - 2] == 1) {
                        able = 0;
                    }
                    if (c < n && arr[0][c] == 1) able = 0;
                    if (able) {
                        check[c - 1] = 0;
                        pos--;
                    }
                }
                if (c - 2 >= 0 && arr[1][c - 2] == 1) {
                    int able = 1;
                    if (c >= 3 && arr[0][c - 3] == 1) {
                        able = 0;
                    }
                    if (arr[0][c - 2] == 1) able = 0;
                    if (able) {
                        check[c - 2] = 0;
                        pos--;
                    }
                }
                if (c < n && arr[1][c] == 1) {
                    int able = 1;
                    if (c + 1 < n && arr[0][c + 1] == 1) {
                        able = 0;
                    }
                    if (arr[0][c] == 1) able = 0;
                    if (able) {
                        check[c] = 0;
                        pos--;
                    }
                }
            }
            if (r == 2) {
                if (check[c - 1] == 1) {
                    check[c - 1] = 0;
                    pos--;
                }
            }
        }
        if (pos == 0) cout << "Yes\n";
        else cout << "No\n";
    }
}

struct pt {
    long long x, y;
    pt() {}
    pt(long long a, long long b) {
        x = a;
        y = b;
    }
};

long long dist(pt a, pt b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void solveD() {
    long long x0, y0, ax, ay, bx, by;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    long long xs, ys, t;
    cin >> xs >> ys >> t;
    pt spt = pt(xs, ys);
    vector<pt> arr;
    int len = 1;
    arr.push_back(pt(x0, y0));
    while (true) {
        long long x = arr[len - 1].x * ax + bx;
        long long y = arr[len - 1].y * ay + by;
        if (x > 4e16 || y > 4e16) break;
        arr.push_back(pt(x, y));
        len++;
    }
    //for (auto i : arr) cout << i.x << ' ' << i.y << '\n';
    int res = 0;
    long long d[len - 1];
    for (int i = 0; i < len - 1; i++) {
        d[i] = dist(arr[i], arr[i + 1]);
    }
    //for (int i = 0; i < len - 1; i++) cout << d[i] << '\n';
    for (int i = 0; i < len; i++) {
        int c = 0;
        long long tmp = t;
        if (dist(spt, arr[i]) <= tmp) {
            c++;
            tmp -= dist(spt, arr[i]);
        }
        else continue;
        for (int j = i; j < len - 1; j++) {
            if (d[j] <= tmp) {
                c++;
                tmp -= d[j];
            }
            else break;
        }
        //cout << c << " ";
        res = max(res, c);
    }
    for (int i = 0; i < len; i++) {
        int c = 0;
        long long tmp = t;
        if (dist(spt, arr[i]) <= tmp) {
            c++;
            tmp -= dist(spt, arr[i]);
        }
        else continue;
        for (int j = i - 1; j >= 0; j--) {
            if (d[j] <= tmp) {
                c++;
                tmp -= d[j];
            }
            else break;
        }
        //cout << c << " ";
        res = max(res, c);
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    solveD();
}

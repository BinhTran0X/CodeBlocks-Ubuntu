#include <bits/stdc++.h>
#define TASK "task"

using namespace std;

void rwFile() {
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
}

void solveA() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        if (n % m == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}

void solveB() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n);
        for (int i = n - 1; i >= 0; i--) cout << arr[i] << ' ';
        cout << '\n';
    }
}

vector<int> getP(long long a, int k) {
    vector<int> res;
    int p = 0;
    int able = 1;
    while (a != 0) {
        while (a % k == 0) {
            a /= k;
            p++;
        }
        res.push_back(p);
        if (a % k != 1) {
            able = 0;
            break;
        }
        else a--;
    }
    if (able == 0) {
        vector<int> tmp;
        return tmp;
    }
    return res;
}

void solveC() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int check[100];
        int able = 1;
        memset(check, 0, sizeof(check));
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) continue;
            vector<int> tmp = getP(a[i], k);
            if ((int)tmp.size() == 0) {
                able = 0;
                break;
            }
            for (int j : tmp) {
                if (check[j] == 0) check[j]++;
                else {
                    able = 0;
                    break;
                }
            }
        }
        if (able) cout << "YES\n";
        else cout << "NO\n";
    }
}

const int maxN = 2e5 + 5;
const long long MOD = 998244353;
long long Fact[maxN];

long long Pow(long long b, int e = MOD - 2) {
    if (e == 0) return 1;
    long long x = Pow(b, e / 2);
    if (e % 2 == 0) return x * x % MOD;
    return (x * x % MOD) * b % MOD;
}

long long Choose(long long n, long long k) {
    if (k > n) return 0;
    long long res = Fact[n];
    res = res * Pow(Fact[k]) % MOD;
    res = res * Pow(Fact[n - k]) % MOD;
    return res;
}

void solveD() {
    Fact[0] = 1;
    for (int i = 1; i < maxN; i++) Fact[i] = Fact[i - 1] * i % MOD;
    long long n, m; cin >> n >> m;
    long long pow2 = Pow(2, n - 3);
    long long res = 0;
    long long tmp = Choose(m, n - 1) * (n - 2) % MOD;
    tmp = tmp * pow2 % MOD;
    res = (res + tmp) % MOD;
    cout << res;
}

void solveE() {
    int n; cin >> n;
    int arr[n + 2];
    for (int i = 1; i <= n; i++) cin >> arr[i];
    arr[0] = arr[n + 1] = -123456789;
    int len = n;
    int i = 1;
    while (i < n) {
        if (arr[i] != arr[i + 1] && arr[i] != arr[i - 1]) {
            i++;
            continue;
        }
        if (arr[i] < 0) break;
        int l = 0, r = 0;
        if (i + 2 < n + 2 && arr[i] == arr[i + 2] && arr[i] == arr[i + 1]) {
            if (arr[i] == arr[i - 1]) {
                l++;
                for (int j = i - 2; j > 0; j--) {
                    if (arr[j] - arr[i] != i - 1 - j) break;
                    l++;
                }
            }
            if (arr[i] == arr[i + 1]) {
                r++;
                for (int j = i + 2; j <= n; j++) {
                    if (arr[j] - arr[i] != j - i - 1) break;
                    r++;
                }
            }
            if (l > r) {
                arr[i]++;
                len--;
                for (int j = i - 1; j > 0; j--) arr[j] = arr[j - 1];
            }
            else {
                arr[i]++;
                len--;
                for (int j = i + 1; j <= n; j++) arr[j] = arr[j + 1];
            }
        }
        else if (arr[i] == arr[i - 1]) {
            arr[i]++;
            len--;
            for (int j = i - 1; j > 0; j--) arr[j] = arr[j - 1];
        }
        else if (arr[i] == arr[i + 1]) {
            arr[i]++;
            len--;
            for (int j = i + 1; j <= n; j++) arr[j] = arr[j + 1];
        }
        //for (int x = 0; x < n + 2; x++) cout << arr[x] << ' ';
        //cout << '\n';
    }
    cout << len;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    solveE();
}

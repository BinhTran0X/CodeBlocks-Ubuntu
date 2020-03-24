#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void solveA() {
    int m, n; cin >> m >> n;
    if (m == n) cout << "Yes";
    else cout << "No";
}

void solveB() {
    int a, b; cin >> a >> b;
    if (a > b) swap(a, b);
    for (int i = 0; i < b; i++) cout << a;
}

void solveC() {
    int n; cin >> n;
    int minn = 1e9, res = 0;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] <= minn) res++;
        minn = min(a[i], minn);
    }
    cout << res;
}

const int maxN = 1e6 + 1;
const long long MOD = 1e9 + 7;
int prime[maxN];

void Seive() {
    for (int i = 2; i < 1000; i++) {
        if (prime[i] == 0) {
            for (int j = i * i; j < maxN; j += i) prime[j] = i;
        }
    }
    for (int i = 2; i < maxN; i++) {
        if (prime[i] == 0) prime[i] = i;
    }
}

long long Pow(int b, int e = MOD - 2){
    if (e == 0) return 1LL;
    long long x = Pow(b, e / 2);
    if (e % 2 == 0) return x * x % MOD;
    return (x * x % MOD) * b % MOD;
}

void solveE() {
    Seive();
    int n; cin >> n;
    int arr[n];
    map<int, int> M;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        int tmp = arr[i];
        while (tmp != 1) {
            int c = 0;
            int p = prime[tmp];
            while (tmp % p == 0) {
                tmp /= p;
                c++;
            }
            M[p] = max(M[p], c);
        }
    }
    long long lcm = 1;
    for (auto i : M) {
        //cout << i.first << ' ' << i.second << '\n';
        lcm = lcm * Pow(i.first, i.second) % MOD;
    }
    long long res = 0;
    //cout << lcm << ' ';
    for (int i = 0; i < n; i++) {
        res = (res + lcm * Pow(arr[i])) % MOD;
    }
    cout << res;
}

int getFirst(int a) {
    while (a >= 10) a /= 10;
    return a;
}

int getLast(int a) {
    return a % 10;
}

void solveD() {
    int n; cin >> n;
    int arr[100];
    memset(arr, 0, sizeof(arr));
    for (int i = 1; i <= n; i++) {
        int ff = getFirst(i);
        int ll = getLast(i);
        arr[ff * 10 + ll]++;
    }
    long long res = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            res += arr[i * 10 + j] * arr[j * 10 + i];
        }
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

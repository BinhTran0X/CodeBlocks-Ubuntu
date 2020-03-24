#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void DSUM() {
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < 3; i++) res += s[i] - '0';
    cout << res;
}

void STR() {
    int a, b; cin >> a >> b;
    if (a > b) swap(a, b);
    for (int i = 0; i < b; i++) cout << a;
}

const int maxN = 1e5 + 5;
vector<int> adj[maxN];
int check[maxN];

int DFSVisit(int u) {
    check[u] = 1;
    int res = 1;
    for (int i : adj[u]) {
        if (check[i] == 0) res += DFSVisit(i);
    }
    return res;
}

void NYTRAVEL() {
    int n, m; cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans;
    int res  = DFSVisit(1);
    for (int i = 2; i <= n; i++) {
        if (check[i] == 0) ans.push_back(DFSVisit(i));
    }
    sort(ans.begin(), ans.end(), greater<int>());
    if ((int)ans.size() >= 1) res += ans[0];
    cout << res;
}

void FILEDEL() {
    int n, q; cin >> n >> q;
    multiset<string> arr[26];
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int i = 0; i < (int)s.size(); i++) {
            arr[s[i] - 'a'].insert(s);
        }
    }
    int res = n;
    while (q--) {
        char x; cin >> x;
        int t = x - 'a';
        res -= arr[t].size();
        for (auto i : arr[t]) {
            string tmp = i;
            //cout << tmp << ' ';
            for (int j = 0; j < (int)tmp.size(); j++) {
                int p = tmp[j] - 'a';
                //cout << p << ' ';
                while (!arr[p].empty() && arr[p].find(tmp) != arr[p].end())
                    arr[p].erase(arr[p].find(tmp));
            }
            //cout << '\n';
        }
        //arr[t].clear();
        cout << res << '\n';
    }
}

long long Pow(long long b, int e, int mod) {
    if (e == 0) return 1LL;
    long long x = Pow(b, e / 2, mod);
    if (e % 2 == 0) return x * x % mod;
    return (x * x % mod) * b % mod;
}

int Phi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            res -= res / i;
        }
    }
    if (n != 1) {
        res -= res / n;
    }
    return res;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int prime[maxN];

typedef map<int, int> ftr;

ftr factorize(int a) {
    ftr res;
    while (a != 1) {
        int tmp = prime[a];
        while (a % tmp == 0) {
            res[tmp]++;
            a /= tmp;
        }
    }
    return res;
}

ftr mult(ftr a, ftr b) {
    for (auto i : b) {
        a[i.first] += i.second;
    }
    return a;
}

ftr divi(ftr a, ftr b) {
    for (auto i : b) {
        a[i.first] -= i.second;
    }
    return a;
}

long long toInt(ftr a, int mod) {
    long long res = 1;
    for (auto i : a) {
        for (int j = 0; j < i.second; j++)
            res = res * i.first % mod;
    }
    return res;
}

void COUNTK() {
    for (int i = 2; i < 400; i++) {
        if (prime[i] == 0) {
            for (int j = i * i; j < maxN; j += i) prime[j] = i;
        }
    }
    for (int i = 2; i < maxN; i++) {
        if (prime[i] == 0) prime[i] = i;
    }
    ftr fact[maxN];
    for (int i = 2; i < 6; i++)
        fact[i] = mult(fact[i - 1], factorize(i));
    int t; cin >> t;
    while (t--) {
        int k, m, n, mod;
        cin >> k >> m >> n >> mod;
        n = abs(n);
        m = abs(m);
        if (k < m + n || (k - m - n) % 2 != 0) {
            cout << "0\n";
            continue;
        }
        long long res = 1;
        int t = (k - m - n) / 2;
        for (int i = 0; i <= t; i++) {
            int p = 0;
            long long tmp =
            for (int )
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///DSUM();
    ///STR();
    ///NYTRAVEL();
    ///FILEDEL();
    COUNTK();
}

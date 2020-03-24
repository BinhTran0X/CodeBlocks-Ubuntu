#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void solveA() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b, c, n;
        cin >> a >> b >> c >> n;
        long long s = a + b + c + n;
        if (s % 3 != 0) {
            cout << "NO\n";
            continue;
        }
        s /= 3;
        if (s < a ||s < b || s < c) {
            cout << "NO\n";
        }
        else cout << "YES\n";
    }
}

typedef pair<int, int> i2;

void solveB() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        i2 arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
        sort(arr, arr + n);
        int able = 1;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1].second < arr[i].second) {
                able = 0;
                break;
            }
        }
        if (arr[0].first < 0 || arr[0].second < 0) able = 0;
        if (able == 0) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int j = 0; j < arr[0].first; j++) cout << "R";
        for (int j = 0; j < arr[0].second; j++) cout << "U";
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < arr[i].first - arr[i - 1].first; j++) cout << "R";
            for (int j = 0; j < arr[i].second - arr[i - 1].second; j++) cout << "U";
        }
        cout << '\n';
    }
}

void solveC() {
    vector<int> primes;
    int maxN = 1e5;
    int arr[maxN];
    memset(arr, 0, sizeof(arr));
    for (int i = 2; i < maxN; i++) {
        if (arr[i] == 0) {
            primes.push_back(i);
            for (int j = i; j < maxN; j += i) arr[j] = 1;
        }
    }
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a = -1, b = -1, c = -1;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                if (a == -1) a = i;
                else if (b == -1) {
                    b = i;
                    break;
                }
                n /= i;
            }
        }
        c = n / b;
        if (c == 1 || a == -1 || b == -1 || c == b || c == a) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << a << ' ' << b << ' ' << c << '\n';
    }
}

void solveD() {
    int q, x; cin >> q >> x;
    const int maxN = 4e5;
    int arr[maxN + 1];
    memset(arr, 0, sizeof(arr));
    stack<int> stk;
    for (int i = maxN + 5; i >= 0; i--) stk.push(i);
    while (q--) {
        int y; cin >> y;
        y %= x;
        if (arr[y] == 0) {
            arr[y]++;
        }
        else {
            if (1LL * arr[y] * x + y <= maxN) arr[arr[y] * x + y]++;
            arr[y]++;
        }
        //cout << arr[1];
        while (arr[stk.top()] != 0) stk.pop();
        cout << stk.top() << '\n';
    }
}

const int maxN = 2e5 + 5;
int check[maxN];
vector<int> adj[maxN];

int DFS(int u) {
    check[u] = 1;
    int maxx = 0;
    for (int i : adj[u]) {
        if (check[i] == 0) {
            maxx = max(maxx, DFS(i) + 1);
        }
    }
    return maxx;
}

void solveE() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << DFS(1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    solveE();
}

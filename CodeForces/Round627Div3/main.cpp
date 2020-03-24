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
        int n; cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        int x = arr[0] % 2, able = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] % 2 != x) {
                able = 0;
                break;
            }
        }
        if (able) cout << "YES\n";
        else cout << "NO\n";
    }
}

void solveB() {
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n], check[n + 1];
        memset(check, 0, sizeof(check));
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            check[arr[i]]++;
            if (i > 0 && arr[i] == arr[i - 1]) {
                if (i > 1 && arr[i] == arr[i - 2]) continue;
                else check[arr[i]]--;
            }
        }
        int able = 0;
        for (int i = 1; i <= n; i++) {
            if (check[i] >= 2) {
                able = 1;
                break;
            }
        }
        if (able) cout << "YES\n";
        else cout << "NO\n";
    }
}

void solveC() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        vector<int> r;
        r.push_back(0);
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == 'R') r.push_back(i + 1);
        }
        r.push_back((int)s.size() + 1);
        int res = 0;
        for (int i = 1; i < (int)r.size(); i++) {
            res = max(res, r[i] - r[i - 1]);
        }
        cout << res << '\n';
    }
}

void solveD() {
    int n; cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        long long x; cin >> x;
        arr[i] -= x;
    }
    sort(arr, arr + n);
    long long res = 0;
    //for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    //cout << '\n';
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) res--;
        int pos = upper_bound(arr, arr + n, - arr[i]) - arr;
        //pos = max(i + 1, pos);
        res += n - pos;
        //cout << res << ' ';
    }
    cout << res / 2;
}

const int maxN = 2e5 + 5;
vector<int> adj[maxN];
int usedByParent[maxN], check[maxN], res[maxN], color[maxN];

void DFS1(int u) {
    check[u] = 1;
    for (int i : adj[u]) {
        if (check[i] == 0) {
            DFS1(i);
            if (res[i] >= 0) {
                res[u] += res[i];
                usedByParent[i] = 1;
            }
        }
    }
    if (color[u] == 0) res[u]--;
    else res[u]++;
}

void DFS2(int u) {
    check[u] = 1;
    for (int i : adj[u]) {
        if (check[i] == 0) {
            if (usedByParent[i]) res[i] = max(res[u], res[i]);
            else res[i] = max(res[u] - 1, res[i]);
            DFS2(i);
        }
    }
}

void solveF() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> color[i + 1];
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS1(1);
    memset(check, 0, sizeof(check));
    DFS2(1);
    for (int i = 1; i <= n; i++) cout << res[i] << " ";
}

void solveE() {
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    int arr[n + 1];
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
        arr[i] %= h;
    }
    int c = 0, res = 0;
    for (int i = 1; i <= n; i++) {
        c++;
        if (arr[i] >= l && arr[i] <= r) {
            res++;
            continue;
        }
        int tmp = (arr[i] - r + h) % h;
        if (tmp <= c) {
            res++;
            for (int j = i; j <= n; j++) arr[j] = (arr[j] - tmp + h) % h;
        }
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    solveE();
    //int arr[] = {1,2,3,4,5};
    //cout << upper_bound(arr, arr + 5, 6) - arr;
}

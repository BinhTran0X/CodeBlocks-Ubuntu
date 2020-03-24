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
        int x; cin >> x;
        cout << 1 << " " << x - 1 << '\n';
    }
}

void solveB() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n);
        int res = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[i - 1]) res++;
        }
        cout << res << '\n';
    }
}

typedef pair<int, int> i2;

const int maxN = 1e5 + 5;
vector<i2> adj[maxN];
int isLeaf[maxN], edge[maxN];
int seg = 0;

void DFS(int u, int p) {
    int c = 0;
    for (i2 i : adj[u]) {
        if (i.first != p) {
            c++;
            DFS(i.first, u);
            if (isLeaf[i.first]) edge[i.second] = seg++;
        }
    }
    if (c == 0) isLeaf[u] = 1;
}

void solveC() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(i2(v, i));
        adj[v].push_back(i2(u, i));
    }
    if (n == 2) {
        cout << 0;
        return;
    }
    int u;
    for (int i = 1; i < n; i++) {
        if ((int)adj[i].size() > 1) {
            u = i;
            break;
        }
    }
    for (int i = 0; i < n; i++) edge[i] = -1;
    DFS(u, -1);
    for (int i = 0; i < n - 1; i++) {
        if (edge[i] == -1) edge[i] = seg++;
    }
    for (int i = 0; i < n - 1; i++) cout << edge[i] << '\n';
}

string toBin(long long u) {
    string res = "";
    while (u) {
        if (u % 2 == 0) {
            res += '0';
        }
        else res += '1';
        u /= 2;
    }
    string tmp = "";
    for (int i = (int)res.size() - 1; i >= 0; i--) tmp += res[i];
    while ((int)tmp.size() < 20) tmp = "0" + tmp;
    return tmp;
}

long long toInt(string s) {
    long long res = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        res = res * 2 + (s[i] - '0');
    }
    return res;
}

void solveD() {
    long long u, v; cin >> u >> v;
    if ((u - v) % 2 == 1 || u > v) {
        cout << -1;
        return;
    }
    if (u == v) {
        if (u == 0) {
            cout << 0;
            return;
        }
        cout << 1 << "\n";
        cout << u;
        return;
    }
    string a = toBin(u), b = toBin(v);
    int c = 0, able = 1;
    string res = "";
    for (int i = 0; i < 20; i++) {
        if (a[i] == '0') {
            if (b[i] == '0') {
                if (c == 1) {
                    res += '1';
                    c = 0;
                }
                else {
                    res += '0';
                    c = 0;
                }
            }
            else {
                if (c == 1) {
                    res += '1';
                }
                else {
                    res += '0';
                    c = 1;
                }
            }
        }
        else {
            if (b[i] == '0') {
                if (c == 1) {
                    res += '0';
                }
                else {
                    able = 0;
                    break;
                }
            }
            else {
                if (c == 1) {
                    able = 0;
                    break;
                }
                else res += '0';
            }
        }
    }
    //if (a[19] == '1' && b[19] == '0') able = 0;
    if (c == 1 || able == 0) {
        cout << "3\n";
        long long tmp = (v - u) / 2;
        cout << tmp << ' ' << tmp << " " << u;
    }
    else {
        cout << "2\n";
        cout << toInt(res) << " " << v - toInt(res);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    solveD();
}

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
        int s = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            s += x;
        }
        cout << min(s, m) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    solveA();
}

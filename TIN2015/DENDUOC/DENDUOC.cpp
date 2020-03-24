#include <bits/stdc++.h>

using namespace std;

void doc() {
    freopen("DENDUOC.inp", "r", stdin);
    freopen("DENDUOC.out", "w", stdout);
}

int res(vector<int> arr[], int start, int check[]) {
    static int ans = 0;
    for (int i:arr[start]) {
        if (check[i] == 0) {
            ans++;
            check[i] = 1;
            res(arr, i, check);
        }
    }
}

int main()
{
    doc();
    int n, m, s;
    cin >> n >> m >>s;
    vector<int> arr[n + 1];
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    int check[n + 1];
    for (int i = 1; i <= n ; i++) {
        check[i] = 0;
        if (i == s) check[i] = 1;
    }
    int result = res(arr, s, check);
}

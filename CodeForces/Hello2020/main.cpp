#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void solveA() {
    int n, m;
    cin >> n >> m;
    string S[n], T[m];
    for (int i = 0; i < n; i++) cin >> S[i];
    for (int i = 0; i < m; i++) cin >> T[i];
    int q; cin >> q;
    while (q--) {
        int y; cin >> y;
        y--;
        string ans = S[y % n] + T[y % m];
        cout << ans << '\n';
    }
}

const int oo = 1e9;

bool hasAscent(vector<int> x) {
    int len = x.size();
    for (int i = 0; i < len - 1; i++) {
        if (x[i] < x[i + 1]) return true;
    }
    return false;
}

void solveB() {
    int n; cin >> n;
    vector<int> arr[n];
    int Min[n], Max[n];
    for (int i = 0; i < n; i++) Min[i] = oo;
    memset(Max, 0, sizeof(Max));
    for (int i = 0; i < n; i++) {
        int l; cin >> l;
        for (int j = 0; j < l; j++) {
            int x; cin >> x;
            Min[i] = min(Min[i], x);
            Max[i] = max(Max[i], x);
            arr[i].push_back(x);
        }
    }
    long long res = 0;
    vector<int> Mini, Maxi;
    long long done = 0;
    for (int i = 0; i < n; i++) {
        if (hasAscent(arr[i])) done++;
        else {
            Mini.push_back(Min[i]);
            Maxi.push_back(Max[i]);
        }
    }
    res = done * done + (n - done) * 2 * done;
    //cout << res << '\n';
    sort(Maxi.begin(), Maxi.end());
    sort(Mini.begin(), Mini.end());
    //for (int i : Maxi) cout << i <<' ';
    //cout << endl;
    //for (int i : Mini) cout << i << ' ';
    //cout << endl;
    for (int i = 0; i < (int)Mini.size(); i++) {
        int pos = upper_bound(Maxi.begin(), Maxi.end(), Mini[i]) - Maxi.begin();
        //cout << pos << ' ';
        res += Maxi.size() - pos;
        //if (Min[i] == Max[i]) res++;
    }
    //for (int i = 0; i < n; i++) cout << Min[i] << ' ';
    //cout << endl;
    cout << res;
}

/*
long long Pow(long long b, int e) {
    if (e == 0) return 1LL;
    long long tmp = Pow(b, e / 2);
    if (e % 2 == 0) return tmp * tmp % MOD;
    return (tmp * tmp % MOD) * b % MOD;
}
*/

long long MOD;
const int MAXN = 256789;

long long Fact[MAXN];
void solveC() {
    int n; cin >> n >> MOD;
    Fact[0] = 1;
    for (int i = 1; i <= n; i++) Fact[i] = Fact[i - 1] * i % MOD;
    long long res = 0;
    for (int i = n; i >= 0; i--) {
        res += (i * Fact[i] % MOD) * Fact[n + 1 - i] % MOD;
        res %= MOD;
    }
    cout << res;
}

void solveD() {
    int n;
    cin >> n;
    int sa[n], ea[n], sb[n], eb[n];
    int sameA[n], sameB[n];
    memset(sameA, 0, sizeof(sameA));
    memset(sameB, 0, sizeof(sameB));
    for (int i = 0; i < n; i++) {
        cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
        if (sa[i] == ea[i]) sameA[i] = 1;
        if (sb[i] == eb[i]) sameB[i] = 1;
    }
    sort(sameA, sameA + n, [&](int i, int j) { return sa[i] < sa[j]; });
    sort(sameB, sameB + n, [&](int i, int j) { return sb[i] < sb[j]; });
    sort(sa, sa + n);
    sort(sb, sb + n);
    sort(ea, ea + n);
    sort(eb, eb + n);
    int able = 1;
    int aaa = 1;
    int k = pos1 = upper_bound(ea, ea + n, sa[0]) - ea - sameA[0];
    for (int i = 0; i < n; i++) {
        int pos1 = upper_bound(ea, ea + n, sa[i]) - ea;
        pos1 -= sameA[i];
        int pos2 = upper_bound(eb, eb + n, sb[i]) - eb;
        pos2 -= sameB[i];
        if (pos1 != pos2) {
            able = 0;
            break;
        }
        if (pos1 != k) aaa = 0;
    }
    if (able) {
        if (aaa == 1) cout << "NO";
        else cout << "YES";
    }
    else cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    solveD();
}

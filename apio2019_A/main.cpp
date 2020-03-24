#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long a, b;
    cin >> n >> a >> b;
    long long alpha = a/__gcd(a, b + 1);
    long long oo = 2e18;
    if (oo/b <= alpha) b = oo;
    else b *= alpha;

    map<long long, long long> lrList;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        long long l, r;
        cin >> l >> r;
        if ((r - l + 1)/b >= 1) res = b;
        else {
            if (l%b < r%b) {
                lrList.insert(make_pair(l%b, r%b));
            }
            if (l%b == r%b) {
                lrList.insert(make_pair(l%b, r%b));
            }
            if (l%b > r%b) {
                lrList.insert(make_pair(0, r%b));
                lrList.insert(make_pair(l%b, b - 1));
            }
        }
    }
    if (res == b) cout << res;
    else {
        map<long long, long long>::iterator rr = --lrList.end();
        map<long long, long long>::iterator ll = lrList.begin();
        res = rr->second - ll->first + 1;
        map<long long, long long>::iterator index;
        map<long long, long long>::iterator secondLast = --lrList.end();
        for (index = lrList.begin(); index != secondLast; index++) {
            map<long long, long long>::iterator itr = index;
            if (itr->second < (++itr)->first) {
                res -= (itr->first - (--itr)->second - 1);
            }
            else itr--;
        }
        cout << res;
    }
}

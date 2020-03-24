#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const int QQ = 3e5 + 10;
const int maxN = (1 << 21) + 100;
const int maxM = 3e5 + 100;
const long long oo = 4e18;
const int INF = 1e9 + 100;
const int MOD = 1e9 + 7;
const int Base = 311;
const long double du = 1e-9;
const string YES = "YES";
const string NO = "NO";
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

void doc() {
    freopen(INP ".inp","r",stdin);
    freopen(OUT ".out","w",stdout);
}

struct Hash {
    vector <int> value;
    Hash() {
        value.resize(300);
        map <int, int> Used;
        for (int i = 0; i < 300; i++) {
            while (true) {
                int x = rnd() % MOD;
                if (Used[x]) continue;
                value[i] = x;
                Used[x]= 1;
                break;
            }
        }
    }

    int getHash(string s) {
        int res = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i];
            assert(c >= 0 && c < 300);
            res = (1LL * res * Base + value[c]) % MOD;
        }
        return res;
    }
}hashString;
typedef pair<int, int> i2;
typedef vector<i2> i2v;
typedef pair<int, i2v> ii2v;
struct Dev {
    string company;
    int B;
    vector <string> skills;
    Dev(){};
    Dev(string _company, int _B, vector <string> _skills) {
        company = _company;
        B = _B;
        skills = _skills;
    }
};

struct PManager {
    string company;
    int B;
    PManager(){};
    PManager(string _company, int _B) {
        company = _company;
        B = _B;
    }
};

int WP(const Dev &A, const Dev &B) {
    set <int> hashA, hashB;
    for (string s : A.skills) {
        int val_hash = hashString.getHash(s);
        assert(hashA.find(val_hash) == hashA.end());
        hashA.insert(val_hash);
    }
    for (string s : B.skills) {
        int val_hash = hashString.getHash(s);
        assert(hashB.find(val_hash) == hashB.end());
        hashB.insert(val_hash);
    }
    int hashAB = 0;
    for (int x : hashA) {
        if (hashB.find(x) != hashB.end()) hashAB += 1;
    }
    return hashAB * ((int)hashA.size() + (int)hashB.size() - hashAB);
}

int WP(const PManager &A, const PManager &B) {
    return 0;
}

int WP(const PManager &A, const Dev &B) {
    return 0;
}

int WP(const Dev &A, const PManager &B) {
    return 0;
}

int BP(const Dev &A, const Dev &B) {
    int hashA = hashString.getHash(A.company);
    int hashB = hashString.getHash(B.company);
    if (hashA == hashB) return A.B * B.B;
    return 0;
}
int BP(const PManager &A, const PManager &B) {
    int hashA = hashString.getHash(A.company);
    int hashB = hashString.getHash(B.company);
    if (hashA == hashB) return A.B * B.B;
    return 0;
}
int BP(const PManager &A, const Dev &B) {
    int hashA = hashString.getHash(A.company);
    int hashB = hashString.getHash(B.company);
    if (hashA == hashB) return A.B * B.B;
    return 0;
}
int BP(const Dev &A, const PManager &B) {
    int hashA = hashString.getHash(A.company);
    int hashB = hashString.getHash(B.company);
    if (hashA == hashB) return A.B * B.B;
    return 0;
}
int TP(const Dev &A, const Dev &B) {
    return WP(A, B) + BP(A, B);
}
int TP(const PManager &A, const PManager &B) {
    return WP(A, B) + BP(A, B);
}
int TP(const Dev &A, const PManager &B) {
    return WP(A, B) + BP(A, B);
}
int TP(const PManager &A, const Dev &B) {
    return WP(A, B) + BP(A, B);
}

i2 Type[1005][1005];
int getScore(vector <string> &Map, vector <Dev> &D, vector<PManager> &PM, vector <i2> &Points) {
    int n = Map.size();
    int m = Map[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) Type[i][j] = {-1, -1};
    }
    int sizeDev = (int)D.size();
    int sizePManager = (int)PM.size();
    for (int i = 0; i < sizeDev; i++) {
        int x = Points[i].first;
        int y = Points[i].second;
        if (x == -1) continue;
        Type[x][y] = {0, i};
    }
    for (int i = 0; i < sizePManager; i++) {
        int x = Points[i + sizeDev].first;
        int y = Points[i + sizeDev].second;
        if (x == -1) continue;
        Type[x][y] = {1, i};
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (Type[i][j].first == -1) continue;
            int u = Type[i][j].second;
            for (int h = 0; h < 4; h++) {
                int x = i + dx[h];
                int y = j + dy[h];
                if (x >= 0 && x < n && y >= 0 && y < m && Type[x][y].first != -1) {
                    int v = Type[x][y].second;
                    if (Type[i][j].first == 0) {
                        if (Type[x][y].first == 0) result += TP(D[u], D[v]);
                        else result += TP(D[u], PM[v]);
                    }
                    else {
                        if (Type[x][y].first == 0) result += TP(PM[u], D[v]);
                        else result += TP(PM[u], PM[v]);
                    }
                }
            }
        }
    }
    return result;
}
ii2v solve(vector<string> &Map, vector<Dev> &D, vector<PManager> &PM) {
    int n = Map.size();
    int m = Map[0].size();
    vector <i2> Points_Dev, Points_PManager;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (Map[i][j] == '_') Points_Dev.push_back({i, j});
            if (Map[i][j] == 'M') Points_PManager.push_back({i, j});
        }
    }
    int sizeDev = (int)D.size();
    int sizePManager = (int)PM.size();

    vector <int> posDev(sizeDev);
    vector <int> posPManager(sizePManager);
    iota(posDev.begin(), posDev.end(), 0);
    iota(posPManager.begin(), posPManager.end(), 0);

    random_shuffle(posDev.begin(), posDev.end());
    random_shuffle(posPManager.begin(), posPManager.end());
    random_shuffle(Points_Dev.begin(), Points_Dev.end());
    random_shuffle(Points_PManager.begin(), Points_PManager.end());

    vector <i2> Points;
    for (int i = 0; i < sizeDev + sizePManager; i++) Points.push_back({-1, -1});
    for (int i = 0; i < min(sizeDev, (int)Points_Dev.size()); i++) {
        int id = posDev[i];
        Points[id] = Points_Dev[i];
    }
    for (int i = 0; i < min(sizePManager, (int)Points_PManager.size()); i++) {
        int id = posPManager[i];
        Points[id + sizeDev] = Points_PManager[i];
    }
    return {getScore(Map, D, PM, Points), Points};
}

vector <string> TestCase = {"a_solar", "b_dream", "c_soup", "d_maelstrom", "e_igloos", "f_glitch"};
void solve(string file) {
    fstream finp, fout;
    string fileInp = file + ".txt";
    string fileOut = file + ".out";
    finp.open(fileInp.c_str(), ios::in);
    fout.open(fileOut.c_str(), ios::out);

    clock_t time_begin = clock();
    int n, m;
    finp >> m >> n;
    vector<string> Map(n);
    for (int i = 0; i < n; i++) finp >> Map[i];

    int sizeDev;
    finp >> sizeDev;
    vector <Dev> D(sizeDev);
    for (int i = 0; i < sizeDev; i++) {
        finp >> D[i].company;
        finp >> D[i].B;
        int k;
        finp >> k;
        while (k--) {
            string s;
            finp >> s;
            D[i].skills.push_back(s);
        }
    }

    int sizePManager;
    finp >> sizePManager;
    vector <PManager> PM(sizePManager);
    for (int i = 0; i < sizePManager; i++) {
        finp >> PM[i].company;
        finp >> PM[i].B;
    }

    int best_res = 0;
    vector <i2> best(sizeDev + sizePManager);
    while ((double)(clock() - time_begin) / (double)CLOCKS_PER_SEC <= 60) {
        ii2v value = solve(Map, D, PM);
        int res = value.first;
        if (best_res < res) {
            best_res = res;
            swap(best, value.second);
        }
    }

    ///fout << best_res << endl;
    int sizeBest = sizeDev + sizePManager;
    for (int i = 0; i < sizeBest; i++) {
        if (best[i].first == -1) fout << "X";
        else fout << best[i].second << " " << best[i].first;
        if (i != sizeBest - 1) fout << '\n';
    }

    finp.close();
    fout.close();
}

int main(int argc,char *argv[]) {
    srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    ///doc();
    for (string file : TestCase) solve(file);
}

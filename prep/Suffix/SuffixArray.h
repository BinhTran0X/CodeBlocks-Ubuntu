#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e5;
string S;
int len, gap;
int suffixArray[maxN], position[maxN], ranks[maxN], LCP[maxN];
bool compare(int i, int j) {
    if (position[i] != position[j])
        return position[i] < position[j];
    i += gap;
    j += gap;
    if (i < len && j < len) {
        return position[i] < position[j];
    }
    return i > j;
}
void buildSA() {
    len = S.size();
    for (int i = 0; i < len; i++) {
        suffixArray[i] = i;
        position[i] = S[i] - 'a';
    }
    gap = 1;
    while (true) {
        sort(suffixArray, suffixArray + len, compare);
        for (int i = 1; i < len; i++)
            ranks[i] = ranks[i - 1] + compare(suffixArray[i - 1], suffixArray[i]);
        for (int i = 0; i < len; i++)
            position[suffixArray[i]] = ranks[i];
        if (ranks[len - 1] == len - 1) break;
        gap *= 2;
    }
    //for (int i = 0; i < len; i++) cout << suffixArray[i] << ' ';
}

void buildLCP() {
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (position[i] == len - 1) continue;
        int j = suffixArray[position[i] + 1];
        while (S[i + k] == S[j + k]) k++;
        LCP[position[i]] = k;
        if (k > 0) k--;
    }
}

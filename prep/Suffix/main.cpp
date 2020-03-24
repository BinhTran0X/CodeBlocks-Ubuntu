#include <bits/stdc++.h>
#include "SuffixArray.h"
#include "SuffixTree.h"

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

int main()
{
    rwFile();
    cin >> S;
    buildSA();
    /*
    for (int i = 0; i < 10; i++)
        cout << SuffixArray::suffixArray[i] << ' ';
    cout << '\n';
    for (int i = 0; i < 10; i++)
        cout << SuffixArray::position[i] << " ";
    cout << '\n';
    SuffixArray::buildLCP();
    for (int i = 0; i < 10; i++)
        cout << SuffixArray::lcp[i] << " ";
    */
    buildLCP();
    SuffixTreeNode* root = buildST();
    //cout << root->children[0]->start;
    DFS(root);
    //test();
}

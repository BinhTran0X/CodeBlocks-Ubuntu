#include <bits/stdc++.h>

using namespace std;

const int sigma = 26 + 1;

class SuffixTreeNode {
public:
    SuffixTreeNode* parent;
    SuffixTreeNode* children[sigma];
    int start, *End, depth;
    SuffixTreeNode() {
        for (int i = 0; i < sigma; i++) children[i] = NULL;
        End = new int(-1);
        parent = NULL;
        start = -1;
        depth = 0;
    }
};


SuffixTreeNode* createNewLeaf(SuffixTreeNode* node, int suffix) {
    SuffixTreeNode* leaf = new SuffixTreeNode();
    leaf->parent = node;
    leaf->depth = len - suffix;
    leaf->start = suffix + node->depth;
    *leaf->End = len - 1;
    int pos = S[leaf->start] - 'a';
    node->children[pos] = leaf;
    return leaf;
}

SuffixTreeNode* breakEdge(SuffixTreeNode* node, int start, int offset) {
    int startPos = S[start] - 'a';
    int midPos = S[start + offset] - 'a';
    SuffixTreeNode* midNode = new SuffixTreeNode();
    midNode->parent = node;
    midNode->depth = node->depth + offset;
    midNode->start = start;
    *midNode->End = start + offset - 1;
    midNode->children[midPos] = node->children[startPos];
    node->children[startPos]->parent = midNode;
    node->children[startPos]->start += offset;
    node->children[startPos] = midNode;
    return midNode;
}

SuffixTreeNode* buildST() {
    SuffixTreeNode* root = new SuffixTreeNode();
    int lcpPrev = 0;
    SuffixTreeNode* tmp = root;
    for (int i = 0; i < len; i++) {
        int suffix = suffixArray[i];
        while (tmp->depth > lcpPrev) tmp = tmp->parent;
        if (tmp->depth == lcpPrev) tmp = createNewLeaf(tmp, suffix);
        else {
            int start = suffixArray[i - 1] + tmp->depth;
            int offset = lcpPrev - tmp->depth;
            SuffixTreeNode* midNode = breakEdge(tmp, start, offset);
            tmp = createNewLeaf(midNode, suffix);
        }
        if (i < len - 1) lcpPrev = LCP[i];
    }
    return root;
}

void test() {
    cout << S;
}


void DFS(SuffixTreeNode* root) {
    int isLeaf = 1;
    for (int i = 0; i < sigma; i++) {
        if (root->children[i] != nullptr) {
            isLeaf = 0;
            DFS(root->children[i]);
        }
    }
    if (isLeaf) cout << root->start << ' ';
}


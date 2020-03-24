#include <iostream>

using namespace std;

enum BFactor { EH = 0, LH = -1, RH = 1 };

class AVLNode {
public:
    int data;
    BFactor b;
    AVLNode *left, *right;
    AVLNode() {
        this->data = -1;
        b = EH;
        left = nullptr;
        right = nullptr;
    }
    AVLNode(int data) {
        this->data = data;
        b = EH;
        left = nullptr;
        right = nullptr;
    }
};

AVLNode *rotateRight(AVLNode *root) { /// rotate right
    AVLNode *tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    return tmp;
}
AVLNode *rotateLeft(AVLNode *root) { ///rotate left
    AVLNode *tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    return tmp;
}

AVLNode *leftBalance(AVLNode *root, bool& isTaller) { /// left balance
    AVLNode *Left = root->left;
    if (Left->b == LH) {
        root->b = EH;
        root = rotateRight(root);
        Left->b = EH;
        isTaller = 0;
    }
    else {
        AVLNode *Right = Left->right;
        if (Right->b == LH) {
            root->b = LH;
            Left->b = EH;
        }
        else if (Right->b == EH) {
            Left->b = EH;
        }
        else {
            root->b = EH;
            Left->b = LH;
        }
        Right->b = EH;
        root->left = rotateLeft(Left);
        root = rotateRight(root);
        isTaller = 0;
        Right = nullptr;
    }
    Left = nullptr;
    return root;
}
AVLNode *rightBalance(AVLNode *root, bool& isTaller) { /// right balance
    AVLNode *Right = root->right;
    if (Right->b == RH) {
        root->b = EH;
        root = rotateLeft(root);
        Right->b = EH;
        isTaller = 0;
    }
    else {
        AVLNode *Left = Right->left;
        if (Left->b == RH) {
            root->b = LH;
            Right->b = EH;
        }
        else if (Left->b == EH) {
            Right->b = EH;
        }
        else {
            root->b = EH;
            Right->b = RH;
        }
        Left->b = EH;
        root->right = rotateRight(Right);
        root = rotateLeft(root);
        isTaller = 0;
        Left = nullptr;
    }
    Right = nullptr;
    return root;
}

AVLNode *Insert(AVLNode *root, int data, bool& isTaller) { /// insert
    if (root == nullptr) {
        root = new AVLNode(data);
        isTaller = 1;
        return root;
    }
    if (data >= root->data) {
        root->right = Insert(root->right, data, isTaller);
        if (isTaller) {
            if (root->b == RH) root = rightBalance(root, isTaller);
            else if (root->b == EH) root->b = RH;
            else {
                root->b = EH;
                isTaller = 0;
            }
        }
    }
    else {
        root->left = Insert(root->left, data, isTaller);
        if (isTaller) {
            if (root->b == LH) root = leftBalance(root, isTaller);
            else if (root->b == EH) root->b = LH;
            else {
                root->b = EH;
                isTaller = 0;
            }
        }
    }
    return root;
}

AVLNode *deleteRightBalance(AVLNode *root, bool& isShorter) {
    if (root->b == LH) root->b = EH;
    else if (root->b == EH) {
        root->b = RH;
        isShorter = 0;
    }
    else {
    AVLNode *Right = root->right;
        if (Right->b == LH) {
            AVLNode *Left = Right->left;
            if (Left->b == LH) {
                Right->b = RH;
                root->b = EH;
            }
            else if (Left->b == EH) {
                root->b = LH;
                Right->b = EH;
            }
            else {
                root->b = LH;
                Right->b = EH;
            }
            Left->b = EH;
            Left = nullptr;
            root->right = rotateRight(Right);
        }
        else {
            if (Right->b == RH) {
                root->b = EH;
                Right->b = EH;
            }
            else {
                root->b = RH;
                Right->b = LH;
                isShorter = 0;
            }
            root = rotateLeft(root);
        }
    }
    return root;
}

AVLNode *deleteLeftBalance(AVLNode *root, bool& isShorter) {
    if (root->b == RH) root->b = EH;
    else if (root->b == EH) {
        root->b = LH;
        isShorter = 0;
    }
    else {
        AVLNode *Left = root->left;
        if (Left->b == RH) {
            AVLNode *Right = Left->right;
            if (Right->b == RH) {
                Left->b = LH;
                root->b = EH;
            }
            else if (Right->b == EH) {
                root->b = RH;
                Left->b = EH;
            }
            else {
                root->b = RH;
                Left->b = EH;
            }
            Right->b = EH;
            root->left = rotateLeft(Left);
        }
        else {
            if (Left->b == LH) {
                root->b = EH;
                Left->b = EH;
            }
            else {
                root->b = LH;
                Left->b = RH;
                isShorter = 0;
            }
            root = rotateRight(root);
        }
    }
    return root;
}

AVLNode *Delete(AVLNode *root, int data, bool &isShorter, bool &success) { /// delete
    if (root == nullptr) {
        isShorter = 0;
        success = 0;
        return nullptr;
    }
    if (data < root->data) {
        root->left = Delete(root->left, data, isShorter, success);
        if (isShorter) root = deleteRightBalance(root, isShorter);
    }
    else if (data > root->data) {
        root->right = Delete(root->right, data, isShorter, success);
        if (isShorter) root = deleteLeftBalance(root, isShorter);
    }
    else {
        AVLNode *delNode = root;
        if (root->right == nullptr) {
            AVLNode *newRoot = root->left;
            success = 1;
            isShorter = 1;
            delete delNode;
            //delNode = nullptr;
            return newRoot;
        }
        else if (root->left == nullptr) {
            AVLNode *newRoot = root->right;
            success = 1;
            isShorter = 1;
            delete delNode;
            //delNode = nullptr;
            return newRoot;
        }
        else {
            AVLNode *tmp = root->left;
            while (tmp->right != nullptr) tmp = tmp->right;
            root->data = tmp->data;
            root->left = Delete(root->left, tmp->data, isShorter, success);
            if (isShorter) root = deleteRightBalance(root, isShorter);
        }
    }
    return root;
}

void printAVLNode(AVLNode *root) {
    if (root == nullptr) cout << "NULL\n";
    cout << root->data << " " << root->b << " " <<root->left->data << " " << root->right->data << '\n';
}

void printLNR(AVLNode *root) {
    if (root == NULL) return;
    printLNR(root->left);
    cout << root->data << " ";
    printLNR(root->right);
}

void printNLR(AVLNode *root) {
    if (root == NULL) return;
    cout << root->data << " ";
    printNLR(root->left);
    printNLR(root->right);
}

void printLRN(AVLNode *root) {
    if (root == NULL) return;
    printLRN(root->left);
    printLRN(root->right);
    cout << root->data << " ";
}

int main()
{
    AVLNode *root = new AVLNode(4);
    bool isTaller;
    bool isShorter;
    bool success;
    root = Insert(root, 3, isTaller);
    root = Insert(root, 6, isTaller);
    root = Insert(root, 7, isTaller);
    root = Insert(root, 9, isTaller);
    root = Insert(root, 5, isTaller);
    printLNR(root);
    cout << '\n';
    printNLR(root);
    cout << '\n';
    root = Delete(root, 7, isShorter, success);
    printLNR(root);
    cout << '\n';
    root = Delete(root, 9, isShorter, success);
    printLNR(root);
    cout << '\n';
    printNLR(root);
    cout <<'\n';
}

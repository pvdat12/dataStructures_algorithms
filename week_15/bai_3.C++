#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int v, Node* l = nullptr, Node* r = nullptr) {
        value = v;
        left = l;
        right = r;
    }
};

class BSTree {
private:
    Node* root;

    void makeEmpty(Node*& t) {
        if (!t) return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = nullptr;
    }

    void insert(int val1, Node*& t) {
        if (!t) {
            t = new Node(val1);
            return;
        }
        if (val1 < t->value) insert(val1, t->left);
        else if (val1 > t->value) insert(val1, t->right);
        // val1 == t->value: bỏ qua (không chèn trùng). Nếu muốn cho phép trùng, quy ước chèn sang trái/phải.
    }

    Node* search(int val2, Node* t) {
        if (!t) return nullptr;
        if (val2 == t->value) return t;
        if (val2 < t->value) return search(val2, t->left);
        return search(val2, t->right);
    }

public:
    BSTree() : root(nullptr) {}
    ~BSTree() { makeEmpty(root); }

    bool isEmpty() { return root == nullptr; }

    void makeEmpty() { makeEmpty(root); }

    void insert(int val1) { insert(val1, root); }

    Node* search(int val2) { return search(val2, root); }

    Node* getRoot() const { return root; }
};

// Traversals
void PREORDER_travl(Node* t) { // N L R
    if (!t) return;
    cout << t->value << " ";
    PREORDER_travl(t->left);
    PREORDER_travl(t->right);
}

void INORDER_travl(Node* t) { // L N R
    if (!t) return;
    INORDER_travl(t->left);
    cout << t->value << " ";
    INORDER_travl(t->right);
}

void POSTORDER_travl(Node* t) { // L R N
    if (!t) return;
    POSTORDER_travl(t->left);
    POSTORDER_travl(t->right);
    cout << t->value << " ";
}

int main() {
    BSTree bst;

    bst.insert(5);
    bst.insert(6);
    bst.insert(3);
    bst.insert(8);
    bst.insert(7);
    bst.insert(4);
    bst.insert(2);

    Node* root = bst.search(5);

    cout << "Duyet truoc (Preorder): ";
    PREORDER_travl(root);
    cout << "\nDuyet giua (Inorder):  ";
    INORDER_travl(root);
    cout << "\nDuyet sau (Postorder): ";
    POSTORDER_travl(root);
    cout << "\n";

    Node* n1 = bst.search(4);
    Node* n2 = bst.search(9);

    if (n1 != nullptr) cout << "Node co gia tri = 4 la " << n1->value << "\n";
    if (n2 == nullptr) cout << "Khong tim thay node co gia tri = 9\n";

    bst.makeEmpty();
    if (bst.isEmpty()) cout << "Cay da bi xoa rong\n";
    return 0;
}

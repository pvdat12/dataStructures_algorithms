#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    // dung cay
    void buildSampleTree() {
    root = new Node(4);

    root->left  = new Node(1);
    root->right = new Node(3);

    root->left->left  = new Node(2);
    root->left->right = new Node(16);

    root->left->left->left  = new Node(14);
    root->left->left->right = new Node(8);

    root->left->right->left = new Node(7);   

    root->right->left  = new Node(9);
    root->right->right = new Node(10);
    }


    // duyet truoc (preorder): N L R
    static void preorder(Node* t) {
        if (!t) return;
        cout << t->val << " ";
        preorder(t->left);
        preorder(t->right);
    }

    // duyet giua (inorder): L N R
    static void inorder(Node* t) {
        if (!t) return;
        inorder(t->left);
        cout << t->val << " ";
        inorder(t->right);
    }

    // duyet sau  (postorder): L R N
    static void postorder(Node* t) {
        if (!t) return;
        postorder(t->left);
        postorder(t->right);
        cout << t->val << " ";
    }

    // vun dong (max-heap)
    static void siftDown(Node* t) {
        if (!t) return;
        while (true) {
            Node* largest = t;
            if (t->left && t->left->val > largest->val) largest = t->left;
            if (t->right && t->right->val > largest->val) largest = t->right;

            if (largest == t) break;
            swap(t->val, largest->val);
            t = largest;
        }
    }

    static void heap(Node* t) {
        if (!t) return;
        heap(t->left);
        heap(t->right);
        siftDown(t);
    }

    // giai phong bo nho
    static void destroy(Node* t) {
        if (!t) return;
        destroy(t->left);
        destroy(t->right);
        delete t;
    }

    ~BinaryTree() { destroy(root); }
};

int main() {
    BinaryTree bt;
    bt.buildSampleTree();

    cout << "Preorder:  ";
    BinaryTree::preorder(bt.root);
    cout << "\nInorder:   ";
    BinaryTree::inorder(bt.root);
    cout << "\nPostorder: ";
    BinaryTree::postorder(bt.root);
    cout << "\n";

    BinaryTree::heap(bt.root);
    cout << "Preorder after heap (max-heap): ";
    BinaryTree::preorder(bt.root);
    cout << "\n";
    return 0;
}

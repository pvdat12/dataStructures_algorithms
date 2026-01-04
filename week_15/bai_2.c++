#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

bool identical(Node* a, Node* b) {
    stack<pair<Node*, Node*>> st;
    st.push({a, b});
    while (!st.empty()) {
        auto [x, y] = st.top(); st.pop();
        if (!x && !y) continue;
        if (!x || !y) return false;
        if (x->val != y->val) return false;
        st.push({x->left, y->left});
        st.push({x->right, y->right});
    }
    return true;
}

int main() {
    // Ví dụ nhỏ
    Node* t1 = new Node(1);
    t1->left = new Node(2);
    t1->right = new Node(3);

    Node* t2 = new Node(1);
    t2->left = new Node(2);
    t2->right = new Node(3);

    cout << (identical(t1, t2) ? "Giong nhau\n" : "Khac nhau\n");

    // > 100000 Nodes
    const int N = 120000;
    Node* a = new Node(0);
    Node* b = new Node(0);
    Node* pa = a;
    Node* pb = b;
    for (int i = 1; i < N; i++) {
        pa->right = new Node(i);
        pb->right = new Node(i);
        pa = pa->right;
        pb = pb->right;
    }

    auto start = chrono::high_resolution_clock::now();
    bool ok = identical(a, b);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms = end - start;

    cout << "Nodes = " << N << "\ntime = " << ms.count() << " ms\n";

    return 0;
}

#include <iostream>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;

template <class T> class BinaryTree {
private:

    struct node {
        node *left, *right;
        T data;

        node () : left(NULL), right(NULL) {}
        node (T x) : left(NULL), right(NULL), data(x) {}

    };

    node *root;
    size_t size = 0;

    void p_add (node*& cur, T x);
    bool p_find (node* cur, T x);

public:

    void add (T x);
    bool find (T x);
    size_t getSize () { return size; }

    void tree_to_array(node* tree, T a[]);
    void sort_tree(T a[], int elem_total);
};

template <class T> void BinaryTree <T> :: p_add (node*& cur, T x) {
    if (!cur) {
        cur = new node (x);
        return;
    }
    if (x < cur->data) {
        if (!cur->left)
            cur->left = new node (x);
        else
            p_add (cur->left, x);
    }
    else if (x > cur->data) {
        if (!cur->right)
            cur->right = new node (x);
        else
            p_add (cur->right, x);
    }
}

template <class T> bool BinaryTree <T> :: p_find (node* cur, T x) {
    if (!cur)
        return false;
    if (x < cur->data) {
        if (!cur->left)
            return false;
        return p_find (cur->left, x);
    }
    else if (x > cur->data) {
        if (!cur->right)
            return false;
        return p_find (cur->right, x);
    }
    return true;
}

template <class T> void BinaryTree <T> :: add (T x) {
    size++;
    p_add (root, x);
}

template <class T> bool BinaryTree <T> :: find (T x) {
    return p_find (root, x);
}

template <class T> void BinaryTree <T> :: tree_to_array(node* tree, T a[]) {
    static int max2 = 0;                 // счетчик элементов нового массива
    if (tree == NULL) return;            // условие окончания - нет сыновей
    tree_to_array(tree->left, a);       // обход левого поддерева
    a[max2++] = tree->data;
    tree_to_array(tree->right, a);      // обход правого поддерева
}

template <class T> void BinaryTree <T> :: sort_tree(T a[], int elem_total) {
    node *root = NULL;
    for (int i = 0; i < elem_total; i++) {        // проход массива и заполнение дерева
        p_add(root, a[i]);
        size++;
    }
    tree_to_array(root, a);             // заполнение массива
}

int main () {
    srand((unsigned int)time(0));
    
    BinaryTree <int> myTree;

    int a[14]={0,7,8,3,52,14,16,18,15,13,42,30,35,26};

    myTree.sort_tree(a, 14);

    cout << "Sorted array of int variables:\n";
    for (int i = 0; i < 14; i++)
        cout << a[i] << " ";
    cout << endl;


    BinaryTree<string> stringTree;

    string arrayStrings[2] = {"world!", "hello"};

    stringTree.sort_tree(arrayStrings, 2);

    cout << "Sorted array of string instances:\n";
    for (int i = 0; i < 2; i++)
        cout << arrayStrings[i] << " ";
    cout << endl;

    return 0;
}


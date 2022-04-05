#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node (int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* build () {
    string input;
    cin >> input;

    node* root = NULL;

    try {
        int value = stoi(input);
        root = new node(value);
    } catch (exception) {
        return root;
    }

    root->left = build();
    root->right = build();

    return root;
}

void preorder(node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << ", ";
    preorder(root->left);
    preorder(root->right);

    return;
}

void inorder(node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << ", ";
    inorder(root->right);

    return;
}

void postorder(node* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << ", ";

    return;
}

int main()
{
    node* root = build();
    preorder(root);
    cout << endl;

    inorder(root);
    cout << endl;

    postorder(root);
    cout << endl;

    return 0;
}
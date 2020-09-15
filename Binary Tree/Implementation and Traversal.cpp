#include <iostream>

struct Node{
    int key;
    Node *left, *right;
    Node(int k){
        key = k;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        std::cout<<root->key<<" ";
        inorder(root->right);
    }
}

void preorder(Node *root){
    if(root!=NULL){
        std::cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        std::cout<<root->key<<" ";
    }
}


int main(){
    // making a tree
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    // traversing the tree
    std::cout<<"Inorder Traversal: ";
    inorder(root);
    std::cout<<"\nPreorder Traversal: ";
    preorder(root);
    std::cout<<"\nPostorder Traversal: ";
    postorder(root);

    return 0;
}

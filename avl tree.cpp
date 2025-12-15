#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    int height;
    public:
    Node(int val){
        data=val;
        left=right=nullptr;
        height=1;
    }
};
int height(Node* n){
    return (n==nullptr)?0:n->height;
}

int getBalance(Node* n){
    return (n==nullptr)?0:height(n->left)-height(n->right);
}
int max(int a,int b){
    return (a>b)?a:b;
}
Node* rightRotate(Node* y){
    Node* left=y->left;
   Node* t2=left->right;
   left->right=y;
   y->left=t2;

   y->height=1+max(height(y->left),height(y->right));
   left->height=1+max(height(left->left),height(left->right));
   return left;

}
Node* leftRotate(Node* y){
    Node* right=y->right;
    Node* t2=right->left;

    right->left=y;
    y->right=t2;

    y->height=1+max(height(y->left),height(y->right));
    right->height=1+max(height(right->left),height(right->right));
    return right;
}
Node* insert(Node* node,int key){
    if(node==nullptr)return new Node(key);
    if(key<node->data)
    node->left=insert(node->left,key);
    else  if(key>node->data)
    node->right=insert(node->right,key);
    else return node;

    node->height=1+max(height(node->left),height(node->right));
    int balance=getBalance(node);

    if(balance>1 && key<node->left->data)
    return rightRotate(node);

    if(balance<-1 && key>node->right->data)return leftRotate(node);

    if(balance>1 && key>node->left->data){
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }
    if(balance<-1 && key<node->right->data){
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }
    return node;

}
void inorder(Node* root){
    if(!root)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);   
}

int main() {
    Node* root=nullptr;
    int ch;
    do{
        cout << "\n--- AVL TREE ---\n";
        cout << "1. Insert\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            int val;
            cout<<"Enter value: ";
            cin>>val;
           root= insert(root,val);
            cout<<"Inserted !";
            break;
        
            case 2:
            inorder(root);
            break;
            case 3:
            cout<<"exiting !";
            break;
        default:
            break;
        }
    }while(ch!=3);

    return 0;
}

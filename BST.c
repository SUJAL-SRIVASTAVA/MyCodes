#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *right;
    struct node *left;
};

struct node *createnew(int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

struct node *insertionbst(struct node *root,int data){
    if(root==NULL)
        return createnew(data);
    else if(data<root->data)
        root->left=insertionbst(root->left,data);
    else
        root->right=insertionbst(root->right,data);
    return root;
}

void inorder(struct node *root){
    if (root == NULL)  
        return; 
    inorder(root->left);
    printf("%d \t",root->data);
    inorder(root->right);
}

int main(){
  struct node* root = NULL;  
  root = insertionbst(root, 45);  
  root = insertionbst(root, 30);  
  root = insertionbst(root, 50);  
  root = insertionbst(root, 25);  
  root = insertionbst(root, 35);  
  root = insertionbst(root, 60);  
  root = insertionbst(root, 4); 
  printf("inorder traversal- \n"); 
  inorder(root);  
    
    return 0;
}

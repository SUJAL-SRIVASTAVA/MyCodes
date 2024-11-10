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


struct node * search(struct node *root,int data){
    struct node *t=root;
    while(t!=NULL){
        if(data==t->data){
            return t;
        }
        else if(data<t->data){
            t=t->left;
        }
        else if(data>t->data){
            t=t->right;
        }

    }
    return t;
}

    
struct node* findMin(struct node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node* deleteNode(struct node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
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
   printf("\n");
  struct node* temp=search(root,30);
  if(temp!=NULL){
      printf("Element found \n");
  }
  else{
      printf("Not found\n");
  }
  temp=search(root,12);
  if(temp!=NULL){
      printf("Element found\n");
  }
  else{
      printf("Not found\n");
  }
  temp=search(root,14);
  if(temp!=NULL){
      printf("Element found\n");
  }
  else{
      printf("Not found\n");
  }
  deleteNode(root,60);
  printf("inorder traversal- \n"); 
  inorder(root);
  printf("\n");
  deleteNode(root,35);
  printf("inorder traversal- \n"); 
  inorder(root);
  
    
    return 0;
}

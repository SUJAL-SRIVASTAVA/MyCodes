#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *r=NULL;
struct node *f=NULL;

void enquer(int value){
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=value;
    ptr->link=NULL;
   
    if(f==NULL){
        f=r=ptr;
    }
    else{
        r->link=ptr;
        r=ptr;
    }
}

void enquef(int value){
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=value;
    ptr->link=NULL;
    if(f==NULL){
        f=r=ptr;
    }
    else{
        ptr->link=f;
        f=ptr;
    }
}


void dequeuef(){
    if(f==NULL){
        printf("Queue underflow");
        return;
    }
    if(f==r){
            f=r=NULL;
            printf("Queue is empty now\n");
        }
    else{
            struct node *ptr;
            ptr=f;
            f=f->link;
            free(ptr);
        }
}

void dequeuer(){
    if(f==NULL){
        printf("Queue underflow");
        return;
    }
    if(f==r){
            free(r);
            f=r=NULL;
            printf("Queue is empty now");
        }
    else{
            struct node *ptr,*ptr2;
            ptr=f;
            while(ptr->link->link!=NULL){
                ptr=ptr->link;
            }
            ptr2=r;
            r=ptr;
            r->link=NULL;
            free(ptr2);
        }
   
   
   
}
void display(){
    struct node *ptr=f;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        printf("\n");
        ptr=ptr->link;
    }
    printf("\n");
}

int main() {
    enquer(5);
    enquer(8);
    enquer(7);
    enquer(9);
    enquef(1);
    enquef(3);
    dequeuef();
    dequeuer();
    dequeuef();
    dequeuer();
    display();
   
    return 0;
}

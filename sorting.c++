#include <iostream>
using namespace std;

    
    
void selection(int a[],int n){
    for(int j=0;j<n;j++){
        int  min=j;
        for(int i=j+1;i<n;i++){
            if(a[i]<a[min]) min=i;
        }
        swap(a[j],a[min]);
        }
}


void bubble(int a[],int n){
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(a[j+1]<a[j]) 
                swap(a[j+1],a[j]);
        }
    }
    
}


void insertion(int a[],int n){
    int i,j;
    for(i=1;i<n;i++){
        int item=a[i];
        for(j=i-1;(j>=0) && (a[j]>item);j--){
            a[j+1]=a[j];
        }
        a[j+1]=item;
    }
    
}

int main() {
    int n=7;
    int a[]={1,8,6,3,4,2,5};
    insertion(a,n);
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<'\t';
    }
    
    
    return 0;
}

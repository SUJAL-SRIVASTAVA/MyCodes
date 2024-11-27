#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[]={1,2,5,8,6,3};
    int key,i,flag=0;
    cin>>key;
    
    for(i=0;i<6;i++){
        if(a[i]==key){
            flag=1;
            break;
        }
    }
    
    if(flag==0){
        cout<<"element not found";
    }
    else{
        cout<<"element found at index ="<<i;
    }

    return 0;
}






int main(){
    int n=7,flag=0;
    int a[]={1,2,8,9,6,3,4};
    int l=0;
    int r=n-1;
    int m=(l+r)/2;
    int key;
    cin>>key;
    
    
    
    sort(a,a+n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<'\t';
    }
    
  while(l<=r){  
    if(key==a[m]){
        flag=1;
        break;
    }
    else if(key<a[m]){
        r=m-1;
    }
    else{
        l=m+1;
    }
    m=(l+r)/2;
  }
  
  if(flag==0){
      cout<<"element not found";
  }
  else{
      cout<<"element found at index "<<m;
  }
    
    return 0;
}







int binary(int a[],int n,int key,int l,int r){
    int m=(l+r)/2;
    
    if(l<=r){
        if(key==a[m]){
            return 1;
        }
        else if(key<a[m]){
            return binary(a,n,key,l,m-1);
        }
        else{
            return binary(a,n,key,m+1,r);
        }
            
    }
    else{
        return 0;
    }
}
int main(){
    int flag=0;
    int a[]={1,5,8,6,3,2,7};
    int n=sizeof(a)/sizeof(a[0]);
    int l=0;
    int r=n-1;
    int key,m;
    cin>>key;
    
    
    sort(a,a+n);
    flag=binary(a,n,key,l,r);
    if(flag==0){
        cout<<"element not found";
    }
    else{
        cout<<"element found";
    }
    
    
    return 0;
}

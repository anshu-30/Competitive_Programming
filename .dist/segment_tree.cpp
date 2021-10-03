#include <bits/stdc++.h>
using namespace std;
//for sum
const int N=1e5+2;
int tree[4*N];
int sum(int a,int b) 
{
    return a+b;
}
void build(int arr[],int i,int j,int node){
    if(i==j){
        tree[node]=arr[i];
        return ;
    }
    int m=(i+j)/2;
    build(arr,i,m,2*node);
    build(arr,m+1,j,2*node+1);
    tree[node]=sum(tree[2*node],tree[2*node+1]);
}
int query(int node,int st,int en,int l,int r){
    if(r<st || l>en) return 0; //no
    if(st>=l && en<=r) return tree[node]; //full
    //partial
    int mid=(st+en)/2;
    return query(2*node,st,mid,l,r)+query(2*node+1,mid+1,en,l,r);

}
void update(int node,int st,int en,int index,int value){
    if(st==en) {
        tree[node] = value;
        return;
    }
    if(index<st || index>en) return;
    int mid=(st+en)/2;
    update(2*node,st,mid,index,value);
    update(2*node+1,mid+1,en,index,value);
    tree[node]=tree[2*node]+tree[2*node+1];
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    build(arr,0,n-1,1);
    for(int i=1;i<=15;i++) cout<<tree[i]<<" ";
    cout<<endl;
    int q;
    cin>>q;
    while(q--){
        int a;
        cin>>a;
        if(a==1){
            //query
            int l,r;
            cin>>l>>r;
            cout<<query(1,0,n-1,l,r)<<endl;
        }
        if(a==2){
            //update
            int index,value;
            cin>>index>>value;
            update(1,0,n-1,index,value);
            for(int i=1;i<=15;i++) cout<<tree[i]<<" ";
            cout<<endl;
        }
    }
}

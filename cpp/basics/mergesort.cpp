#include <bits/stdc++.h>
using namespace std;

void merge(int arr[],int l,int m,int r){
    int left=l;
    int right=m+1;
    vector<int> ans;
    while(left<=m && right<=r){
        if(arr[left]<arr[right]){
            ans.push_back(arr[left]);
            left++;
        }
        else{
            ans.push_back(arr[right]);
            right++;
        }
    }
    while(left<=m){
        ans.push_back(arr[left]);
        left++;
    }
    while(right<=r){
        ans.push_back(arr[right]);
        right++;
    }
    // for(auto i:ans) cout<<i<<" ";
    // cout<<endl;
}

void mergesort(int arr[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}


int main(){
    int arr[]={5,7,6,1,2,3};
    mergesort(arr,0,5);
    
}
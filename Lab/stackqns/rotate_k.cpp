#include<bits/stdc++.h>
using namespace std;

vector<int> rev(vector<int>&arr,int l,int r){
    while(l<r){
        swap(arr[l],arr[r]);
        l++;
        r--;
    }
    return arr;
}

vector<int> rev_k(vector<int>&arr, int k){
    rev(arr,0,k-1);
    rev(arr,k,arr.size()-1);
    rev(arr,0,arr.size()-1);
    return arr;
}

int main(){
    vector<int>arr={1,2,3,4,5,6,7};
    int k;
    cin>>k;
    arr=rev_k(arr,k);
    for(auto i:arr) cout<<i<<" ";
}   
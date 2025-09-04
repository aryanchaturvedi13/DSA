#include <bits/stdc++.h>
using namespace std;

int max_sum(vector<int> &arr){
    int sum=0;
    int maxi=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
        }
        else if(sum<0) sum=0;
    }
    return maxi;
}


int main(){
    vector<int> arr={2,3,-8,7,-1,2,3};
    vector<int> arr2={-1,-1,-1,-1,7,1,-1,-1};
    vector<int> arr3={1,1,1,1,1,-5};
    int maxi=max_sum(arr3);
    cout<<maxi;
}
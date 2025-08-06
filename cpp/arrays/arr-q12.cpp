#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
//q12 find the number that appears once 
int main() {
    int n;
    cin >> n;
    int arr[n];
    int m=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //BRUTE 
    // for(int i=0;i<n;i++){
    //     m=max(m,arr[i]);
    // }
    // int hash[m+1]={0};
    // for(int i=0;i<n;i++){
    //     hash[arr[i]]+=1;
    // }

    // for(int i=0;i<m+1;i++){
    //     if(hash[i]==1) {
    //         cout<<i;
    //         break;
    //     }
    // }

    //BETTER 
    // map<int,int>mpp;
    // for(int i=0;i<n;i++){
    //     mpp[arr[i]]+=1;
    // }
    // for(auto i:mpp){
    //     if(i.second==1) {
    //         cout<<i.first;
    //         break;
    //     } 
    // }

    //OPTIMAL
    //use XOR 
    int XOR=0;
    for(int i=0;i<n;i++){
        XOR=XOR^arr[i];
    }
    cout<<XOR;

}
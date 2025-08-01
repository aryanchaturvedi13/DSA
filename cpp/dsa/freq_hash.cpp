#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


    map <int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    int maxval=0;
    for(auto &i:mpp){
        maxval=max(maxval,i.second);
    }

    vector<int>maxkey;
    for(auto &i:mpp){
        if(maxval==i.second) maxkey.push_back(i.first);
    }

    cout<<maxkey[0];


}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[a[i]]++;
        }
        int found=0;
        for(auto i:mp){
            if(i.second>1){
                cout<<"YES"<<endl;
                found=1;
                break;
            }
        }
        if(found==0) cout<<"NO"<<endl;
    }
    return 0;
}
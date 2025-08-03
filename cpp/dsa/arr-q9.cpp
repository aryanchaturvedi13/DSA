#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

//find union and intersection of sorted arrays 
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++) cin>>b[i];
    //BRUTE 
    //union
    // set<int> uni;
    // for(auto i:a) uni.insert(i);
    // for(auto i:b) uni.insert(i);

    // vector <int> unio;
    // for(auto i:uni) unio.push_back(i);

    // for(auto i:unio) cout<<i<<" ";
    // cout<<endl;
    // //intersection
    // vector<int> both;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(a[i]==b[j]) both.push_back(a[i]);
    //     }
    // }

    // for(auto i:both) cout<<i<<" ";

    //OPTIMAL
    // tc=o(n+m)
    // sc=o(n+m)
    vector<int> uni;
    int i=0;
    int j=0;
    uni.push_back(min(a[0],b[0]));
    
    while(i<n && j<m){
        int x=min(a[i],b[j]);
        if(x!=uni.back()){
            uni.push_back(x);
            if(a[i]>=b[j]) j++;
            else i++;
        }
        else if(x==uni.back()) {
            if(x==a[i]) i++;
            else j++;
        }
    }
    while (i<n){
        uni.push_back(a[i]);
        i++;
    }

    while(j<m){
        if(uni.back()!=b[j]){
            uni.push_back(b[j]);
        }
        j++;
    }

    for(auto i:uni) cout<<i<<" ";
    
}
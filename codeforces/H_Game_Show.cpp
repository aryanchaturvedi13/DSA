#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    int x=100;
    int maxi=100;
    for(int i = 0; i < t; i++) {
        int k;
        cin>>k;
        maxi=max(maxi,x+k);
        x+=k;
    }
    cout<<maxi<<endl;
    return 0;
}
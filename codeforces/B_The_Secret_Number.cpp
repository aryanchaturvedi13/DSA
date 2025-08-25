#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n;
        cin>>n;
        if(n==0){
            cout<<0<<endl;
            break;
        }
        else{
        vector<long long> x;
        long long p=10;
        while(n>=(p+1)){
            if(n%(p+1)==0){
                x.push_back(n/(p+1));
            }
            p=p*10;
        }

        cout<<x.size()<<endl;
        reverse(x.begin(),x.end());
        for(auto i:x) cout<<i<<" ";
        if(x.size()!=0) cout<<endl;
    }
    }
    return 0;
}

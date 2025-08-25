#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        long long k;
        cin>>k;
        long long sum=0;

        if(k<10){
            while(k>0){
                sum+=k;
                k--;
            }
        }
        
        cout<<sum<<endl;
    }
    return 0;
}
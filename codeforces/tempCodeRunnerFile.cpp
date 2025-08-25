#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n;
        long long x;
        int k=0;
        long long p=1;

        while(n%(p+1)==0){
            k++;
            p*=10;
        }
        cout<<k<<endl;

        if(k!=0){
            while(p>1){
                x=n/(p+1);
                cout<<x<<" ";
                p=p/10;
            }
        }
        cout<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin>>n;
        long long g[n];
        for(int i=0;i<n;i++) cin>>g[i];
        sort(g,g+n);
        long long em=0;
        int l=n-2;
        int r=n-1;
        int com=0;
        if (all_of(g, g + n, [&](long long x){ return x == g[0]; })) {
            if(n%2==0) cout<<(n/2)*g[0]<<endl;
            else cout <<(n/2+1)*g[0]<<endl;
            com=1;
        }
        while(l>=0 && r>=1){
            em+=max(g[l],g[r]);
            long long c=g[l];
            g[l]-=min(g[l],g[r]);
            g[r]-=min(c,g[r]);
            l=l-2;
            r=r-2;
        }
        if(com==0) cout<<em+g[0]<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int B=d-b;
        int A=c-a;
        if(max(a,b)/2-1+(max(a,b)%2)<=min(a,b)) cout<<"YES"<<endl;
        else if(max(A,B)/2-1+max(A,B)%2<=min(A,B)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
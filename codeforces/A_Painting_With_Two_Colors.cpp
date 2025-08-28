#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n,a,b;
        cin>>n;
        cin>>a;
        cin>>b;
        int arr[n];
        for(int j=0;j<n;j++) arr[j]=-1;
        
        for(int j=n/2-1;j<n/2+a-1;j++){
            arr[j]=0;
        }
        for(int j=n/2-1;j<n/2+b-1;j++){
            arr[j]=1;
        }
        int k=0;
        for(int j=0;j<n/2;j++){
            if(arr[j]!=arr[n-j-1]) {
                cout<<"NO"<<endl;
                break;
            }
            else k++;
        }
        if(k==n/2-1) cout<<"YES"<<endl;
    }
    return 0;
}
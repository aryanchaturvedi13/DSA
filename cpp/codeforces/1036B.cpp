#include <iostream>
using namespace std;

int main() {
int t;
cin >> t;
for(int i = 0; i < t; i++) {
    int n;
    cin>>n;
    int a[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }

    cout<<sum;
}
    return 0;
}
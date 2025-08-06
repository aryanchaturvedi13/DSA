#include <iostream>
using namespace std;

//q8 linear search: t=return the index where a given element occurs first
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int k;
    cin>>k;
    int c=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==k) {
            c=i;
            cout<<c;
            break;
        }
    }
    if(c==-1) cout<<-1;
}

//return statement indiacates the completion of code in the func. so return is used in cases where we need to stop the code after a single particular iteration. 
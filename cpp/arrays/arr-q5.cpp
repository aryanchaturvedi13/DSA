#include <iostream>
using namespace std;
int main() {
    //q5: rotate array by one place 
    //TC=O(N)
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int temp=arr[0];
    for(int i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;

    for(auto i: arr) cout<<i<<" ";
}
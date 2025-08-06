#include <iostream>
#include <algorithm>
// q10 missing number 
using namespace std;
int main() {
    //BRUTE 
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    // int c=-1;
    // sort(arr,arr+n);
    // int nums[n];
    // for(int i=0;i<n;i++) nums[i]=i+1;

    // for(int i=0;i<n;i++){
    //     if(arr[i]!=nums[i]) {
    //         c=i+1;
    //         break;
    //     }
    // }

    // cout<<c;

    //OPTIMAL
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(arr[i]!=i){
            cout<<i;//return i;
            break;
        }
    }
    cout<<n;// return n;

}
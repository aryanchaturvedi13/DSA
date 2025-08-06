#include <iostream>
#include <algorithm>

//q7 shift zeros to end 

using namespace std;
void rev(int *arr, int low, int high){
    while(low<high){
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    //works for positive entries 
    // int cnt=0;
    // for(int i=0;i<n;i++){
    //     if(arr[i]==0) cnt++;
    // }

    // sort(arr,arr+n-1);

    // rev(arr,0,cnt-1);
    // rev(arr,cnt,n-1);
    // rev(arr,0,n-1);

    //for neg entries
    // sort(arr,arr+n);
    // while(zero<last){
    //     if(arr[zero]==0) {
    //         swap(arr[zero],arr[last]);
    //         zero++;
    //         last--;
    //     }
    //     else zero++;
    // }

    // while(zero<last){
    //     if(arr[zero]==0){
    //         swap(arr[zero],arr[last]);
    //         zero++;
    //         last--;
    //     }
    //     else zero++;
    // }

    //best soln 
    // tc=o(n) sc=o(1)
    int first=0;
    int next=1;
    while(next<n){
        if(arr[first]==0 && arr[next]!=0){
            swap(arr[first],arr[next]);
            first++;
            next++;
        }
        else if(arr[first]==0 && arr[next]==0){
            next++;
        }
        else {
            first++;
            next++;
        }
    }

    for(auto i: arr) cout<<i<<" ";

}
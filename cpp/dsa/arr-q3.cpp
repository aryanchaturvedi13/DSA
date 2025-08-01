#include <iostream>
using namespace std;
int main(){
    //q3: check if array is sorted
    //TC=O(N)
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int cnt=0;
    for(int i=1;i<n-1;i++){
        if(arr[i]>=arr[i-1] && arr[i]<=arr[i+1]) cnt++;
    }
    if(cnt==n-2) cout<<"sorted";
    else cout<<"not sorted";
}
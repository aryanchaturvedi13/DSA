#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
           if(arr[i-j-1]>arr[i-j]) swap(arr[i-j-1],arr[i-j]);
           cout<<"run\n";
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
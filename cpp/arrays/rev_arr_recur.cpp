#include <iostream>
using namespace std;
 
void rev(int a, int arr[], int n){
        if(a>=n/2) return;
        swap(arr[a],arr[n-a-1]);
        rev(a+1,arr,n);
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    
    rev(0,arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}
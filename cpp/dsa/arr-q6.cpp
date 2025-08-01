#include <iostream>
using namespace std;

void rev(int* arr, int low,int n){
    for(int i=low;i<n/2;i++){
        swap(arr[i],arr[n-i-1]);
    }
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int d;
    cin>>d;
    //brute 
    // for(int i=0;i<d%n;i++){
    //     int temp=0;
    //     temp=arr[0];
    //     for(int j=0;j<n;j++){
    //         arr[j]=arr[j+1];
    //     }
    //     arr[n-1]=temp;
    // }

    // for(auto i:arr){
    //     cout<<i<<" ";
    // }
        //OR
    // int temp[d];
    // for(int i=0;i<d;i++){
    //    temp[i]=arr[i];
    // }
    // for(int i=d;i<n;i++){
    //     arr[i-d]=arr[i];
    // }
    // for(int i=n-d;i<n;i++){
    //     arr[i]=temp[i-n+d];
    // }
    // for(auto i:arr) cout<<i<<" ";

    //optimal
    rev(arr,0,d);
    //rev(arr,d,n);
    rev(arr,0,n);

    for(auto i:arr) cout<<i<<" ";
}
#include <iostream>
using namespace std;

void rev(int *arr, int low,int high){
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

    int d;
    cin>>d;
    //brute 
    for(int i=0;i<d%n;i++){
        int temp=0;
        temp=arr[0];
        for(int j=0;j<n;j++){
            arr[j]=arr[j+1];
        }
        arr[n-1]=temp;
    }

    for(auto i:arr){
        cout<<i<<" ";
    }
        //OR
    int temp[d];
    for(int i=0;i<d;i++){
       temp[i]=arr[i];
    }
    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }
    for(int i=n-d;i<n;i++){
        arr[i]=temp[i-n+d];
    }
    for(auto i:arr) cout<<i<<" ";

    //optimal
    //TC=O(N), SC=O(1)
    rev(arr,0,d-1);
    rev(arr,d,n-1);
    rev(arr,0,n-1);
    for(auto i:arr) cout<<i<<" ";
}
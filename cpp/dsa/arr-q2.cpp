#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    //q2: second largest element 
    // optimal: TC=O(N);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int largest=arr[0];
    int s_largest=-1;
    for(int i=0;i<n;i++){
        if(largest<arr[i]){
            s_largest=largest;
            largest=arr[i];
        }
        else if(largest>arr[i] && s_largest<arr[i]){
            s_largest=arr[i];
        }
    }
    cout<<s_largest;
    }
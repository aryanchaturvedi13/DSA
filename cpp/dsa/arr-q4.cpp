#include <iostream>
#include <set>
using namespace std;
int main() {
    //q4: remove duplicates from sorted arr
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    //brute 
    //TC= O(NlogN+N)
    //SC=O(N)
    // set<int> st;
    // for(int i=0;i<n;i++){
    //     st.insert(arr[i]);
    // }
    // int point=0;
    // for(auto i:st){
    //     arr[point]=i;
    //     point++;
    // }
    // for(auto i:arr) cout<<i<<" ";

    // cout<<endl<<point<<" unq elements";

    //optimal
    //TC=O(N)
    int i=0;
    int j=1;
    int unq=1;
    while(i<n-1 && j<n){
        if(arr[i]==arr[j]){
            j++;
        }
        else {
            i++;
            arr[i]=arr[j];
            j++;
            unq++;
        }
    }

    cout<<unq<<" unq\n";
    for(auto i:arr) cout<<i<<" ";
}
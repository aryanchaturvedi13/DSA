#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int cnt=0;
    int max_cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1) {
            cnt++;
            max_cnt=max(cnt,max_cnt);
        }
        else cnt=0;
    }

    cout<<max_cnt;

}
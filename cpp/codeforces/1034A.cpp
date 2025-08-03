#include <iostream>
#include <vector>
using namespace std;

int main() {
int t;
cin >> t;
int n;
int c;
for(int i = 0; i < t; i++) {
        cin>>n;
        vector<int> arr;
        for(int j=n-1;j>=0;j--){
            arr.push_back(j);
        }
        
        for(int a=0;a<n;a++){
            arr.erase(arr.begin()+a);
            for(int b=a;b<n;b++){
                
            }
        }

        if(c==1) cout<<"bob\n";
        else cout<<"alice\n";
}
    return 0;
}
#include <iostream>
#include <vector> 
using namespace std;
int main() {
    int n;
    cin>>n;
    int sum=0;
    vector<int> divs;
    for(int i=1;i<=n;i++){
        if(n%i==0) {
         divs.push_back(i);
         sum=sum+i;
        }
    }
    cout<<sum;
}
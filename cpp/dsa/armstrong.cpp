#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int n;
    int count=0;
    vector <int> dgts;
    cin>>n;
    int temp=n;
    while(temp>0){
        count++;
        dgts.push_back(temp%10);
        temp=temp/10;
    }
    int x=0;
    for(int i=0;i<count;i++){
        x+=round(pow(dgts[i],count));
    }

    if(x==n) cout<<"true"<<endl;
    else cout<<"false"<<endl;
}
#include <iostream>
using namespace std;

int main() {
int t;
cin >> t;
for(int i = 0; i < t; i++) {
    int x;
    cin>>x;
    int a=x;
    int cnt=0;
    while(x>0){
        cnt++;
        x=x/10;
    }
    int dgt[cnt]={0};
    for(int i=0;i<cnt;i++){
        dgt[i]=a%10;
        a=a/10;
    }

    for(int i=0;i<cnt-1;i++){
        for(int j=i+1;j<cnt;j++){
            if(dgt[i]>dgt[j]) swap(dgt[i],dgt[j]);
        }
    }

    cout<<dgt[0];
}
    return 0;
}
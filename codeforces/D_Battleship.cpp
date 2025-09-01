#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    bool k=true;
    cin >> t;
    for(int i = 0; i < t; i++){
        int d,l,r,c;
        cin >>d>>l>>r>>c;
        if(c+l-1>10||r+l-1>10)k=false;
        bool arr[10][10];
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                arr[i][j]=false;
            }
        }
        if(d==0){
            for(int i=c-1;i<c+l-1;i++){
                if(arr[r-1][i] == true) {
                    k=false;
                }
                arr[r-1][i]=true;
            }
        }
        else if(d==1){
            for(int i=r-1;i<r+l-1;i++){
                if(arr[i][c-1]==true){
                    k=false;
                }
                arr[i][c-1]=true;
            }
        }
    }
    cout<<(k==true?"Y":"N");
    return 0;
}
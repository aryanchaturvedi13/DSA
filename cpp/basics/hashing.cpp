#include <iostream>
#include <map>
using namespace std;
int main() {
    int arr[4]={1,2,5,1};

    map<int,int> mpp;
    for (int i=0;i<4;i++){
        mpp[arr[i]]++;
    }

    for(int i=0;i<6;i++){
        cout<<mpp[i]<<endl;
    }

}
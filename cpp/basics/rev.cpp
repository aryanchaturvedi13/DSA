#include <iostream>
using namespace std;
int main() {
    int x;
    cin>>x;
    int rev_x=0;
    while(x>0){
        int lastdgt=x%10;
        rev_x=(rev_x*10)+lastdgt;
        x=x/10;
    }

    cout<<rev_x;
    return 0;
}
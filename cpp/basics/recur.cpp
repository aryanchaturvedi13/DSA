#include <iostream>
#include <string>
using namespace std;
 
void ispalin(string s,int i) {
    int n=s.size();
    if(i>=n/2) {
        cout<<"is a palin";
        return;
    }
    else{
        if(s[i]==s[n-i-1]) ispalin(s,i+1);
        else cout<<"not a palin";
    }
}

int main(){
    string s;
    cin>>s;
    ispalin(s,0);
    return 0;
}
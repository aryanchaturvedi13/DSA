/*

#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin>>s;

    int hash[256]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]]+=1;
    }

    int q;
    cin>>q;
    while(q--){
        char x;
        cin>>x;
        cout<<hash[x]<<endl;
    }
}

*/

#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    string s;
    cin>>s;

    map<char,int> mpp;
    for(int i=0;i<s.size();i++){
        mpp[s[i]]+=1;
    }

    int q;
    cin>>q;
    while(q--){
        char x;
        cin>>x;
        cout<<mpp[x]<<endl;
    }
}
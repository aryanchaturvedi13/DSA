#include <iostream>
#include <string>
using namespace std;

void ispalin(string s, int i){
    string a=s;
    int n=s.size();
    if(i>n/2) {
        if(a==s) {
            cout<<"true";
        }
        else cout<<"false";
        return;
    }
    swap(a[i],a[n-i-1]);
    ispalin(s,i+1);
}

int main() {
    string s;
    cin>>s;
    ispalin(s,0);
}


// int main() {
//     string s,rev_s;
//     cin>>s;
//     int n=s.size();

//     for(int i=0;i<n;i++){
//         rev_s[i]=s[n-i-1];
//     }

//     for(int i=0;i<n;i++){
//         cout<<rev_s[i];
//     }

// }

// int main() {
//     string s="aryan";
//     int n=s.size();
//     for(int i=0;i<n/2;i++){
//         swap(s[i],s[n-i-1]);
//     }

//     for(int i=0;i<n;i++){
//         cout<<s[i];
//     }
// }
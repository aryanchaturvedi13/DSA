#include <bits/stdc++.h>
using namespace std;

bool isvalid(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(' || s[i]=='{') st.push(s[i]);
        else if(s[i]==')'){
            if(st.top()='(') st.pop();
            else return false;
        }
        else if(s[i]=='}'){
            if(st.top()=='{') st.pop();
            else return false;
        }
    }
    if(st.empty()) return true;
    else return false;
}



int main(){
    string s="(){}{{}()}";
    cout<<isvalid(s);

}
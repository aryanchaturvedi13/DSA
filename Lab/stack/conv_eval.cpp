#include <bits/stdc++.h>
using namespace std;

int priority(char s){
    if(s=='^') return 3;
    else if(s=='*' || s=='/') return 2;
    else if(s=='+' || s=='-') return 1;
    else return -1;
}

string rev(string s){
    for(int i=0;i<s.size()/2;i++){
        swap(s[i],s[s.size()-i-1]);
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') s[i]=')';
        else if(s[i]==')') s[i]='(';
    }
    return s;
}

// Remove spaces from the input string
string removeSpaces(const string& s) {
    string res;
    for(char c : s) {
        if(c != ' ') res += c;
    }
    return res;
}

string in_to_post(string s){
    s = removeSpaces(s); // Remove spaces for correct parsing
    string ans = "";
    stack<char> st;
    int i = 0;
    while(i < s.size()){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            ans += s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else{
            while(!st.empty() && priority(s[i]) <= priority(st.top())){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;}

string in_to_pre(string s){
    s = removeSpaces(s);
    s=rev(s);
    string ans="";
    stack<char>st;
    int i=0;
    while(i<s.size()){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else {
            if(s[i]=='^'){
                while(!st.empty() && priority(s[i])<priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            }
            else{
                while(!st.empty() && priority(s[i])<=priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    s=rev(ans);
    return s;
}

// Postfix to infix
string post_to_in(string s)
{
    s = removeSpaces(s);
    stack<string> st;
    for (int i=0;i<s.length();i++)
    {
        if ((s[i]>='A'&&s[i]<='Z') ||
            (s[i]>='a'&&s[i]<='z') ||
            (s[i]>='0'&&s[i]<='9'))
        {
            string ele(1,s[i]);
            st.push(ele);
        }
        else
        {
            string top1 = st.top(); st.pop();
            string top2 = st.top(); st.pop();
            string ele="("+top2+s[i]+top1+")";
            st.push(ele);
        }
    }
    return st.top();
}

// Prefix to Infix
string pre_to_in(string s){
    s = removeSpaces(s);
    int n=s.length();
    int i=n-1;
    stack<string> st;
    while(i>=0){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            string temp="";
            temp+=s[i];
            st.push(temp);
        }else{
            string t1=st.top(); st.pop();
            string t2=st.top(); st.pop();
            string converted='('+t1+s[i]+t2+')';
            st.push(converted);
        }
        i--;
    }
    return st.top();
}

// Evaluate postfix
int evalPostfix(string s,map<char,int> &val) {
    s = removeSpaces(s);
    stack<int> st;
    for (char i:s) {
        if ((i>='A'&&i<='Z') ||
            (i>='a'&&i<='z') ||
            (i>='0'&&i<='9')) {
            if(isdigit(i)) st.push(i-'0');
            else st.push(val[i]);
        } else {
            int b=st.top(); st.pop();
            int a=st.top(); st.pop();
            if(i=='+') st.push(a+b);
            else if(i=='-')  st.push(a-b);
            else if(i=='*') st.push(a*b);
            else if(i=='/') st.push(a/b);.
            else st.push(pow(a,b));
        }
    }
    return st.top();
}

// Evaluate prefix
int evalPrefix(string s,map<char,int> &val) {
    s = removeSpaces(s);
    stack<int> st;
    for (int i=s.size()-1;i>=0;i--) {
        char ch = s[i];
        if ((ch>='A'&&ch<='Z') ||
            (ch>='a'&&ch<='z') ||
            (ch>='0'&&ch<='9')) {
            if(isdigit(ch)) st.push(ch-'0');
            else st.push(val[ch]);
        } else {
            int a=st.top(); st.pop();
            int b=st.top(); st.pop();
            if(ch=='+') st.push(a+b);
            else if(ch=='-') st.push(a-b);
            else if(ch=='*') st.push(a*b);
            else if(ch=='/') st.push(a/b);
            else st.push(pow(a,b));
        }
    }
    return st.top();
}

//change pre to post
string pre_to_post(string s){
    s=pre_to_in(s);
    s=in_to_post(s);
    return s;
}

//change post to pre
string post_to_pre(string s){
    s=post_to_in(s);
    s=in_to_pre(s);
    return s;
}

// Evaluate infix directly using postfix conversion
int evalInfix(string s,map<char,int> &val) {
    string postfix = in_to_post(s);
    return evalPostfix(postfix,val);
}

int main(){
    string infix   = "((A^B)*(C-D/E)+F)/(G*(H^I-J))";
    string prefix  = "/+*^AB-C/DEF*G-^HIJ";
    string postfix = "AB^CDE/-F+GHI^J-*/";

    map<char,int> val = {
        {'A',2},{'B',3},{'C',10},{'D',8},{'E',4},
        {'F',5},{'G',2},{'H',2},{'I',2},{'J',1}
    };
    cout<<"Postfix: " << in_to_post(infix)<<endl;
    cout<<"Prefix: " << in_to_pre(infix)<<endl;
    cout<<"Postfix to Infix: " << post_to_in(postfix)<<endl;
    cout<<"Prefix to Infix: " << pre_to_in(prefix)<<endl;
    cout << "Infix Evaluation   = " << evalInfix(infix, val) << endl;
    cout << "Prefix Evaluation  = " << evalPrefix(prefix, val) << endl;
    cout << "Postfix Evaluation = " << evalPostfix(postfix,val)<<endl;
}
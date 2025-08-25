#include <bits/stdc++.h>
using namespace std;
// Helper Function Priority
int priority(char c)
{
    if (c=='^')
    {
        return 3;
    }
    else if (c=='*'||c=='/')
    {
        return 2;
    }
    else if (c=='+'||c=='-')
    {
        return 1;
    }
    return -1;
}

// Infix to Postfix
string InfixToPostfix(string s){
    int n=s.length();
    stack<char> st;
    string ans="";
    int i=0;
    while(i<n){
        if(s[i]==' '){
            i++;
            continue;
        }
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            ans+=s[i];
        }else if(s[i]=='('){
            st.push(s[i]);
        }else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }else{
            while(!st.empty() && priority(s[i])<=priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    return ans;
}

// Infix to Prefix
string infixToPrefix(string s)
{
    reverse(s.begin(),s.end());
    for (int i=0;i<s.length();i++)
    {
        if (s[i]=='(')
        {
            s[i]=')';
        }
        else if(s[i]==')')
        {
            s[i]='(';
        }
    }
    stack<char> st;
    string ans="";

    for (int i=0;i<s.length();i++)
    {
        if(s[i]==' ') continue;
        if ((s[i]>='A'&&s[i]<='Z') ||
            (s[i]>='a'&&s[i]<='z') ||
            (s[i]>='0'&&s[i]<='9'))
        {
            ans+=s[i];
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            while (!st.empty()&&st.top()!='(')
            {
                ans+=st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            if(s[i]=='^'){
                while(!st.empty() && (priority(s[i])<=priority(st.top()))){
                    ans+=st.top();
                    st.pop();
                }
            }else{
                while(!st.empty() && (priority(s[i])<priority(st.top()))){
                    ans+=st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

// Prefix to Infix
string PrefixToInfix(string s){
    int n=s.length();
    int i=n-1;
    stack<string> st;
    while(i>=0){
        if(s[i]==' '){
            i--;
            continue;
        }
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            string temp="";
            temp+=s[i];
            st.push(temp);
        }else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();

            string converted='('+t1+s[i]+t2+')';
            st.push(converted);
        }
        i--;
    }
    return st.top();
}

// Prefix to Postfix
string prefixToPostfix(string s)
{
    stack<string> st;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]==' ') continue;
        if ((s[i]>='A'&&s[i]<='Z') ||
            (s[i]>='a'&&s[i]<='z') ||
            (s[i]>='0'&&s[i]<='9'))
        {
            string ele(1, s[i]);
            st.push(ele);
        }else{
            string top1,top2;
            if(!st.empty()){
                top1=st.top();
                st.pop();
            }
            if(!st.empty()){
                top2=st.top();
                st.pop();
            }
            string ele=top1+top2+s[i];
            st.push(ele);
        }
    }
    return st.top();
}

// Postfix to prefix
string postfixToPrefix(string s)
{
    stack<string> st;
    for(int i=0;i<s.length();i++){
        if(s[i]==' ') continue;
        if ((s[i]>='A'&&s[i]<='Z') ||
            (s[i]>='a'&&s[i]<='z') ||
            (s[i]>='0'&&s[i]<='9'))
        {
            string ele(1, s[i]);
            st.push(ele);
        }else{
            string top1,top2;
            if(!st.empty()){
                top1=st.top();
                st.pop();
            }
            if(!st.empty()){
                top2=st.top();
                st.pop();
            }
            string ele=s[i]+top2+top1;
            st.push(ele);
        }
    }
    return st.top();
}

// Postfix to infix
string postfixToInfix(string s)
{
    stack<string> st;
    for (int i=0;i<s.length();i++)
    {
        if(s[i]==' ') continue;
        if ((s[i]>='A'&&s[i]<='Z') ||
            (s[i]>='a'&&s[i]<='z') ||
            (s[i]>='0'&&s[i]<='9'))
        {
            string ele(1,s[i]);
            st.push(ele);
        }
        else
        {
            string top1,top2;
            if (!st.empty())
            {
                top1=st.top();
                st.pop();
            }
            if (!st.empty())
            {
                top2=st.top();
                st.pop();
            }
            string ele="("+top2+s[i]+top1+")";
            st.push(ele);
        }
    }
    return st.top();
}
// Evaluate postfix
int evalPostfix(string s,map<char,int> &val) {
    stack<int> st;
    for (char i:s) {
        if(i==' ') continue;
        if ((i>='A'&&i<='Z') ||
            (i>='a'&&i<='z') ||
            (i>='0'&&i<='9')) {
            st.push(val[i]);
        } else {
            int b=st.top(); 
            st.pop();
            int a=st.top(); 
            st.pop();
            if(i=='+') st.push(a+b);
            else if(i=='-')  st.push(a-b);
            else if(i=='*') st.push(a*b);
            else if(i=='/') st.push(a/b);
            else st.push(pow(a,b));
        }
    }
    return st.top();
}

// Evaluate prefix
int evalPrefix(string s,map<char,int> &val) {
    stack<int> st;
    for (int i=s.size()-1;i>=0;i--) {
        if(s[i]==' ') continue;
        if ((s[i]>='A'&&s[i]<='Z') ||
            (s[i]>='a'&&s[i]<='z') ||
            (s[i]>='0'&&s[i]<='9')) {
            st.push(val[s[i]]);
        } else {
            int a=st.top(); 
            st.pop();
            int b=st.top();
            st.pop();
            if(s[i]=='+') st.push(a+b);
            else if(s[i]=='-') st.push(a-b);
            else if(s[i]=='*') st.push(a*b);
            else if(s[i]=='/') st.push(a/b);
            else st.push(pow(a,b));
        }
    }
    return st.top();
}

// Evaluate infix directly using postfix conversion
int evalInfix(string s,map<char,int> &val) {
    string postfix = InfixToPostfix(s);
    return evalPostfix(postfix,val);
}

int main() {
    string infix   = " ((A^B) (C-D/E)+F) /(G(H^I-J))";
    string prefix  = " /+*^AB -C/DEF*G-^HI J";
    string postfix = " AB^CDE /-F+GHI^J-/";

    map<char,int> val = {
        {'A',2},{'B',3},{'C',10},{'D',8},{'E',4},
        {'F',5},{'G',2},{'H',2},{'I',2},{'J',1}
    };
    cout<<"ans  = "<< InfixToPostfix(infix)<<endl;
    cout<<"ans3 = "<< prefixToPostfix(prefix)<<endl;
    cout<<"ans2 = "<< infixToPrefix(infix)<<endl;
    cout<<"ans5 = "<<postfixToPrefix(postfix)<<endl;
    cout<<"ans1 = "<< PrefixToInfix(prefix)<<endl;
    cout<<"ans4 = "<< postfixToInfix(postfix)<<endl;
    cout << "Infix Evaluation   = " << evalInfix(infix, val) << endl;
    cout << "Prefix Evaluation  = " << evalPrefix(prefix, val) << endl;
    cout << "Postfix Evaluation = " << evalPostfix(postfix, val) << endl;

    return 0;
}

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

string in_to_post(string s){
    // infix to postfix
    // stack contains operators + - * /
    // operands are put in the ans string directly 
    string ans = "";
    stack<char> st; 
    int i = 0;
    while(i < s.size()){
        //inserting operands into the ans string;
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            ans += s[i];
        }
        //inserting the opening bracket into the stack
        else if(s[i] == '('){
            st.push(s[i]);
        }
        //if closing bracket comes, then we need to push the elements to ans string and pop the elements of stack till the opening bracket comes to the top of the stack 
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); 
        }
        // for operators ,we compare priority and place them into the stack, if priority of st.top > s[i] we add st.top into ans and st.pop and push s[i] into the stack 
        else{
            while(!st.empty() && priority(s[i]) <= priority(st.top())){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    //after all the operators and operands and brackets are inserted properly into ans, we need to add the remaining items of the stack till it becomes empty
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}

string in_to_pre(string s){
    // same as above with a twist, we first reverse the given string then find its postfix and then find its reverse !!
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
                while(!st.empty() && priority(s[i])<=priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            }
            else{
            while(!st.empty() && priority(s[i])<priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
            }
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

// Prefix to Infix
string pre_to_in(string s){
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

//Evaluate pre to post
string pre_to_post(string s){
    s=pre_to_in(s);
    s=in_to_post(s);
    return s;
}

//Evaluate post to pre
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
string infix   = " ((A^B) (C-D/E)+F) /(G(H^I-J))";
    string prefix  = " /+*^AB -C/DEF*G-^HI J";
    string postfix = " AB^CDE /-F+GHI^J-/";

    map<char,int> val = {
        {'A',2},{'B',3},{'C',10},{'D',8},{'E',4},
        {'F',5},{'G',2},{'H',2},{'I',2},{'J',1}
    };
    cout<<"ans  = "<< in_to_post(infix)<<endl;
    cout<<"ans3 = "<< pre_to_in(prefix)<<endl;
    cout<<"ans2 = "<< in_to_pre(infix)<<endl;
    cout<<"ans5 = "<<post_to_pre(postfix)<<endl;
    cout<<"ans1 = "<< pre_to_in(prefix)<<endl;
    cout<<"ans4 = "<< post_to_in(postfix)<<endl;
    cout << "Infix Evaluation   = " << evalInfix(infix, val) << endl;
    cout << "Prefix Evaluation  = " << evalPrefix(prefix, val) << endl;
    cout << "Postfix Evaluation = " << evalPostfix(postfix,val)<<endl;
}
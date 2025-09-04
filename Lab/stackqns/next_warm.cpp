#include <bits/stdc++.h>
using namespace std;

vector<int> nextwarmday(vector<int>&arr){
    if(arr.empty()) return {};
    vector<int> next;
    stack<int> st;
    for(int i=arr.size()-1;i>=0;i--){
        if(st.empty()){
            next.push_back(0);
            st.push(i);
        }
        else{
            if(arr[i]<arr[st.top()]){
                next.push_back(st.top()-i);
                st.push(i);
            }
            else{
                while(!st.empty() && arr[i]>=arr[st.top()]){
                    st.pop();
                }
                if(st.empty()) next.push_back(0);
                else next.push_back(st.top()-i);
                st.push(i);
            }
        }
    }
    reverse(next.begin(),next.end());
    return next;   
}

int main(){
    vector<int> arr={30,40,50,60};
    arr=nextwarmday(arr);
    for(auto i:arr) cout<<i<<" ";
}

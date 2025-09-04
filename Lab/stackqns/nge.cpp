#include <bits/stdc++.h>
using namespace std;

vector<int> nextgreaterelement(vector<int>&arr){
    // vector<int> nge;
    // stack<int> st;
    // for(int i=arr.size()-1;i>=0;i--){
    //     if(st.empty()){
    //         nge.push_back(-1);
    //         st.push(arr[i]);
    //     }
    //     else if(!st.empty() && arr[i]<=st.top()){
    //         nge.push_back(st.top());
    //         st.push(arr[i]);
    //     }
    //     else if(!st.empty() && arr[i]>st.top()){
    //         while(!st.empty() && arr[i]>st.top()){
    //             st.pop();
    //         }
    //         nge.push_back(st.top());
    //         st.push(arr[i]);
    //     }
    // }
    // reverse(nge.begin(),nge.end());
    // return nge;

    vector<int> nge;
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            if(!st.empty()) nge.push_back(st.top());
            else nge.push_back(-1);
            st.push(arr[i]);
        }
        reverse(nge.begin(),nge.end());
    return nge;
}


int main(){
    vector<int> arr={4,5,2,10,11};
    arr=nextgreaterelement(arr);
    for(auto i:arr) cout<<i<<" ";
}
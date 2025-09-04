#include <bits/stdc++.h>
using namespace std;

// find nge in circular array

vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nge;
        stack<int> st;
        int n=nums.size();
        //create a hypothetical array upto 2n length, now start from 2n-1 to 0, till n dont push_back into nge just maintain the stack acc to the max values, after reaching n start push_back into nge.  
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && nums[i%n]>=st.top()){
                st.pop();
            }
            if(i<n){
                if(st.empty()) nge.push_back(-1);
                else nge.push_back(st.top());
            }
            st.push(nums[i%n]);
        }
        reverse(nge.begin(),nge.end());
        return nge;
    }

int main() {
    vector<int>arr={2,10,5,12,11};
}
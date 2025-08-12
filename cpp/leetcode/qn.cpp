#include <bits/stdc++.h>
using namespace std;
int main() {
    // class Solution {
    // public:
    // int maxArea(vector<int>& height) {
        vector<int>height={1,6,8,4};
        int hmax=0;
        int x=0;
        for(int i=0;i<height.size();i++){
            if(height[i]>hmax) x=i;
            hmax=max(height[i],hmax);
        }
        int area=0;
        for(int i=0;i<height.size();i++){
            area=max(area,hmax*(x-i));
        }
        
    }
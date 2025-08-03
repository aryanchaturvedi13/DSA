#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        vector <int> index;
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0){ 
                count++;
                index.push_back(i);
            }
        }
        if(count<int(n/2)) return -1;
        
    }
};
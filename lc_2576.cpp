#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return 0;
        sort(nums.begin(), nums.end());
        cout << len << endl;
        int l = 0;
        int r = len / 2;
        int mid = r;
        int res = 0;
        vector<bool> tag(len, false);
        while(l < mid && r < len){
            // cout << nums[]
            if(nums[l] * 2 <= nums[r]){
                res += 2;
                tag[l] = true;
                tag[r] = true;
                ++l;
                ++r;
            }
            else r++;
            
        }
        return res;
    }
};


int main(){
    vector<int> nums = {57,40,57,51,90,51,68,100,24,39,11,85,2,22,67,29,74,82,10,96,14,35,25,76,26,54,29,44,63,49,73,50,95,89,43,62,24,88,88,36,6,16,14,2,42,42,60,25,4,58,23,22,27,26,3,79,64,20,92};
    Solution s;
    int res = s.maxNumOfMarkedIndices(nums);
    return 0;
}
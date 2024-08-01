#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> count_one(len, -1);
        for(int ii = 0; ii < len; ii++){
            count_one[ii] = counts(nums[ii]);
        }
        int ii = 0, max_l = 0, min_r, max_r;
        while(ii < len){
            vector<int> temp_v;
            int l = ii;
            int count_here = count_one[ii];
            while(ii < len && count_here == count_one[ii]){
                ii++;
            }
            int r = ii;
            min_r = nums[l];
            max_r = nums[l];
            for(int jj = l + 1; jj < r; jj++){
                min_r = min(min_r, nums[jj]);
                max_r = max(max_r, nums[jj]);
            }
            if(min_r < max_l) return false;
            max_l = max_r;
        }
        return true;

    }

    int counts(int a){
        int res = 0;
        while(a > 0){
            res += a % 2;
            a /= 2;
        }
        return res;
    }
};



int main(){
    vector<int> nums = {3, 16, 8, 4, 2};
    Solution s;
    bool b = s.canSortArray(nums);
    return 0;

}
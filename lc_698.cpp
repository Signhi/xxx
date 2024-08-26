#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <functional>

using namespace std;

// class Solution {
// public:
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         int sum_all = accumulate(nums.begin(), nums.end(), 0);
//         int average = sum_all / k;
//         if(sum_all % k != 0 || average < nums[nums.size() - 1]) return false;
//         vector<int> tag_num(nums.size(), 1);
//         for(int ii = 0; ii < k; ii++){
//             int sum_h = 0;
//             int tag = 0;
//             for(int jj = 0; jj < tag_num.size(); jj++){
//                 if(tag_num[jj]){
//                     vector<int> v_index;
//                     int tag = 0;
//                     dfs(nums, tag_num, sum_h, jj, average, v_index, tag);
//                     if(!tag) return false;
//                     break;
//                 }
//             }
            
//         }
//         return true;
//     }


//     void dfs(vector<int>& nums, vector<int>& tag_num, int sum_h, int jj, int average, vector<int>& v_index, int& tag){
//         v_index.push_back(jj);
//         sum_h += nums[jj];
//         if(sum_h == average){
//             for(int xx : v_index) tag_num[xx] = 0;
//             tag = 1;
//             return ;
//         }
//         if(sum_h > average){
//             return;
//         }
//         for(int ii = jj + 1; ii < tag_num.size(); ii++){
//             if(tag_num[ii]){
//                 dfs(nums, tag_num, sum_h, ii, average, v_index, tag);
//                 v_index.pop_back();
//                 if(tag) return ;
//             } 
//         }
//         return ;
//     }
// };

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int all = accumulate(nums.begin(), nums.end(), 0);
        if (all % k > 0) {
            return false;
        }
        int per = all / k; 
        sort(nums.begin(), nums.end());
        if (nums.back() > per) {
            return false;
        }
        int n = nums.size();
        vector<bool> dp(1 << n, true);
        function<bool(int,int)> dfs = [&](int s, int p)->bool {
            if (s == 0) {
                return true;
            }
            if (!dp[s]) {
                return dp[s];
            }
            dp[s] = false;
            for (int i = 0; i < n; i++) {
                if (nums[i] + p > per) {
                    break;
                }
                if ((s >> i) & 1) {
                    if (dfs(s ^ (1 << i), (p + nums[i]) % per)) {
                        return true;
                    }
                }
            }
            return false;
        };
        return dfs((1 << n) - 1, 0);
    }
};



int main(){
    vector<int> nums = {4,4,6,2,3,8,10,2,10,7};
    int k = 4;
    Solution s;
    bool b = s.canPartitionKSubsets(nums, k);
    return 0;
}
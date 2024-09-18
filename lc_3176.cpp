#include <vector>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<int> res_v = {};
        int res = 0;
        dfs(res_v, 0, 0, k, res, nums);
        return res;
    }

    void dfs(vector<int>& res_v, int index, int count_x, int& k, int& res, vector<int>& nums){
        if(count_x > k || index == nums.size()){
            if(count_x > k) res = res > res_v.size() - 1 ? res : res_v.size() - 1;
            else res = res > res_v.size() ? res : res_v.size();
            return;
        }
        for(int ii = index; ii < nums.size(); ii++){
            if(res_v.size() != 0){
                if(res_v.back() != nums[ii]){
                    res_v.push_back(nums[ii]);
                    dfs(res_v, ii + 1, count_x + 1, k, res, nums);
                }
                else{
                    res_v.push_back(nums[ii]);
                    dfs(res_v, ii + 1, count_x, k, res, nums);
                }
            }
            else{
                res_v.push_back(nums[ii]);
                dfs(res_v, ii + 1, count_x, k, res, nums);
            }
            res_v.pop_back();
        }
        return ;


    }
};




int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 1};
    int k = 0;
    Solution s;
    int res = s.maximumLength(nums, k);
    return 0;
}
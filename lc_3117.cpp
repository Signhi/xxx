#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        vector<vector<int>> v(nums.size(), (vector<int>(nums.size())));
        int res = -1;
        for(int ii = 0; ii < nums.size(); ii++){
            int temp = nums[ii];
            for(int jj = ii; jj < nums.size(); jj++){
                temp = temp & nums[jj];
                v[ii][jj] = temp;
            }
        }
        dfs(v, 0, andValues, res, 0, 0, nums);
        return res;

    }


    void dfs(vector<vector<int>>& v, int index_andValues, vector<int>& andValues, int& res, int last_index, int sum_nums, vector<int>& nums){
        if(index_andValues >= andValues.size() && last_index == nums.size()){
            // if(sum_nums == 19){
            //     cout << "sss" << endl;
            // }
            if(res == -1) res = sum_nums; 
            res = min(res, sum_nums);
            return;
        }
        if(last_index >= nums.size() || nums.size() - last_index < andValues.size() - index_andValues) return;
        if(index_andValues >= andValues.size()) return;
        
        // int tag = 0;
        for(int ii = last_index; ii < nums.size(); ii++){
            if(v[last_index][ii] == andValues[index_andValues]){
                dfs(v, index_andValues + 1, andValues, res, ii + 1, sum_nums + nums[ii], nums);
            }
        }
        return ;
    }
};

int main(){
    vector<int> nums = {2,3,5,7,7,7,5};
    vector<int> andValues = {0,7,5};
    Solution s;
    int res = s.minimumValueSum(nums, andValues);
    cout << res << endl;
    return 0;

}
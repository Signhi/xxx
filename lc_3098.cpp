#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int sumOfPowers(vector<int>& nums, int k) {
        int res = 0;
        
        for(int ii = 0; ii <= nums.size() - k; ii++){
            vector<int> here_v;
            dfs(nums, 0, k, ii, here_v, res);
        }
        return res;


    }

    void dfs(vector<int>& nums, int temp_c, int& k, int ii, vector<int>& here_v, int& res){
        if(ii >= nums.size()) return;
        here_v.push_back(nums[ii]);
        temp_c++;
        if(temp_c == k){
            vector<int> temp_v = here_v;
            sort(temp_v.begin(), temp_v.end());
            int temp = temp_v[1] - temp_v[0];
            for(int jj = 2; jj < temp_v.size(); jj++){
                temp = min(temp, temp_v[jj] - temp_v[jj - 1]);
            }
            res += temp;
            cout << temp << endl;
            return ;
        }
        for(int jj = ii + 1; jj <= nums.size() - (k - temp_c); jj++){
            dfs(nums, temp_c, k, jj, here_v, res);
            here_v.pop_back();
        }
    }
};

int main(){
    vector<int> nums = {4, 3, -1};
    int k = 2;
    Solution s;
    int res = s.sumOfPowers(nums, k);
    return 0;
}
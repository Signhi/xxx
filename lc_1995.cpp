#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int ii = 0; ii < nums.size(); ii++){
            for(int jj = ii + 1; jj < nums.size(); jj++){
                for(int kk = jj + 1; kk < nums.size(); kk++){
                    auto it = find(nums.begin() + kk + 1, nums.end(), nums[ii] + nums[jj] + nums[kk]);
                    if(it != nums.end()){
                        int temp = *it;
                        while(it != nums.end() && temp == *it){
                            ++res;
                            ++it;
                        }
                    }
                    
                }
            }
        }
        return res;
    }
};

int main(){
    vector<int> v = {28,8,49,85,37,90,20,8};
    Solution s;
    s.countQuadruplets(v);
    return 0;
}






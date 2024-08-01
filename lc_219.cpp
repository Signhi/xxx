#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "../../../Compiler/C++/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/algorithmfwd.h"

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int, int>> v;
        int len = nums.size();
        for(int ii = 0; ii < len; ii++){
            v.push_back(make_pair(ii, nums[ii]));
        }
        sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) -> bool{
            return a.second > b.second;
        });
        int  temp, ii = 0;
        while(ii < len){
            temp = v[ii].second;
            vector<int> temp_v;
            while(v[ii].second == temp){
                temp_v.push_back(v[ii].first);
                ++ii;
            }
            sort(temp_v.begin(), temp_v.end());
            for(int jj = 1; jj < temp_v.size(); jj++){
                if(abs(temp_v[jj] - temp_v[jj - 1]) <= k) return true;
            }
        }
        return false;
    }
};


int main(){
    vector<int> nums = {1,2,3,1,2,3};
    Solution s;
    bool res = s.containsNearbyDuplicate(nums, 2);
    return 0;
}
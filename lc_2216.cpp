#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return 0;
        int ptr = 1, res = 0, len = nums.size();
        int temp = nums[0];
        while(ptr < len){
            while(ptr < len && nums[ptr] == temp){
                ++res;
                ++ptr;
            }
            ++ptr;
            temp = nums[ptr];
            ++ptr;
        }
        return res;
    }
};

int main(){
    vector<int> v = {1,1,2,2,3,3};
    Solution s;
    s.minDeletion(v);
    return 0;
}






#include <vector>

using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        
        
        int tag = nums[0] % 2;
        int len = nums.size();
        for(int ii = 1; ii < len; ii++){
            if(tag == nums[ii] % 2) return false;
            tag = !tag;
        }
        return true;
    }
};


int main(){
    vector<int> nums = {2, 1, 4};
    Solution s;
    bool b = s.isArraySpecial(nums);
    return 0;
}
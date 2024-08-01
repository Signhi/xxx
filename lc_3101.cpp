#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long res = nums.size();
        for(int temp_len = 2; temp_len <= nums.size(); temp_len++){
            int l = 0;
            int here_len;
            int tag = 0;
            while(l < nums.size() - 1){
                here_len = 1;
                while(l < nums.size() - 1 && nums[l] != nums[l + 1] && here_len < temp_len){
                    l++;
                    here_len++;
                }
                if(here_len == temp_len){
                    tag = 1;
                    res++;
                    l = l - (temp_len - 2);
                    continue;
                }
                else l++;
            }
            if(!tag) return res;
        }
        return res;
    }
};

int main(){
    vector<int> nums = {0, 1, 0, 1};
    Solution s;
    int res = s.countAlternatingSubarrays(nums);
    return 0;
}
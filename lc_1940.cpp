#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution{
public:
    vector<int> findLongestVec(vector<int> &nums1, vector<int>& nums2){
        int ptr_1 = 0, ptr_2 = 0;
        vector<int> res;
        int len_1 = nums1.size(), len_2 = nums2.size();
        while(ptr_1 < len_1 && ptr_2 < len_2){
            if(nums1[ptr_1] == nums2[ptr_2]){
                res.push_back(nums1[ptr_1]);
                ++ptr_1;
                ++ptr_2;
            }
            else if(nums1[ptr_1] < nums2[ptr_2]){
                ++ptr_1;
            }
            else{
                ++ptr_2;
            }
        }
        return res;
    }

    vector<int> findLongestVecV2(vector<vector<int>>& nums){
        int len = nums.size();
        vector<int> v_ptr(len);
        vector<int> res;
        
        while(true){
            
            int max_num = nums[0][v_ptr[0]], tag_ptr = 0;
            for(int ii = 0; ii < len; ii++){
                if(v_ptr[ii] >= nums[ii].size()){
                    tag_ptr = 1;
                    break;
                } 
                max_num = max(max_num, nums[ii][v_ptr[ii]]);
            }
            if(tag_ptr) break;
            vector<int> temp_v;
            for(int ii = 0; ii < len; ii++){
                if(nums[ii][v_ptr[ii]] != max_num) temp_v.push_back(ii);
            }
            if(temp_v.size()){
                for(auto xx : temp_v){
                    v_ptr[xx]++;
                }
            }
            else{
                res.push_back(nums[0][v_ptr[0]]);
                for(auto& xx : v_ptr){
                    xx++;
                }
            }
        }
        return res;
    }



};


int main(){
    // vector<int> nums1 = {1, 3, 4}, nums2 = {1, 4, 7, 9};
    vector<vector<int>> nums = {{1,2,3,4,5}, {6,7,8}};
    Solution s;
     vector<int> res = s.findLongestVecV2(nums);
    // vector<int> res = s.findLongestVec(nums1, nums2);
    for_each(res.begin(), res.end(), [](int& a){
        cout << a << ' ';
    });
    return 0;

}



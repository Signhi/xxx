#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int res = 1000;
        for(int ii = 0; ii < nums1.size() - 1; ii++){
            for(int jj = ii + 1; jj < nums1.size(); jj++){
                int ptr_1 = 0, ptr_2 = 0;
                while(ptr_1 == ii || ptr_1 == jj) ptr_1++;
                int temp = nums2[ptr_2] - nums1[ptr_1];
                while(ptr_1 < nums1.size() && ptr_2 < nums2.size()){
                    while(ptr_1 == ii || ptr_1 == jj) ptr_1++;
                    if(nums2[ptr_2] - nums1[ptr_1] != temp) break;
                    ++ptr_1;
                    ++ptr_2;
                }
                if(ptr_2 == nums2.size()) res = min(res, temp);
            }
        }
        return res;
    }
};


int main(){
    vector<int> v1 = {4, 7, 5};
    vector<int> v2 = {5};
    Solution s;
    int res = s.minimumAddedInteger(v1, v2);
    return 0;
}
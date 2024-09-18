#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int res = -1;
        
        int len = nums.size();
        vector<vector<int>> v(len, vector<int>(len));
        for(int ii = 0; ii < len; ii++){
            set<int> s;
            for(int jj = ii; jj < len; jj++){
                s.insert(nums[jj]);
                v[ii][jj] = s.size();
            }
        }
        int c_v = 0;
        for(int ii = 1; ii <= len; ii++) c_v += ii;
        int l = c_v / 2, r = c_v / 2;
        int temp = len;
        
        if(c_v % 2 == 0){
            l--;
            c_v = 0;
            while(c_v + temp < l + 1) {
                c_v += temp;
                temp--;
            }
            int l_num = v[l - c_v][l - c_v + len - temp];
            while(c_v + temp < r + 1) {
                c_v += temp;
                temp--;
            }
            int r_num = v[r - c_v][r - c_v + len - temp];
            res = min(l_num, r_num);
        }
        else{
            c_v = 0;
            while(c_v + temp < l + 1) {
                c_v += temp;
                temp--;
            }
            res = v[l - c_v][l - c_v + len - temp];
        }
        return res;
    }
};

int main(){
    
    vector<int> nums = {30,23,61,12,23,23,30};
    Solution s;
    int res = s.medianOfUniquenessArray(nums);
    return 0;
}
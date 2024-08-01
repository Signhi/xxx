#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        vector<int> sum_left = {0};
        int len = arr.size();
        for(int ii = 0; ii < len; ii++){
            sum_left.push_back(sum_left[sum_left.size() - 1] + arr[ii]);
        }
        int res = arr[0];
        for(int ii = 0; ii < len - 1; ii++){
            int min_num = arr[ii];
            for(int jj = ii + 1; jj < len; jj++){
                min_num = min(min_num, arr[jj]);
                if(sum_left[jj + 1] - sum_left[ii] - min_num > res) res = sum_left[jj + 1] - sum_left[ii] - min_num;
            }
        }
        return res;
    }
};


int main(){
    vector<int> arr = {100,30,1,987,400,200,9};
    Solution s;
    int res = s.maximumSum(arr);
    return 0;
}
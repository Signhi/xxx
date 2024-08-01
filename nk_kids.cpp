#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @param m int整型 
     * @return int整型
     */
    int LastRemaining_Solution(int n, int m) {
        vector<int> nums_f;
        for(int ii = 0; ii < n; ii++){
            nums_f.push_back(ii);
        }
        int tag = 0;
        while(nums_f.size() > 1){
            int change = m % nums_f.size();
            int del = nums_f[(tag + change - 1 + nums_f.size()) % nums_f.size()];
            cout << del << endl;
            nums_f.erase(nums_f.begin() + (tag + change - 1 + nums_f.size()) % nums_f.size());
            if((tag + change - 1 + nums_f.size() + 1) % (nums_f.size() + 1) == nums_f.size()) tag = 0;
            else tag = (tag + change - 1 + nums_f.size() + 1) % (nums_f.size() + 1);
        }
        return nums_f[0];
    }
};


int main(){
    int m = 5, n = 3;
    Solution s;
    s.LastRemaining_Solution(m, n);
    return 0;
}
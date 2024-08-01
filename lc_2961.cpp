#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> res;
        int index = 0;
        for(auto xx : variables){
            int temp_num = xx[0];
            int temp = temp_num % 10;
            for(int ii = 1; ii < xx[1] - 1; ii++){
                temp *= temp_num;
                temp %= 10;
                // cout << temp << endl;
            }
            cout << temp << endl;
            temp_num = temp;
            temp %= xx[3];
            
            for(int ii = 1; ii < xx[2]; ii++){
                temp *= temp_num;
                temp %= xx[3];
            }
            if(temp == target) res.push_back(index);
            ++index;
        }
        return res;
    }
};


int main(){
    vector<vector<int>> variables = {{2,3,3,10}, {3,3,3,1}, {6,1,1,4}};
    Solution s;
    s.getGoodIndices(variables, 2);
    return 0;
}
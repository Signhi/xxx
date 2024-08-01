#include <vector>
#include <map>

using namespace std;

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         vector<int> last(nums.size(), -1), sum_n(nums.size(), 0);
//         unordered_map<int, int> m;
//         for(int ii = 0; ii < nums.size(); ii++){
            
//             if(m.find(nums[ii]) != m.end()) continue;
//             m[nums[ii]] = ii;
//             if(m.find(nums[ii] + 1) != m.end()){
//                 sum_n[ii] = sum_n[m[nums[ii] + 1]] + 1;
//                 int index = 1;
//                 while(m.find(nums[ii] - index) != m.end()){
//                     sum_n[m[nums[ii] - index]] += sum_n[ii];
//                     index++;
//                 }
//                 continue;
//             }
//             sum_n[ii] = 1;
//             int index = 1;
//             while(m.find(nums[ii] - index) != m.end()){
//                 sum_n[m[nums[ii] - index]] += sum_n[ii];
//             }
            
//         }
//         int res = 0;
//         for(int aa : sum_n){
//             res = res > aa ? res : aa;
//         }
//         return res;
//     }
// };

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> m;
        for(auto xx : nums){
            m[xx] = 1;
        }
        int res = 0, out;
        auto it = m.begin();
        while(it != m.end()){
            out = 1;
            auto temp_it = it;
            it++;
            while(it != m.end() && it->first == temp_it->first + 1){
                it++;
                temp_it++;
                out++;
            }
            if(out > res) res = out;
        }
        return res;
    }
};


int main(){
    vector<int> v = {100,4,200,1,3,2};
    Solution s;
    int xx = s.longestConsecutive(v);
    return 0;
}
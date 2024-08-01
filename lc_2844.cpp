#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int minimumOperations(string num) {
        int res = num.size();
        vector<string> v = {"00", "25", "50", "75"};
        for(auto xx : v){
            char c_1 = xx[1], c_2 = xx[0];
            int temp = 0;
            int ptr = num.size() - 1;
            // int tag = 0;
            while(ptr >= 0 && num[ptr] != c_1){
                ptr--;
                temp++;
            }
            // cout << temp << endl;
            if(ptr >= 0){
                ptr--;
                while(ptr >= 0 && num[ptr] != c_2){
                    ptr--;
                    temp++;
                }
                // cout << temp << endl;
                if(ptr >= 0) res = min(res, temp);
                
            }
            else continue;
        }
        return res;
    }
};


int main(){
    string s = "2908305";
    Solution ss;
    int res = ss.minimumOperations(s);
    return 0;
}
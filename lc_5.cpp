#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int res = 1;
        string res_s;
        res_s += s[0];
        for(int ii = 1; ii < s.size(); ii++){
            int temp_len;
            int l = ii - 1, r = ii + 1;
            temp_len = 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                temp_len += 2;
                l--;
                r++;
            } 
            if(temp_len > res){
                res = temp_len;
                res_s = s.substr(l + 1, temp_len);
            }
            if(s[ii] == s[ii - 1]){
                temp_len = 2;
                l = ii - 2;
                r = ii + 1;
                while(l >= 0 && r < s.size() && s[l] == s[r]){
                    temp_len += 2;
                    l--;
                    r++;
                } 
                if(temp_len > res){
                    res = temp_len;
                    res_s = s.substr(l + 1, temp_len);
                }
            }
        }
        return res_s;

    }
};


int main(){
    string s = "babab";
    Solution ss;
    string res = ss.longestPalindrome(s);
    return 0;
}
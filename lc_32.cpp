#include <string>
#include <iostream>
#include <stack>
using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        int count_l = 0, count_r = 0;
        stack<char> st;
        int ii = 0;
        int res = 0;
        while(ii < s.size()){
            if(s[ii] == '('){
                count_l++;
                st.push('(');
            } 
            else {
                count_r++;
                st.push(')');
            }
            if(count_r > count_l){
                cout << st.size() << endl;
                int len = st.size() - 1;
                res = max(res, len);
                while(!st.empty()) st.pop();
                count_l = 0, count_r = 0;
            }
            ii++;
        }
        count_r = 0;
        count_l = 0;
        while(!st.empty()){
            while(!st.empty() && count_r >= count_l){
                if(st.top() == ')') count_r++;
                else count_l++;
                st.pop();
            }
            res = max(res, 2 * count_r);
            count_l = 0;
            count_r = 0;
        }
        return res;
    }
};




int main(){
    string s = ")()())";
    Solution ss;
    int aa = ss.longestValidParentheses(s);
    return 0;
}
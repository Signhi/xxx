#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution{
public:
    int findNumSubstr(string& s, string& substr){
        unordered_map<char, int> m;
        int res = 0;
        int len_s = s.size(), len_substr = substr.size();
        if(len_s < len_substr) return 0;
        for(auto xx : substr){
            if(m.find(xx) == m.end()){
                m[xx] = 1;
            }
            else m[xx]++;
        }
        int tag = 0;
        unordered_map<char, int> m_x;
        for(int jj = 0; jj < len_substr; jj++){
            if(m_x.find(s[jj]) == m_x.end()){
                m_x[s[jj]] = 1;
            }
            else m_x[s[jj]]++;
        }
        if(m_x == m) res++;
        int ii = len_substr;
        while(ii < len_s){
            if(m_x.find(s[ii]) == m_x.end()){
                m_x[s[ii]] = 1;
            }
            else m_x[s[ii]]++;
            m_x[s[ii - len_substr]]--;
            if(m_x[s[ii - len_substr]] == 0) m_x.erase(s[ii - len_substr]);
            if(m_x == m) res++;
            ii++;
        }
        return res;
    }
};


// int main(){
//     string s = "abab", substr = "ab";
//     Solution ss;
//     int res = ss.findNumSubstr(s, substr);
//     return 0;
// }



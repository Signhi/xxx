#include <string>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
//         int len = accounts.size();
//         vector<int> tag(len, 0);
//         vector<vector<string>> res;
//         for(int ii = 0; ii < len; ii++){
//             if(tag[ii] == 0){
//                 tag[ii] = 1;
//                 set<string> s1;
//                 for(int jj = 1; jj < accounts[ii].size(); jj++){
//                     s1.insert(accounts[ii][jj]);
//                 }
//                 for(int jj = ii + 1; jj < len; jj++){
//                     set<string> s2;
//                     for(int kk = 1; kk < accounts[jj].size(); kk++){
//                         s2.insert(accounts[jj][kk]);
//                     }
//                     set<string> x;
//                     set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(x, x.begin()));
//                     if(!x.empty()){
//                         set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s1, s1.begin()));
//                         tag[jj] = 1;
//                     }
//                 }
//                 vector<string> temp_v = {accounts[ii][0]};
//                 for(auto it = s1.begin(); it != s1.end(); it++) temp_v.push_back(*it);
//                 res.push_back(temp_v);
//             }
//         }
//         sort(res.begin(), res.end(), [](vector<string>& v1, vector<string>& v2){
//             return v1[0] < v2[0];
//         });
//         return res;
//     }
// };

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int len = accounts.size();
        vector<int> tag(len, 0);
        vector<vector<string>> res;
        for(int ii = 0; ii < len; ii++){
            if(tag[ii] == 0){
                tag[ii] = 1;
                set<string> s1;
                for(int jj = 1; jj < accounts[ii].size(); jj++){
                    s1.insert(accounts[ii][jj]);
                }
                int temp_size = 0;
                while(s1.size() != temp_size){
                    temp_size = s1.size();
                    for(int jj = ii + 1; jj < len; jj++){
                        if(tag[jj] == 1) continue;
                        set<string> s2;
                        for(int kk = 1; kk < accounts[jj].size(); kk++){
                            s2.insert(accounts[jj][kk]);
                        }
                        set<string> x;
                        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(x, x.begin()));
                        if(!x.empty()){
                            set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s1, s1.begin()));
                            tag[jj] = 1;
                        }
                    }
                }
                vector<string> temp_v = {accounts[ii][0]};
                for(auto it = s1.begin(); it != s1.end(); it++) temp_v.push_back(*it);
                res.push_back(temp_v);
            }
        }
        sort(res.begin(), res.end(), [](vector<string>& v1, vector<string>& v2){
            return v1[0] < v2[0];
        });
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<string>> accounts = {{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};
    s.accountsMerge(accounts);
    return 0;
}
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>>& res, vector<int>& temp_v, int n, int ii){
    if(temp_v.size() == ii){
        res.push_back(temp_v);
        return;
    } 
    int yy = -1;
    if(!temp_v.empty()) yy =  temp_v.back();
    for(int jj = yy + 1; jj < n; jj++){
        temp_v.push_back(jj);
        dfs(res, temp_v, n, ii);
        temp_v.pop_back();
    }
    return;
}




int main() {
    // vector<vector<int>> vp;
    // vector<int> vv = {};
    // dfs(vp, vv, 5, 4);
    int n = 5, temp;
    // cin >> n;
    vector<int> v = {3,7,6,8,4};
    // for(int ii = 0; ii < n; ii++){
    //     cin >> temp;
    //     v.push_back(temp);
    // }
    vector<set<int>> v_contain(n, set<int>());
    for(int ii = 0; ii < n; ii++){
        set<int> s;
        for(int jj = 0; jj < n; jj++){
            if((v[ii] | v[jj]) == v[ii]) v_contain[ii].insert(jj);
        }
    }
    
    for(int jj = 1; jj < n; jj++){
        vector<vector<int>> vp;
        vector<int> vv = {};
        dfs(vp, vv, n, jj);
        for(auto xx : vp){
            set<int> temp_s = v_contain[xx[0]];
            for(int ii = 1; ii < xx.size(); ii++){
                set<int> temp;
                set_union(temp_s.begin(), temp_s.end(), v_contain[xx[ii]].begin(), v_contain[xx[ii]].end(), inserter(temp, temp.begin()));
                if(temp.size() == n) {
                    cout << jj << endl;
                    return 0;
                }
                temp_s = temp;
            }
        }
    }
    cout << n << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")
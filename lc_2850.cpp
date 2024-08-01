#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int res = 100000;
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> vg, vl;
        for(int ii = 0; ii < row; ii++){
            for(int jj = 0; jj < col; jj++){
                if(grid[ii][jj] > 1){
                    for(int kk = 0; kk < grid[ii][jj] - 1; kk++){
                        vg.push_back({ii, jj});
                    }
                }
                else if(!grid[ii][jj]) vl.push_back({ii, jj});
            }
        }
        vector<vector<vector<int>>> dis = find_all(vl);
        // return dis.size();
        for(auto xx : dis){
            int temp_dis = 0;
            for(int ii = 0; ii < xx.size(); ii++){
                temp_dis += find_dis(xx[ii], vg[ii]);
            }
            if(temp_dis < res) res = temp_dis;
            // return temp_dis;
        }
        return res;
        
    }

    vector<vector<vector<int>>> find_all(vector<vector<int>>& v){
        vector<vector<int>> res;
        vector<int> temp_res;
        int n = v.size();
        dfs(res, temp_res, n);
        vector<vector<vector<int>>> xxx;
        for(auto xx : res){
            vector<vector<int>> temp;
            for(auto yy : xx){
                temp.push_back(v[yy]);
            }
            xxx.push_back(temp);
        }
        return xxx;
    }

    void dfs(vector<vector<int>>& res, vector<int>& temp_res, int n){
        if(temp_res.size() == n){
            res.push_back(temp_res);
            // temp_res.pop_back();
            return;
        }
        for(int ii = 0; ii < n; ii++){
            if(find(temp_res.begin(), temp_res.end(), ii) == temp_res.end()){
                temp_res.push_back(ii);
                dfs(res, temp_res, n);
                temp_res.pop_back();
            }
            // temp_res.pop_back();
        }
        return ;
    }

    int find_dis(vector<int>& a, vector<int>& b){
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    
};



int main(){
    vector<vector<int>> grid = {{1, 3, 0}, {1, 0, 0}, {1, 0, 3}};
    Solution s;
    int res = s.minimumMoves(grid);
    return 0;
}
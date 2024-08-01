#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution{
public:
    int express_num(vector<vector<int>>& v){
       vector<int> tag_v(v.size(), 0);
       int res = 0;
       for(int ii = 0; ii < v.size(); ii++){
            queue<int> q;
            if(tag_v[ii] == 1) continue;
            tag_v[ii] = 1;
            q.push(ii);
            while(!q.empty()){
                int len_q = q.size();
                for( int jj = 0; jj < len_q; jj++){
                    int here = q.front();
                    q.pop();
                    for(int kk = 0; kk < v.size(); kk++){
                        if(v[here][kk] != 0 && tag_v[kk] != 1){
                            q.push(kk);
                            tag_v[kk] = 1;
                        } 
                    }
                }
            }
            res++;
       }
       return res;
    }
};

int main(){
    // vector<vector<int>> v = {{1,1,1,1},{1,1,1,0},{1,1,1,0},{1,0,0,1}};
    vector<vector<int>> v = {{1,1,0,0},{1,1,0,0},{0,0,1,0},{0,0,0,1}};

    Solution s;
    int res = s.express_num(v);
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        vector<int> v(numCourses, 0);
        for(auto xx : prerequisites){
            if(m.find(xx[0]) == m.end()) m[xx[0]] = {xx[1]};
            else m[xx[0]].push_back(xx[1]);
            v[xx[0]] = 1;
        }
        vector<int> temp_v;
        int res_n = 0;
        for(int ii = 0; ii < numCourses; ii++){
            if(v[ii] == 0){
                temp_v.push_back(ii);
                res_n++;
            } 
            
        }
        while(!temp_v.empty()){
            vector<int> temp;
            for(auto& yy : m){
                for(auto xx : temp_v){
                   vector<int> xxx;
                   for(auto xxxx : yy.second){
                    if(xxxx != xx) xxx.push_back(xxxx);
                   }
                   yy.second = xxx;
                 }
                if(yy.second.empty()){
                    temp.push_back(yy.first);
                    res_n++;
                }
            }
            if(res_n == numCourses) return true;
            temp_v = temp;
        }
        
        return false;
    }

    
};


int main(){
    //vector<vector<int>> v = {{0,1}, {0, 2}, {1,2}} ;
    vector<vector<int>> v = {{0,1}};
    int numCourses = 2;
    Solution s;
    bool res = s.canFinish(numCourses, v);
    return 0;
}
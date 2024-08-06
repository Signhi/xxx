#include <deque>
#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int max_num = max(zero, one);
        int min_num = min(zero, one);
        if(static_cast<double>(max_num) / (min_num + 1) > limit) return 0;
        int res = 0;
        deque<int> q;
        dfs(q, zero, one, limit + 1, res, 0, 0);
        return res;
        
    }

    void dfs(deque<int>& q, int zero, int one, int limit, int& res, int zero_num, int one_num){
        if(zero == 0 && one == 0){
            if(zero_num && one_num) res++;
            return;
        } 
        if(q.size() >= limit){
            if(!zero_num || !one_num) return;
            if(q[q.size() - limit]) one_num--;
            else zero_num--;
            if(zero){
                q.push_back(0);
                dfs(q, zero - 1, one, limit, res, zero_num + 1, one_num);
                if(!q.empty()) q.pop_back();
            } 
            if(one){
                q.push_back(1);
                dfs(q, zero, one - 1, limit, res, zero_num, one_num + 1);
                if(!q.empty()) q.pop_back();
            }
        }
        else {
            if(zero){
                q.push_back(0);
                dfs(q, zero - 1, one, limit, res, zero_num + 1, one_num);
                if(!q.empty()) q.pop_back();
            } 
            if(one){
                q.push_back(1);
                dfs(q, zero, one - 1, limit, res, zero_num, one_num + 1);
                if(!q.empty()) q.pop_back();
            }
        }
        return ;
    }
};


int main(){
    int one = 1;
    int zero = 1;
    int limit = 1;
    Solution s;
    int res = s.numberOfStableArrays(zero, one, limit);
    return 0;
}
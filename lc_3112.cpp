#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], length = edge[2];
            adj[u].emplace_back(v, length);
            adj[v].emplace_back(u, length);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, 1);
        vector<int> answer(n, -1);
        answer[1] = 0;
        while (!pq.empty()) {
            auto [t, u] = pq.top();
            pq.pop();
            // if (t != answer[u]) {
            //     continue;
            // }
            for (const auto& [v, length] : adj[u]) {
                if (t + length < disappear[v] && (answer[v] == -1 || t + length < answer[v])) {
                    pq.emplace(t + length, v);
                    answer[v] = t + length;
                }
            }
        }
        return answer;
    }
};

int main(){
    vector<vector<int>> edges = {{0,1,2},{1,2,1},{0,2,4}};
    vector<int> disappear = {1, 1, 5}; 
    Solution s;
    vector<int> res = s.minimumTime(3, edges, disappear);
    return 0;
}
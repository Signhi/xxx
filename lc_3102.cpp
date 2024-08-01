#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class compared{
public:
    bool operator()(pair<vector<int>, int>& a, pair<vector<int>, int>& b){
        return a.second < b.second;
    }
};

class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        priority_queue<pair<vector<int>, int>, vector<pair<vector<int>, int>>, compared> pq;
        for(int ii = 0; ii < points.size() - 1; ii++){
            for(int jj = ii + 1; jj < points.size(); jj++){
                int temp_l = abs(points[ii][0] - points[jj][0]) + abs(points[ii][1] - points[jj][1]);
                pq.push({{ii, jj}, temp_l});
            }
        }
        set<int> s;
        s.insert(pq.top().first[0]);
        s.insert(pq.top().first[1]);
        int del_node;
        pq.pop();
        while(s.size() > 1 && !pq.empty()){
            vector<int> temp_v = pq.top().first;
            set<int> temp_s;
            temp_s.insert(temp_v[0]);
            temp_s.insert(temp_v[1]);
            set<int> c;
            set_intersection(s.begin(),s.end(),temp_s.begin(),temp_s.end(),inserter(c,c.begin()));
            if(c.size() == 0) return pq.top().second;
            else if(c.size() == 1){
                auto it = c.begin();
                del_node = *it;
                break;
            }
            pq.pop();
        }
        while(!pq.empty()){
            vector<int> xx = pq.top().first;
            if(find(xx.begin(), xx.end(), del_node) == xx.end()) return pq.top().second;
            pq.pop();
        }
        return 0;

    }

};

// class compared{
// public:
//     bool operator()(const vector<int>& a, const vector<int>& b){
//         return a[2] < b[2];
//     }
// };

// class Solution {
// public:
//     int minimumDistance(vector<vector<int>>& points) {
//         priority_queue<vector<int>, vector<vector<int>>, compared> pq;
//         for(int ii = 0; ii < points.size() - 1; ii++){
//             for(int jj = ii + 1; jj < points.size(); jj++){
//                 int temp_l = abs(points[ii][0] - points[jj][0]) + abs(points[ii][1] - points[jj][1]);
//                 pq.push({ii, jj, temp_l});
//             }
//         }
//         set<int> s;
//         s.insert(pq.top()[0]);
//         s.insert(pq.top()[1]);
//         int del_node;
//         pq.pop();
//         while(s.size() > 1 && !pq.empty()){
//             set<int> temp_s;
//             temp_s.insert(pq.top()[0]);
//             temp_s.insert(pq.top()[1]);
//             set<int> c;
//             set_union(s.begin(),s.end(),temp_s.begin(),temp_s.end(),inserter(c,c.begin()));
//             if(c.size() == 0) return pq.top()[2];
//             else if(c.size() == 1){
//                 auto it = c.begin();
//                 del_node = *it;
//                 break;
//             }
//             pq.pop();
//         }
//         while(!pq.empty()){
//             vector<int> xx = {pq.top()[0], pq.top()[1]};
//             if(find(xx.begin(), xx.end(), del_node) == xx.end()) return pq.top()[2];
//         }
//         return 0;

//     }

// };

int main(){


    // priority_queue<int> aa;

    // aa.push(7);
    // aa.push(15);
    // aa.push(7);
    // aa.push(18);
    // aa.push(16);
    // aa.push(8);
    // while(!aa.empty()){
    //     cout << aa.top() << " ";
    //     aa.pop();
    // }
    vector<vector<int>> v = {{3,10}, {5, 15}, {10, 2}, {4, 4}};
    Solution s;
    int x = s.minimumDistance(v);
    return 0;
}


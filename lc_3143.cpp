#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Compare{
public:
    bool operator()(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
};

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int res = 0;
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        for(int ii = 0; ii < points.size(); ii++){
            pq.push({ii, max(abs(points[ii][0]), abs(points[ii][1]))});
        }
       // cout << pq.top()[0] << " " << pq.top()[1] << endl;
        unordered_map<char, int> m;
        while(!pq.empty()){
            int temp = pq.top()[1];
            int temp_a = 0;
            while(!pq.empty() && pq.top()[1] == temp){
                if(!(m.find(s[pq.top()[0]]) == m.end())) return res;
                else m[s[pq.top()[0]]] == 1;
                pq.pop();
                temp_a++;
            }
            res += temp_a;
        }
        return res;
    }
};


int main(){
    vector<vector<int>> points = {{-1,-4}, {16,-8}, {13,-3}, {-12,0}};
    string s = "abda";
    Solution ss;
    int res = ss.maxPointsInsideSquare(points, s);
    return 0;
}
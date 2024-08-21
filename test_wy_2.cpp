#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int m, a, b;
    cin >> m;
    map<int, vector<int>> mp;
    map<int, int> num;

    map<int, int> vis;
    for(int ii = 0; ii < m / 2; ii++){
        cin >> a >> b;
        vis[b] = 1;
        if(vis.find(a) == vis.end()) vis[a] = 0;
        if(mp.find(a) == mp.end()) mp[a] = {b};
        else mp[a].push_back(b);
    }
    queue<int> q;
    for(auto it = vis.begin(); it != vis.end(); it++){
        if(it->second == 0){
            q.push(it->first);
            break;
        }
    }
    int floor = 1;
    while(!q.empty()){
        int len = q.size();
        for(int ii = 0; ii < len; ii++){
            int temp_a = q.front();
            num[temp_a] == floor;
            q.pop();
            if(mp.find(temp_a) == mp.end()) continue;
            for(int xx : mp[temp_a]) q.push(xx);
        }
    }


    int n;
    cin >> n;
    vector<int> res;
    for(int ii = 0; ii < n / 2; ii++){
        int tag = 0;
        cin >> a >> b;
        if(abs(num[a] - nums[b]) < 3){
            res.push_back(a);
            res.push_back(b);
        }
        
    }
    sort(res.begin(), res.end());
    for(auto xx : res){
        cout << xx << ' ';
    }
    cout << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")
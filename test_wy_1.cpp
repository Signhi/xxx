#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;




class Sulotion{
public:
    int find_person_num(vector<vector<int>>& times){
        sort(times.begin(), times.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        int res = times[0][2], temp_res = times[0][2];
        vector<int> temp_v = {times[0][1]};
        for(int ii = 1; ii < times.size(); ii++){
            temp_res += times[ii][2];
            int xx = temp_res;
            for(int jj = 0; jj < temp_v.size(); jj++){
                if(times[ii][0] >= temp_v[jj]) xx -= times[jj][2];
            }
            res = max(res, xx);
            temp_v.push_back(times[ii][1]);
        }
        return res;

    }
};







int main() {
    int M, N;
    cin >> M;
    Sulotion sss;
5    for(int ii = 0; ii < M; ii++){
        cin >> N;
        vector<vector<int>> times;
        for(int jj = 0; jj < N; jj++){
            string temp_s;
            vector<int> all_fb(3);
            vector<string> temp_x;
            for(int kk = 0; kk < 3; kk++){
                cin >> temp_s;
                temp_x.push_back(temp_s);
            }
            all_fb[0] = stoi(temp_x[0].substr(0,2)) * 60 + stoi(temp_x[0].substr(3, 2));
            all_fb[1] = all_fb[0] + stoi(temp_x[2]);
            all_fb[2] = stoi(temp_x[1]);
            times.push_back(all_fb);
        }

        cout << sss.find_person_num(times) << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int len = temperatures.size();
        //vector<int> res(len, 0);
        int ii = 0;
        while(ii < len){
            while(ii < len - 1 && temperatures[ii] >= temperatures[ii + 1]){
                s.push(temperatures[ii]);
                temperatures[ii] = 0;
                ii++;
            } 
            if(ii == len - 1){
                break;
            } 
            else{
                temperatures[ii] = 0;
                s.push(temperatures[ii]);
                int temp = ii;
                int count = 1;
                while(!s.empty() && s.top() < temperatures[ii + 1]){
                    while(temperatures[temp] != 0){
                        temp--;
                        count++;
                    } 
                    temperatures[temp] = count;
                    count++;
                    temp--;
                    s.pop();
                }
                
                ii++;
            }
        }
        temperatures[len - 1] = 0;
        return temperatures;
    }

    
};

int main(){


    vector<int> v = {73,74,75,71,69,72,76,73};
    Solution s;
    // for(int ii = 0; ii < 5; ii++) s.addA();
    // vector<int> res = s.dailyTemperatures(v);
    return 0;

}

// 构建红黑树


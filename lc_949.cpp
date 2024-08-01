#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        string res;
        vector<int> v = {0, 1, 2, 3};
        sort(arr.begin(), arr.end());
        int ptr = 0;
        while(ptr < 4 && arr[ptr] < 3){
            ptr++;
        }
        if(ptr == 0) return "";
        res += to_string(arr[ptr - 1]);
        auto it = find(v.begin(), v.end(), ptr - 1);
        v.erase(it);
        ptr = 0;
        if(res == "2"){
            while(ptr < 4 && arr[ptr] < 4) ptr++;
            if(ptr == 1) return "";
            if(find(v.begin(), v.end(), ptr - 1) != v.end()){
                res += to_string(arr[ptr - 1]);
                it = find(v.begin(), v.end(), ptr - 1);
                v.erase(it);
            }
            else{
                res += to_string(arr[ptr - 2]);
                it = find(v.begin(), v.end(), ptr - 2);
                v.erase(it);
            }
            int min_mi = min(arr[v[0]], arr[v[1]]);
            int max_mi = max(arr[v[0]], arr[v[1]]);
            if(min_mi > 5) return "";
            if(max_mi < 6){
                res += ':';
                res += to_string(max_mi);
                res += to_string(min_mi);
            }
            else{
                res += ':';
                res += to_string(min_mi);
                res += to_string(max_mi);
            }
        }
        else{
            while(ptr < 4 && arr[ptr] < 10) ptr++;
            if(ptr == 1) return "";
            if(find(v.begin(), v.end(), ptr - 1) != v.end()){
                res += to_string(arr[ptr - 1]);
                it = find(v.begin(), v.end(), ptr - 1);
                v.erase(it);
            }
            else{
                res += to_string(arr[ptr - 2]);
                it = find(v.begin(), v.end(), ptr - 2);
                v.erase(it);
            }
            int min_mi = min(arr[v[0]], arr[v[1]]);
            int max_mi = max(arr[v[0]], arr[v[1]]);
            if(min_mi > 5) return "";
            if(max_mi < 6){
                res += ':';
                res += to_string(max_mi);
                res += to_string(min_mi);
            }
            else{
                res += ':';
                res += to_string(min_mi);
                res += to_string(max_mi);
            }
        }
        
        return res; 
    }

    
    
};




int main(){
    
    
    
    vector<int> v = {2, 3, 6, 9};
    Solution s;
    string res = s.largestTimeFromDigits(v);
    return 0;
}
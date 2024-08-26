#include <vector>
#include <iostream> 

using namespace std;



class Solution {
public:
    long long minEnd(int n, int x) {
        if(n == 1) return x;
        int n_c = 0, temp = x, temp_c = 1;
        while(temp > 0){
            temp = temp >> 1;
            n_c++;
        }
        int temp_p = 1 << n_c;
        vector<int> v_f = {x};
        for(int ii = x + 1; temp_c < n, ii < x + temp_p; ii++){
            if((x & ii) == x){
                v_f.push_back(ii);
                temp_c++;
            } 
        } 
        if(temp_c == n) return v_f[n - 1];
        
        int l = n / temp_c, r = n % temp_c;
        if(r == 0) {
            l--;
            r = temp_c;
        }
        
        return v_f[r - 1] + temp_p * l;
    }
};


int main(){
    Solution s;
    int res = s.minEnd(5, 6);
    return 0;

}


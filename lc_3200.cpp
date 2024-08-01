#include<iostream>

using namespace std;

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
         int max_n = red > blue ? red : blue;
         int min_n = blue > red ? red : blue;
         int res_1 = 0, res_2 = 0, xx = 0;
         while(max_n >= 0 and min_n >= 0){
            min_n = min_n - (xx * 2 + 1);
            if(min_n < 0) break;
            res_1++;
            max_n = max_n - (xx * 2 + 2);
            if(max_n < 0) break;
            res_1++;
            xx++;
         }
         xx = 0;
         max_n = red > blue ? red : blue;
         min_n = blue > red ? red : blue;
         while(max_n >= 0 and min_n >= 0){
            max_n = max_n - (xx * 2 + 1);
            if(max_n < 0) break;
            res_2++;
            min_n = min_n - (xx * 2 + 2);
            if(min_n < 0) break;
            res_2++;
            xx++;
         }
         return max(res_1, res_2);
         
    }
};

int main(){
    int red = 2, blue = 4;
    Solution s;
    int  xx = s.maxHeightOfTriangle(red, blue);
    return 0;
}
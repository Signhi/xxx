#include <string>
#include <iostream>

using namespace std;



class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int l = 0, r = 0, count_c = 0, count_h = 0;
        int res = 0;
        while(r < answerKey.size()){
            while(count_c < k + 1 && r < answerKey.size()){
                if(answerKey[r] == 'F') count_c++;
                count_h++;
                r++;
            }
            if(r == answerKey.size() && count_c != k + 1) res = max(res, count_h);
            else res = max(res, count_h - 1);
            if(count_c == k + 1){
                while(answerKey[l] == 'T'){
                    l++;
                    count_h--;
                }
                l++;
                count_h--;
                count_c--;
            }
        }
        l = 0, r = 0, count_c = 0, count_h = 0;
        while(r < answerKey.size()){
            while(count_c < k + 1 && r < answerKey.size()){
                if(answerKey[r] == 'T') count_c++;
                count_h++;
                r++;
            }
            if(r == answerKey.size() && count_c != k + 1) res = max(res, count_h);
            else res = max(res, count_h - 1);
            if(count_c == k + 1){
                while(answerKey[l] == 'F'){
                    l++;
                    count_h--;
                }
                l++;
                count_h--;
                count_c--;
            }
        }
        return res;
    }
};

int main(){
    string ss = "TFFT";
    int k = 1;
    Solution s;
    int res = s.maxConsecutiveAnswers(ss, 1);
    return 0;

}
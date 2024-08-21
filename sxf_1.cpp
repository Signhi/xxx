#include <iostream>
using namespace std;

int main() {
    string s, temp_s;
    cin >> s >> temp_s;
    int ptr = 0, ptr_s = 0;
    char last_c = 'x';
    int res = 0;
    while(ptr < temp_s.size() && ptr_s < s.size()){
        //char c = temp_s[ptr];
        if(temp_s[ptr] == '*' && s[ptr_s] != last_c){
            ptr++;
        } 
        else if(temp_s[ptr] == '*'){
            int temp_p = ptr + 1;
            int count = 0;
            while(temp_p < temp_s.size() && (temp_s[temp_p] == '*' || temp_s[temp_p] == last_c)){
                if(temp_s[temp_p] == last_c) count++;
                temp_p++;
            } 
            ptr = temp_p;
            temp_p = ptr_s;
            int count_s = 0;
            while(temp_p < s.size() && s[temp_p] == last_c){
                temp_p++;
                count_s++;
            } 
            if(count_s < count) {
                res += count_s;
                break;
            }
            res += count_s;
            ptr_s = temp_p;
        }
        else{
            if(temp_s[ptr] == s[ptr_s]){
                last_c = temp_s[ptr];
                ptr++;
                ptr_s++;
                res++;
            }
            else break;
        }
    }
    cout << res << endl;
    return 0;

}
// 64 位输出请用 printf("%lld")
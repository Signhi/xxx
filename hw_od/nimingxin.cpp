#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <sstream>
#include <algorithm>

using namespace std;


class Solution{
public:
    // bool findNews(vector<string>& news, vector<string>& letter){
    //     // unordered_map<unordered_map<char, int>, int> m;
    //     set<unordered_map<char, int>> ms;
    //     for(string temp_s : news){
    //         unordered_map<char, int> temp_m;
    //         for(char c : temp_s){
    //             if(temp_m.find(c) == temp_m.end()) temp_m[c] = 1;
    //             else temp_m[c]++;
    //         }
    //         if(m.find(temp_m) == m.end()) m[temp_m] == 1;
    //         else m[temp_m]++;
    //     }
    //     for(string temp_s : letter){
    //         unordered_map<char, int> temp_m;
    //         for(char c : temp_s){
    //             if(temp_m.find(c) == temp_m.end()) temp_m[c] = 1;
    //             else temp_m[c]++;
    //         }
    //         if(m.find(temp_m) == m.end()) return false;
    //         if(m[temp_m] == 0) return false;
    //         m[temp_m]--;
    //     }
    //     return true;
    // }

    bool findNews(vector<string>& news, vector<string>& letter){
        // unordered_map<unordered_map<char, int>, int> m;
        vector<unordered_map<char, int>> v_m;
        for(string temp_s : news){
            unordered_map<char, int> temp_m;
            for(char c : temp_s){
                if(temp_m.find(c) == temp_m.end()) temp_m[c] = 1;
                else temp_m[c]++;
            }
            if(find(v_m.begin(), v_m.end(), temp_m) == v_m.end()) v_m.push_back(temp_m);
        }
        for(string temp_s : letter){
            unordered_map<char, int> temp_m;
            for(char c : temp_s){
                if(temp_m.find(c) == temp_m.end()) temp_m[c] = 1;
                else temp_m[c]++;
            }
            if(find(v_m.begin(), v_m.end(), temp_m) == v_m.end()) return false;
        }
        return true;
    }
};

std::vector<std::string> splitString(const std::string &str, char delimiter) {
    std::vector<std::string> result;
    std::string token;
    std::istringstream tokenStream(str);
    
    while (std::getline(tokenStream, token, delimiter)) {
        result.push_back(token);
    }
    
    return result;
}


int main(){
    vector<string> news, letter;
    string s;
    getline(cin, s);
    news = splitString(s, ' ');
    getline(cin, s);
    letter = splitString(s, ' ');
    Solution ss;
    bool res = ss.findNews(news, letter);
    return 0;
}
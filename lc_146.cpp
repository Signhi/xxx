#include <unordered_map>
#include <list>
#include <iostream>

using namespace std;

class LRUCache {
private:
    int cap;
    unordered_map<int, list<vector<int>>::iterator> m;
    list<vector<int>> l;
    int length = 0;


public:
    LRUCache(int capacity) : cap(capacity) {
        
    }
    
    int get(int key) {
        unordered_map<int, list<vector<int>>::iterator>::iterator it = m.find(key);
        if(it == m.end()) return -1;
        list<vector<int>>::iterator l_it = m[key];
        int res = (*l_it)[1];
        l.erase(l_it);
        l.push_front({key, res});
        m[key] = l.begin();
        return res;
    }
    
    void put(int key, int value) {
        unordered_map<int, list<vector<int>>::iterator>::iterator it = m.find(key);
        if(it != m.end()){
            list<vector<int>>::iterator l_it = m[key];
            l.erase(l_it);
            l.push_front({key, value});
            m[key] = l.begin();
        }
        else{
            if(length < cap){
                l.push_front({key, value});
                m[key] = l.begin();
                length++;
            }
            else{
                int del = l.back()[0];
                list<vector<int>>::iterator l_it = m[del];
                m.erase(del);
                l.erase(l_it);
                l.push_front({key, value});
                m[key] = l.begin();
            }
            
        } 

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main(){
    LRUCache L(2);
    L.put(1, 0);
    L.put(2, 2);
    L.get(1);
    L.put(3, 3);
    L.get(2);
    L.put(4, 4);
    L.get(1);
    L.get(3);
    L.get(4);
    return 0;
}
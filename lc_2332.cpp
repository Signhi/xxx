#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int ridePersonCount = 0;
        int cap = 0;
        int ptr1 = 0;
        int ptr2 = 0;
        int n = buses.size();
        int m = passengers.size();
        int tag;
        while(ptr1 < n && ptr2 < m){
            while(ptr2 < m && passengers[ptr2] <= buses[ptr1]){
                ++cap;
                ++ptr2;
            }
            if(cap < capacity){
                ridePersonCount += cap;
                cap = 0;
                tag = true;
            }
            else {
                ridePersonCount += capacity;
                cap -= capacity;
                tag = false;
            }
            ++ptr1;
            cout << ridePersonCount << endl;
        }

        if(ridePersonCount == 0) return buses[n - 1];
        if(ptr2 == m && ptr1 < n) return buses[n - 1];

        int ptr;
        if(tag){
            if(passengers[ridePersonCount - 1] != buses[n - 1]) return buses[n - 1];
            ptr = ridePersonCount - 1;
        }
        else {
            ptr = ridePersonCount - 1;
        } 
        while(ptr >= 1 && passengers[ptr] - passengers[ptr - 1] == 1) {
                ptr--;
        }
        return passengers[ptr] - 1;
    }
};

int main(){
    vector<int> buses = {3};
    vector<int> passengers = {2, 4};
    int capacity = 2;
    Solution s;
    int res = s.latestTimeCatchTheBus(buses, passengers, capacity);
    return 0;
}
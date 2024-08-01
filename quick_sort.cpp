#include <iostream>
#include <vector>

using namespace std;


void quick_sort(vector<int>& v, int first, int last){
    
    if(first >= last) return;
    int t_f = first, t_l = last;
    int temp = v[first];
    while(first < last){
        while(last > first && v[last] > temp) --last;
        v[first] = v[last];
        while(first < last && v[first] <= temp ) ++first;
        v[last] = v[first];
    }
    v[first] = temp;
    quick_sort(v, t_f, first - 1);
    quick_sort(v, first + 1, t_l);
}

int main(){
    vector<int> x = {5, 6, 1, 3, 2, -1, 0};
    quick_sort(x, 0, x.size() - 1);
    for(auto xx : x) cout << xx << endl;
    return 0;
}
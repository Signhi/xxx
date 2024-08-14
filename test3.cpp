#include <iostream>
#include <vector>
using namespace std;

int main() {
    unsigned short n;
    cin >> n;
    int temp;
    vector<int> v(n, 100000);
    for(int ii = 0; ii < n; ii++){
        cin >> temp;
        if(temp != -1){
            int temp_mod = temp % n;
            for(int jj = 0; jj < n; jj++){
                if(v[(temp_mod + jj) % n] == 100000){
                    //cout << temp_mod << endl;
                    v[(temp_mod + jj) % n] = temp;
                    break;
                } 
            }
        }
    }
    for(int xx : v){
        if(xx != 100000) cout << xx << " ";
    }
    cout << endl;
    return 0;

}

// 64 位输出请用 printf("%lld")
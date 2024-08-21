#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int temp;
    vector<int> nums;
    for(int ii = 0; ii < n; ii++){
        cin >> temp;
        nums.push_back(temp);
    }
    vector<int> dp;
    dp.push_back(nums[0]);
    int max_num = nums[0];
    vector<int> max_v = {nums[0]};
    for(int ii = 1; ii < n && ii < k; ii++){
        max_num = max(max_num, nums[ii]);
        cout << max_num << endl;

        dp.push_back(nums[ii]);
        max_v.push_back(max_num);
    }
    
    for(int jj = k; jj < n; jj++){
        dp.push_back(max_v[jj - k] + nums[jj]);
        max_num = max(max_num, max_v[jj - k] + nums[jj]);
        cout << max_num << endl;
        max_v.push_back(max_num);
    }
    cout << max_num << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")
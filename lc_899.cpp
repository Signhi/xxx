#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* head = new TreeNode(preorder[0]);
        construcTree(head, preorder, postorder);
        return head;
    }

    void construcTree(TreeNode* head, vector<int>& preorder, vector<int>& postorder){
        if(preorder.size() > 1){
            head->left = new TreeNode(preorder[1]);
            int len = find(postorder.begin(), postorder.end(), preorder[1]) - postorder.begin() + 1;
            vector<int> temp_pre(preorder.begin() + 1, preorder.begin() + 1 + len);
            vector<int> temp_pos(postorder.begin(), postorder.begin() + len);
            construcTree(head->left, temp_pre, temp_pos);

            if(find(postorder.begin(), postorder.end(), preorder[1]) != postorder.end() - 2){
                head->right = new TreeNode(postorder[postorder.size() - 2]);
                auto it = find(postorder.begin(), postorder.end(), preorder[1]) + 1;
                int len = find(postorder.begin(), postorder.end(), preorder[1]) - postorder.begin() + 1;
                vector<int> temp_pre_1(preorder.begin() + len + 1, preorder.end());
                vector<int> temp_pos_1(it, postorder.end() - 1);
                construcTree(head->right, temp_pre_1, temp_pos_1);
            }
        }
        return ;

    }
};


int main(){
    vector<int> v1 = {1,2,4,5,3,6,7};
    vector<int> v2 = {4,5,2,6,7,3,1};
    Solution s;
    TreeNode* res = s.constructFromPrePost(v1, v2);
    return 0;

}
#include <iostream>
#include <sstream>
#include <vector>
#include <string>


using std::vector;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {};
};

/**
 * 前序遍历
 */
class Solution_preorderTraversal {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> v1;
        preorderTraversal2(root, v1);
        return v1;
    }

    void preorderTraversal2(TreeNode *root, std::vector<int> &v1){
        if (root == nullptr)
        {   
            // v1.push_back(-999);
            return;
        }
        v1.push_back(root->val);
        preorderTraversal2(root->left, v1);
        preorderTraversal2(root->right, v1);
    }
};

int main() {
    
    Solution_preorderTraversal s1 = Solution_preorderTraversal();
    TreeNode treeNodel = TreeNode(-1);
    TreeNode treeNoderl = TreeNode(3);
    TreeNode treeNoder = TreeNode(2, &treeNoderl, nullptr);
    TreeNode rootNode = TreeNode(1, &treeNodel, &treeNoder);
    std::vector<int>  res  = s1.preorderTraversal(&rootNode);
    for(int s : res) {
        std::cout << s << std::endl;
    }
    return 0;
}
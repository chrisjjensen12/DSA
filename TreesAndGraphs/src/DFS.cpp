
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};


//regular dfs
void dfs(TreeNode *root){

    if(root == nullptr){
        return;
    }

    dfs(root->left);
    dfs(root->right);

}

//dfs preorder traversal
void dfs_preorder(TreeNode *root){

    if(root == nullptr){
        return;
    }

    cout << root->val << endl;
    dfs_preorder(root->left);
    dfs_preorder(root->right);

}

//dfs inorder traversal
void dfs_inorder(TreeNode *root){

    if(root == nullptr){
        return;
    }

    dfs_inorder(root->left);
    cout << root->val << endl;
    dfs_inorder(root->right);

}


//dfs postorder traversal
void dfs_postorder(TreeNode *root){

    if(root == nullptr){
        return;
    }

    dfs_postorder(root->left);
    dfs_postorder(root->right);
    cout << root->val << endl;

}

/////////////////////////////////////////////////////////////////////////////////////

//find the maximum depth of a binary tree
int max_depth(TreeNode *root){
    if(root == nullptr){ //base case
        return 0; //return 0 because for an empty tree the depth is 0
    }

    //recursively call children 
    int right = max_depth(root->left);
    int left = max_depth(root->right);

    //do some logic 
    int maxdepth = max(right, left) + 1;

    //return the answer
    return maxdepth;
    
}

/////////////////////////////////////////////////////////////////////////////////////

bool path_sum_helper(TreeNode *root, int curr, int target){

    if(root == nullptr){
        return false; //if empty tree
    }

    //check if we're at a leaf
    if(root->right == nullptr && root->left == nullptr){
        //we're at a leaf, so check if it equals target
        return (curr + root->val) == target;
    }
    
    curr = curr + root->val;
    bool left = path_sum_helper(root->left, curr, target);
    bool right = path_sum_helper(root->right, curr, target);

    return left || right;

}

bool path_sum(TreeNode *root, int target){
    return path_sum_helper(root, 0, target); //use helper function because we need to keep track of a curr variable
}

/////////////////////////////////////////////////////////////////////////////////////

int good_nodes_helper(TreeNode *root, int maxnode){

    if(root == nullptr){
        return 0; //empty tree has 0 good nodes
    }


    int left = good_nodes_helper(root->left, max(maxnode, root->val));
    int right = good_nodes_helper(root->right, max(maxnode, root->val));

    //the number of good nodes in a subtree is equal to the # of good nodes in the left subtree + # of good nodes in the right subtree
    //plus 1 if the current node is a good node.
    int ans = left + right;
    if(root->val >= maxnode){
        ans += 1;
    }

    return ans;

}

int good_nodes(TreeNode *root){
    return good_nodes_helper(root, INT_MIN);
}


int main(){
    /*
    //tree that looks like this:

                    0
                  /  \
                 1    2
                /\     \
               3 4      5
                  \
                   6

    */  

    TreeNode* root = new TreeNode(0);
    TreeNode* one = new TreeNode(1);
    TreeNode* two = new TreeNode(2);
    TreeNode* three = new TreeNode(3);
    TreeNode* four = new TreeNode(4);
    TreeNode* five = new TreeNode(5);
    TreeNode* six = new TreeNode(6);
    
    root->left = one;
    root->right = two;
    one->left = three;
    one->right = four;
    four->right = six;
    two->right = five;
    

    // cout << "dfs preorder: " << endl;
    // dfs_preorder(root);
    // cout << "dfs inorder: " << endl;
    // dfs_inorder(root);
    // cout << "dfs postorder: " << endl;
    // dfs_postorder(root);


    /*
    Example 1: 104. Maximum Depth of Binary Tree
    Given the root of a binary tree, find the length of the longest path from the root to a leaf.
    */
    //cout << "max depth: " << max_depth(root) << endl;


    /*
    Example 2: 112. Path Sum
    Given the root of a binary tree and an integer targetSum, return true if there is a path from 
    the root to a leaf such that the sum of the nodes on the path is equal to targetSum, and return 
    false otherwise.
    */
    // if(path_sum(root, 7)){
    //     cout << "true" << endl;
    // }else{
    //     cout << "false" << endl;
    // }


    /*
    Example 3: 1448. Count Good Nodes in Binary Tree
    Given the root of a binary tree, find the number of nodes that are good. A node is good if the path 
    between the root and the node has no nodes with a greater value.
    */
    cout << good_nodes(root) << endl;


    return 0;
}



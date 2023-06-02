#include <iostream>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

void bfs(TreeNode *root){

    if(!root){
        return;
    }

    queue<TreeNode*> queue;
    queue.push(root); //push first node onto queue

    while(!queue.empty()){ //traverse the tree
        //get number of nodes on the current level of the tree
        int numNodesOnThisLevel = queue.size();
        cout << "\n";

        //for each node on the current level
        for(int i = 0; i < numNodesOnThisLevel; i++){
            TreeNode *node = queue.front(); //get the next node 
            queue.pop(); //we dont need the node on the queue anymore

            //do some logic on the current node here
            cout << node->val << " "; //print out the node 

            //put next level onto the queue
            if(node->left) queue.push(node->left);
            if(node->right) queue.push(node->right);
        }

    }

    cout << "\n";

    return;
}

vector<int> rightsideview(TreeNode* root){
    vector<int> ans;
    if(!root) return ans;
    queue<TreeNode*> queue;
    queue.push(root);

    while(!queue.empty()){
        int numNodesOnLevel = queue.size();

        //for each node on level
        for(int i = 0; i < numNodesOnLevel; i++){
            TreeNode* node = queue.front();
            queue.pop();

            if(i+1 == numNodesOnLevel) ans.push_back(node->val);

            if(node->left) queue.push(node->left);
            if(node->right) queue.push(node->right);
        }

    }
    
    return ans;

}

vector<int> largest_val_each_row(TreeNode *root){
    vector<int> ans;
    if(!root) return ans;

    queue<TreeNode*> queue;
    queue.push(root);

    while(!queue.empty()){
        int numNodesInRow = queue.size();
        int maxNum = INT_MIN;

        for(int i = 0; i < numNodesInRow; i++){
            TreeNode* node = queue.front();
            queue.pop();
            
            maxNum = max(maxNum, node->val);

            if(node->left) queue.push(node->left);
            if(node->right) queue.push(node->right);
        }

        ans.push_back(maxNum);

    }

    return ans;
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
    
    bfs(root);

    /*
    Example 1: 199. Binary Tree Right Side View
    Given the root of a binary tree, imagine yourself standing on the right side of it. 
    Return the values of the nodes you can see ordered from top to bottom.  
    */
    // vector<int> ans = rightsideview(root);

    // for(int i = 0; i < ans.size(); i++){
    //     cout << ans[i] << endl;
    // }

    /*
    Example 2: 515. Find Largest Value in Each Tree Row
    Given the root of a binary tree, return an array of the largest value in each row of the tree.
    */

    // vector<int> ans = largest_val_each_row(root);

    // for(int i = 0; i < ans.size(); i++){
    //     cout << ans[i] << endl;
    // }

    return 0;
}
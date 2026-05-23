class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        // both nodes are NULL
        if(p == NULL && q == NULL){
            return true;
        }

        // one is NULL and other is not
        if(p == NULL || q == NULL){
            return false;
        }

        // values are different
        if(p->val != q->val){
            return false;
        }

        // check left and right subtree
        return isSameTree(p->left, q->left) && 
               isSameTree(p->right, q->right);
    }
};
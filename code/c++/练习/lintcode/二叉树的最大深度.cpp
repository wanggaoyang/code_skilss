//二叉树的最大深度 
//递归!递归！ 
int maxDepth(TreeNode *root) 
{
    // write your code here
    if (NULL == root) 
    {
        return 0;
    }

    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);

    return max(left_depth, right_depth) + 1;
}

void invertBinaryTree(TreeNode *root) 
{
    // write your code here
    if(root==NULL) return;//µÝ¹é½áÊø
        
    TreeNode * temp;
    temp=root->left;
    root->left=root->right;
    root->right=temp;
        
    invertBinaryTree(root->left);
    invertBinaryTree(root->right);
}

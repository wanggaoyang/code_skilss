//二叉查找树中搜索区间
//这道题目把二叉树里面的中序遍历的作用体现出来了，对于一个二叉排序树，采用中序遍历并输出的方法，可以
//直接将二叉树里面的元素按从小到大输出！（应该直接就能想到中序遍历了）

void in_order(vector<int> &ret,TreeNode* root,int k1, int k2)
{
    if(root==NULL)
        return ;
    in_order(ret,root->left,k1,k2);
        
    if((root->val>=k1)&&(root->val<=k2))
        ret.push_back(root->val);
        
    in_order(ret,root->right,k1,k2);
        
}
    
vector<int> searchRange(TreeNode* root, int k1, int k2) 
{
    // write your code here
    vector <int> result;
    in_order(result,root,k1,k2);
    return result;
} 

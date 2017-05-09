//子树 
//思路：要找出子树，先找出和子树的根节点相同的结点，从该结点起，遍历子树的结点，与母树相同，判定为子树。 
bool identical(TreeNode *T1, TreeNode *T2)//这个函数的功能是，在母树中找到和子树根节点相同的点后，
//分别遍历这两个树剩下的结点，看是否相同。 
{
    if (T1 == NULL && T2 == NULL) 
        return true;
    if (T1 == NULL || T2 == NULL) 
        return false;
    if (T1->val != T2->val) 
        return false;
        
    return identical(T1->left, T2->left) && identical(T1->right, T2->right);
}
    
bool isSubtree(TreeNode *T1, TreeNode *T2) //这个函数的功能是，在母树中找到和子树根节点相同的结点，并 
{//将结点传给identical函数 
    // write your code here
    if (T2 == NULL) 
        return true;
    if (T1 == NULL) 
        return false;
    return identical(T1, T2) || isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
}

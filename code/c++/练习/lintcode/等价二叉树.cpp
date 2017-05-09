//µÈ¼Û¶ş²æÊ÷ 
bool isIdentical(TreeNode* a, TreeNode* b) 
{
    // Write your code here
    if(a==NULL&&b==NULL)return true;
	if(a!=NULL&&b!=NULL&&a->val==b->val&&isIdentical(a->left,b->left)&&isIdentical(a->right,b->right))
		return true;
	else
		return false;
}

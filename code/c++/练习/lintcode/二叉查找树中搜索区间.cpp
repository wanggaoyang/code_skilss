//�������������������
//�����Ŀ�Ѷ��������������������������ֳ����ˣ�����һ�������������������������������ķ���������
//ֱ�ӽ������������Ԫ�ذ���С�����������Ӧ��ֱ�Ӿ����뵽��������ˣ�

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

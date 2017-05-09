//���� 
//˼·��Ҫ�ҳ����������ҳ��������ĸ��ڵ���ͬ�Ľ�㣬�Ӹý���𣬱��������Ľ�㣬��ĸ����ͬ���ж�Ϊ������ 
bool identical(TreeNode *T1, TreeNode *T2)//��������Ĺ����ǣ���ĸ�����ҵ����������ڵ���ͬ�ĵ��
//�ֱ������������ʣ�µĽ�㣬���Ƿ���ͬ�� 
{
    if (T1 == NULL && T2 == NULL) 
        return true;
    if (T1 == NULL || T2 == NULL) 
        return false;
    if (T1->val != T2->val) 
        return false;
        
    return identical(T1->left, T2->left) && identical(T1->right, T2->right);
}
    
bool isSubtree(TreeNode *T1, TreeNode *T2) //��������Ĺ����ǣ���ĸ�����ҵ����������ڵ���ͬ�Ľ�㣬�� 
{//����㴫��identical���� 
    // write your code here
    if (T2 == NULL) 
        return true;
    if (T1 == NULL) 
        return false;
    return identical(T1, T2) || isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
}

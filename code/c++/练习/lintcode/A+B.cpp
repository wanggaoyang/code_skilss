//A+B���� 
int aplusb(int a, int b) 
    {
        // write your code here, try to do it without arithmetic operators.
        if(a==0)return b;  
        if(b==0)return a;  
        int x1 = a^b;  //��� �������ǽ�λ����λ�����濼�� 
        int x2 = (a&b)<<1;  //�����λ���Ƶģ� 
        return aplusb(x1,x2); //�ݹ飬֪��(a&b)==0,����û�н�λ�ˣ����� 
    } 

//���������ж��ٸ�1�������Ŀչ���˱��֮���� 
#include <iostream>
using namespace std; 
//�����ķ���¡�س����� 
int countOnes(int num)
    {
        int count = 0;
        while(num!=0)
        {
            num = num & (num-1);//ֱ�Ӱ�λ�룬ÿ��(num-1)��һ�Σ��ͻ���һ��1�����Ժ���count++�� 
            count++;//ֱ���������������û��1�ˣ�Ҳ����Ϊ0�ˣ�����ѭ���� 
        }
        return count; 
    }
//�����Լ���ı��취�����ǵ�����32��1ʱ�������и���ʱ���Ͳ������ˡ� 
int countOnes2(int num)
    {
        // write your code here
        int count=0;
        if(num==0)
            return 0;
        if(num==1)
            return 1;    
        
		while(num>1)
        {
            if((num%2)!=0)
            {
                count++;
			}
            
			num=num/2;
			
			if(num==1)
            	count++;
        }
            
    }
    
int main()
{
	int count =countOnes(511);
	cout<<count<<endl;
	return 0;
}

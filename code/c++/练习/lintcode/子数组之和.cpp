///������֮��
//˵��������һ��map��¼�ӵ�һ��Ԫ�ؿ�ʼ����ǰԪ��֮��
//�Լ���ǰԪ�ص��±꣬ÿһ��sumֵ�����Ӧһ���±꣬������sumֵ�ڶ��γ���ʱ����˵�����м��Ԫ��֮��Ϊ0�� 
//ʱ�临�Ӷ���O(n) 
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> subarraySum(vector<int> nums)
{  
    vector<int> ret;  
    int n;  
    if((n=nums.size())==0)  
        return ret;  
    map<int,int> mark;    
    mark[0]=-1;   //�Է���Ϊ����������ôӵ�һ��Ԫ�ؿ�ʼ  
    int sum=0;  
    for(int i=0;i<n;++i)
	{  
        sum+=nums[i];
        cout<<sum<<endl;
		cout<<mark.count(sum)<<endl;
        if(mark.count(sum))//��������������ж�mark���ӳ�����sum�������ģ����ٴγ�����ͬ��sumʱ����������1������ѭ�� 
		{  
            ret.push_back(mark[sum]+1);  //mark[sum]�м�¼�����ϴ�sumֵʱԪ�ص��±꣬����±꿪ʼ���¸��±���Ƿ��ص���λ�� 
            ret.push_back(i);  //����βλ�� 
            return ret;  
        }  
        mark[sum]=i;  //������һ��ӳ���ϵ��sum�ǵ�ǰԪ��֮�ͣ�i�ǵ�ǰԪ���±� 
    }  
    return ret;  
}  

int main()
{
	
	vector <int> ali;
	ali.push_back(-3);
	ali.push_back(1);
	ali.push_back(3);
	ali.push_back(-4);
	ali.push_back(4);
	
	vector <int> joe;
	
	joe=subarraySum(ali);
	for(int k=0;k<joe.size();k++)
		cout<<joe[k]<<endl;
	
	return 0;
}

///子数组之和
//说明：利用一个map记录从第一个元素开始到当前元素之和
//以及当前元素的下标，每一个sum值都会对应一个下标，当检测出sum值第二次出现时，即说明这中间的元素之和为0。 
//时间复杂度是O(n) 
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
    mark[0]=-1;   //以防和为零的序列正好从第一个元素开始  
    int sum=0;  
    for(int i=0;i<n;++i)
	{  
        sum+=nums[i];
        cout<<sum<<endl;
		cout<<mark.count(sum)<<endl;
        if(mark.count(sum))//这个函数是用来判断mark这个映射出现sum的数量的，当再次出现相同的sum时，函数返回1，进入循环 
		{  
            ret.push_back(mark[sum]+1);  //mark[sum]中记录的是上次sum值时元素的下标，这个下标开始的下个下标就是返回的首位置 
            ret.push_back(i);  //返回尾位置 
            return ret;  
        }  
        mark[sum]=i;  //建立的一种映射关系，sum是当前元素之和，i是当前元素下标 
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

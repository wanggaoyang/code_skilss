//二进制中有多少个1。这道题目展现了编程之美！ 
#include <iostream>
using namespace std; 
//完美的方法隆重出场！ 
int countOnes(int num)
    {
        int count = 0;
        while(num!=0)
        {
            num = num & (num-1);//直接按位与，每和(num-1)与一次，就会少一个1！所以后面count++， 
            count++;//直到这个二进制数中没有1了，也就是为0了，跳出循环！ 
        }
        return count; 
    }
//这是自己想的笨办法，但是当出现32个1时，或者有负数时，就不好用了。 
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

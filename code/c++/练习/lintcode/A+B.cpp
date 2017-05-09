//A+B问题 
int aplusb(int a, int b) 
    {
        // write your code here, try to do it without arithmetic operators.
        if(a==0)return b;  
        if(b==0)return a;  
        int x1 = a^b;  //异或 ，不考虑进位，进位由下面考虑 
        int x2 = (a&b)<<1;  //负责进位控制的， 
        return aplusb(x1,x2); //递归，知道(a&b)==0,即，没有进位了，结束 
    } 

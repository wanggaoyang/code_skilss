//余弦相似度，没什么难度，按着公示表达出来即可 
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

double cosineSimilarity(vector<int> A, vector<int> B)
{
    // write your code here
    double son=0;
    double amother=0;
    double bmother=0;
    if(A.size()==0||B.size()==0)
        return 2;
    if(A.size()!=B.size()) 
        return 2;
    for(int k=0;k<A.size();k++)
    {
        son+=A[k]*B[k];
        amother+=A[k]*A[k];
    	bmother+=B[k]*B[k];
    }
    double rel;
    if(amother==0)
        return 2;
    else
    {
        rel=son/(sqrt(amother)*sqrt(bmother));
        return rel;
    }
}

int main()
{
	vector <int> a;
	vector <int> b;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	cosineSimilarity(a,b);
	return 0;
}

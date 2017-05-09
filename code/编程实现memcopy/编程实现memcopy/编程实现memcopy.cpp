#include<iostream>
using namespace std;

void *memcopy2(void *memTo, const void *memForm, size_t size)
{
	if (memTo == NULL || memForm == NULL || size <= 0)
		return NULL;
	char *memTo_temp = (char *)memTo;
	char *memForm_temp = (char *)memForm;
	while (size--)
	{
		*memTo_temp = *memForm_temp;
		memTo_temp++;
		memForm_temp++;
	}
	return memTo;
}

int main()
{
	char memTo[20];
	char memForm[] = "hello world";

	memcopy2(memTo, memForm, 11);
	memTo[12] = '\0';
	cout << memTo << endl;

}
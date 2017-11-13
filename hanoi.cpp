//hanoi.cpp

#include <iostream>

using namespace std;

int count=0;

int hanoi(int n,char sp,char inter,char dest);

int main()
{
	cout << "count=" << hanoi(5,'a','b','c') << endl;
	return 0;
}

int hanoi(int n,char sp,char inter,char dest)
{
	if(1==n)
	{
		cout << n << ":" << sp << "->" << dest << endl;
		count++;
	}
	else
	{	
		hanoi(n-1,sp,dest,inter);
		cout << n << ":" << sp << "->" << dest << endl;
		count++;
		hanoi(n-1,inter,sp,dest);
	}
	return count;
}

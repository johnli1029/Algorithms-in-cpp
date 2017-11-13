//subdivide 2.0

#include <iostream>

using namespace std;

const int Len=66; // 65*n+1-(n-1)
const int Divs=6;
typedef char exm[Len];

void subdivide (char arr[],int low,int high,int level);
void (*pf)(char arr[],int low,int high,int level);

int main()
{
	pf=subdivide;
	exm ruler;
	for(int j=1;j<Len-2;++j)
		ruler[j]=' ';
	ruler[Len-1]='\0';
	ruler[Len-2]=ruler[0]='|';
	cout << ruler << endl;
	for(int j=1;j<Len-2;++j)
		ruler[j]=' ';
	for(int i=1;i<=Divs;++i)
	{
		(*pf)(ruler,1,Len-1,i);
		cout << ruler << endl;
		for(int j=1;j<Len-2;++j)
			ruler[j]=' ';
	}
	return 0;
	
}

void subdivide (char arr[],int low,int high,int level)
{
	int change=(low+high)/2;
	arr[change-1]='|';
	if (level>1)
	{
		subdivide(arr,low,change,level-1);
		subdivide(arr,change,high,level-1);
	}
	
}

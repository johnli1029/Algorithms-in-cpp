// the implement of bubble sorting by C++
// Just like verse, algorithms can be terse, elusive, dense, and even mysterious. 

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void trans (int *a , int *b);

int main()
{
	bool swapped ;
	int num , unsorted_num ;
	cout << "Just Enter a Number:" << endl ;
	cin >> num ;
	int *arr = new int[num] ;
	
/*	for(int i = 0 ; i < num ; i++)
	{
		cin >> *(arr + i ) ;
	}
*/	

	srand(time(0));
	for(int i = 0 ; i < num ; i++)
	{
		*(arr + i)= rand() ;
	} 
	unsorted_num = num ;
	
	do
	{
		swapped = false ;
		for (int i = 0 ; i < unsorted_num - 1; i++)
		{
			if (*(arr + i) > *(arr + i + 1))
			{
				trans ((arr + i) , (arr + i + 1)) ;
				swapped = true ;
			}
		}
		unsorted_num = unsorted_num - 1 ;
	}
	while (swapped);
	
	for(int i = 0 ; i < num ; i++)
	{
		cout << *(arr + i ) << "\t" ;
	}
	return 0 ;
}


void trans (int *a , int *b)
{
	int temp ;
	temp = *a ;
	*a = *b ;
	*b = temp ;
}

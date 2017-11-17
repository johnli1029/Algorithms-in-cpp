// Shuffle.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void FYShuffle (int arr[],int n);
void SattoloShuffle (int arr[],int n);


int main()
{
	srand(time(0)); // 别在函数里面重新设立种子 
	const int N=10;
	int arr[N]={0,1,2,3,4,5,6,7,8,9};
	int arr2[N]={0,1,2,3,4,5,6,7,8,9};
	FYShuffle(arr,N);
	for(int i=0; i < N; ++i)
		cout << arr[i] << " ";
	SattoloShuffle (arr2,N);
	cout << endl;
	for(int i=0; i < N; ++i)
		cout << arr2[i] << " ";
	return 0;
} 

void FYShuffle (int arr[],int n)
{
	for(int i = n-1; i > 0; i--)
	{
		int j = (int) (rand() / (double) RAND_MAX * (i+1)) ; // j = [0,i]
	//	cout << "j = " << j << endl;
		int swap = arr[j];
		arr[j] = arr [i];
		arr [i] = swap;
	}
}

void SattoloShuffle (int arr[],int n)
{
	for(int i = n-1; i > 0; i--)
	{
		int j = (int) (rand() / (double) RAND_MAX * (i)) ; // j = [0,i)
		int swap = arr[j];
		arr[j] = arr [i];
		arr [i] = swap;
	}
		
}



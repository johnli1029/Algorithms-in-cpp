// Binomial.cpp

#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

long count=0;

double Binomial1(int N, int k, double p);
double Binomial2(int N, int k, double p);
void timeclock(int N, int k, double p,double (*pf)(int,int,double));

int main()
{
	const int N=30;
	const double p=0.4;
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=i;j++)
		{
			cout << "Iteration:" << endl;
			timeclock(i,j,p,Binomial2);
			cout << "Recursion:" << endl;
			timeclock(i,j,p,Binomial1);
			cout << "count=" << count << endl << endl;
			count=0;
		}
	}
	return 0;
} 

double Binomial1(int N, int k, double p)
{
	++count;
	if(N < 0 || k < 0)
		return 0.0;
	else if(0==N && 0==k)
		return 1.0;
	return (1.0-p)*Binomial1(N-1,k,p)+p*Binomial1(N-1,k-1,p);
}

double Binomial2(int N, int k, double p)
{
	double arr[N+1][k+1];
	for(int i=0;i<=N;++i)
	{
		for(int j=0;j<=k;++j)
		{
			arr[i][j]=0.0;
		}
	}
	for(int i=0;i<=N;++i)
		arr[i][0]=pow((1.0-p),i);
	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=k;++j)
		{
			arr[i][j]=(1.0-p)*arr[i-1][j]+p*arr[i-1][j-1];
		}
	}
	return arr[N][k];
}

void timeclock(int N, int k, double p,double (*pf)(int,int,double))
{
	cout << "N=" << N << "\tk=" << k << endl;
	clock_t start=clock();
	cout << (*pf)(N,k,p) << endl;
	clock_t usage=clock()-start;
	cout << "usage: " << usage/1000.0 << " s.\n" << endl;
}


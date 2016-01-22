#include "stdafx.h"


const int maxm = 1000;
const int maxn = 1000;

int a [maxm][maxn];

int f1[maxm][maxn];
int f2[maxm][maxn];

int besta [maxn];
int n, m;


int min( int a, int b, int c) 
{
	
	if ((a <= b) && (a <= c)) {
		return a;
	}
		
	else
	{
		if ((b <= a) && (b <= c))
		{
			return	b;
		}
		else
		 {
			 if ((c <= b) && (c <= a))
				 return c;
		 }
			
		}
}

int minn(int a, int b, int c)
{
	if ((a <= b) && (a <= c))
	{
		return  -1;
	}
	else
	{
		if ((b <= a) && (b <= c))
		{
			return  0;
		}
			 else
			 {
				 if ( (c <= b) && (c <= a))
				 {
				    return 1;
				 }
					 
			 }
			
	}
	
	
		
}




int mx(int a)
{
	if (a<1) return  1;
	if (a>n) return n;
}







int main()
{

	for (auto j = 1; j < m ; j++)
	{
		for (auto i = 0; i < n; i ++)
		{
			a[j] [i] = min(a[j - 1][ mx(i - 1)], a[j - 1][ i], a[j - 1][ mx(i + 1)]) + a[j][ i];
		}
	}


auto b = 1;
for (auto i = 0; i < n; i++)
{
	if (a[m][ b]>a[m][ i])
		b  = i;
}

auto bestst = a[m][ b];

besta[m] = b;
for (auto i = m - 1; i>0; i--)
{
	besta[i] = mx(besta[i + 1] + minn(a[i][ mx(besta[i + 1] - 1)], a[i][ mx(besta[i + 1])], a[i][ mx(besta[i + 1] + 1)]));
}



	return 0;
}
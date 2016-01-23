#include "stdafx.h"
#include <ostream>
#include <iostream>

/*
const int maxm = 5;
const int maxn = 4;



int f1[maxm][maxn];
int f2[maxm][maxn];

int besta [maxn];
int n = 4, m = 5;


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

	int a[maxm][maxn] =
	{
		{ 4,  1, 6, 8 },
		{ 1,  1, 6, 9 },
		{ 10, 5, 1, 9 },
		{ 7,  6, 1, 9, },
		{ 10, 2, 6, 2, },
	};

	for (auto j = 1; j < m ; j++)
	{
		for (auto i = 0; i < n; i ++)
		{
			a[j] [i] = min(a[j - 1][ mx(i - 1)], a[j - 1][ i], a[j - 1][ mx(i + 1)]) + a[j][ i];
		}
	}


auto b = 0;
for (auto i = 0; i < n; i++)
{
	if (a[m][ b]>a[m][ i])
		b  = i;
}

int bestst = a[m][b];

besta[m] = b;
for (auto i = m ; i>0; i--)
{
	besta[i] = mx(besta[i + 1] + minn(a[i][ mx(besta[i + 1] - 1)], a[i][ mx(besta[i + 1])], a[i][ mx(besta[i + 1] + 1)]));
}

std::cout << bestst  << std::endl;

 for (auto i = 0; i < m; i++)
{
   std::cout <<  a[i][ mx(besta[i])] << ' ' ;
}


	return 0;
}
*/


using namespace std;
const int n = 4;
const int m = 5;

const int V = 20; // 4*5

//алгоритм Дейкстры
void Dijkstra(int** GR, int st)
{
	int distance[V], count, index, i, u, m = st + 1;
	bool visited[V];
	for (i = 0; i<V; i++)
	{
		distance[i] = INT_MAX; visited[i] = false;
	}
	distance[st] = 0;
	for (count = 0; count<V - 1; count++)
	{
		int min = INT_MAX;
		for (i = 0; i<V; i++)
			if (!visited[i] && distance[i] <= min)
			{
				min = distance[i]; index = i;
			}
		u = index;
		visited[u] = true;
		for (i = 0; i<V; i++)
			if (!visited[i] && GR[u][i] && distance[u] != INT_MAX &&
				distance[u] + GR[u][i]<distance[i])
				distance[i] = distance[u] + GR[u][i];
	}
	cout << "Стоимость пути из начальной вершины до остальных:\t\n";
	for (i = 0; i < V; i++) {
		if (distance[i] != INT_MAX)
		{
			cout << m << " > " << i + 1 << " = " << distance[i] << endl;
		}
		else
		{
			cout << m << " > " << i + 1 << " = " << "маршрут недоступен" << endl;
		}
	}
}

bool IsInRange(int cI,int cJ)
{
	return (cI >= 0 && cI < m) && (cJ>=0 && cJ < n);
}

int** GenereateSmegnostGraph(int matrix[n][m])
{
	int** table = new int*[V];
	for (int i = 0; i < V; ++i)
	{
		table[i] = new int[V];

		for (int j = 0; j < V; j++)
		{
			table[i][j] = 0;
		}
	}

	int cI;
	int cJ;

	for (int index = 0; index < V; index++ )
	{
		// tranlsate index
		
		int j = index / m;
		int i = index - j*m;

		// check can move 8 direction 
		// using ULITKA NOTATION:
		/*
			1 2 3
			8 x 4
			7 6 5
		*/



		//check 1

		cI = i - 1;
		cJ = j - 1;

		// if in range
		if (IsInRange(cI,cJ))
		{
			//find number

			int tV = index - m - 1;

			//write into smejnost
			table[index][tV] = matrix[cJ][cI];
		}

		// check 2
		cI = i;
		cJ = j-1;
		if (IsInRange(cI, cJ))
		{
			//find number

			int tV = index - m;

			//write into smejnost
			table[index][tV] = matrix[cJ][cI];
		}

		// check 3
		cI = i + 1;
		cJ = j - 1;
		if (IsInRange(cI, cJ))
		{
			//find number

			int tV = index - (m - 1);

			//write into smejnost
			table[index][tV] = matrix[cJ][cI];
		}

		// check 4
		cI = i + 1;
		cJ = j ;
		if (IsInRange(cI, cJ))
		{
			//find number

			int tV = index +1;

			//write into smejnost
			table[index][tV] = matrix[cJ][ cI];
		}

		// check 5
		cI = i + 1;
		cJ = j + 1;
		if (IsInRange(cI, cJ))
		{
			//find number

			int tV = index + m + 1;

			//write into smejnost
			table[index][tV] = matrix[cJ][cI];
		}

		// check 6
		cI = i;
		cJ = j + 1;
		if (IsInRange(cI, cJ))
		{
			//find number

			int tV = index + m;

			//write into smejnost
			table[index][tV] = matrix[cJ][cI];
		}

		// check 7
		cI = i -1;
		cJ = j + 1;
		if (IsInRange(cI, cJ))
		{
			//find number

			int tV = index + (m-1);

			//write into smejnost
			table[index][tV] = matrix[cJ][cI];
		}

		// check 8
		cI = i ;
		cJ = j - 1;
		if (IsInRange(cI, cJ))
		{
			//find number

			int tV = index - 1;

			//write into smejnost
			table[index][tV] = matrix[cJ][cI];
		}
	}

	return table;
}



//главная функция
void main()
{

	setlocale(LC_ALL, "Rus");

	int strafMatrix[n][m] = {
		{3,2,8,6,4},
		{4,7,12,9,1},
		{55,8,3,2,8},
		{20,7,4,9,1},
	};

	int **GR = GenereateSmegnostGraph(strafMatrix);

	int start;
	
	
	for (int i = 0; i < V; ++i)
	{
		for (int j = 0; j < V; j++)
		{
			cout << GR[i][j] << " ";
		}
		cout << endl;
	}
	
	// = {
		/*{ 0, 1, 4, 0, 2, 0 },
		{ 0, 0, 0, 9, 0, 0 },
		{ 4, 0, 0, 7, 0, 0 },
		{ 0, 9, 7, 0, 0, 2 },
		{ 0, 0, 0, 0, 0, 8 },
		{ 0, 0, 0, 0, 0, 0 } };*/
	cout << "Начальная вершина >> "; cin >> start;
	Dijkstra(GR, start - 1);

	GR = nullptr;

	system("pause>>void");
}
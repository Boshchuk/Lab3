#include "stdafx.h"
#include <ostream>
#include <iostream>
#include <vector>

using namespace std;

const int size_n = 4;
const int size_m = 5;

const int V = 20; // 4*5

struct ResultItem
{
	int straph;
	vector<int> trace;
};

struct Result
{
	ResultItem ForEachStr[size_n-1];
};

//алгоритм Дейкстры
Result DijkstraWithAction(int** GR, int st, int stratValue, bool part1)
{
	int distance[V], count, index, i, u, m = st + 1;

	vector<int> trace[V];

	bool visited[V];
	for (i = 0; i<V; i++)
	{
		distance[i] = INT_MAX;
		visited[i] = false;
	}
	distance[st] = 0;

	trace[st].push_back(stratValue);


	for (count = 0; count<V - 1; count++)
	{
		int min = INT_MAX;
		for (i = 0; i < V; i++)
		{
			if (!visited[i] && distance[i] <= min)
			{
				min = distance[i];
				index = i;
			}
		}
		u = index;
		visited[u] = true;
		for (i = 0; i < V; i++) 
		{
			if (!visited[i] && GR[u][i] && distance[u] != INT_MAX &&
				distance[u] + GR[u][i] < distance[i])
			{
				//trace[i].push_back(distance[u]);

				for (auto it = trace[u].begin(); it != trace[u].end(); ++it)
				{
					trace[i].push_back(*it);
				}
				trace[i].push_back(GR[u][i]);
				distance[i] = distance[u] + GR[u][i];
			}
		}
	}

	if (part1)
	{
		int arMin[size_n - 1];
		int dis[size_n - 1];
		int l = 0;
	
		for (int i = size_m; i < V;)
		{
			int t_MIn= INT_MAX;
			arMin[l] = i;
			
			for (int j = 0; j < size_m; j++)
			{
				if (distance[i+j] <= t_MIn)
				{
					t_MIn = distance[i+j];
					arMin[l] = i + j;
					dis[l] =  distance[i + j];
				}
			}
			i = i + size_m;
			l++;
		}

		Result res;
		//res.Pos = 
		for (int i = 0; i < size_n - 1;i++)
		{
			int number = arMin[i];
		/*	cout << "Pos of min stroku in stroka:" << i + 2 << "      " <<arMin[i] << endl;
			cout << "Put:";
			
			for (auto it = trace[number].begin(); it != trace[number].end(); ++it)
			{
				cout << *it << " ";
			}
			cout << endl;*/

			
			res.ForEachStr[i].trace = trace[number];
			res.ForEachStr[i].straph = dis[i];
		}

		return res;

	}
	else
	{
		cout << "Стоимость пути из начальной вершины до остальных:\t\n";
		for (i = 0; i < V; i++)
		{
			if (distance[i] != INT_MAX)
			{
				cout << m << " > " << i + 1 << " = " << distance[i] << endl;

				for (auto it = trace[i].begin(); it != trace[i].end(); ++it)
				{
					cout << *it << " ";
				}
				cout << endl;

			}
			else
			{
				cout << m << " > " << i + 1 << " = " << "маршрут недоступен" << endl;
			}
		}
		Result r;
		return 	r;
	}


}

bool IsInRange(int cI,int cJ)
{
	return (cI >= 0 && cI < size_m) && (cJ>=0 && cJ < size_n);
}

int** GenereateSmegnostGraph(int matrix[size_n][size_m])
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
		
		int j = index / size_m;
		int i = index - j*size_m;

		// check can move 8 direction 
		// using ULITKA NOTATION:
		/*
			1 2 3
			8 x 4
			7 6 5
		*/

		//comment 1-4 and 8

		//check 1

		cI = i - 1;
		cJ = j - 1;

		// if in range
		if (IsInRange(cI,cJ))
		{
			//find number

			int tV = index - size_m - 1;

			//write into smejnost
			table[index][tV] = matrix[cJ][cI];
		}

		// check 2
		cI = i;
		cJ = j-1;
		if (IsInRange(cI, cJ))
		{
			//find number

			int tV = index - size_m;

			//write into smejnost
			table[index][tV] = matrix[cJ][cI];
		}

		// check 3
		cI = i + 1;
		cJ = j - 1;
		if (IsInRange(cI, cJ))
		{
			//find number

			int tV = index - (size_m - 1);

			//write into smejnost
			table[index][tV] = matrix[cJ][cI];
		}


		// check 8
		cI = i - 1;
		cJ = j;
		if (IsInRange(cI, cJ))
		{
			//find number

			int tV = index - 1;

			//write into smejnost
			table[index][tV] = matrix[cJ][cI];
		}
		//end of comment


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

			int tV = index + size_m + 1;

			//write into smejnost
			table[index][tV] = matrix[cJ][cI];
		}

		// check 6
		cI = i;
		cJ = j + 1;
		if (IsInRange(cI, cJ))
		{
			//find number

			int tV = index + size_m;

			//write into smejnost
			table[index][tV] = matrix[cJ][cI];
		}

		// check 7
		cI = i -1;
		cJ = j + 1;
		if (IsInRange(cI, cJ))
		{
			//find number

			int tV = index + (size_m-1);

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

	int strafMatrix[size_n][size_m] = {
		{3, 2, 8, 6, 4},
		{4, 7, 12,9, 1},
		{55,8, 3, 2, 8},
		{20,7, 4, 9, 1},
	};

	int **GR = GenereateSmegnostGraph(strafMatrix);

	int start;
	
	// рисование смежности для проверки
	/*for (int i = 0; i < V; ++i)
	{
		for (int j = 0; j < V; j++)
		{
			cout << GR[i][j] << " ";
		}
		cout << endl;
	}*/

	Result theMin;
	for (int i=0; i < size_n - 1; i++)
	{
		theMin.ForEachStr[i].straph = INT_MAX;
	}


	for (int i = 0; i < size_m; i ++)
	{
		int jk = i  / size_m;
		int ik = i  - jk*size_m;
		Result res = DijkstraWithAction(GR, i, strafMatrix[jk][ik], true);

		for (int ii = 0; ii < size_n - 1; ii++)
		{
			if (res.ForEachStr[ii].straph <=theMin.ForEachStr[ii].straph)
			{
				if (res.ForEachStr[ii].straph == theMin.ForEachStr[ii].straph)
				{
					if( res.ForEachStr[ii].trace.front() < theMin.ForEachStr[ii].trace.front())
					{
						theMin.ForEachStr[ii].straph = res.ForEachStr[ii].straph;
						theMin.ForEachStr[ii].trace = res.ForEachStr[ii].trace;
					}
				}
				else
				{
					theMin.ForEachStr[ii].straph = res.ForEachStr[ii].straph;
					theMin.ForEachStr[ii].trace = res.ForEachStr[ii].trace;
				}
			}
		}
	}

	

	for (int line = 0; line < size_n - 1; line++)
	{
		cout << "Минимальный штраф c 1 до строки #"<< line+2 << ": "<<theMin.ForEachStr[line].straph + theMin.ForEachStr[line].trace.front() <<endl;
		cout << "Маршрут штрафов:";
		for (auto it = theMin.ForEachStr[line].trace.begin(); it != theMin.ForEachStr[line].trace.end(); ++it)
		{
			cout << *it << " ";
		}
		cout << endl;
	}


	//cout << "Начальная вершина >> ";std::cin >> start;
	start = 1;
	int j = start - 1 / size_m;
	int i = start -1 - j*size_m;

	Result res =  DijkstraWithAction(GR, start - 1, strafMatrix[j][i],false);

	//GR = nullptr;

	std::system("pause>>void");
}
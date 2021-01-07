

#include <iostream>

using namespace std;


#define N 4 
#define INF 99999


void print(int matrix[][N])
{

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (matrix[i][j] == 99999)
				cout << "INF ";
			else
				cout << matrix[i][j] << "   ";
		}
		cout << endl;
	}
}


void fwAlgoritmus(int graph[][N])
{

	int temp[N][N];
	for (int i = 0; i < N; i++)  
	{

		for (int j = 0; j < N; j++)
		{
			temp[i][j] = graph[i][j];
		}
	}
	
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			
			for (int j = 0; j < N; j++)
			{

				if (temp[i][k] + temp[k][j] < temp[i][j])  
				{
					temp[i][j] = temp[i][k] + temp[k][j];
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{

		for (int j = 0; j < N; j++)
		{
			graph[i][j]=temp[i][j];
		}
	}

}



int main()
{
	int graph[N][N] =   {{0, 5, INF, 10},
							  {INF, 0, 3, INF},
						      {INF, INF, 0, 1},
						      {INF, INF, INF, 0}};
	

	fwAlgoritmus(graph);
	print(graph);
}



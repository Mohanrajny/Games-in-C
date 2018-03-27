#include<stdio.h>
#define N 9
#define UNASSIGNED 0
bool findUnassigned(int grid[N][N],int &row,int &col);
bool isSafe(int grid[N][N],int row,int col,int num);
bool solveSuduku(int grid[N][N])
{
	int row,col;
	if(!findUnassigned(grid,row,col))
	return true;
	
	for(int num=1;num<=N;num++)
	{
		if(isSafe(grid,row,col,num))
		{
			grid[row][col]=num;
			if(solveSuduku(grid))
				return true;
				
			grid[row][col]=UNASSIGNED;
			
		}
		
	}
	return false;
}
bool findUnassigned(int grid[N][N],int &row,int &col)
{
	for(row=0;row<N;row++)
	{
		for(col=0;col<N;col++)
		{
			if(grid[row][col]==UNASSIGNED)
			return true;
		}
	}
	return false;
}
bool isUsedInRow(int grid[N][N],int row,int num)
{
	for(int col=0;col<N;col++)
	{
		if(grid[row][col]==num)
		return true;
	}
	return false;
}
bool isUsedInCol(int grid[N][N],int col,int num)
{
	for(int row=0;row<N;row++)
	{
		if(grid[row][col]==num)
		{
			return true;
		}
	}
	return false;
}
bool isUsedInBox(int grid[N][N],int rowStart,int colStart,int num)
{
	for(int row=0;row<3;row++)
	{
		for(int col=0;col<3;col++)
		{
			if(grid[row+rowStart][col+colStart]==num)
			{
				return true;
			}
		}
	}
	return false;
}
bool isSafe(int grid[N][N],int row,int col,int num)
{
	return !isUsedInRow(grid,row,num) && !isUsedInCol(grid,col,num) && !isUsedInBox(grid,row-row%3,col-col%3,num);
	
}

void printGrid(int grid[N][N])
{
	printf("\tGrid\n\n");
	for(int i=0;i<N;i++)
	{
		 for(int j=0;j<N;j++)
		 {
		 	printf("%2d",grid[i][j]);
		 }
		 
		 	printf("\n");
	}
}
int main()
{
	  int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
	if(solveSuduku(grid))
	{
		printf("Solved Suduku");
		printGrid(grid);
	}
	else
	{
		printf("not Soleved");
		printGrid(grid);
	}
}

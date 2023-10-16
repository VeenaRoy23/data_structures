#include<stdio.h>

struct matrix
{
	int row;
	int col;
	int value;
}mat1[100],mat2[100],res[100];

void input(int mat[10][],int r,int c)
{
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
}



int conversion(int mat[10][],int r,int c,struct matrix arr[] )
{
	int k=0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(mat[i][j]!=0)
			{
				arr[k].row=i;
				arr[k].col=j;
				arr[k].value=mat[i][j];
				k++;
			}
			else
				continue;
		}
	}
	return k;
}

void display(struct matrix arr[],int n)
{
	printf("The matrix is\n");
	for(int i=0;i<n;i++)
	{
		printf("< %d, %d, %d",arr[i].row,arr[i].col,arr[i].value);
	}
}
	



int main()
{
	int r1,c1,r2,c2,choice;
	int matA[10][10];
	printf("Enter the number of rows and columns\n");
	scanf("%d%d",&r1,&c1);
	input(matA,r1,c1);
	int k=conversion(matA,r1,c1,mat1);
	display(mat1,k);
}
		

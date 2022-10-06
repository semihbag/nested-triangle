// Name = Semih
// Surname = Bağ
// Purpose = Draw triangles

#include <stdio.h>

void createBoard(int numberOfIteration);
void build(int height, int numberOfIteration, int row, int column);
void createTriangle(int height, int numberOfIteration, int row, int column);


int main()
{
	int numberOfIteration;
	printf("Enter a number of iterations: ");
	scanf("%d", &numberOfIteration);
    createBoard(numberOfIteration);
	return 0;
}


void createBoard(int numberOfIteration) 
{
	build(32, numberOfIteration, 1, 1);
}


void build(int height, int numberOfIteration, int row, int column)
{
	if ((row) != (height+1)) {
		createTriangle(height, numberOfIteration, row, column);
		if (column != (2 * height - 1)) {
			build(height, numberOfIteration, row, column + 1);
		}
		else {
			if (row < height) {
				printf("\n");
				build(height, numberOfIteration, row+1, 1);
			}
			else {
				build(height, numberOfIteration, row+1, 1);				
			}
		}
	}
	
}


void createTriangle(int height, int numberOfIteration, int row, int column)
{
	if (numberOfIteration==0) {
		if (((height - row) >= (column)) || ((column - height) >= (row))) {
			printf("_");
		}
		else {
			printf("1");
		}
	}
	else {
		if (row <= height/2) {
			if ((column < height/2) || (column > 3 * height/2)) {
				printf("_");
			}
			else {
				createTriangle(height/2, numberOfIteration-1, row, column - height/2);
			}
		}
		else {
			if (column < height) {
				createTriangle(height/2 ,numberOfIteration-1 ,row - height/2 ,column);
			}
			else if (column > height) {
				createTriangle(height/2, numberOfIteration-1, row - height/2, column - height);
			}
			else {
				printf("_");
			}
		}
	}		
}

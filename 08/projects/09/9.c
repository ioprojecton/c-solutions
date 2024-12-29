#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define ROWS 10
#define COLS 10
#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

int main()
{
 char array[ROWS][COLS];
 memset(array,'.',ROWS*COLS*sizeof(char));

srand((unsigned int)time(NULL));

unsigned char r=0;
unsigned char c=0;
char letter='A';

while(letter<='Z'){

unsigned char move=rand()%4;

switch(move){
case UP:
    if(r+1<ROWS && array[r+1][c]=='.') array[++r][c]=letter++;
    else if(r-1>=0 && array[r-1][c]=='.') array[--r][c]=letter++;
    else if(c+1<COLS && array[r][c+1]=='.') array[r][++c]=letter++;
    else if(c-1>=0 && array[r][c-1]=='.') array[r][--c]=letter++;
    else letter='a';//'a' is greater than 'Z' so bool var not needed!
break;

case DOWN:
    if(r-1>=0 && array[r-1][c]=='.') array[--r][c]=letter++;
    else if(r+1<ROWS && array[r+1][c]=='.') array[++r][c]=letter++;
    else if(c+1<COLS && array[r][c+1]=='.') array[r][++c]=letter++;
    else if(c-1>=0 && array[r][c-1]=='.') array[r][--c]=letter++;
    else letter='a';
break;

case RIGHT:
    if(c+1<COLS && array[r][c+1]=='.') array[r][++c]=letter++;
    else if(c-1>=0 && array[r][c-1]=='.') array[r][--c]=letter++;
    else if(r+1<ROWS && array[r+1][c]=='.') array[++r][c]=letter++;
    else if(r-1>=0 && array[r-1][c]=='.') array[--r][c]=letter++;
    else letter='a';
break;

case LEFT:
    if(c-1>=0 && array[r][c-1]=='.') array[r][--c]=letter++;
    else if(c+1<COLS && array[r][c+1]=='.') array[r][++c]=letter++;
    else if(r+1<ROWS && array[r+1][c]=='.') array[++r][c]=letter++;
    else if(r-1>=0 && array[r-1][c]=='.') array[--r][c]=letter++;
    else letter='a';

break;

default:
    break;
}
}

for(unsigned char i=0,b=0;i<ROWS;i++,b=0){
    while(b<COLS) putchar(array[i][b++]);
    putchar('\n');
    }
    return 0;
}

//How about this

	srand((unsigned) time(NULL));	

	char a[10][10];
	memset(a, '.', 10 * 10 * sizeof(char));

	short row = 0, col = 0;
	bool valid_move;

	a[0][0] = 'A';
	
	for (char i = 'B'; i <= 'Z'; i++)
	{
		valid_move = false;

		if ((row - 1 < 0 || a[row - 1][col] != '.') &&
	    	    (col + 1 > 9 || a[row][col + 1] != '.') &&
	    	    (row + 1 > 9 || a[row + 1][col] != '.') &&
	    	    (col - 1 < 0 || a[row][col - 1] != '.'))
	   	{	
			printf("Error, terminating.\n");
			break;
		}

		while (!valid_move)
		{
			switch (rand() % 4)
			{
				case 0: //walks north
					if (row - 1 < 0 || a[row - 1][col] != '.') break;

					valid_move = true;
					a[--row][col] = i;
					break;

				case 1: //walks east
					if (col + 1 > 9 || a[row][col + 1] != '.') break;

					valid_move = true;
					a[row][++col] = i;
					break;	

				case 2: //walks south
					if (row + 1 > 9 || a[row + 1][col] != '.') break;

					valid_move = true;
					a[++row][col] = i;
					break;	

				case 3: //walks west
					if (col - 1 < 0 || a[row][col - 1] != '.') break;

					valid_move = true;
					a[row][--col] = i;
					break;

				default:
					break;
			}
		} 
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			printf("%3c", a[i][j]);
		
		putchar('\n'); 
	} 

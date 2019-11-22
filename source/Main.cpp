#include <stdio.h>
#include <stdlib.h>

#define STUDENTS 3
#define EXAMS 4

void min(int grades[][EXAMS], int pup, int test);
void max(int grades[][EXAMS], int pup, int test);
void ave(int grades[][EXAMS], int pup, int test);
void printarr(int grades[][EXAMS], int pup, int test);
void printMenu();

void main()
{
	void(*processGrages[4])(int[][EXAMS], int, int) = { printarr,min,max,ave};
	int choice = 0;
	int stuGrades[STUDENTS][EXAMS] = {{77,68,86,73},{96,87,89,78},{70,90,86,81}};
	while (choice != 4)
	{
		do
		{
			printMenu();
			scanf_s("%d",&choice);
		} while (choice < 0 || choice >4);
		if (choice != 4)
		{
			(*processGrages[choice])(stuGrades,STUDENTS,EXAMS);
		}else{
			printf("Program Ended.\n");
		}
	}
	system("PAUSE");
}

void min(int grades[][EXAMS], int pup, int test)
{
	int i, j, lowg = 100;
	for (i = 0; i <= pup - 1; i++)
	{
		for (j = 0; j <= test - 1; j++)
		{
			if (grades[i][j] < lowg)
			{
				lowg = grades[i][j];
			}
		}
	}
	printf("\n\tThe lowest grade is %d\n", lowg);
}

void max(int grades[][EXAMS], int pup, int test)
{
	int i, j, hig = 100;
	for (i = 0; i <= pup - 1; i++)
	{
		for (j = 0; j <= test - 1; j++)
		{
			if (grades[i][j] < hig)
			{
				hig = grades[i][j];
			}
		}
	}
	printf("\n\tThe hightest grade is %d\n", hig);
}


void ave(int grades[][EXAMS], int pup, int test)
{
	int i, j, total;
	for (i = 0; i <= pup - 1; i++)
	{
		total = 0;
		for (j = 0; j <= test - 1; j++)
		{
			total += grades[i][j];
		}
		printf("\n\tThe average grade for student %d is %f\n", i + 1, (double)total / test);
	}
}


void printarr(int grades[][EXAMS], int pup, int test)
{
	int i, j;
	printf("\n\t        [0]  [1]  [2]  [3]");
	for (i = 0; i <= pup - 1; i++)
	{
		printf("\n\tstudentGrades[%d]", i);
		for (j = 0; j <= test - 1; j++)
		{
			printf("%-7d",grades[i][j]);
		}
		printf("\n");
	}
}

void printMenu()
{
	printf("\n\tEnter a choice:\n"
		"\t    0  Print the array of grades\n"
		"\t    1   Find the minimum grade\n"
		"\t    2   Find the maximum grade\n"
		"\t    3   Print the average on all\n"
		" tests for each student \n"
		"\t    4   End program\n\t?");
}
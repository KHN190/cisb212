#include "binheap.h"
#include <stdio.h>
#include <stdlib.h>

#define DATA100 "data100"

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define RESET "\033[0m"

int main() {

	/* Question 1. */
	puts(KBLU "\n1. Read in numbers in data 100 one by one and insert them into an initially empty heap. Print out the elements in the array (you should check the output to see if the heap order is satisfied)." RESET);

	// open file
	FILE * fp = fopen(DATA100, "rb+");
	if (!fp) 
	{
		puts(KRED "ERROR: Failed to open file." RESET);
		exit(-1);
	}
	// create binary heap
	PriorityQueue H = Initialize( 100 );
	// insert data
	int i, cur;
	for ( i = 0; i < 100; ++i )
	{
		fscanf(fp, "%d", &cur);
		Insert(cur, H);
	}

	// print data in order
	PrintHeap( H );
	// empty the heap
	MakeEmpty( H );
	// destroy the heap
	Destroy( H );


	/* Question 2. */
	puts(KBLU "\n2. Write a function to print out elements that are smaller than 15000 (not necessary in sorted order). The function should run in O(K), where K is the number of the elements you print out. " RESET);

	// open file
	fp = fopen(DATA100, "rb+");
	if (!fp) 
	{
		puts("ERROR: Failed to open file.");
		exit(-1);
	}
	// create binary heap
	H = Initialize( 100 );
	// insert data
	for ( i = 0; i < 100; ++i )
	{
		fscanf(fp, "%d", &cur);
		Insert(cur, H);
	}

	// print data in order
	PrintSmaller( 15000, H );
	// empty the heap
	MakeEmpty( H );
	// destroy the heap
	Destroy( H );

	/* Question 3. */
	puts(KBLU "\n3. Read in numbers in data 100 into an array. Implement BuildHeap and use it to convert the array into a heap.\n" RESET);

	// open file
	fp = fopen(DATA100, "rb+");
	if (!fp) 
	{
		puts("ERROR: Failed to open file.");
		exit(-1);
	}
	// create binary heap
	H = Initialize( 100 );
	// insert data
	for ( i = 0; i < 100; ++i )
	{
		fscanf(fp, "%d", &cur);
		Append(cur, H);
	}

	// random array
	puts("before:"); PrintHeap( H );
	// build heap
	BuildHeap( H );
	// print the heap
	puts("\nafter:"); PrintHeap( H );

	// empty the heap
	MakeEmpty( H );
	// destroy the heap
	Destroy( H );

	/* Question 4. */
	puts(KBLU "\n4. Find the 30th smallest element by repeatly using DeleteMin. \n" RESET);

	// open file
	fp = fopen(DATA100, "rb+");
	if (!fp) 
	{
		puts("ERROR: Failed to open file.");
		exit(-1);
	}
	// create binary heap
	H = Initialize( 100 );
	// build heap
	for ( i = 0; i < 100; ++i )
	{
		fscanf(fp, "%d", &cur);
		Append(cur, H);
	}
	BuildHeap( H );

	// first 30 smallest number
	int tmp;

	for ( i = 0; i < 30; ++i ) 
	{
		tmp = DeleteMin( H );
		printf("%d ", tmp);
	}
	printf("\n\n\t30th smallest number is" KYEL " %d\n" RESET, tmp);

	// empty the heap
	MakeEmpty( H );
	// destroy the heap
	Destroy( H );

	/* Question 5. */
	puts(KBLU "\n5. Implement Algorithm 6B and use it to find the 71st largest element in file data 100. \n" RESET);

	// open file
	fp = fopen(DATA100, "rb+");
	if (!fp) 
	{
		puts("ERROR: Failed to open file.");
		exit(-1);
	}
	// create binary heap
	H = Initialize( 100 );
	// build heap
	for ( i = 0; i < 71; ++i )
	{
		fscanf(fp, "%d", &cur);
		Append(cur, H);
	}
	BuildHeap( H );
	// replace the smallest element
	for ( i = 71; i < 100; ++i )
	{
		fscanf(fp, "%d", &cur);
		if ( cur > FindMin( H ) )
		{
			DeleteMin( H );
			Insert( cur, H );
		}
	}
	printf("\t71st largest number is" KYEL " %d\n" RESET, FindMin( H ));

	// empty the heap
	MakeEmpty( H );
	// destroy the heap
	Destroy( H );

	/* EXPERIMENT */
	puts(KBLU "\n6. Read in numbers in data 100 into an array. Implement BuildHeap and use it to convert the array into a 4-heap.\n" RESET);

	// open file
	fp = fopen(DATA100, "rb+");
	if (!fp) 
	{
		puts("ERROR: Failed to open file.");
		exit(-1);
	}
	// create binary heap
	H = Initialize4Heap( 100 );
	// build heap
	for ( i = 0; i < 100; ++i )
	{
		fscanf(fp, "%d", &cur);
		Append(cur, H);
	}

	// random array
	puts("before:"); PrintHeap( H );
	// build heap
	BuildHeap( H );
	// print the heap
	puts("\nafter:"); PrintHeap( H );

	/* Question 7. */
	puts(KBLU "\n7. Find the 30th smallest element by repeatly using DeleteMin. (4-heap)\n" RESET);

	// first 30 smallest number
	for ( i = 0; i < 30; ++i ) 
	{
		tmp = DeleteMin( H );
		printf("%d ", tmp);
	}
	printf("\n\n\t30th smallest number is" KYEL " %d\n" RESET, tmp);

	// empty the heap
	MakeEmpty( H );
	// destroy the heap
	Destroy( H );

	/* Question 8. */
	puts(KBLU "\n8. Implement Algorithm 6B and use it to find the 71st largest element in file data 100. (4-heap)\n" RESET);

	// open file
	fp = fopen(DATA100, "rb+");
	if (!fp) 
	{
		puts(KRED "ERROR: Failed to open file." RESET);
		exit(-1);
	}
	// create binary heap
	H = Initialize4Heap( 100 );
	// build heap
	for ( i = 0; i < 71; ++i )
	{
		fscanf(fp, "%d", &cur);
		Append(cur, H);
	}
	BuildHeap( H );
	// replace the smallest element
	for ( i = 71; i < 100; ++i )
	{
		fscanf(fp, "%d", &cur);
		if ( cur > FindMin( H ) )
		{
			DeleteMin( H );
			Append( cur, H );
			BuildHeap( H );
		}
	}
	printf("\t71st largest number is" KYEL " %d\n" RESET, FindMin( H ));
	puts("");

	// empty the heap
	MakeEmpty( H );
	// destroy the heap
	Destroy( H );

	return 0;
}
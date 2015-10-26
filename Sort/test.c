#include "sort.h"

#define ARRSIZE1 10000
#define ARRSIZE2 100
#define DATA10000 "data10000"
#define DATA100 "data100"

int main(void)
{

	// Initialization

	FILE * fp = fopen(DATA10000, "rb+");
	if(!fp)
	{
		puts("ERROR: Failed to open file.");
		exit(-1);
	}

	int * array = malloc(sizeof(int) * ARRSIZE1);
	if(!array)
	{
		puts("ERROR: Failed to allocate mem.");
		exit(-1);
	}

	int i, curr;
	for(i = 0; i < ARRSIZE1; ++i)
	{
		fscanf(fp, "%d", &curr);
		array[i] = curr;
	}

	clearmove();

	// Insertion Sort
	InsertSort(array, ARRSIZE1);
	puts("Insertion Sort #1");

	// for(i = 0; i < ARRSIZE1; ++i)
	// {
	// 	printf("%d ", array[i]);
	// }
	// puts("");

	printmove();

	// Release Memory
	free(array);
	fclose(fp);

	// // // //

	// Initilization
	// fp = fopen(DATA100, "rb+");
	// if(!fp)
	// {
	// 	puts("ERROR: Failed to open file.");
	// 	exit(-1);
	// }

	// array = malloc(sizeof(int) * ARRSIZE2);
	// if(!array)
	// {
	// 	puts("ERROR: Failed to allocate mem.");
	// 	exit(-1);
	// }

	// clearmove();

	// // Link Insert Sort
	// plist l = LinkInsertSort(array, ARRSIZE2);
	// puts("Link Insertion Sort #2");

	// PrintList(l);
	// printmove();
	
	// // Release Memory
	// DestroyList(l);
	// free(array);
	// fclose(fp);
	
	// // // // //

	// // Initialization
	// fp = fopen(DATA10000, "rb+");
	// if(!fp)
	// {
	// 	puts("ERROR: Failed to open data10000.");
	// 	exit(-1);
	// }

	// array = malloc(sizeof(int) * ARRSIZE1);
	// if(!array)
	// {
	// 	puts("ERROR: Failed to allocate mem.");
	// 	exit(-1);
	// }

	// for(i = 0; i < ARRSIZE1; ++i)
	// {
	// 	fscanf(fp, "%d", &curr);
	// 	array[i] = curr;
	// }

	// clearmove();

	// // Shell Sort
	// shell(array, ARRSIZE1);
	// puts("Shell & Hibbard Sort #3");

	// for(i = 0; i < ARRSIZE1; ++i)
	// 	printf("%d ", array[i]);
	// puts("");

	// printmove();

	// fclose(fp);
	// free(array);

	// // // // //

	// // Initialization
	// fp = fopen(DATA10000, "rb+");
	// if(!fp)
	// {
	// 	puts("ERROR: Failed to open data10000.");
	// 	exit(-1);
	// }

	// array = malloc(sizeof(int) * ARRSIZE1);
	// if(!array)
	// {
	// 	puts("ERROR: Failed to allocate memory.");
	// 	exit(-1);
	// }

	// for(i = 0; i < ARRSIZE1; ++i)
	// {
	// 	fscanf(fp, "%d", &curr);
	// 	array[i] = curr;
	// }

	// clearmove();

	// // Hibbard's Incre
	// hibbard(array, ARRSIZE1);

	// for(i = 0; i < ARRSIZE1; ++i)
	// 	printf("%d ", array[i]);

	// putchar('\n');
	// printmove();

	// // Release Memory
	// fclose(fp);
	// free(array);

	// // // // //

	// // Initialization
	// fp = fopen(DATA100, "rb+");
	// if(!fp)
	// {
	// 	puts("ERROR: Failed to open data100.");
	// 	exit(-1);
	// }

	// array = malloc(sizeof(int) * ARRSIZE2);
	// if(!array)
	// {
	// 	puts("ERROR: Failed to allocate memory.");
	// 	exit(-1);
	// }

	// l = CreateList(array, ARRSIZE2);

	// // Merge sort
	// MergeSort(&l);
	// puts("Merge Sort #4");
	// PrintList(l);
	
	// // Release Resource
	// DestroyList(l);
	// free(array);
	// fclose(fp);

	// // // // //

	// // Initialization
	// fp = fopen(DATA10000, "rb+");
	// if(!fp)
	// {
	// 	puts("ERROR: Failed to open data10000.");
	// 	exit(-1);
	// }

	// array = malloc(sizeof(int) * ARRSIZE1);
	// if(!array)
	// {
	// 	puts("ERROR: Failed to allocate memory.");
	// 	exit(-1);
	// }

	// for(i = 0; i < ARRSIZE1; ++i)
	// {
	// 	fscanf(fp, "%d", &curr);
	// 	array[i] = curr;
	// }

	// clearmove();

	// // Quick Sort
	// puts("Quick Sort #5");

	// Quicksort(array, ARRSIZE1);

	// for(i = 0; i < ARRSIZE1; ++i)
	// 	printf("%d ",array[i]);
	// puts("");

	// printmove();

	// // Release Memory
	// free(array);
	// fclose(fp);

	return 0;
}


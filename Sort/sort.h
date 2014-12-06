#ifndef _sort_header
#define _sort_header

#include <stdio.h>
#include <stdlib.h>

struct list;
typedef struct list * plist;

void InsertSort(int *, int);
plist LinkInsertSort(int *, int);

void shell(int *, int);
void hibbard(int *, int);

plist SortedMerge(plist a, plist b);
void LeftRightSplit(plist source, plist* leftRef, plist* rightRef);
void MergeSort(plist *);

void Quicksort(int *, int);

plist CreateList(int *, int);
void PrintList(plist);
void DestroyList(plist);

void clearmove(void);
void printmove(void);

#endif

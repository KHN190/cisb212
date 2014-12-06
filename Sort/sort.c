#include "sort.h"

int move = 0;

struct list 
{
	int element;
	plist next;
};

void
Swap( int *Lhs, int *Rhs )
{
    int Tmp = *Lhs;
    *Lhs = *Rhs;
    *Rhs = Tmp;
}

void InsertSort(int * array, int size)
{
	int p, i;
	int tmp;

	for(p = 1; p < size; ++p)
	{
		tmp = array[p];

		for(i = p - 1; array[i] > tmp && i >= 0; --i)
		{
			array[i + 1] = array[i];
			move++;
		}

		array[i + 1] = tmp;
		++move;
	}
			
}

plist LinkInsertSort(int * array, int size)
{
	plist l = malloc(sizeof(struct list));

	l->element = array[0];
	l->next = NULL;

	int p;
	plist tmp, prev, curr;

	++move;

	for(p = 1; p < size; ++p)
	{
		for(curr = l, prev = 0; 
			array[p] > curr->element && curr->next != NULL; 
			prev = curr, curr = curr->next);

		tmp = malloc(sizeof(struct list));
		++move;

		if(!tmp)
		{
			puts("ERROR: Failed to allocate node.");
			exit(-1);
		}

		if(!prev)
		{
			tmp->next = l;
			tmp->element = array[p];
			l = tmp;
		}
		else
		{
			tmp->element = array[p];
			prev->next = tmp;
			tmp->next = curr;
		}
	}
	return l;
}

void PrintList(plist l)
{
	plist i;
	for(i = l; i->next != NULL; i = i->next)
		printf("%d ", i->element);
	puts("");
}

void DestroyList(plist l)
{
	plist i, j;

	for(i = l; i != NULL; i = j)
	{
		j = i->next;
		free(i);
	}

}
void clearmove(void)
{
	move = 0;
}

void printmove(void)
{
	printf("Move: %d\n", move);
}

void shell(int * array, int size)
{
	int inc, i, j, tmp;

	for(inc = size / 2; inc > 0; inc /= 2)
	{
		for(i = inc; i < size; ++i)
		{
			tmp = array[i];
			// j count from 0
			for(j = i - inc; // start from 1 increment
				j >= 0 && array[j] > array[i]; // if order is not right
				j -= inc) // jump to next
			{
				array[j + inc] = array[j];
				move++;
			}

			array[j + inc] = tmp;
			++move;
		}
	}
}

void hibbard(int * array, int size)
{
	int inc, i, j, tmp, m;

	for(m = 1; (2 << (m - 1)) - 1 < size; ++m)
	{
		// inc = 2 ^ ( m - 1 ) - 1
		inc = (2 << (m - 1)) - 1;
		for(i = inc; i < size; ++i)
		{
			tmp = array[i];
			for(j = i - inc; j >= 0 && array[j] > tmp; j -=inc)
			{
				array[j + inc] = array[j];
				move++;
			}

			array[j + inc] = tmp;
			move++;
		}
	}
}

void MergeSort(plist* headRef)
{
	plist head = *headRef;
	plist a, b;
	       
	if ((head == NULL) || (head->next == NULL))
		return;

	LeftRightSplit(head, &a, &b); 
  
	MergeSort(&a);
	MergeSort(&b);
		       
	*headRef = SortedMerge(a, b);
}
 
plist SortedMerge(plist a, plist b)
{
	  plist result = NULL;
	   
	    /* Base case */
	    if (a == NULL) 
	    	return(b);

	    else if (b==NULL) 
	    	return(a);
	       
	    if (a->element <= b->element)
	  {
	       result = a;
	       result->next = SortedMerge(a->next, b);
	  }
	  else
	  {
	      result = b;
	      result->next = SortedMerge(a, b->next);
	  }
	    return(result);
}
 
void LeftRightSplit(plist source,
        plist* leftRef, plist* rightRef)
{
	plist fast;
	plist slow;

	if(source==NULL || source->next==NULL)
	{
		*leftRef = source;
		*rightRef = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;
			   
	    while (fast != NULL)
	    {
	        fast = fast->next;
			if (fast != NULL)
			{
		    	slow = slow->next;
		    	fast = fast->next;
			}
	    }
					       
	    *leftRef = source;
	    *rightRef = slow->next;

	    slow->next = NULL;
	}
}

plist CreateList(int * array, int size)
{
	plist l = malloc(sizeof(struct list));

	if(!l)
	{
		puts("ERROR: Failed to allocate mem.");
		exit(-1);
	}

	int i;
	plist itor = l;

	for(i = 1; i < size; ++i)
	{
		itor->next = malloc(sizeof(struct list));
		itor = itor ->next;
		itor->element = array[i];
		itor->next = NULL;
	}
	return l;
}

int 
Median3( int A[ ], int Left, int Right )
{
    int Center = ( Left + Right ) / 2;

    if( A[ Left ] > A[ Center ] )
	{
        Swap( &A[ Left ], &A[ Center ] );
		move++;
	}
    
    if( A[ Left ] > A[ Right ] )
	{
        Swap( &A[ Left ], &A[ Right ] );
		move++;
    }

    if( A[ Center ] > A[ Right ] )
    {
        Swap( &A[ Center ], &A[ Right ] );
		move++;
    }

    /* Invariant: A[ Left ] <= A[ Center ] <= A[ Right ] */

    Swap( &A[ Center ], &A[ Right - 1 ] );  /* Hide pivot */
    return A[ Right - 1 ];                /* Return pivot */
}
/* END */

/* START: fig7_14.txt */
#define Cutoff ( 3 )

void
Qsort( int A[ ], int Left, int Right )
{
    int i, j;
    int Pivot;

	if( Left + Cutoff <= Right )
    {
		Pivot = Median3( A, Left, Right );

		i = Left; j = Right - 1;
		for( ; ; )
        {
        	while( A[ ++i ] < Pivot ){ ++move; }
        	while( A[ --j ] > Pivot ){ ++move; }

        	if( i < j )
        		Swap( &A[ i ], &A[ j ] );
            else
            	break;
        }

		Swap( &A[ i ], &A[ Right - 1 ] );  /* Restore pivot */

        Qsort( A, Left, i - 1 );
        Qsort( A, i + 1, Right );
    }
    else  /* Do an insertion sort on the subarray */

    InsertSort( A + Left, Right - Left + 1 );
}
/* END */

/* START: fig7_12.txt */
void
Quicksort( int * A, int N )
{
    Qsort( A, 0, N - 1 );
}
/* END */


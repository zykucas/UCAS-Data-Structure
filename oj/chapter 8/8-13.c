#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Space
{
	int tag;
	int addr;
	int size;
	struct Space* next;
	struct Space* prev;
} Space;


int main() {
	int addr;
	int space_size;
	char c;

	Space* space_ptr = (Space*)malloc(sizeof(Space));
	space_ptr->tag = 0;
	space_ptr->addr = 0;
	space_ptr->size = 0;
	space_ptr->next = NULL;
	space_ptr->prev = NULL;

	Space* space_ptr_1;
	Space* space_ptr_2;
	space_ptr_1 = space_ptr;
	space_ptr_2 = space_ptr;

	while ((c = getchar()) != '\n')
	{
		Space* sp = (Space*)malloc(sizeof(Space));
		sp->tag = 0;
		sp->addr = 0;
		sp->size = 0;
		sp->next = NULL;
		sp->prev = NULL;

		sp->tag = c - '0';
		c = getchar();
		scanf("%d", &addr);
		sp->addr = addr;
		c = getchar();
		scanf("%d", &space_size);
		sp->size = space_size;
		c = getchar();
		space_ptr->next = sp;
		sp->prev = space_ptr;
		space_ptr = sp;
	}

	Space* tail = (Space*)malloc(sizeof(Space));
	tail->tag = 0;
	tail->addr = INT_MAX;
	tail->size = 0;
	tail->next = NULL;
	tail->prev = space_ptr;

	space_ptr->next = tail;
	

	while ((c = getchar()) != EOF)
	{
		c = getchar();
		scanf("%d", &addr);
		c = getchar();
		scanf("%d", &space_size);
		c = getchar();

		while (addr + space_size > space_ptr_2->addr && space_ptr_2->next != NULL)
		{
			space_ptr_2 = space_ptr_2->next;
		}

		if (space_ptr_2->prev != NULL && space_ptr_2->next != NULL)
		{
			if (addr == (space_ptr_2->prev->addr + space_ptr_2->prev->size) && addr + space_size == space_ptr_2->addr)
			{
				space_ptr_2->addr = space_ptr_2->prev->addr;
				space_ptr_2->size = space_ptr_2->size + space_ptr_2->prev->size + space_size;
				space_ptr_2->prev = space_ptr_2->prev->prev;
				space_ptr_2->prev->next = space_ptr_2;
			}
			else if (addr == (space_ptr_2->prev->addr + space_ptr_2->prev->size) && (addr + space_size) != space_ptr_2->addr)
			{
				space_ptr_2->prev->size += space_size;
			}
			else if (addr != (space_ptr_2->prev->addr + space_ptr_2->prev->size) && (addr + space_size) == space_ptr_2->addr)
			{
				space_ptr_2->addr -= space_size;
				space_ptr_2->size += space_size;
			}
			else if (addr != (space_ptr_2->prev->addr + space_ptr_2->prev->size) && (addr + space_size) != space_ptr_2->addr)
			{
				Space* sp = (Space*)malloc(sizeof(Space));
				sp->tag = 0;
				sp->addr = addr;
				sp->size = space_size;
				sp->next = space_ptr_2;
				sp->prev = space_ptr_2->prev;
				
				space_ptr_2->prev->next = sp;
				space_ptr_2->prev = sp;
			}
		}
	
	}

	while (space_ptr_1->next->next!=NULL)
	{
		if (space_ptr_1->size != 0)
		{
			printf("0 %d %d\n", space_ptr_1->addr, space_ptr_1->size);
			space_ptr_1 = space_ptr_1->next;
		}
		else
		{
			space_ptr_1 = space_ptr_1->next;
		}
	}
	if (space_ptr_1->size != 0) {
		printf("0 %d %d", space_ptr_1->addr, space_ptr_1->size);
	}
	else
	{
		printf("0 %d %d", addr, space_size);
	}
	
	
	while (tail->prev!=NULL)
	{
		tail = tail->prev;
		free(tail->next);
	}
	free(tail);

	return 0;
}

#include <stdlib.h>

#include "Heap.h"

void* MemoryInit()
{
	PMetaData ptr = (PMetaData) GH;

	ptr->BYTES = MAX - sizeof(struct MetaData);
	ptr->NEXT = NULL;
	ptr->FREE = 1; // 1 means free block of memory, 0 means occupied

	return ptr;
}

void* FindFitChunk(int bytes)
{
	PMetaData ptr = (PMetaData)GH;

	while (ptr != NULL)
	{
		if (ptr->FREE == 1 && ptr->BYTES >= bytes)
		{
			break;
		}
		else
		{
			ptr = ptr->NEXT;
		}
	}

	return ptr;
}

void* New(int bytes)
{
	PMetaData ptr = (PMetaData) FindFitChunk(bytes);

	ptr->BYTES = bytes;
	ptr->NEXT = NULL;
	ptr->FREE = 0;

	return ptr + 1;
}

void Delete(void* ptr)
{
	PMetaData p = (PMetaData) GH;

	if (p == ptr)
	{
		p->FREE = 1;
	}
	else
	{
		while (p->NEXT != ptr)
		{
			p = p->NEXT;
		}

		if (p->FREE == 1)
		{
			p->BYTES += p->NEXT->BYTES + (int)sizeof(struct MetaData);
			p->NEXT = p->NEXT->NEXT;
		}
		else
		{
			p->NEXT->FREE = 1;
		}
	}
}

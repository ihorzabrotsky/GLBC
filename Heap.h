#ifndef _HEAP_H_
#define _HEAP_H_

enum { MAX = 20 };

typedef struct MetaData* PMetaData;

struct MetaData
{
	int BYTES;
	PMetaData NEXT;
	int FREE;
};

void* GH;

void* MemoryInit();

void* FindFitChunk(int bytes);

void* New(int bytes);

void Delete(void* ptr);

#endif /* _HEAP_H_ */

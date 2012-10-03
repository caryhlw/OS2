/* mem.c : memory manager
 */

#include <xeroskernel.h>

//Data pertaining to the memory header
struct memHeader {
	unsigned long size;
	struct memHeader *next;
	char * sanityCheck;
	unsigned char dataStart[0];
};

unsigned char mem[4000];
extern long freemem;
struct memHeader *hdr, *hdr2;
unsigned char *memStart;

//Initiates the LL containing the memory headers in use
void kmeminit(void)
{
	struct memHeader *hdr, *hdr2;
	memStart = freemem;
	hdr = (struct memHeader *) memStart;
	hdr2 = hdr;
}

//Allocates the appropriate memory size requests and sets up the next header at the next available memory block. Changes the memory pointer to the available block, and returns the address of the address proceeding the header.
void *kmalloc(int size)
{
	hdr2->size = size;
	hdr2->next = (struct memHeader *) (memStart + hdr->size + sizeof (struct memHeader));
	hdr2 = hdr2->next;
	*memStart = hdr2->dataStart;
	return memStart;
}


#include <stdio.h>

struct memHeader {
  unsigned long size;
  struct memHeader *prev;
  struct memHeader *next;
  char * sanityCheck;
  unsigned char dataStart[0];
};

unsigned char mem[4000];

int main(int argc, char ** argv) {

  struct  memHeader *hdr, *hdr2;
  unsigned char *memStart = mem;


  hdr = (struct memHeader *)  memStart;
  hdr->size = 128;
  hdr->next  = (struct memHeader *)    
    (memStart + hdr->size + sizeof (struct memHeader));
  hdr->prev = 0;
  hdr->sanityCheck = (char *) 0x1233;
  
  hdr2 = hdr->next;
  hdr2->prev = hdr;
  hdr2->size = 32;

    
  printf("%x  dataStart %x %d \n", hdr, &hdr->dataStart, sizeof(hdr));
  printf("%x  dataStart %x %d \n", hdr2, &hdr2->dataStart, sizeof(struct memHeader));

}

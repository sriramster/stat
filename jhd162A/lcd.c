#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int mem_fd;
void *gpio_map;
static volatile uint32_t *gpio;

/* BCM pin mapping */
static int map_pin2gpio [64] = {17, 18, 27, 22, 23, 24, 25, 4, 28, 29, 30, 31};
/* physical pin mapping, i.e actual board pin mapping , copied 
 * array from wiringPi */
static int map_phy2gpio [64] = {
     -1,		// 0 Safe Code Pin number starts from '1' and not idx
     -1, -1,	// 1, 2
     2, -1,
     3, -1,
     4, 14,
     -1, 15,
     17, 18,
     27, -1,
     22, 23,
     -1, 24,
     10, -1,
     9, 25,
     11,  8,
     -1,  7,	// 25, 26
// Padding:
     -1, -1, -1, -1, -1,	// ... 31
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// ... 47
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// ... 63
};

/* Works only for RaspberryPi Model B (512MB), revision: 000e */
int pinConfInit()
{
#ifdef MEM_MAPPED
     if ((fd = open ("/dev/mem", O_RDWR | O_SYNC | O_CLOEXEC) ) < 0) {
	  perror("Could not intialize memory mapped stuffs");
	  exit(-1);
     }
     gpio_map = mmap(
	  NULL,
	  BLOCK_SIZE,
	  PROT_READ|PROT_WRITE,
	  MAP_SHARED,
	  mem_fd,
	  GPIO_BASE
	  );

     close(mem_fd);
     
   if (gpio_map == MAP_FAILED) {
      printf("mmap error %d\n", (int)gpio_map);//errno also set!
      exit(-1);
   }

   gpio = (volatile unsigned *)gpio_map;

#else
   /* TODO: sysfs version */
  sysfsinit();
#endif
}

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
int main(void)
{
	int mem_dev = -1, read_ret,write_ret = -1;
	int fd = -1, i;
	unsigned int alloc_mem_size, page_mask, page_size;
	char *mem_pointer, *virt_addr;
	const unsigned long  mem_address = 0x100000000;
	const unsigned int  mem_size = 0x4096;
	char *read_buff;
	//char *test_read_buff;
	fd = open("test.txt", O_RDONLY);
	if(fd == -1)
	{
		printf("test.txt open failed\n");
	}
#if 0
	read_buff = (char *)malloc(4096);
	read_ret = read(fd, read_buff, 4096);
	if(read_ret == -1)
	{
		printf("read failed errno:%d\n", errno);
	}
	printf("BOSCH_DEBUG :%s\n", read_buff);
#endif
	mem_dev = open("/dev/mem", O_RDWR | O_SYNC);
	if(mem_dev == -1)
	{
		printf("/dev/mem open failed\n");
	}
	page_size = sysconf(_SC_PAGESIZE);
	printf("BOSCH_DEBUG page_size:%d\n", page_size);
	alloc_mem_size = (((mem_size / page_size) + 1) * page_size);
	printf("BOSCH_DEBUG alloc_mem_size:%d\n", alloc_mem_size);
	page_mask = (page_size - 1);
	printf("BOSCH_DEBUG page_mask:%d\n", page_mask);
	mem_pointer = mmap(NULL,
			alloc_mem_size,
			PROT_READ | PROT_WRITE,
			MAP_SHARED,
			mem_dev,
			(mem_address & ~page_mask)
			);

	if(mem_pointer == MAP_FAILED)
	{  
		printf("mmap open failed errno:%d\n", errno);
	}
	printf("BOSCH_DEBUG mem_pointer:%x\n", mem_pointer);
	printf("BOSCH_DEBUG mem_pointer p:%p\n", mem_pointer);
	virt_addr = (char *)(mem_pointer + (mem_address & page_mask));
	read_buff = (char *)malloc(4096);
	read_ret = read(fd, read_buff, 4096);
	//read_ret = read(fd, virt_addr, 4096);
	if(read_ret == -1)
	{
		printf("read failed errno:%d\n", errno);
	}
	for(i=0; i <= 50; i++ )
	{
		printf("index:[%d] value:%x\n", i, *(read_buff+i));
	}
	printf("BOSCH_DEBUG :%s\n", read_buff);
#if 1
	memcpy(virt_addr, read_buff, 4096);
	for(i=0; i <= 50; i++ )
	{
		printf("index:[%d] value:%x\n", i, *(virt_addr+i));
	}
#endif
	printf("BOSCH_DEBUG read_ret:%d\n", read_ret);
#if 0
	write_ret = write(fd, read_buff, 4096);
	if(write_ret == -1)
	{
		printf("write failed errno:%d\n", errno);
	}
#endif
	fd = open("test_write.txt", O_CREAT | O_RDWR);
	if(fd == -1)
	{
		printf("test_write.txt open failed\n");
	}
	write_ret = write(fd, virt_addr, 4096);
	if(write_ret == -1)
	{
		printf("write failed errno:%d\n", errno);
	}
	 
	printf("BOSCH_DEBUG virt_addr:%x\n", virt_addr);
	printf("BOSCH_DEBUG virt_addr p:%p\n", virt_addr);
	while(1)
	{
		sleep(2);
	}
	munmap(mem_pointer, alloc_mem_size);
	close(mem_dev);
	close(fd);

	return 0;
}

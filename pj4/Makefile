pj4: part1 part2
obj-m += Project4_part1.o
part1:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
# 	gcc -g Project4_part1.c -o va_space -pthread -D GNU_SOURCE

part2:
	gcc -g Project4_part2.c -o va_status -pthread -D GNU_SOURCE
clean:
	rm sequential va_status *.cmd *.o *.ko
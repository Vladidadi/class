pj4: part1 part2
obj-m += Project4_part1.o Project4_part2.o
part1:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules && mv Project4_part1.ko p1.ko 
# 	gcc -g Project4_part1.c -o va_space -pthread -D GNU_SOURCE

run: 
	insmod p1.ko pid_arg="$(pgrep bash) && dmesg | tail && rmmod p1
part2:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules && mv Project4_part2.ko p2.ko 
clean:
	rm sequential va_status *.cmd *.o *.ko *.mod 

Project4_part2: 
	make part2
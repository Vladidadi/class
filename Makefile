pj3:  list-forming_original_clean.c 
	gcc -g list-forming_original_clean.c -o list-forming -pthread -D GNU_SOURCE

improved: MY_list-forming.c 
	gcc  MY_list-forming.c list-forming2.h -o improved_list-forming -pthread -D GNU_SOURCE

test: list-forming_test.c 
	gcc list-forming_test.c  MY_list-forming.c list-forming2.h  -o list-forming_test -pthread -D GNU_SOURCE

sequential:
	gcc substring_sequential.c -o sequential

paralell:
	gcc -g substring_paralell.c -o paralell; chmod +x paralell; ./paralell 

push:
	 git add . ; git commit -C project3; git push

pc_old:
	gcc -I . -g producer_consumer2.c pcbuffer.c -o pc
pc:
	gcc -I . -g producer_consumer3.c pcbuffer2.c -o pc
clean:
	rm sequential paralell list-forming pc

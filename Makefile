pj3: list-forming list-forming.c 
	gcc list-forming.c -o list-forming -pthread -D GNU SOURCE

sequential:
	gcc -c substring_sequential.c -o sequential

paralell:
	gcc -c substring_paralell.c -o paralell
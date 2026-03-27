pj3: list-forming list-forming.c 
	gcc list-forming.c -o list-forming -pthread -D GNU SOURCE

sequential:
	gcc substring_sequential.c -o sequential

paralell:
	gcc -g substring_paralell.c -o paralell; chmod +x paralell; ./paralell

clean:
	rm sequential paralell list-forming
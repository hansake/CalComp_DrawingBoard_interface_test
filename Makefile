dtest : dtest.o
	gcc -o dtest dtest.o

dtest.o : dtest.c
	gcc -c dtest.c
  

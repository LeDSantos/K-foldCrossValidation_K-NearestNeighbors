CrossFold_Kvizinhos: main.o 
	gcc -o3 -o CrossFold_Kvizinhos main.o

main.o: main.c
	gcc -c main.c

clean:
	@echo "FEITO PARA WINDOWS, TROCAR PARA rm EM LINUX"
	del  *.o *.exe
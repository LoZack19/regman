CC      = /usr/bin/gcc

regman: filelib.o regrd.o regwr.o reglib.o main.o
	$(CC) filelib.o regrd.o regwr.o reglib.o main.o -o regman

filelib.o: Tokens/filelib.c
	$(CC) -c Tokens/filelib.c -o filelib.o

regrd.o: regrd.c
	$(CC) -c regrd.c -o regrd.o

regwr.o: regwr.c
	$(CC) -c regwr.c -o regwr.o

reglib.o: reglib.c
	$(CC) -c reglib.c -o reglib.o

main.o: main.c
	$(CC) -c main.c -o main.o

clean:
	rm *.o

# Run as root
configure:
	mkdir /usr/share/zpm
	touch /usr/share/zpm/zpm-reg
	chmod a+rw /usr/share/zpm/zpm-reg

install:
	sudo install regman /usr/bin
	rm regman

# Run as root
uninstall:
	rm -rf /usr/share/zpm
	rm /usr/bin/regman
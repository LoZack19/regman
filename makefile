CC=gcc
CFLAGS=-O2
#debug flags:-g -Wall
OBJ=filelib.o regrd.o regwr.o reglib.o main.o
TARGET=regman

all: configure regman

filelib.o: Tokens/filelib.c
	$(CC) $(CFLAGS) -c Tokens/filelib.c -o filelib.o

%.o: %.c
	$(CC) $(CFLAGS) -c $^

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf *.o regman Tokens/

configure:
	git clone https://github.com/LoZack19/Tokens

postconfigure:
	sudo mkdir /usr/share/zpm
	sudo touch /usr/share/zpm/zpm-reg
	sudo chmod a+rw /usr/share/zpm/zpm-reg

install:
	sudo install regman /usr/bin
	rm regman

uninstall:
	sudo rm -rf /usr/share/zpm
	sudo rm /usr/bin/regman
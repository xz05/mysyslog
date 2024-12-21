CC = gcc
CFLAGS = -Wall -g -I/home/ice/mysyslog/libmysyslog -I/home/ice/mysyslog/libmysyslog-text -I/home/ice/mysyslog/libmysyslog-json
LDFLAGS = -L/home/ice/mysyslog/libmysyslog -L/home/ice/mysyslog/libmysyslog-text -L/home/ice/mysyslog/libmysyslog-json -lmysyslog -lmysyslog-text -lmysyslog-json

all: libmysyslog-client

libmysyslog-client: libmysyslog-client.o
	$(CC) -o $@ $^ $(LDFLAGS)

libmysyslog-client.o: libmysyslog-client.c
	$(CC) $(CFLAGS) -c $<

run: libmysyslog-client
	./libmysyslog-client

clean:
	rm -f libmysyslog-client *.o

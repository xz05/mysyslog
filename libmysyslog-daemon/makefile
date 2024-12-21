CC = gcc
CFLAGS = -Wall -g -I/home/ice/mysyslog/libmysyslog -I/home/ice/mysyslog/libmysyslog-text -I/home/ice/mysyslog/libmysyslog-json
LDFLAGS = -L/home/ice/mysyslog/libmysyslog -L/home/ice/mysyslog/libmysyslog-text -L/home/ice/mysyslog/libmysyslog-json -lmysyslog -lmysyslog-text -lmysyslog-json

all: libmysyslog-daemon

libmysyslog-daemon: libmysyslog-daemon.o
	$(CC) -o $@ $^ $(LDFLAGS)

libmysyslog-daemon.o: libmysyslog-daemon.c
	$(CC) $(CFLAGS) -c $<

run: libmysyslog-daemon
	./libmysyslog-daemon

clean:
	rm -f libmysyslog-daemon *.o

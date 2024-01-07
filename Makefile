CC = gcc
CFLAGS = -Wall -pthread

all: adder subtractor multiplier divider worker_monitor

adder: adder.c
	$(CC) $(CFLAGS) -o adder adder.c

subtractor: subtractor.c
	$(CC) $(CFLAGS) -o subtractor subtractor.c

multiplier: multiplier.c
	$(CC) $(CFLAGS) -o multiplier multiplier.c

divider: divider.c
	$(CC) $(CFLAGS) -o divider divider.c

worker_monitor: worker_monitor.c
	$(CC) $(CFLAGS) -o worker_monitor worker_monitor.c

clean:
	rm -f adder subtractor multiplier divider worker_monitor


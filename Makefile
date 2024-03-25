CC=gcc
CFLAGS= -Wall -Wextra -O3 -std=c99
OBJS = *.c
TARGET = migrafo

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

.PHONY: clean
clean:
	@rm -f *.o $(TARGET)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -Imunit
SOURCES = sum.c munit/munit.c test_sum.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = test_sum

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all run clean

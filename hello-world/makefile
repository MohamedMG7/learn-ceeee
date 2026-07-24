CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = hello

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	del $(TARGET).exe
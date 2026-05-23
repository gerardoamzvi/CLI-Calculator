CC = gcc
CFLAGS = -Wall -Wextra
TARGET = calc

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET).exe
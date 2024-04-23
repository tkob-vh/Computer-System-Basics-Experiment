CC=gcc
CFLAGS= -g -D U5 -m32 -fno-stack-protector -no-pie -fcf-protection=none -z execstack
TARGET=bufbomb

all: $(TARGET)

$(TARGET): bufbomb.c buf.c support.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)

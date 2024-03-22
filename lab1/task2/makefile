CC = gcc
CFLAGS = -Og

SRCS = absVal.c addOK.c bitAnd.c bitCount.c bitMask.c bitOr.c bitXor.c byteSwap.c isTmax.c negate.c main.c

OBJS = $(SRCS:.c=.o)
HEADERS = absVal.h addOK.h bitAnd.h bitCount.h bitMask.h bitOr.h bitXor.h byteSwap.h isTmax.h negate.h

TARGET = main.out

.PHONY: all clean

all: $(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

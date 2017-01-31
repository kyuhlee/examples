SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))
CFLAGS = -g

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS)  -o $@ $<

clean:
	rm $(PROGS)


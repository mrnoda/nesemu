src = $(shell find src -name '*.c')
obj = $(src:.c=.o)

CFLAGS = -I./include -g
LDFLAGS = -lm

bin/nesemu: $(obj)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -rf $(obj) bin/

src = $(shell find src -name '*.c')
obj = $(src:.c=.o)

CFLAGS = -I./include --std=c99 -g -Wpedantic
LDFLAGS = -lm

bin/nesemu: $(obj)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -rf $(obj) bin/

CC=g++
CFLAGS=-Wall -g
BINS=test.elf shim.so
all: $(BINS)
%.so: %.cpp
	$(CC) $(CFLAGS) -fPIC -shared -Wl,--no-as-needed -ldl -o $@ $^
	#$(CC) $(CFLAGS) -fPIC -shared -o $@ $^

%.elf: %.cpp
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm $(BINS)
	rm -r *.so
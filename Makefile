
objs-a = region.o slabnew.o salloc.o
objs-b = foo.o
shared-a = libsalloc.so

.PHONY: all
all: $(shared-a)

%.o : %.c
	gcc -fPIC -c $< -O3

foo.o : $(objs-a)
	ld -r $(objs-a) -o $@

libsalloc.so : foo.o
	gcc -O3 -shared -o libsalloc.so foo.o

clean:
	rm -f *.o *.so

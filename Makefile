HEADERS = src/scanner.h
OBJECTS = src/scanner.o src/main.o

default: scanner

%.o: %.c $(HEADERS)
	gcc -c $< -o $@

scanner: $(OBJECTS)
	gcc $(OBJECTS) -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f scanner
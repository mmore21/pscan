HEADERS = src/scanner.h
OBJECTS = src/scanner.o

default: src/scanner

%.o: %.c $(HEADERS)
	gcc -c $< -o $@

program: $(OBJECTS)
	gcc $(OBJECTS) -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f src/scanner
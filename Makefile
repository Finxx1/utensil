all:
	$(CC) -o bin/utensil src/utensil.c -Wall -W -pedantic -std=c99
	$(CC) -o bin/fork src/fork/src/fork.c -Wall -W -pedantic -std=c99
	cp ./src/spatula/spatula ./bin/spatula
debug:
	$(CC) -o bin/utensil src/*.c -g -Wall -W -pedantic -std=c99
install:
	mkdir -p $(DESTDIR)/opt/utensil/bin
	set PATH=/opt/utensil:$PATH
	cp bin/fork $(DESTDIR)/opt/utensil/bin/fork
	cp bin/utensil $(DESTDIR)/opt/utensil/utensil
	cp bin/spatula $(DESTDIR)/opt/utensil/bin/spatula
uninstall:
	rm -f /opt/utensil/bin/*
	rmdir /opt/utensil/bin
	rm -f /opt/utensil/*
	rmdir /opt/utensil

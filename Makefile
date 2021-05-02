all:
	$(CC) -o bin/utensil src/utensil.c -Wall -W -pedantic -std=c99
	$(CC) -o bin/fork src/fork/src/fork.c -Wall -W -pedantic -std=c99
	$(CC) -o bin/spoon src/spoon/src/spoon.c -Wall -W -pedantic -std=c99
	$(CC) -o bin/knife src/knife/src/knife.c -Wall -W -pedantic -std=c99
	$(CC) -o bin/whisk src/whisk/src/whisk.c -Wall -W -pedantic -std=c99
	cp ./src/spatula/spatula ./bin/spatula
	cp ./src/spatula/spatula.cfg ./bin/spatula.cfg
debug:
	$(CC) -o bin/utensil src/*.c -g -Wall -W -pedantic -std=c99
install:
	mkdir -p $(DESTDIR)/opt/utensil/bin
	cp bin/utensil $(DESTDIR)/opt/utensil/utensil
	cp bin/utensil $(DESTDIR)/bin/utensil
	cp bin/fork $(DESTDIR)/opt/utensil/bin/fork
	cp bin/spoon $(DESTDIR)/opt/utensil/bin/spoon
	cp bin/knife $(DESTDIR)/opt/utensil/bin/knife
	cp bin/whisk $(DESTDIR)/opt/utensil/bin/whisk
	cp bin/spatula.cfg $(DESTDIR)/opt/utensil/bin/spatula.cfg
	cp bin/spatula $(DESTDIR)/opt/utensil/bin/spatula
macos_install:
	mkdir -p $(DESTDIR)/opt/utensil/bin
	cp bin/utensil $(DESTDIR)/opt/utensil/utensil
	cp bin/utensil $(DESTDIR)/usr/local/bin/utensil
	cp bin/fork $(DESTDIR)/opt/utensil/bin/fork
	cp bin/spoon $(DESTDIR)/opt/utensil/bin/spoon
	cp bin/knife $(DESTDIR)/opt/utensil/bin/knife
	cp bin/whisk $(DESTDIR)/opt/utensil/bin/whisk
	cp bin/spatula.cfg $(DESTDIR)/opt/utensil/bin/spatula.cfg
	cp bin/spatula $(DESTDIR)/opt/utensil/bin/spatula
macos_uninstall:
	rm -f /opt/utensil/bin/*
	rmdir /opt/utensil/bin
	rm -f /opt/utensil/*
	rmdir /opt/utensil
	rm -f /usr/local/bin/utensil
uninstall:
	rm -f /opt/utensil/bin/*
	rmdir /opt/utensil/bin
	rm -f /opt/utensil/*
	rmdir /opt/utensil
	rm -f /bin/utensil

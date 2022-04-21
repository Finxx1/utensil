linux:
	$(CC) -o bin/lin/utensil src/utensil.c -Wall -W -pedantic -std=c99
	$(CC) -o bin/lin/fork src/fork/src/fork.c -Wall -W -pedantic -std=c99
	$(CC) -o bin/lin/spoon src/spoon/src/spoon.c -Wall -W -pedantic -std=c99
	$(CC) -o bin/lin/knife src/knife/src/knife.c -Wall -W -pedantic -std=c99
	$(CC) -o bin/lin/whisk src/whisk/src/whisk.c -Wall -W -pedantic -std=c99
	cp ./src/whisk/bin/LICENSE.md ./bin/lin/LICENSE.md
	cp ./src/spatula/spatula ./bin/lin/spatula
	cp ./src/spatula/spatula.cfg ./bin/lin/spatula.cfg
macos:
	$(CC) -o bin/mac/utensil src/utensil.c -Wall -W -pedantic -std=c99
	$(CC) -o bin/mac/fork src/fork/src/fork.c -Wall -W -pedantic -std=c99
	$(CC) -o bin/mac/spoon src/spoon/src/spoon.c -Wall -W -pedantic -std=c99
	$(CC) -o bin/mac/knife src/knife/src/knife.c -Wall -W -pedantic -std=c99
	$(CC) -o bin/mac/whisk src/whisk/src/whisk.c -Wall -W -pedantic -std=c99
	cp ./src/whisk/bin/LICENSE.md ./bin/mac/LICENSE.md
	cp ./src/spatula/spatula ./bin/mac/spatula
	cp ./src/spatula/spatula.cfg ./bin/mac/spatula.cfg
debug:
	$(CC) -o bin/utensil src/*.c -g -Wall -W -pedantic -std=c99
linux_install:
	mkdir -p $(DESTDIR)/opt/utensil/bin
	cp bin/lin/utensil $(DESTDIR)/opt/utensil/utensil
	cp bin/lin/utensil $(DESTDIR)/bin/utensil
	cp bin/lin/fork $(DESTDIR)/opt/utensil/bin/fork
	cp bin/lin/spoon $(DESTDIR)/opt/utensil/bin/spoon
	cp bin/lin/knife $(DESTDIR)/opt/utensil/bin/knife
	cp bin/lin/whisk $(DESTDIR)/opt/utensil/bin/whisk
	cp bin/lin/LICENSE.md $(DESTDIR)/opt/utensil/bin/LICENSE.md
	cp bin/lin/spatula.cfg $(DESTDIR)/opt/utensil/bin/spatula.cfg
	cp bin/lin/spatula $(DESTDIR)/opt/utensil/bin/spatula
macos_install:
	mkdir -p $(DESTDIR)/opt/utensil/bin
	cp bin/mac/utensil $(DESTDIR)/opt/utensil/utensil
	cp bin/mac/utensil $(DESTDIR)/usr/local/bin/utensil
	cp bin/mac/fork $(DESTDIR)/opt/utensil/bin/fork
	cp bin/mac/spoon $(DESTDIR)/opt/utensil/bin/spoon
	cp bin/mac/knife $(DESTDIR)/opt/utensil/bin/knife
	cp bin/mac/whisk $(DESTDIR)/opt/utensil/bin/whisk
	cp bin/mac/LICENSE.md $(DESTDIR)/opt/utensil/bin/LICENSE.md
	cp bin/mac/spatula.cfg $(DESTDIR)/opt/utensil/bin/spatula.cfg
	cp bin/mac/spatula $(DESTDIR)/opt/utensil/bin/spatula
macos_uninstall:
	rm -f /opt/utensil/bin/*
	rmdir /opt/utensil/bin
	rm -f /opt/utensil/*
	rmdir /opt/utensil
	rm -f /usr/local/bin/utensil
linux_uninstall:
	rm -f /opt/utensil/bin/*
	rmdir /opt/utensil/bin
	rm -f /opt/utensil/*
	rmdir /opt/utensil
	rm -f /bin/utensil

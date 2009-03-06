all: temperhum eeprom_dump
temperhum: comms.c readings.c temperhum.c
	gcc \
		-Wall -Wextra \
		-lm -lrt -lrrd \
		-O2 -D_POSIX_C_SOURCE=200112L -D_ISOC99_SOURCE -D_SVID_SOURCE \
		comms.c readings.c temperhum.c \
		-o temperhum
eeprom_dump: comms.c eeprom_dump.c
	gcc \
		-Wall -Wextra \
		-lrt \
		-O2 -D_POSIX_C_SOURCE=200112L -D_ISOC99_SOURCE -D_SVID_SOURCE \
		comms.c eeprom_dump.c \
		-o eeprom_dump
README.html: README Makefile
	sed \
		-e 's@$$@<br>@' \
		-e 's@^= \(.*\) =<br>$$@<h1>\1</h1>@' \
		-e 's@^== \(.*\) ==<br>$$@<h2>\1</h2>@' \
		-e 's@^[\t]<br>$$@@' \
		-e 's@^ \(.*\)$$@<code>\1</code>@' \
		-e 's@\(http://[^ ]*\)@<a href="\1">\1</a>@' \
		< README > README.html

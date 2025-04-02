BUILDDIR=build/linux
CC=cc
LD=ld
AR=ar
STRIP=strip

all:
	cd $(BUILDDIR) && make
	cp $(BUILDDIR)/libmediakit.a .

clean:
	rm -f libmediakit.a
	cd $(BUILDDIR) && make clean

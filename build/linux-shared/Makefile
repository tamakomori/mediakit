CC=cc
LD=ld
AR=ar

CPPFLAGS=\
	-I../../include \
	-I./libroot/include

CFLAGS=\
	-O0 \
	-g3

LDFLAGS=\
	-lX11 \
	-lasound \
	-lasound \
	-lX11 \
	-lXpm \
	-lGL \
	-lGLX \
	-lpthread \
	-lm \
	-lpng16 \
	-ljpeg \
	-lwebp \
	-lvorbisfile \
	-lvorbis \
	-logg \
	-lbrotlidec\
	-lbrotlicommon \
	-lbz2 \
	-lz

all: libmediakit.so

libmediakit.so: linuxmain.o stdfile.o image.o glrender.o
	$(CC) -o $@ -shared (CFALGS) $^

linuxmain.o: ../../src/linuxmain.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $<

stdfile.o: ../../src/stdfile.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $<

image.o: ../../src/image.c libroot
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $<

glrender.o: ../../src/glrender.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $<

clean:
	rm -rf testapp libmediakit.a *.o libroot

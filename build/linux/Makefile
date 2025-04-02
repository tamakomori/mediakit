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
	libroot/lib/libpng.a \
	libroot/lib/libjpeg.a \
	libroot/lib/libwebp.a \
	libroot/lib/libvorbis.a \
	libroot/lib/libogg.a \
	libroot/lib/libbrotlidec.a \
	libroot/lib/libbrotlicommon.a \
	libroot/lib/libbz2.a \
	libroot/lib/libz.a \
	-lX11 \
	-lasound \
	-lasound \
	-lX11 \
	-lXpm \
	-lGL \
	-lGLX \
	-lpthread \
	-lm

all: libmediakit.a testapp

testapp: testprogram.o libmediakit.a
	$(CC) -o $@ $(CPPFLAGS) $(CFLAGS) $^ $(LDFLAGS)

testprogram.o: ../../src/testprogram.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $<

libmediakit.a: linuxmain.o stdfile.o image.o glrender.o
	$(AR) rcs $@ $^

libroot:
	@../../external/build-libs.sh "" $(CC) "-O2 -g0" $(AR)

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

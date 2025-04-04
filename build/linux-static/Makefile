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
	-lm

all: libmediakit.a testapp

testapp: testprogram.o libmediakit.a
	$(CC) -o $@ $(CPPFLAGS) $(CFLAGS) $^ $(LDFLAGS)

testprogram.o: ../../src/testprogram.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $<

libmediakit.a: linuxmain.o stdfile.o image.o glrender.o libroot
	rm -rf tmp
	mkdir tmp
	cd tmp && \
	  $(AR) x ../libroot/lib/libpng.a && \
	  $(AR) x ../libroot/lib/libjpeg.a && \
	  $(AR) x ../libroot/lib/libwebp.a && \
	  $(AR) x ../libroot/lib/libvorbisfile.a && \
	  $(AR) x ../libroot/lib/libvorbis.a && \
	  $(AR) x ../libroot/lib/libogg.a && \
	  $(AR) x ../libroot/lib/libbrotlidec.a && \
	  $(AR) x ../libroot/lib/libbrotlicommon.a && \
	  $(AR) x ../libroot/lib/libbz2.a && \
	  $(AR) x ../libroot/lib/libz.a && \
	cd ..
	$(AR) rcs $@ linuxmain.o stdfile.o image.o glrender.o tmp/*.o
	rm -rf tmp

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

CFLAGS += -O3 -ffast-math -march=native
CPPFLAGS += -DUSE_C_BLOCKFUNC

SRCS_C =\
	patchfile.c \
	crypto.c \
	fprom.c \
	cpukeys.c \
	dump_patch.c \
	file_io.c \
	filefmt.c

patchtools: $(SRCS_C)

clean:
	rm *.o patchtools

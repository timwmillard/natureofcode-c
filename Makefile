#
#APPNAME:=$(shell basename `pwd`)

LDFLAGS:=$(shell pkg-config raylib --libs)
#LDLIBS=

CFLAGS:=$(shell pkg-config raylib --cflags)
CFLAGS+= -std=c99
#INCLUDE=

#SRC:=$(wildcard src/*.c)
#OBJ:=$(SRC:src/%.c=obj/%.o)
#INC:=$(wildcard include/*.h)

CC=clang

CORE = core/external/open-simplex-noise.c


INTRO = \
	intro/random_walker \
	intro/random \
	intro/perlin_noise \
	intro/random_1d \
	intro/perlin_noise_1d \
	intro/random_2d \
	intro/perlin_noise_2d \

CHAP1 = \
	chap1/vectors \
	chap1/bouncingball_novectors \
	chap1/bouncingball_vectors \
	chap1/bouncingball_acceleration \
	chap1/vector_line 


CHAP2 = \
	chap2/ball_with_force \
	chap2/ball_with_mass \
	chap2/balls_with_random_mass \
	chap2/balls_with_gravity \
	chap2/ball_with_wind

all: $(INTRO) $(CHAP1) $(CHAP2)

core: $(CORE)

intro: $(INTRO)

chap1: $(CHAP1)

chap2: $(CHAP2)

%: %.c
	$(CC) -o $@$(EXT) $(CORE) $< $(CFLAGS) $(INCLUDE) $(LDFLAGS) $(LDLIBS)

#$(OBJ): obj/%.o : src/%.c
#	$(CC) -o $@$(EXT) $< $(CFLAGS) $(INCLUDE) $(LDFLAGS) $(LDLIBS)

.PHONY: debug release
debug: CFLAGS+= -g

.PHONY:	clean
clean:
	find . -type f -perm +ugo+x -delete
	rm -f *.o

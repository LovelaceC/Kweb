FLAGS=-Wall -Werror -std=gnu99 -Iinc -fPIC -O0 -g
LIBS=-lonion

FILES=build/core/kweb.o build/elements/primitives/label.o \
	build/utils/vector.o build/core/kpage.o build/elements/element.o \
	build/elements/primitives/division.o build/utils/file.o \
	build/elements/primitives/list.o
OUT=bin/libkweb.so

GREEN=\033[0;32m
NOCOLOR=\033[0m

all: $(FILES)
	$(CC) -shared $(FLAGS) $(FILES) -o $(OUT) $(LIBS) -lc
	echo -e "[ ${GREEN}DONE${NOCOLOR} ] Building kweb"

build/core/kweb.o: src/core/kweb.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

build/elements/primitives/label.o: src/elements/primitives/label.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

build/utils/vector.o: src/utils/vector.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

build/core/kpage.o: src/core/kpage.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

build/elements/element.o: src/elements/element.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

build/elements/primitives/division.o: src/elements/primitives/division.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

build/utils/file.o: src/utils/file.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

build/elements/primitives/list.o: src/elements/primitives/list.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

build_demo: all
	cd demo && $(MAKE)
	echo -e "[ ${GREEN}DONE${NOCOLOR} ] Building the demo"

run_demo: build_demo
	cd demo && $(MAKE) run

run: run_demo

clean:
	rm $(FILES)
	rm $(OUT)

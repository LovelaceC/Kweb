FLAGS=-Wall -Werror -std=gnu99 -Iinc -O0 -g
LIBS=-lonion

FILES=build/demo.o build/core/kweb.o build/elements/primitives/label.o \
	build/utils/vector.o build/core/kpage.o build/elements/element.o \
	build/elements/primitives/division.o build/utils/file.o
OUT=bin/server

all: $(FILES)
	$(CC) $(FLAGS) $(FILES) -o $(OUT) $(LIBS)

build/demo.o: src/demo.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

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

run: all
	$(OUT)

clean:
	rm $(FILES)
	rm $(OUT)

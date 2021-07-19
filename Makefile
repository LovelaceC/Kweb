FLAGS=-Wall -Werror -std=gnu99 -Iinc -O0 -g
LIBS=-lonion

FILES=build/demo.o build/core/kweb.o build/elements/label.o
OUT=bin/server

all: $(FILES)
	$(CC) $(FLAGS) $(FILES) -o $(OUT) $(LIBS)

build/demo.o: src/demo.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

build/core/kweb.o: src/core/kweb.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

build/elements/label.o: src/elements/label.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

run: all
	$(OUT)

clean:
	rm $(FILES)
	rm $(OUT)

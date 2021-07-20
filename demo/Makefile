FLAGS=-Wall -Werror -std=gnu99 -I../inc -O0 -g -L../bin
LIBS=-lkweb

FILES=build/main.o build/pages/home.o
OUT=bin/demo

all: $(FILES)
	$(CC) $(FLAGS) $(FILES) -o $(OUT) $(LIBS)

build/main.o: src/main.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

build/pages/home.o: src/pages/home.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

run: all
	$(OUT)

clean:
	rm $(FILES)
	rm $(OUT)

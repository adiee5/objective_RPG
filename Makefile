SRC= main.cpp item.cpp characters.cpp stattypes.cpp


.PHONY: all clean

all: RPG

RPG: $(SRC)
	g++ $(SRC) -o $@

clean:
	rm RPG
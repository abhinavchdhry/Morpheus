CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
CC := g++
CFLAGS := -g --std=c++0x -Iinc 

#ToDo Need a main.cpp in root folder to test the library
all: main.cpp libmorpheus.a
	$(CC) $(CFLAGS) main.cpp -lmorpheus -o morpheus

#ToDo Need to convert this into shared object. Will finish that once the code is working
libmorpheus.a: objdir $(OBJ_FILES)
	ar rvs libmorpheus.a $(OBJ_FILES)

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

objdir:
	mkdir -p obj

clean:
	rm -Rf obj

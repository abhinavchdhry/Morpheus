BUILDDIR := build
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix $(BUILDDIR)/,$(notdir $(CPP_FILES:.cpp=.o)))
CC := g++
CFLAGS := -g --std=c++0x -Iinc 

#ToDo Need a main.cpp in root folder to test the library
#ToDo @Aman Change linker directory specified by -L to something more comprehensive than '.'
#Currently making it '.'
all: main.cpp $(BUILDDIR)/libmorpheus.a
	$(CC) $(CFLAGS) main.cpp -L $(BUILDDIR)/ -l morpheus -o $(BUILDDIR)/morpheus

#ToDo Need to convert this into shared object. Will finish that once the code is working
$(BUILDDIR)/libmorpheus.a: objdir $(OBJ_FILES)
	ar rvs $(BUILDDIR)/libmorpheus.a $(OBJ_FILES)

$(BUILDDIR)/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

objdir:
	mkdir -p $(BUILDDIR)

clean:
	rm -Rf $(BUILDDIR)

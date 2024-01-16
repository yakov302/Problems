
SRC_DIR = ../src
INC_DIR = ../inc

CXX = g++
CC = $(CXX)
WARNINGS = -pedantic
WARNINGS += -Wall -Werror
DEBUG = -g3
CXX_STD = c++2a
LDLIBS  = 

CXXFLAGS = $(WARNINGS) $(DEBUG) -std=$(CXX_STD) $(LDLIBS)
CPPFLAGS = -I$(INC_DIR)


TARGET = main
OBJS = ./main.o ./linked_list.o ./node.o ./iterator.o ./add_2_numbers.o

$(TARGET):$(OBJS)

build: $(TARGET)
	./$(TARGET) -v  

clean:
	@$(RM) $(TARGET) $(OBJS)

debug:
	gdb ./$(TARGET)  

debug1:
	valgrind --log-file=V1.log ./$(TARGET)  

debug2:
	valgrind --log-file=V2.log --leak-check=full --track-origins=yes ./$(TARGET)  

debug3:
	valgrind --log-file=V3.log --leak-check=full --track-origins=yes -s ./$(TARGET) 

.PHONY: check clean
# Note: the following is just an option to make sure Make won't automatically delete any object files after every build; don't worry about that
.PRECIOUS: %.o 

all: test1 test2 test3 test4 test5 test6 test7 test8 test9 test10

test%: main%.o Inventory.o Item.o
	g++ -std=c++11 -o $@ $^ 
# Note: $^ is not covered in lab1. It basically denotes all depended files, i.e., all 3 files "main%.o Inventory.o Item.o"

Item.o: Item.cpp Item.h
	g++ -std=c++11 -c $< -o $@ 

Inventory.o: Inventory.cpp Inventory.h
	g++ -std=c++11 -c $< -o $@ 

%.o: %.cpp
	g++ -std=c++11 -c $< -o $@ 
# Note: this meta rule (see lab 1) is to generate rules for main1.o, ..., main10.o 

clean:
	del *.o *.exe
# On most Windows, use: del *.o *.exe
# On Linux or MacOS or some Windows (just try which command works for you), use: rm -f *.o *.exe
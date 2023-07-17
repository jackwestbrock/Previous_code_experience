## style guide: https://style-guides.readthedocs.io/en/latest/makefile.html
#

# use g++ compiler
cc = g++

# add parent directory to include path and root of linter
path = ..

# compile with C++ 17 standard
flags = -std=c++17
# emit "all warnings"
flags += -Wall
# add debugger info
flags += -g
# parent directory on include path
flags += -I $(path)

# Create link variable to compile, assemble, link, and name
link = $(cc) $(flags) -o

# Create variable compile to compile, assemble, but not link
compile = $(cc) $(flags) -c



# Problem 1
#
problem1.o: problem1.cpp problem1.h
	$(compile) $<

problem1-style: problem1.cpp problem1.h
	cpplint --root=$(path) $^


# Problem 2
#
problem2.o: problem2.cpp problem2.h
	$(compile) $<

problem2-style: problem2.cpp problem2.h
	cpplint --root=$(path) $^


# Testing
#
problem-test: problem1-test problem2-test 
	@echo "All Tests Ran"

# problem 1 test
problem1-test : problem1
	./problem1
	
problem1: problem1.o problem1-test.o
	$(link) $@ $^

problem1-test.o: problem1_test.cpp problem1.h
	$(compile) -o $@ $<


# problem 2 test

problem2-test : problem2
	./problem2
  
problem2:  problem2.o problem2-test.o
	$(link) $@ $^

problem2-test.o: problem2_test.cpp problem2.h
	$(compile) -o $@ $<


clean:
	$(RM) problem1 problem2 *.o

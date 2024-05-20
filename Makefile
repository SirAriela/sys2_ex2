#//206862666
#//ariela
#!make -f

CXX=clang++
CXXFLAGS=-std=c++11 -Werror -Wsign-conversion -pedantic
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99
LDLIBS = -pthread


SOURCES=Graph.cpp Algorithms.cpp Demo.cpp my_test.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

#run: demo
#	./$^

demo: Demo.o Graph.o Algorithms.o
	$(CXX) $(CXXFLAGS) $^ -o demo

#test: TestCounter.o Test.o $(OBJECTS)
#	$(CXX) $(CXXFLAGS) $^ -o test

# my_demo: Graph.o Algorithms.o demo.o
# 	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o my_demo

my_test: Graph.o Algorithms.o my_test.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o my_test
tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

#valgrind: demo test
#	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
#	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o my_test demo

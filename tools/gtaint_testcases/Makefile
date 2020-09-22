
SOURCES:=$(shell find -iname '*.cpp')
LIBS=$(SOURCES:%.cpp=%.o)

CXX?=g++
CXXFLAGS ?= -O0 -masm=intel


all: testcases.a


$(LIBS):%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c -o $*.o $*.cpp

testcases.a: $(LIBS)
	ar -rsv $@ $(LIBS)

clean:
	rm -f testcases.a $(LIBS)

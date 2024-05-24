CXX := g++ -std=c++11 #启动c++编译器
CXXFLAGS := -g -Wall

all: main

main: hdfsioutil.o hdfsioutilv2.o hdfsioutilv3.o
	$(CXX) $(CXXFLAGS) -o main main.cpp

hdfsioutilv3.o: hdfsioutilv3.h
	$(CXX) $(CXXFLAGS) -c hdfsioutilv3.cpp

hdfsioutilv2.o: hdfsioutilv2.h
	$(CXX) $(CXXFLAGS) -c hdfsioutilv2.cpp	

hdfsioutil.o: hdfsioutil.h
	$(CXX) $(CXXFLAGS) -c hdfsioutil.cpp

clean:
	rm -rf main hdfsioutil.o hdfsioutilv2.o hdfsioutilv3.o
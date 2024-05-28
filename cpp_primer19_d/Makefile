CXX := g++ -std=c++11 #启动c++编译器
CXXFLAGS := -g -Wall

all: forward_list invalid_iterator string_use

string_use:
	$(CXX) $(CXXFLAGS) -o string_use string_use.cpp


forward_list:
	$(CXX) $(CXXFLAGS) -o forward_list forward_list.cpp

invalid_iterator:
	$(CXX) $(CXXFLAGS) -o invalid_iterator invalid_iterator.cpp

clean:
	rm -rf forward_list invalid_iterator string_use
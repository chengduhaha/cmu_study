CXX := g++ -std=c++14 #启动c++编译器 14版本有make_unique方法
CXXFLAGS := -g -Wall

all: unique_pointer weak_pointer

unique_pointer:
	$(CXX) $(CXXFLAGS) -o unique_pointer unique_pointer.cpp

weak_pointer:
	$(CXX) $(CXXFLAGS) -o weak_pointer weak_pointer.cpp

clean:
	rm -rf unique_pointer weak_pointer
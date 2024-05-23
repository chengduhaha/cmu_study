CXX := g++ -std=c++11 #启动c++编译器
CXXFLAGS := -g -Wall

all: cpp_class cpp_access cpp_class_ref cpp_class_const

cpp_class:
	$(CXX) $(CXXFLAGS) -o cpp_class cpp_class.cpp

cpp_access:
	$(CXX) $(CXXFLAGS) -o cpp_access cpp_access.cpp

cpp_class_ref:
	$(CXX) $(CXXFLAGS) -o cpp_class_ref cpp_class_ref.cpp

cpp_class_const:
	$(CXX) $(CXXFLAGS) -o cpp_class_const cpp_class_const.cpp

clean:
	rm -rf cpp_class cpp_access cpp_class_ref cpp_class_const
CXX := g++ -std=c++11 #启动c++编译器
CXXFLAGS := -g -Wall

all: class_delegate_constructor class_default_constructor class_static_attribute

class_static_attribute:
	$(CXX) $(CXXFLAGS) -o class_static_attribute class_static_attribute.cpp

class_default_constructor:
	$(CXX) $(CXXFLAGS) -o class_default_constructor class_default_constructor.cpp

class_delegate_constructor:
	$(CXX) $(CXXFLAGS) -o class_delegate_constructor class_delegate_constructor.cpp

clean:
	rm -rf class_delegate_constructor class_default_constructor class_static_attribute
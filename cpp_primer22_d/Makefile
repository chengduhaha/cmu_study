CXX := g++ -std=c++11 #启动c++编译器 14版本有make_unique方法
CXXFLAGS := -g -Wall

all: template_01 template_02_class

template_01:
	$(CXX) $(CXXFLAGS) -o template_01 template_01.cpp

template_02_class:
	$(CXX) $(CXXFLAGS) -o template_02_class template_02_class.cpp

clean:
	rm -rf template_01 template_02_class
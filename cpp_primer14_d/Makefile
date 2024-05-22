CXX := g++ -std=c++11 #启动c++编译器
CXXFLAGS := -g -Wall

all: cpp_initializer_list cpp_returnvalue cpp_overload cpp_default_parameter cpp_assert cpp_function_pointer

cpp_initializer_list:
	$(CXX) $(CXXFLAGS) -o cpp_initializer_list cpp_initializer_list.cpp

cpp_returnvalue:
	$(CXX) $(CXXFLAGS) -o cpp_returnvalue cpp_returnvalue.cpp

cpp_overload:
	$(CXX) $(CXXFLAGS) -o cpp_overload cpp_overload.cpp

cpp_default_parameter:
	$(CXX) $(CXXFLAGS) -o cpp_default_parameter cpp_default_parameter.cpp

cpp_assert:
	$(CXX) $(CXXFLAGS) -o cpp_assert cpp_assert.cpp

cpp_function_pointer:
	$(CXX) $(CXXFLAGS) -o cpp_function_pointer cpp_function_pointer.cpp

clean:
	rm -rf cpp_initializer_list cpp_returnvalue cpp_overload cpp_default_parameter cpp_assert cpp_function_pointer
CXX := g++ -std=c++14 #启动c++编译器 14版本有make_unique方法
CXXFLAGS := -g -Wall

all: unique_pointer weak_pointer dynamic_array copy_constructor deconstrucotor swap move_object operator_overload input_output_overload

unique_pointer:
	$(CXX) $(CXXFLAGS) -o unique_pointer unique_pointer.cpp

weak_pointer:
	$(CXX) $(CXXFLAGS) -o weak_pointer weak_pointer.cpp

dynamic_array:
	$(CXX) $(CXXFLAGS) -o dynamic_array dynamic_array.cpp

copy_constructor:
	$(CXX) $(CXXFLAGS) -o copy_constructor copy_constructor.cpp

deconstrucotor:
	$(CXX) $(CXXFLAGS) -o deconstrucotor deconstrucotor.cpp

swap:
	$(CXX) $(CXXFLAGS) -o swap swap.cpp

move_object:
	$(CXX) $(CXXFLAGS) -o move_object move_object.cpp

operator_overload:
	$(CXX) $(CXXFLAGS) -o operator_overload operator_overload.cpp

input_output_overload:
	$(CXX) $(CXXFLAGS) -o input_output_overload input_output_overload.cpp


clean:
	rm -rf unique_pointer weak_pointer dynamic_array copy_constructor deconstrucotor swap move_object operator_overload input_output_overload
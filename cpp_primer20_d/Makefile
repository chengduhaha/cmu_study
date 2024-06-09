CXX := g++ -std=c++11 #启动c++编译器
CXXFLAGS := -g -Wall

all: algorithm_comparator algorithm_lambda pair map_learn shared_unique_pointer shallow_deep_copy

algorithm_comparator:
	$(CXX) $(CXXFLAGS) -o algorithm_comparator algorithm_comparator.cpp

algorithm_lambda:
	$(CXX) $(CXXFLAGS) -o algorithm_lambda algorithm_lambda.cpp

pair:
	$(CXX) $(CXXFLAGS) -o pair pair.cpp

map_learn:
	$(CXX) $(CXXFLAGS) -o map_learn map_learn.cpp

shared_unique_pointer:
	$(CXX) $(CXXFLAGS) -o shared_unique_pointer shared_unique_pointer.cpp

shallow_deep_copy:
	$(CXX) $(CXXFLAGS) -o shallow_deep_copy shallow_deep_copy.cpp
clean:
	rm -rf algorithm_comparator algorithm_lambda pair map_learn shared_unique_pointer shallow_deep_copy
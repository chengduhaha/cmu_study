CXX := g++ -std=c++11 #启动c++编译器
CXXFLAGS := -g -Wall

all: algorithm_comparator algorithm_lambda

algorithm_comparator:
	$(CXX) $(CXXFLAGS) -o algorithm_comparator algorithm_comparator.cpp

algorithm_lambda:
	$(CXX) $(CXXFLAGS) -o algorithm_lambda algorithm_lambda.cpp

clean:
	rm -rf algorithm_comparator algorithm_lambda
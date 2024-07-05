CXX := g++ -std=c++11 #启动c++编译器 14版本有make_unique方法
CXXFLAGS := -g -Wall

all: two_sum sftsql sftsql_02_print_build_listnode sftsql_03_tree_traversal

two_sum:
	$(CXX) $(CXXFLAGS) -o two_sum two_sum.cpp 

sftsql:
	$(CXX) $(CXXFLAGS) -o sftsql sftsql.cpp

sftsql_02_print_build_listnode:
	$(CXX) $(CXXFLAGS) -o sftsql_02_print_build_listnode sftsql_02_print_build_listnode.cpp 

sftsql_03_tree_traversal:
	$(CXX) $(CXXFLAGS) -o sftsql_03_tree_traversal sftsql_03_tree_traversal.cpp 	

clean:
	rm -rf two_sum sftsql sftsql_02_print_build_listnode sftsql_03_tree_traversal
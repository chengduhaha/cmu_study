CXX := g++
CXXFLAGS := -g -Wall


all: extern02a extern01b extern02b_pointer

extern02b_pointer:
	$(CXX) $(CXXFLAGS) -o extern02b_pointer extern02b_pointer.cpp

extern02a:
	$(CXX) $(CXXFLAGS) -o extern02a extern02a.cpp

extern01b: extern01a.o
	$(CXX) $(CXXFLAGS) -o extern01b extern01b.cpp extern01a.o

extern01a.o:
	$(CXX) $(CXXFLAGS) -c extern01a.cpp

clean:
	rm -rf extern01b extern01a.o extern02a extern02b_pointer

# g++ -g -Wall 命令意味着编译器不仅会生成可执行文件，并且还会在这个过程中包含调试信息，同时显示所有的警告信息，以便开发者进行深入的调试和代码优化。

# -g：这个选项告诉编译器生成包含调试信息的可执行文件。当你需要使用像 GDB 这样的调试器来调试你的程序时，这些调试信息是非常重要的。它包含了源代码级别的信息，如变量名、函数名以及源代码行号等，使得调试过程能够对应到具体的源码位置。

# -Wall：这个选项指示编译器开启所有警告（All Warnings）。编译器会尽可能地报告源代码中可能存在的问题或不规范的写法，而不仅仅是错误。这有助于开发者发现并修正潜在的编程错误或不好的编程习惯，提高代码质量。

# all: extern01
# extern01: extern01a.o extern01b.o
#     g++ -g -Wall -o extern01 extern01a.o extern01b.o
# 
# extern01a.o: extern01a.cpp
#     g++ -g -Wall -c extern01a.cpp
# 
# extern01b.o: extern01b.cpp
#     g++ -g -Wall -c extern01b.cpp
#
#这段 makefile 定义了三个目标：all（默认目标）、extern01（最终的可执行文件）、以及 extern01a.o 和 extern01b.o
#（分别代表 extern01a.cpp 和 extern01b.cpp 编译后的目标文件）。
#首先，它会分别编译 extern01a.cpp 和 extern01b.cpp 生成对应的 .o 文件，然后将这两个目标文件链接起来生成最终的可执行文件 extern01。

#请确保您的目录中有一个正确的 makefile，并且当您运行 make 命令时，它能够正确识别并执行上述逻辑。
# 这样，既包含了 extern01a.cpp 中的全局变量声明与定义，也包含了 extern01b.cpp 中的 main 函数，从而可以成功编译并运行程序。

# g++ -c 是一个编译命令行选项，用于指示 GNU C++ 编译器 (g++) 只进行编译步骤而不进行链接步骤。
# 这意味着它会将源代码文件（如 .cpp 文件）转换为目标文件（通常是 .o 文件，即目标代码或对象文件），但不会进一步生成可执行文件。

# Makefile for arithmetic sequence calculator

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# 目标程序
TARGETS = test_arithmetic arithmetic_sequence

# 默认目标
all: $(TARGETS)

# 编译测试程序
test_arithmetic: test.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# 编译交互式计算器
arithmetic_sequence: arithmetic_sequence.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# 运行测试
test: test_arithmetic
	./test_arithmetic

# 运行交互式程序（用于演示）
demo: arithmetic_sequence
	echo "5\n2\n8" | ./arithmetic_sequence

# 清理编译文件
clean:
	rm -f $(TARGETS)

# 安装（将可执行文件复制到 /usr/local/bin）
install: $(TARGETS)
	cp $(TARGETS) /usr/local/bin/

.PHONY: all test demo clean install
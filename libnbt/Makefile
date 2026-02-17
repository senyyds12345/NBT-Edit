# 编译器
CXX = g++
CXXFLAGS = -std=c++11 -Wall -O2 -Iinclude

# 目录
SRCDIR = src
INCDIR = include
LIBDIR = lib
BINDIR = bin

# 源文件
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(LIBDIR)/%.o)

# 目标库
LIB_TARGET = $(LIBDIR)/libnbt.a
SHARED_TARGET = $(LIBDIR)/libnbt.so

# 测试程序（如果有）
TEST_SRC = test.cpp
TEST_TARGET = $(BINDIR)/nbt-test

# 默认目标
all: dirs static shared

# 创建目录
dirs:
	@mkdir -p $(LIBDIR) $(BINDIR)

# 静态库
static: $(LIB_TARGET)

$(LIB_TARGET): $(OBJS)
	ar rcs $@ $^
	@echo "✅ 静态库已创建: $@"

# 动态库
shared: $(SHARED_TARGET)

$(SHARED_TARGET): $(OBJS)
	$(CXX) -shared -o $@ $^
	@echo "✅ 动态库已创建: $@"

# 编译目标文件
$(LIBDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -fPIC -c $< -o $@
	@echo "🔨 编译: $<"

# 测试程序（如果有 test.cpp）
test: dirs $(LIB_TARGET)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_SRC) -L$(LIBDIR) -lnbt
	@echo "✅ 测试程序已创建: $(TEST_TARGET)"

# 运行测试
run-test: test
	@$(TEST_TARGET)

# 安装到系统（需要 sudo）
install: static shared
	@echo "📦 安装头文件到 /usr/local/include/nbt/"
	@sudo mkdir -p /usr/local/include/nbt
	@sudo cp $(INCDIR)/*.h /usr/local/include/nbt/
	@echo "📦 安装库到 /usr/local/lib/"
	@sudo cp $(LIB_TARGET) $(SHARED_TARGET) /usr/local/lib/
	@sudo ldconfig
	@echo "✅ 安装完成"

# 卸载
uninstall:
	@echo "🗑️  卸载头文件和库"
	@sudo rm -rf /usr/local/include/nbt
	@sudo rm -f /usr/local/lib/libnbt.*
	@sudo ldconfig
	@echo "✅ 卸载完成"

# 清理
clean:
	rm -rf $(LIBDIR) $(BINDIR)
	@echo "🧹 清理完成"

# 彻底清理（包括依赖）
distclean: clean
	rm -f *.deb *.tar.gz

# 打包成 deb（可选）
deb: static
	@echo "📦 创建 deb 包..."
	@mkdir -p deb/usr/local/include/nbt deb/usr/local/lib
	@cp $(INCDIR)/*.h deb/usr/local/include/nbt/
	@cp $(LIB_TARGET) $(SHARED_TARGET) deb/usr/local/lib/
	@mkdir -p deb/DEBIAN
	@echo "Package: libnbt" > deb/DEBIAN/control
	@echo "Version: 1.0.0" >> deb/DEBIAN/control
	@echo "Architecture: all" >> deb/DEBIAN/control
	@echo "Maintainer: senyyds12345" >> deb/DEBIAN/control
	@echo "Description: NBT library for Minecraft" >> deb/DEBIAN/control
	@dpkg-deb --build deb libnbt_1.0.0_all.deb
	@rm -rf deb
	@echo "✅ deb 包已创建: libnbt_1.0.0_all.deb"

# 帮助
help:
	@echo "可用的 make 命令："
	@echo "  make          - 编译静态库和动态库"
	@echo "  make static   - 只编译静态库 (.a)"
	@echo "  make shared   - 只编译动态库 (.so)"
	@echo "  make test     - 编译测试程序"
	@echo "  make run-test - 运行测试"
	@echo "  make install  - 安装到系统"
	@echo "  make uninstall- 卸载"
	@echo "  make clean    - 清理编译文件"
	@echo "  make distclean- 彻底清理"
	@echo "  make deb      - 创建 deb 包"
	@echo "  make help     - 显示帮助"

.PHONY: all dirs static shared test run-test install uninstall clean distclean deb help
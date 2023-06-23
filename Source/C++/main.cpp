#include <iostream>
// 去注释则禁用 assert()。
// #define NDEBUG
#include <cassert>

int main(int argc, char const *argv[])
{
    int i = 1;
    assert(i); // 断言与0比较，==0 会出错。
    std::cout << "finish" << std::endl;
    --i;
    assert(("this is test.",i)); // 断言可以添加信息。
    std::cout << "finish" << std::endl;
    return 0;
}

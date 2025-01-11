#include "../exercise.h"
#include <string>

// READ: 字符串 <https://zh.cppreference.com/w/cpp/string/basic_string>

int main(int argc, char **argv) {
    // READ: 字符串字面量 <https://zh.cppreference.com/w/cpp/string/basic_string/operator%22%22s>
    using namespace std::string_literals;
    auto hello = "Hello"s; // 使用字符串字面量后缀 `s`，类型为 std::string
    auto world = "world";  // 普通字符串字面量，类型为 const char*
    // READ: `decltype` 表达式 <https://zh.cppreference.com/w/cpp/language/decltype>
    // READ: `std::is_same_v` 元编程判别 <https://zh.cppreference.com/w/cpp/types/is_same>
    ASSERT((std::is_same_v<decltype(hello), std::string>), "Fill in the missing type."); // hello 的类型是 std::string
    ASSERT((std::is_same_v<decltype(world), const char*>), "Fill in the missing type."); // world 的类型是 const char*
    // TODO: 将 `?` 替换为正确的字符串
    ASSERT(hello + ", " + world + '!' == "Hello, world!", "Fill in the missing string."); // 拼接后的字符串是 "Hello, world!"
    return 0;
}
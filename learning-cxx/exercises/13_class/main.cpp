#include "../exercise.h"

// C++ 中，`class` 和 `struct` 之间的**唯一区别**是
// `class` 默认访问控制符是 `private`，
// `struct` 默认访问控制符是 `public`。
// READ: 访问说明符 <https://zh.cppreference.com/w/cpp/language/access>

// 这个 class 中的字段被 private 修饰，只能在 class 内部访问。
// 因此必须提供构造器来初始化字段。
// READ: 构造器 <https://zh.cppreference.com/w/cpp/language/constructor>
class Fibonacci {
    size_t cache[16];
    int cached;

public:
    // 构造函数，初始化缓存
    Fibonacci() : cached(0) {
        cache[0] = 0;  // fibonacci(0) = 0
        cache[1] = 1;  // fibonacci(1) = 1
    }

    // 获取第 i 个斐波那契数
    size_t get(int i) {
        // 如果 i 为负数，直接返回 0
        if (i < 0) return 0;

        // 如果 i 超出缓存范围，直接返回 0
        if (i >= 16) return 0;

        // 如果缓存未计算到 i，则继续计算
        if (cached <= i) {
            for (; cached <= i; ++cached) {
                if (cached == 0) {
                    cache[0] = 0;  // fibonacci(0) = 0
                } else if (cached == 1) {
                    cache[1] = 1;  // fibonacci(1) = 1
                } else {
                    cache[cached] = cache[cached - 1] + cache[cached - 2];
                }
            }
        }

        // 返回缓存中的结果
        return cache[i];
    }
};

int main(int argc, char **argv) {
    // 现在类型拥有无参构造器，声明时会直接调用。
    // 这个写法不再是未定义行为了。
    Fibonacci fib;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}

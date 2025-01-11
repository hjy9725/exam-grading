#include "../exercise.h"

// READ: 析构函数 <https://zh.cppreference.com/w/cpp/language/destructor>
// READ: RAII <https://learn.microsoft.com/zh-cn/cpp/cpp/object-lifetime-and-resource-management-modern-cpp?view=msvc-170>

/// @brief 任意缓存容量的斐波那契类型。
/// @details 可以在构造时传入缓存容量，因此需要动态分配缓存空间。
class DynFibonacci {
    size_t *cache;  // 动态分配的缓存数组
    int capacity;   // 缓存容量
    int cached;     // 当前缓存的最大索引

public:
    // 构造函数，动态分配缓存空间并初始化
    DynFibonacci(int capacity) : capacity(capacity), cached(0) {
        cache = new size_t[capacity];  // 动态分配缓存数组
        cache[0] = 0;  // fibonacci(0) = 0
        cache[1] = 1;  // fibonacci(1) = 1
    }

    // 析构函数，释放动态分配的缓存空间
    ~DynFibonacci() {
        delete[] cache;  // 释放缓存数组
    }

    // 获取第 i 个斐波那契数
    size_t get(int i) {
        // 如果 i 为负数，直接返回 0
        if (i < 0) return 0;

        // 如果 i 超出缓存范围，直接返回 0
        if (i >= capacity) return 0;

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
    DynFibonacci fib(12);
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}

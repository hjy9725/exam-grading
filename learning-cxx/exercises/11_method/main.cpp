#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128];
    int cached;

    // TODO: 实现正确的缓存优化斐波那契计算
    // 构造函数，初始化缓存
    Fibonacci() : cached(0) {
        cache[0] = 0;  // fibonacci(0) = 0
        cache[1] = 1;  // fibonacci(1) = 1
    }

    // 获取第 i 个斐波那契数
    unsigned long long get(int i) {
        // 如果 i 为负数，直接返回 0
        if (i < 0) return 0;

        // 如果 i 超出缓存范围，直接返回 0
        if (i >= 128) return 0;

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
        return cache[i];
    }
};

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    Fibonacci fib;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}

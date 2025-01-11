#include "../exercise.h"

// READ: 复制构造函数 <https://zh.cppreference.com/w/cpp/language/copy_constructor>
// READ: 函数定义（显式弃置）<https://zh.cppreference.com/w/cpp/language/function>



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

    // 复制构造函数，深拷贝缓存数组
    DynFibonacci(DynFibonacci const &other) : capacity(other.capacity), cached(other.cached) {
        cache = new size_t[capacity];  // 动态分配新的缓存数组
        for (int i = 0; i <= cached; ++i) {
            cache[i] = other.cache[i];  // 复制缓存数据
        }
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

    // const 版本的 get 方法
    size_t get(int i) const {
        if (i <= cached) {
            return cache[i];
        }
        ASSERT(false, "i out of range");
        return 0;  // 避免编译器警告
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    DynFibonacci const fib_ = fib;
    ASSERT(fib_.get(10) == fib.get(10), "Object cloned");
    return 0;
}

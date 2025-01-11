﻿#include "../exercise.h"
#include <cstring>
#include <vector>

// READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector>

int main(int argc, char **argv) {
    {
        std::vector<int> vec{1, 2, 3, 4, 5};
        ASSERT(vec.size() == 5, "Fill in the correct value."); // vec 的大小为 5
        // THINK: `std::vector` 的大小是什么意思？与什么有关？
        // 答：`std::vector` 的大小是指当前存储的元素数量，与 `size()` 返回值相同。
        ASSERT(sizeof(vec) == sizeof(std::vector<int>), "Fill in the correct value."); // sizeof(vec) 是 std::vector 对象的大小
        int ans[]{1, 2, 3, 4, 5};
        ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values."); // 使用 vec.data() 获取原始指针
    }
    {
        std::vector<double> vec{1, 2, 3, 4, 5};
        {
            ASSERT(vec.size() == 5, "Fill in the correct value."); // vec 的大小为 5
            ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value."); // sizeof(vec) 是 std::vector 对象的大小
            double ans[]{1, 2, 3, 4, 5};
            ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values."); // 使用 vec.data() 获取原始指针
        }
        {
            vec.push_back(6);
            ASSERT(vec.size() == 6, "Fill in the correct value."); // push_back 后大小为 6
            ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value."); // sizeof(vec) 不变
            vec.pop_back();
            ASSERT(vec.size() == 5, "Fill in the correct value."); // pop_back 后大小为 5
            ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value."); // sizeof(vec) 不变
        }
        {
            vec[4] = 6;
            ASSERT(vec[0] == 1, "Fill in the correct value.");
            ASSERT(vec[1] == 2, "Fill in the correct value.");
            ASSERT(vec[2] == 3, "Fill in the correct value.");
            ASSERT(vec[3] == 4, "Fill in the correct value.");
            ASSERT(vec[4] == 6, "Fill in the correct value.");
        }
        {
            // THINK: `std::vector` 插入删除的时间复杂度是什么？
            // 答：插入和删除的时间复杂度为 O(n)，因为需要移动元素。
            vec.insert(vec.begin() + 1, 1.5); // 在第二个位置插入 1.5
            ASSERT((vec == std::vector<double>{1, 1.5, 2, 3, 4, 6}), "Make this assertion pass.");
            vec.erase(vec.begin() + 3); // 删除第四个元素（值为 3）
            ASSERT((vec == std::vector<double>{1, 1.5, 2, 4, 6}), "Make this assertion pass.");
        }
        {
            vec.shrink_to_fit();
            ASSERT(vec.capacity() == vec.size(), "Fill in the correct value."); // shrink_to_fit 后 capacity 等于 size
            vec.clear();
            ASSERT(vec.empty(), "`vec` is empty now.");
            ASSERT(vec.size() == 0, "Fill in the correct value."); // clear 后大小为 0
            ASSERT(vec.capacity() >= 0, "Fill in the correct value."); // capacity 可能大于等于 0
        }
    }
    {
        std::vector<char> vec(48, 'z'); // 调用构造函数，创建大小为 48，每个元素为 'z' 的 vector
        ASSERT(vec[0] == 'z', "Make this assertion pass.");
        ASSERT(vec[47] == 'z', "Make this assertion pass.");
        ASSERT(vec.size() == 48, "Make this assertion pass.");
        ASSERT(sizeof(vec) == sizeof(std::vector<char>), "Fill in the correct value."); // sizeof(vec) 是 std::vector 对象的大小
        {
            auto capacity = vec.capacity();
            vec.resize(16);
            ASSERT(vec.size() == 16, "Fill in the correct value."); // resize 后大小为 16
            ASSERT(vec.capacity() == capacity, "Fill in a correct identifier."); // capacity 可能不变
        }
        {
            vec.reserve(256);
            ASSERT(vec.size() == 16, "Fill in the correct value."); // reserve 不改变 size
            ASSERT(vec.capacity() == 256, "Fill in the correct value."); // reserve 后 capacity 为 256
        }
        {
            vec.push_back('a');
            vec.push_back('b');
            vec.push_back('c');
            vec.push_back('d');
            ASSERT(vec.size() == 20, "Fill in the correct value."); // push_back 4 次后大小为 20
            ASSERT(vec.capacity() == 256, "Fill in the correct value."); // capacity 不变
            ASSERT(vec[15] == 'z', "Fill in the correct value."); // resize 后多余的元素被初始化为默认值（'\0'）
            ASSERT(vec[16] == 'a', "Fill in the correct value.");
            ASSERT(vec[17] == 'b', "Fill in the correct value.");
            ASSERT(vec[18] == 'c', "Fill in the correct value.");
            ASSERT(vec[19] == 'd', "Fill in the correct value.");
        }
    }

    return 0;
}
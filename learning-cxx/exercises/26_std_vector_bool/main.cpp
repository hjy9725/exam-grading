#include "../exercise.h"
#include <vector>
#include <iostream>

// READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector_bool>
// READ: 模板特化 <https://zh.cppreference.com/w/cpp/language/template_specialization>

int main(int argc, char **argv) {
    std::vector<bool> vec(100, true); // 调用构造函数，创建大小为 100，每个元素为 true 的 vector
    ASSERT(vec[0], "Make this assertion pass."); // vec[0] 为 true
    ASSERT(vec[99], "Make this assertion pass."); // vec[99] 为 true
    ASSERT(vec.size() == 100, "Make this assertion pass."); // vec 的大小为 100
    // NOTICE: 平台相关！注意 CI:Ubuntu 上的值。
    std::cout << "sizeof(std::vector<bool>) = " << sizeof(std::vector<bool>) << std::endl;
    ASSERT(sizeof(vec) == sizeof(std::vector<bool>), "Fill in the correct value."); // sizeof(vec) 是 std::vector<bool> 对象的大小
    {
        vec[20] = false;
        ASSERT(!vec[20], "Fill in `vec[20]` or `!vec[20]`."); // vec[20] 被设置为 false
    }
    {
        vec.push_back(false);
        ASSERT(vec.size() == 101, "Fill in the correct value."); // push_back 后大小为 101
        ASSERT(!vec[100], "Fill in `vec[100]` or `!vec[100]`."); // vec[100] 为 false
    }
    {
        auto ref = vec[30];
        ASSERT(ref, "Fill in `ref` or `!ref`"); // ref 是 vec[30] 的引用，值为 true
        ref = false;
        ASSERT(!ref, "Fill in `ref` or `!ref`"); // ref 被设置为 false
        // THINK: WHAT and WHY?
        // 答：ref 是 std::vector<bool>::reference 类型，修改 ref 会同步修改 vec[30]。
        ASSERT(!vec[30], "Fill in `vec[30]` or `!vec[30]`."); // vec[30] 被修改为 false
    }
    return 0;
}
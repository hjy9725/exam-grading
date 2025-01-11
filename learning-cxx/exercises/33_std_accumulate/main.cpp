#include "../exercise.h"
#include <numeric> // for std::accumulate
#include <cstddef> // for std::size_t

// READ: `std::accumulate` <https://zh.cppreference.com/w/cpp/algorithm/accumulate>

int main(int argc, char **argv) {
    using DataType = float;
    int shape[]{1, 3, 224, 224};

    // Calculate the total number of elements in the tensor
    std::size_t num_elements = std::accumulate(
        std::begin(shape), std::end(shape), 1, std::multiplies<int>());

    // Calculate the total size in bytes
    std::size_t size = num_elements * sizeof(DataType);

    // Assert the calculated size matches the expected value
    ASSERT(size == 602112, "4x1x3x224x224 = 602112");

    return 0;
}
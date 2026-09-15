#include <iostream>
#include "lru_cache.hpp"

static void print(const LRUCache& cache, int key) {
    int value = const_cast<LRUCache&>(cache).get(key);
    std::cout << "get(" << key << ") = " << value << "\n";
}

int main() {
    LRUCache cache(3);

    std::cout << "=== Insert A=1, B=2, C=3 ===\n";
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);
    print(cache, 1);  // 1
    print(cache, 2);  // 2
    print(cache, 3);  // 3

    std::cout << "\n=== Insert D=4 (evicts LRU) ===\n";
    cache.put(4, 4);
    print(cache, 1);  // -1 (evicted)
    print(cache, 2);  // 2
    print(cache, 3);  // 3
    print(cache, 4);  // 4

    std::cout << "\n=== Update A=10 ===\n";
    cache.put(2, 20);
    print(cache, 2);  // 20

    return 0;
}
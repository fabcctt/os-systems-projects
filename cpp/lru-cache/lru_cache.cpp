#include "lru_cache.hpp"

LRUCache::LRUCache(int capacity) : capacity(capacity) {}

int LRUCache::get(int key) {
    auto it = index.find(key);
    if (it == index.end()) {
        return -1;
    }

    // Move to front (most recently used)
    items.splice(items.begin(), items, it->second);
    return it->second->second;
}

void LRUCache::put(int key, int value) {
    auto it = index.find(key);

    if (it != index.end()) {
        // Update existing
        it->second->second = value;
        items.splice(items.begin(), items, it->second);
        return;
    }

    // Evict if full
    if (static_cast<int>(items.size()) >= capacity) {
        int old_key = items.back().first;
        items.pop_back();
        index.erase(old_key);
    }

    // Insert at front
    items.emplace_front(key, value);
    index[key] = items.begin();
}

int LRUCache::size() const {
    return static_cast<int>(items.size());
}

bool LRUCache::contains(int key) const {
    return index.find(key) != index.end();
}
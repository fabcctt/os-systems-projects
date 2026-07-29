#include <iostream>
#include <vector>

class MemoryBlock {
    private:
        int size;
        bool isFree;
    public:
        MemoryBlock(int s) {
            size = s;
            isFree = true;
        }
        int getSize() {
            return size;
        }
        bool getIsFree() {
            return isFree;
        }
        void occupy() {
            isFree = false;
        }
        void free() {
            isFree = true;
        }
};

class RAM {
    private:
        std::vector<MemoryBlock> blocks;
    public:
        void addBlock(MemoryBlock b) {
            blocks.push_back(b);
        }
        void showStatus() {
            for (int i = 0; i < blocks.size(); i++) {
                if (blocks[i].getIsFree()) {
                    std::cout << "Block " << i << ": " << blocks[i].getSize() << "KB [FREE]" << std::endl;
                } else {
                    std::cout << "Block " << i << ": " << blocks[i].getSize() << "KB [OCCUPIED]" << std::endl;
                }
            }
        }
        void allocate(int requiredSize) {
            for (int i = 0; i < blocks.size(); i++) {
                if (blocks[i].getIsFree() && blocks[i].getSize() >= requiredSize) {
                 blocks[i].occupy();
                 std::cout << "Allocated " << requiredSize << "KB in Block " << i << std::endl;
            return;
        }
    }
    std::cout << "Not enough memory available" << std::endl;
  }
};

int main() {
    MemoryBlock blocks1(128);
    MemoryBlock blocks2(256);
    MemoryBlock blocks3(512);
    RAM ram;
    ram.addBlock(blocks1);
    ram.addBlock(blocks2);
    ram.addBlock(blocks3);
    ram.showStatus();
    std::cout << "\n--- Allocating 200KB ---" << std::endl;
    ram.allocate(200);
    ram.showStatus();
    return 0;
}
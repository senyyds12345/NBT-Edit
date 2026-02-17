#include <iostream>
#include "nbt.h"

int main() {
    NBT nbt("test.nbt");
    nbt.init();
    
    nbt.add_byte("health", 20);
    nbt.add_short("xp", 1000);
    nbt.add_end();
    
    std::cout << "NBT file created: test.nbt" << std::endl;
    return 0;
}
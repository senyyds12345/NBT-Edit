#ifndef NBT_H
#define NBT_H

#include <string>
#include <fstream>

class NBT
{
private:
    std::string filename;
    std::ofstream file;
public:
    NBT(std::string filename);
    void init();
    void add_byte(std::string name, int8_t value);
    void add_end();
    void add_short(std::string name, short value);
};

#endif
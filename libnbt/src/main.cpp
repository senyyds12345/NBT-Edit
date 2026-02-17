#include <ios>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "nbt.h"
NBT::NBT(std::string filename)
{
    this->filename = filename;
    this->file.open(filename, std::ios::out | std::ios::binary | std::ios::app);
    if(!file.is_open())
    {
        std::cerr << "Error: cannot open file" << std::endl;
        return;
    }
}
void NBT::init()
{
    file.write("\x0A", 1);
    file.write("\x00\x04", 2);
    file.write("root", 4);
}

void NBT::add_byte(std::string name, int8_t value)
{
    if(value < -128 || value > 127)
    {
        std::cerr << "Error: Value Overflow" << std::endl;
        return;
    }
    file.write("\x01", 1);
    file.write("\x00", 1);
    file.put(static_cast<char>(name.length()));
    file.write(name.c_str(), name.length());
    file.put(static_cast<char>(value));
}

void NBT::add_short(std::string name, short value)
{
    if(value < -32768 || value > 32767)
    {
        std::cerr << "Error: Value Overflow" << std::endl;
    }
    file.write("\x02", 1);
    file.write("\x00", 1);
    file.put(static_cast<char>(name.length()));
    file.write(name.c_str(), name.length());
    int16_t val = static_cast<int16_t>(value);
    file.put(static_cast<char>((val >> 8) & 0xFF));
    file.put(static_cast<char>(val & 0xFF));
}

void NBT::add_end()
{
    file.write("\x00", 1);
    file.close();
}
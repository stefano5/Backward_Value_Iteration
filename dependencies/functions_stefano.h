/*
 *
 *      Author: stefano
 *
*/




#ifndef API_S_H
#define API_S_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <locale>

class API_S {
    public:
        static inline void ltrim(std::string &s);
        static inline void rtrim(std::string &s);
        static inline void trim(std::string &s);
        static int16_t get_size_file(std::string file_to_read);
        static bool exist_file(std::string file_to_read);
        static std::vector<std::string> read_file(std::string file_to_read);
        static std::string vector2string(std::vector<std::string> vector, std::string delimeter);       // from vector<string> to string with delimeter
        static std::string vector2string(std::vector<std::string> vector);
};

#endif

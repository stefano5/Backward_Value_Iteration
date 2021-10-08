
#include "functions_stefano.h"

#ifndef API_S_CPP_CPP
#define API_S_CPP_CPP

inline void API_S::ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

inline void API_S::rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

inline void API_S::trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

int16_t API_S::get_size_file(std::string file_to_read) {
    std::streampos begin,end;
    std::ifstream myfile (file_to_read, std::ios::binary);
    if (myfile.is_open()) {
        begin = myfile.tellg();
        myfile.seekg (0, std::ios::end);
        end = myfile.tellg();
        myfile.close();
        return end - begin;
    } else return -1;
}

bool API_S::exist_file(std::string file_to_read) {
    return get_size_file(file_to_read) != -1;
}

std::vector<std::string> API_S::read_file(std::string file_to_read) {
    std::string file_raw;
    std::vector<std::string> all_file;
    std::ifstream file(file_to_read);

    if (file.is_open()) {
        while ( getline(file, file_raw) ) {
            all_file.push_back(file_raw);
        }
        file.close();
    } else {
        std::cerr << "read_file(" << file_to_read << ") <= file not found" << std::endl;
    }
    return all_file;
}

std::string API_S::vector2string(std::vector<std::string> vector, std::string delimeter) {
    std::string all_row = "";
    for (std::string v:vector) {
        all_row += v + delimeter;
    }
    trim(all_row);
    return all_row;
}

std::string API_S::vector2string(std::vector<std::string> vector) {
    return vector2string(vector, "\n");
}



#endif


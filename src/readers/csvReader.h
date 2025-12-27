#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <fstream>
#include <vector>
#include "../engine/feature.h"

class CsvReader {
public:
    explicit CsvReader(const std::string& filename);

    bool next(Feature& feature);

private:
    std::ifstream file_;
    std::vector<std::string> headers_;
    bool initialized_ = false;

    void readHeader();
};

#endif
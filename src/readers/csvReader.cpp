#include "csvReader.h"
#include <sstream>
#include <stdexcept>
#include <iostream>

CsvReader::CsvReader(const std::string& filename) : file_(filename)  {
    if (!file_) {
        throw std::runtime_error("Failed to open csv file");
    }
}

void CsvReader::readHeader() {
    std::string line;
    std::getline(file_, line);

    std::stringstream ss(line);
    std::string column;
    while (std::getline(ss, column, ',')) {
        headers_.push_back(column);
    }
    initialized_ = true;
}

bool CsvReader::next(Feature& feature) {
    if (!initialized_) {
        readHeader();
    }

    // read each row
    std::string line;
    if (!std::getline(file_, line)) {
        return false;
    }

    std::stringstream ss(line);
    std::string value;
    size_t index = 0;

    // read each value in the row
    while (std::getline(ss, value, ',') && index < headers_.size()) {
        feature.setAttribute(headers_[index], value);
        ++index;
    }
    return true;
}
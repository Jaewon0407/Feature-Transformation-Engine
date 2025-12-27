#ifndef CSVWRITER_H
#define CSVWRITER_H

#include <fstream>
#include "../engine/feature.h"

class CsvWriter {
public:
    explicit CsvWriter(const std::string& filename);

    void write(const Feature& feature);

private:
    std::ofstream file_;
    bool headerWritten_ = false;

    void writeHeader(const Feature& feature);
};

#endif
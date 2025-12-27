#include "csvWriter.h"
#include <stdexcept>

CsvWriter::CsvWriter(const std::string& filename) : file_(filename) {
    if (!file_) {
        throw std::runtime_error("Failed to open output csv");
    }
}

void CsvWriter::writeHeader(const Feature& feature) {
    bool first = true;
    for (const auto& [key, _] : feature.getAttributes()) {
        if (!first) file_ << ",";
        file_ << key;
        first = false;
    }
    file_ << "\n";
    headerWritten_ = true;
}

void CsvWriter::write(const Feature& feature) {
    if (!headerWritten_) {
        writeHeader(feature);
    }

    bool first = true;
    for (const auto& [_, value] : feature.getAttributes()) {
        if (!first) file_ << ",";
        std::visit([&](auto&& v) { file_ << v; }, value);
        first = false;
    }
    file_ << "\n";
}
#include <iostream>
#include "engine/feature.h"
#include "engine/pipeline.h"
#include "transformers/renameAttribute.h"
#include "readers/csvReader.h"
#include "writers/csvWriter.h"

int main() {
    CsvReader reader("data/input.csv");
    CsvWriter writer("data/output.csv");

    Pipeline pipeline;
    pipeline.addTransformer(std::make_unique<RenameAttribute>("name", "new_name"));

    Feature feature;
    while (reader.next(feature)) {
        // Run transformer on each feature
        if (pipeline.run(feature)) {
            writer.write(feature);
        }
    }

    std::cout << "Transformation Complete" << std::endl;

    return 0;
}
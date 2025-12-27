#include "pipeline.h"

void Pipeline::addTransformer(std::unique_ptr<Transformer> transformer) {
    transformers_.push_back(std::move(transformer));
}

bool Pipeline::run(Feature& feature) {
    for (auto& transformer : transformers_) {
        if (!transformer->process(feature)) {
            return false;
        }
    }
    return true;
}
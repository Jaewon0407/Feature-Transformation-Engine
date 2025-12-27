#ifndef PIPELINE_H
#define PIPELINE_H  

#include "transformer.h"
#include <vector>
#include <memory>

class Pipeline {
public:
    void addTransformer(std::unique_ptr<Transformer> transformer);

    bool run(Feature& feature);
    
private:
    std::vector<std::unique_ptr<Transformer>> transformers_;
};

#endif
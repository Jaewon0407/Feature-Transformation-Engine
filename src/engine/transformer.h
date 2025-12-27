#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include "feature.h"

class Transformer {
public:
    virtual ~Transformer() = default;
    
    virtual bool process(Feature& feature) = 0;
};

#endif
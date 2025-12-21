#include "renameAttribute.h"

bool renameAttribute::process(Feature& feature) {
    auto val = feature.getAttribute(from_);
    if (!val) {
        // attribute missing, do nothing or log
        return true;
    }

    feature.setAttribute(to_, *val);
    feature.removeAttribute(from_);
    return true;
}
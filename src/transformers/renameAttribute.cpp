#include "renameAttribute.h"

RenameAttribute::RenameAttribute(const std::string& from, const std::string& to) : from_(std::move(from)), to_(std::move(to)) {}

bool RenameAttribute::process(Feature& feature) {
    auto val = feature.getAttribute(from_);
    if (!val) {
        // attribute missing, do nothing or log
        return true;
    }

    feature.setAttribute(to_, *val);
    feature.removeAttribute(from_);
    return true;
}
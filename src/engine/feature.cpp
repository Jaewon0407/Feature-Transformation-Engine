#include "feature.h"

void Feature::setAttribute(const std::string& key, attributeValue value) {
    attributes_[key] = std::move(value);
}

std::optional<attributeValue> Feature::getAttribute(const std::string& key) const {
    auto it = attributes_.find(key);
    // if we cannot find the attribute, return empty
    if (it == attributes_.end()) {
        return std::nullopt;
    }
    return it->second;
}

bool Feature::hasAttribute(const std::string& key) const {
    if (attributes_.find(key) != attributes_.end()) {
        return true;
    } else{
        return false;
    }
}

void Feature::removeAttribute(const std::string& key) {
    attributes_.erase(key);
}

std::size_t Feature::attributeCount() const {
    return attributes_.size();
}

const std::unordered_map<std::string, attributeValue>& Feature::getAttributes() const {
    return attributes_;
}
#include "../engine/transformer.h"
#include <string>

class renameAttribute : public Transformer {
public:
    renameAttribute(std::string from, std::string to) : from_(std::move(from)), to_(std::move(to)) {}
    bool process(Feature& feature) override;
private:
    std::string from_;
    std::string to_;
};

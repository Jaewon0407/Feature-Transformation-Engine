#include "../engine/transformer.h"
#include <string>

class RenameAttribute : public Transformer {
public:
    RenameAttribute(const std::string& from, const std::string& to);
    bool process(Feature& feature) override;
private:
    std::string from_;
    std::string to_;
};

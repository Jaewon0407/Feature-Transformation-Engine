#include <variant>
#include <string>
#include <optional>
#include <unordered_map>

using attributeValue = std::variant<int, double, std::string>;

class Feature {
public:
    void setAttribute(const std::string& key, attributeValue value);
    
    std::optional<attributeValue> getAttribute(const std::string& key) const;
    
    bool hasAttribute(const std::string& key) const;
    
    void removeAttribute(const std::string& key);
    
    std::size_t attributeCount() const;

private:
    std::unordered_map<std::string, attributeValue> attributes_;
};
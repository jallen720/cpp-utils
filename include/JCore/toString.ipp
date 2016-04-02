namespace JCore {

template<typename T>
std::string toString(const T val) {
    return std::to_string(val);
}

template<>
std::string toString(const bool isTrue) {
    return isTrue ? "true" : "false";
}

} // namespace JCore

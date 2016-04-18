namespace JCore {


template<typename T>
void assertEqualElements(
    const std::vector<T>& expectedElements,
    const std::vector<T>& actualElements)
{
    ASSERT_EQ(expectedElements.size(), actualElements.size());

    for (auto i = 0u; i < expectedElements.size(); i++) {
        ASSERT_EQ(expectedElements[i], actualElements[i]);
    }
}


} // namespace JCore

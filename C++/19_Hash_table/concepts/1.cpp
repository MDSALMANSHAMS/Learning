#include <iostream>
#include <unordered_map>

int main()
{
    // Create an unordered_map where keys are strings and values are integers
    std::unordered_map<std::string, int> umap;

    // Insert key-value pairs
    umap["apple"] = 1;
    umap["banana"] = 2;
    umap["cherry"] = 3;

    // Access elements
    std::cout << "apple: " << umap["apple"] << std::endl;
    std::cout << "banana: " << umap["banana"] << std::endl;

    // Check if a key exists
    if (umap.find("cherry") != umap.end())
    {
        std::cout << "cherry is in the map" << std::endl;
    }

    // Iterate over elements
    for (const auto &pair : umap)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}

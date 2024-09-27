#include <iostream>
#include <cstdlib>

int main()
{
    size_t size = 100;
    void *ptr = malloc(size);

    if (ptr == nullptr)
    {
        std::cerr << "Memory allocation failed" << std::endl;
        return 1;
    }

    std::cout << "Allocated memory at: " << ptr << std::endl;

    // Cast to a char pointer to inspect raw bytes
    char *raw_ptr = static_cast<char *>(ptr);

    // Print the first few bytes to inspect
    for (int i = 0; i < 16; ++i)
    {
        std::cout << "Byte " << i << ": " << static_cast<int>(raw_ptr[i]) << std::endl;
    }

    free(ptr);
    return 0;
}

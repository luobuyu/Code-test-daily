#include <iostream>
#include <memory>

void modifySharedPtr(std::shared_ptr<int> sp)
{
    sp = std::make_shared<int>(30); // 修改智能指针本身
    // *sp = 100;
}

int main()
{
    std::shared_ptr<int> sp = std::make_shared<int>(10);
    modifySharedPtr(sp);
    std::cout << "Outside: " << *sp << std::endl;
    return 0;
}

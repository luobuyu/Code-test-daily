#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
void threadFunction()
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Thread executing: " << i << std::endl;
        std::this_thread::sleep_for(chrono::seconds(1));
    }
}

int main()
{
    std::thread t(threadFunction);

    std::cout << "Main thread finished" << std::endl;

    // Detach the thread, allowing it to run independently
    t.detach();
    this_thread::sleep_for(chrono::seconds(10));
    return 0;
}

#include <iostream>

#include <thread>
#include "boot/boot.h"

using namespace std;

int main()
{
    // thread thread1 = thread(func_type_thread, 10);
    Boot* boot = Boot::getInstance();
    thread _thread = thread(&Boot::init, boot);
    _thread.join();

    return 0;
}

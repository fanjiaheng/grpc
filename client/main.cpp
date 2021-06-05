#include "Client.h"

int main()
{
    cli::Client handle;
    handle.init();

    // say hello
    for (int i = 0; i < 10; i++) {
        handle.sayHello("fanjiaheng test");
    }

    handle.unInit();

    return 0;
}
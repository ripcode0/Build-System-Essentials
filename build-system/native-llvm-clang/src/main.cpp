
#include <iostream>

#include "game.h"

enum flag { opengl, dx11 };

int main(int args, char *argv[]) {
    flag flags{opengl};

    switch (flags) {
        case opengl:
            break;
        case dx11:
            break;
    }
    printf("my name is %s\n", emt::game::get_name());
    return 0;
}
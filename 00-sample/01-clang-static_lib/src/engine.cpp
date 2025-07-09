#include "engine.h"

void engine::print_all() {
    std::vector<const char*> strs;
    strs.emplace_back("hello");
    strs.emplace_back("engine");
    
    for(size_t i = 0; i < strs.size(); ++i){
        printf("name : %s\n", strs[i]);
    }
}
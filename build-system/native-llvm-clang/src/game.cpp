#include "game.h"

namespace emt {
    namespace game {
        const char* get_name() {
#if defined(CUSTOM_MSG)
            return CUSTOM_MSG;
#else
            return "game";
#endif
        }
    }  // namespace game
}  // namespace emt
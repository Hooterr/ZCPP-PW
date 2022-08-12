#include "tile.h"


bool operator >=(const ITile& t1, const ITile& t2) {
    if (t1.isEmpty()) {
        return true;
    }

    if (t2.isEmpty()) {
        return false;
    }

    return t1.getSequence() >= t2.getSequence();
}

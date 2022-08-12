#ifndef EMPTYTILE_H
#define EMPTYTILE_H
#include "tile.h"


class EmptyTile : ITile {
public:
    bool isEmpty() const {
        return true;
    }
};

#endif // EMPTYTILE_H

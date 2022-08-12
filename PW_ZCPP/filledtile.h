#ifndef FILLEDTILE_H
#define FILLEDTILE_H

#include "tile.h"

class FilledTile : ITile {
public:
    bool isEmpty() const {
        return false;
    }

    FilledTile(int sequence) {
        _sequence = sequence;
    }
};

#endif // FILLEDTILE_H

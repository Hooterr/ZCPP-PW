#ifndef EMPTYTILE_H
#define EMPTYTILE_H
#include "tile.h"

/**
 * @brief Represents an empty tile
 * 
 */
class EmptyTile : ITile {
public:

    /**
     * @brief Gets whether this tile is empty or not
     * 
     * @return true if the tile is empty,
     * @return false otherwise
     */
    bool isEmpty() const {
        return true;
    }
};

#endif // EMPTYTILE_H

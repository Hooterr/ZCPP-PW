#ifndef FILLEDTILE_H
#define FILLEDTILE_H

#include "tile.h"

/**
 * @brief Represents a tile that is not empty (filled)
 * 
 */
class FilledTile : ITile {
public:

    /**
     * @brief Gets whether this tile is empty or not
     * 
     * @return true if the tile is empty,
     * @return false otherwise
     */
    bool isEmpty() const {
        return false;
    }

    /**
     * @brief Construct a new Filled Tile object with a given sequence number
     * 
     * @param sequence The sequence number
     */
    FilledTile(int sequence) {
        _sequence = sequence;
    }
};

#endif // FILLEDTILE_H

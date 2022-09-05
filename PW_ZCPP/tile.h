#ifndef ITILE_H
#define ITILE_H

/**
 * @brief Provides basic functionallity for the tile game objects
 * 
 */
class ITile {
public:

    /**
     * @brief Gets whether this tile is empty or not
     * 
     * @return true if the tile is empty,
     * @return false otherwise
     */
    bool virtual isEmpty() const = 0;

    /**
     * @brief Gets sequence number of this instance
     * 
     * @return int The sequence number
     */
    int getSequence() const {
        return _sequence;
    }

protected:

    /**
     * @brief The sequence number
     * 
     */
    int _sequence;
};

#endif // ITILE_H

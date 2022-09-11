#ifndef GAME_H
#define GAME_H
#include "tile.h"
#include <vector>

/**
 * @brief Represents the instance of a game
 * 
 */
class Game {
public :
    /**
     * @brief Construct a new Game object with a given size
     * 
     * @param size The size of the board
     */
    Game(int size);

    /**
     * @brief Destroy the Game object
     * 
     */
    ~Game() {
    }

    /**
     * @brief Gets the flag indicating whether the game has finished or not
     * 
     * @return true if the game has finished
     * @return false otherwise 
     */
    bool getIsFinished() const {
        return _isFinished;
    }

    /**
     * @brief Get the size of the board
     * 
     * @return int the size of the board
     */
    int getSize() const {
        return _size;
    }

    /**
     * @brief Gets the row number of the empty tile
     * 
     * @return int 0-based row index of the empty tile
     */
    int getEmptyTileRow() const {
        return _emptyTileRow;
    }

    /**
     * @brief Gets the col number of the empty tile
     * 
     * @return int 0-based col index of the empty tile
     */
    int getEmptyTileCol() const {
        return _emptyTileCol;
    }

    /**
     * @brief Gets the number of moves that the user has made in this game
     *
     * @return number of moves
     */
    int getNumberOfMoves() const {
        return _numberOfMoves;
    }

    /**
     * @brief Moves the specific element on the board
     * 
     * @param row 0-based row index of the element
     * @param col 0-based col index of the element
     * @return true if the element could be moved and as moved
     * @return false if the element wasn't able to be moved, the board is unaltered
     */
    bool move(int row, int col);

    /**
     * @brief Gets an iterator pointing to the begining of the board vector
     * 
     * @return std::vector<ITile *>::const_iterator The iterator
     */
    std::vector<ITile *>::const_iterator getElementsBegin() const {
        return _board.begin();
    }

    /**
     * @brief Gets an iterator pointing to the end of the board vector
     * 
     * @return std::vector<ITile *>::const_iterator The iterator
     */
    std::vector<ITile *>::const_iterator getElementsEnd() const {
        return _board.end();
    }


private:
    bool _isFinished;
    int _size;
    std::vector<ITile *> _board;
    int _emptyTileRow;
    int _emptyTileCol;
    int _numberOfMoves;
    void updateGameFinished();
};


#endif // GAME_H

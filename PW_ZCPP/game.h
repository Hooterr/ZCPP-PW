#ifndef GAME_H
#define GAME_H
#include "tile.h"
#include <vector>

class Game {
public :
    Game(int size);
    ~Game(){
    }


    bool getIsFinished() const {
        return _isFinished;
    }

    int getSize() const {
        return _size;
    }

    bool move(int row, int col);
private:
    bool _isFinished;
    int _size;
    std::vector<ITile *> _board;
    int _emptyTileRow;
    int _emptyTileCol;

    void updateGameFinished();
};


#endif // GAME_H

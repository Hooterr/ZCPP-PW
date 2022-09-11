#include "game.h"
#include "filledtile.h"
#include "emptytile.h"
#include <algorithm>
#include <time.h>

Game::Game(int size) : _size(size)
{
    _numberOfMoves = 0;
    int sequence = 1;
    const int totalCount = _size * _size;
    ITile *emptyTile = (ITile*)new EmptyTile();
    for (int i = 0; i < totalCount; i++) {
        if (i == totalCount - 1) {
            _board.push_back(emptyTile);
        }
        else {
            _board.push_back((ITile *) new FilledTile(sequence++));
        }
    }

    srand(time(0));
    std::random_shuffle(_board.begin(), _board.end());

    int emptyTileIdx = 0;
    for (int i = 0; i < totalCount; i++) {
        if (_board[i]->isEmpty()) {
            emptyTileIdx = i;
        }
    }

    _emptyTileCol = emptyTileIdx % _size;
    _emptyTileRow = (emptyTileIdx - _emptyTileCol) / _size;
}


bool Game::move(int row, int col) {

    if (row >= _size || col >= _size) {
        return false;
    }

    int totalPosDiff = std::abs(_emptyTileRow - row) + std::abs(_emptyTileCol - col);

    // In order to move the tile it must be exactly next to the empty tile
    if (totalPosDiff != 1) {
        return false;
    }

    std::swap(_board[row * _size + col], _board[_emptyTileRow * _size + _emptyTileCol]);

    _emptyTileCol = col;
    _emptyTileRow = row;
    _numberOfMoves++;
    updateGameFinished();

    return true;
}

bool compare(const ITile *t1, const ITile *t2) {
    if (t1->isEmpty()) {
        return false;
    }

    if (t2->isEmpty()) {
        return true;
    }

    return t1->getSequence() <= t2->getSequence();
}

void Game::updateGameFinished() {
    _isFinished = std::is_sorted(_board.begin(), _board.end(), compare);
}





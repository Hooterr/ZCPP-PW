#ifndef ITILE_H
#define ITILE_H


class ITile {
public:
    bool virtual isEmpty() const = 0;
    int getSequence() const {
        return _sequence;
    }

protected:
    int _sequence;
};

#endif // ITILE_H

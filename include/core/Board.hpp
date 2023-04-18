#pragma once

#include "Field.hpp"
#include "Pos.hpp"
#include "TGameState.hpp"

#include <iostream>
#include <vector>

namespace minesweeper
{

    typedef std::vector<std::vector<Field>> Board_t;

    class Board
    {
    private:
        Board_t _board;
        size_t _width;
        size_t _height;
        TGameState _state{TGameState::Standby};

    public:
        Board() : _width(0), _height(0){};

        inline size_t w() const { return this->_width; }

        inline size_t h() const { return this->_height; }

        inline const Board_t &get() const { return this->_board; }

        inline bool inside(const Pos &pos) const
        {
            return (pos.x >= 0 && pos.y >= 0) &&
                   (pos.x < this->_width && pos.y < this->_height);
        }

        void setSize(size_t width, size_t height);

        bool putMine(const Pos &pos);

        void calcMines();

        void restart();

        bool uncover(const Pos &pos);

        inline const Field &operator()(const Pos &pos) const
        {
            return this->_board[pos.y][pos.x];
        }

    private:
        inline Field &operator()(const Pos &pos)
        {
            return this->_board[pos.y][pos.x];
        }

        static const std::vector<Pos> _AROUND;
    };

}
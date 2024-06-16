#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
public:
	char[] square_;

	Board();
	~Board();
};

Board::Board()
{
	square_ = new char[64];

	for (int i = 0; i < 64; i++)
	{
		square_[i] = '0';
	}

}

Board::~Board()
{
	delete[] square_;
}

#endif

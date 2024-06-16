#ifndef BOARD_PATTERN_HPP
#define BOARD_PATTERN_HPP

#include <SFML/Graphics.hpp>

class BoardPattern
{
	size_t size_ = 8;
	size_t squareSize_;

	sf::RectangleShape squares[8][8];

public:
	BoardPattern(size_t squareSize);	

	size_t getSize();
	size_t getSquareSize();

	sf::RectangleShape getSquare(int x, int y);
};

// Initialize chess board pattern
BoardPattern::BoardPattern(size_t squareSize): squareSize_(squareSize)
{
	for (int row = 0; row < size_; row++)
	{
		for (int col = 0; col < size_; col++)
		{
			squares[row][col].setSize(sf::Vector2f(squareSize_, squareSize_));
			squares[row][col].setPosition(row * squareSize_, col * squareSize_);

			if ((row + col) % 2 == 0)
			{	
				// Light shade square
				squares[row][col].setFillColor(sf::Color(255, 254, 242));
			}

			else
			{
				// Dark shade square
				squares[row][col].setFillColor(sf::Color(83, 132, 172));
			}
		}
	}
}

size_t BoardPattern::getSize()
{
	return size_;
}

size_t BoardPattern::getSquareSize()
{
	return squareSize_;
}

sf::RectangleShape BoardPattern::getSquare(int x, int y)
{
	return squares[x][y];
}
#endif
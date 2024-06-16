#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>
#include <string>
#include "BoardPattern.hpp"

int main()
{
    auto window = sf::RenderWindow{ { 1200u, 1200u }, "Chess 1.0", sf::Style::Default};

    // Enable vsync 
    window.setVerticalSyncEnabled(true);

    // Initialize chess board pattern
    BoardPattern board(window.getSize().x / 8);

    // Initialize text and font for displaying board coordinates
    sf::Font coordinatesFont;

    coordinatesFont.loadFromFile("D:\\PWR - materia³y\\IV semestr\\Algorytmy\\Chess\\assets\\ArialMdm.ttf");
    coordinatesFont.setSmooth(true);

    sf::Text columnID("a", coordinatesFont, 40);
    sf::Text rowID("1", coordinatesFont, 40);

    const std::string letters[8] = { "a", "b", "c", "d", "e", "f", "g", "h" };
    const std::string numbers[8] = { "8", "7", "6", "5", "4", "3", "2", "1" };

    // Initialize chess pieces
    sf::Texture rookTexture;
    rookTexture.loadFromFile("D:\\PWR - materia³y\\IV semestr\\Algorytmy\\Chess\\assets\\white-rook.png");

    sf::Sprite rookPiece;
    rookPiece.setTexture(rookTexture);
    rookPiece.setPosition(11, 1061);

    // Main game loop
    while (window.isOpen())
    {
        // Check for events and take action if needed
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                std::cout << "Closing window\n";
                window.close();
            }


            if (event.type == sf::Event::Resized)
            {
                std::cout << "new width: " << event.size.width << '\n';
                std::cout << "new height: " << event.size.height << '\n';
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    std::cout << "the right button was pressed" << '\n';
                    std::cout << "mouse x: " << event.mouseButton.x << '\n';
                    std::cout << "mouse y: " << event.mouseButton.y << '\n';
                }

                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "the left button was pressed" << '\n';
                    std::cout << "mouse x: " << event.mouseButton.x << '\n';
                    std::cout << "mouse y: " << event.mouseButton.y << '\n';
                }
            }

            if (event.type == sf::Event::MouseMoved)
            {
                std::cout << "new mouse x: " << event.mouseMove.x << '\n';
                std::cout << "new mouse y: " << event.mouseMove.y << '\n';
            }
        }

        
        window.clear(sf::Color(48, 48, 48));

        // Draw chess board
        for (int i = 0; i < board.getSize(); i++)
        {
            for (int j = 0; j < board.getSize(); j++)
            {
                window.draw(board.getSquare(i, j));
            }
        }

        // Draw cooridnates
        for (int i = 0; i < board.getSize(); i++)
        {
            // Choose color shade based of square
            if (i % 2 == 0)
            {
                rowID.setFillColor(sf::Color(255, 254, 242));
                columnID.setFillColor(sf::Color(83, 132, 172));
            }

            else
            {
                rowID.setFillColor(sf::Color(83, 132, 172));
                columnID.setFillColor(sf::Color(255, 254, 242));
            }

            // Draw letter
            rowID.setPosition(i * board.getSquareSize() + 120, 1145);
            rowID.setString(letters[i]);
            window.draw(rowID);

            // Draw number
            columnID.setPosition(10, i * board.getSquareSize() + 10);
            columnID.setString(numbers[i]);
            window.draw(columnID);
        }

        window.draw(rookPiece);
        window.display();
    }
}

//    This file is part of LightBot.
//
//    LightBot is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    Foobar is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
    
#include "Appli.h"

Appli::Appli()
{
    m_buttonHome.push_back({{(float)SCREEN_WIDTH/2, SCREEN_HEIGHT/(float)1.8}, {90, 70}, LEVEL_SELECTION}); // Totaly not bobfix
    m_buttonHome.push_back({{SCREEN_WIDTH/(float)1.11, SCREEN_HEIGHT/(float)1.05}, {150, 50}, CREDITS});
    m_buttonLevelSelection.push_back({{(float)SCREEN_WIDTH/25, (float)SCREEN_HEIGHT/20}, {50, 50}, HOME});
    m_buttonCredits.push_back({{(float)SCREEN_WIDTH/25, (float)SCREEN_HEIGHT/20}, {50, 50}, HOME});
    m_gameState = HOME;
}

/**
 * Appli::run()
 * ouverture de la fenêtre et boucle d'interaction
 */
void Appli::loop()
{
    m_window.create(sf::VideoMode {SCREEN_WIDTH, SCREEN_HEIGHT, 32},
                    "Light Bot",
                    sf::Style::Close
                    );
    m_window.setFramerateLimit(20);

    m_running = true;
    while (m_running) {
        processEvents();
        drawScreen();
    }
}

std::vector<Button> Appli::choseButton()
{
    std::vector<Button> button;

    if (m_gameState == HOME)
    {
        button = m_buttonHome;
    }
    else if (m_gameState == LEVEL_SELECTION)
    {
        button = m_buttonLevelSelection;
    }
    else if (m_gameState == CREDITS)
    {
        button = m_buttonCredits;
    }

    return button;
}

sf::Vector2i Appli::getMousePos()
{
    return m_mousePos = sf::Mouse::getPosition(m_window);
}

int Appli::getButton()
{
    int buttonRect = 99;

    for(Button & bouton : choseButton())
    {
        if(bouton.overRect(getMousePos(), bouton.button()))
        {
            buttonRect = bouton.getId();
        }
    }
    return buttonRect;
}

void Appli::processEvents()
{
    sf::Event event;
    while(m_window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed :
            m_running = false;
            break;
        case sf::Event::MouseButtonPressed:
            mouseButtonReleased();
            break;
        default:
            break;
        }
    }
}

void Appli::drawScreen()
{
    m_window.clear(sf::Color::White);

    for(Button & bouton : choseButton())
    {
        if (bouton.overRect(getMousePos(), bouton.button()))
        {
            bouton.setColor(sf::Color::Blue);
        }
        else
            bouton.setColor(sf::Color::Red);
        bouton.draw_on(m_window);
    }
    m_window.display();
}

void Appli::mouseButtonReleased()
{
    int buttonClicked = getButton();
    //    sf::Event event;
    //    while(m_window.pollEvent(event)) {
    //        if (event.type == sf::Event::MouseButtonReleased)
    //         {
    switch (buttonClicked) {
    case HOME:
        std::cout << "home" << std::endl;
        m_gameState = HOME;
        break;
    case CREDITS:
        std::cout << "credits" << std::endl;
        m_gameState = CREDITS;
        break;
    case LEVEL_SELECTION:
        std::cout << "level_selection" << std::endl;
        m_gameState = LEVEL_SELECTION;
        break;


    }

}




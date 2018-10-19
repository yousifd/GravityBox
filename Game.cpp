#include "Game.hpp"

Game::Game() : 
    m_window(new sf::RenderWindow(sf::VideoMode(1280, 720), "Gravity Box")),
    m_player(new Player())
{
    m_window->setKeyRepeatEnabled(false);
}

Game::~Game() {
}

void Game::start() {
    const float velocity = 0.15f;
    while (m_window->isOpen())
    {
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    m_window->close();
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Escape:
                            m_window->close();
                            break;
                        case sf::Keyboard::W:
                            m_player->SetYVelocity(-velocity);
                            break;
                        case sf::Keyboard::S:
                            m_player->SetYVelocity(velocity);
                            break;
                        case sf::Keyboard::A:
                            m_player->SetXVelocity(-velocity);
                            break;
                        case sf::Keyboard::D:
                            m_player->SetXVelocity(velocity);
                            break;
                        default:
                            break;
                    }
                    break;
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Escape:
                            m_window->close();
                            break;
                        case sf::Keyboard::W:
                            m_player->SetYVelocity(velocity);
                            break;
                        case sf::Keyboard::S:
                            m_player->SetYVelocity(-velocity);
                            break;
                        case sf::Keyboard::A:
                            m_player->SetXVelocity(velocity);
                            break;
                        case sf::Keyboard::D:
                            m_player->SetXVelocity(-velocity);
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }

        m_window->clear();

        // Updates
        m_player->Update(1.f, m_window);

        m_window->display();
    }
}
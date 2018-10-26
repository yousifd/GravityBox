#include <Box2D/Box2D.h>
#include "Game.hpp"
#include <iostream>

Game::Game() : 
    m_window(new sf::RenderWindow(sf::VideoMode(1280, 720), "Gravity Box")),
    // TODO(yousifd): Alginment issues might be because I have things flipped
    m_gravity(new b2Vec2(0.0f, -1.0f)),
    m_world(new b2World(*m_gravity)),
    m_player(new Player(m_world))
{
    m_window->setKeyRepeatEnabled(false);
}

Game::~Game() {
}

void Game::UpdateGravity(bool left) {
    b2Vec2 gravity = m_world->GetGravity();
    // std::cout << "Before Gravity: " << gravity.x << " " << gravity.y << std::endl;
    if (left) {
        if (gravity.x < 0) { // Going Left
            m_world->SetGravity(b2Vec2(0.f, 1.f));
        } else if (gravity.x > 0) { // Going Right
            m_world->SetGravity(b2Vec2(0.f, -1.f));
        }

        if (gravity.y > 0) { // Going Up
            m_world->SetGravity(b2Vec2(1.f, 0.f));
        } else if (gravity.y < 0) { // Going Down
            m_world->SetGravity(b2Vec2(-1.f, 0.f));
        }
    } else {
        if (gravity.x < 0) { // Going Left
            m_world->SetGravity(b2Vec2(0.f, -1.f));
        } else if (gravity.x > 0) { // Going Right
            m_world->SetGravity(b2Vec2(0.f, 1.f));
        }

        if (gravity.y > 0) { // Going Up
            m_world->SetGravity(b2Vec2(-1.f, 0.f));
        } else if (gravity.y < 0) { // Going Down
            m_world->SetGravity(b2Vec2(1.f, 0.f));
        }
    }
    // std::cout << "After Gravity: " << m_world->GetGravity().x << " " << m_world->GetGravity().y << std::endl;
}

sf::RectangleShape Game::Ground(float width, float height, float x, float y) {
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(x, -y);
    b2Body *groundBody = m_world->CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(width, height);
    groundBody->CreateFixture(&groundBox, 0.f);
    sf::Vector2f size(width, height);
    sf::RectangleShape ground(size);
    ground.setFillColor(sf::Color::Red);
    ground.setPosition(sf::Vector2f(x, y));

    return ground;
}

void Game::Start() {
    sf::Clock clock;
    sf::Time prev_time;
    const float velocity = 0.15f;

    // Ground
    auto ground = Ground(1280.f, 10.f, 0.f, 710.f);
    auto roof = Ground(1280.f, 10.f, 0.f, 0.f);
    auto left = Ground(10.f, 720.f, 0.f, 0.f);
    auto right = Ground(10.f, 720.f, 1270.f, 0.f);

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
                            m_player->SetYVelocity(-.20);
                            break;
                        case sf::Keyboard::S:
                            m_player->SetYVelocity(.20);
                            break;
                        case sf::Keyboard::A:
                            m_player->SetXVelocity(-velocity);
                            UpdateGravity(true);
                            break;
                        case sf::Keyboard::D:
                            m_player->SetXVelocity(velocity);
                            UpdateGravity(false);
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
        float elapsed_time = (clock.getElapsedTime() - prev_time).asSeconds();
        m_world->Step(1.f / 60.f, 6, 2);
        m_player->Update(elapsed_time, m_window);

        m_window->draw(ground);
        m_window->draw(roof);
        m_window->draw(left);
        m_window->draw(right);
        m_window->display();

        prev_time = clock.getElapsedTime();
    }
}
#include <Box2D/Box2D.h>
#include "Game.hpp"

Game::Game() : 
    m_window(new sf::RenderWindow(sf::VideoMode(1280, 720), "Gravity Box")),
    // TODO(yousifd): Alginment issues might be because I have things flipped
    m_gravity(new b2Vec2(0.0f, m_gravity_vel)),
    m_world(new b2World(*m_gravity)),
    m_player(new Player(m_world))
{
    m_window->setKeyRepeatEnabled(false);
}

Game::~Game() {
}

void Game::UpdateGravity(bool left) {
    b2Vec2 gravity = m_world->GetGravity();
    if (left) {
        if (gravity.x < 0) { // Going Left
            m_world->SetGravity(b2Vec2(0.f, -m_gravity_vel));
        } else if (gravity.x > 0) { // Going Right
            m_world->SetGravity(b2Vec2(0.f, m_gravity_vel));
        }

        if (gravity.y > 0) { // Going Up
            m_world->SetGravity(b2Vec2(-m_gravity_vel, 0.f));
        } else if (gravity.y < 0) { // Going Down
            m_world->SetGravity(b2Vec2(m_gravity_vel, 0.f));
        }
    } else {
        if (gravity.x < 0) { // Going Left
            m_world->SetGravity(b2Vec2(0.f, m_gravity_vel));
        } else if (gravity.x > 0) { // Going Right
            m_world->SetGravity(b2Vec2(0.f, -m_gravity_vel));
        }

        if (gravity.y > 0) { // Going Up
            m_world->SetGravity(b2Vec2(m_gravity_vel, 0.f));
        } else if (gravity.y < 0) { // Going Down
            m_world->SetGravity(b2Vec2(-m_gravity_vel, 0.f));
        }
    }
}

sf::RectangleShape Game::Ground(float width, float height, float x, float y) {
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(x, -y);
    b2Body *groundBody = m_world->CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(width / 2.f, height / 2.f);
    groundBody->CreateFixture(&groundBox, 0.f);
    sf::Vector2f size(width, height);
    sf::RectangleShape ground(size);
    ground.setFillColor(sf::Color::Red);
    ground.setOrigin(width / 2.f, height / 2.f);
    ground.setPosition(sf::Vector2f(x, y));

    return ground;
}

void Game::Start() {
    sf::Clock clock;
    sf::Time prev_time;

    // Ground
    auto ground = Ground(1280.f, 10.f, 1280.f/2.f, 720.f);
    auto roof = Ground(1280.f, 10.f, 1280.f/2.f, 0.f);
    auto left = Ground(10.f, 720.f, 0.f, 720.f/2.f);
    auto right = Ground(10.f, 720.f, 1280.f, 720.f/2.f);

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
                        case sf::Keyboard::A:
                            UpdateGravity(true);
                            break;
                        case sf::Keyboard::D:
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
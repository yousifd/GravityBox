#include <Box2D/Box2D.h>

#include "Game.hpp"
#include "GameObject.hpp"

Game::Game() : 
    m_window(sf::VideoMode(1280, 720), "Gravity Box"),
    m_gravity(0.0f, m_gravity_vel),
    m_world(m_gravity),
    m_player(m_world),
    m_puzzle(5, 5, m_world)
{
    m_window.setKeyRepeatEnabled(false);
}

Game::~Game() {
}

void Game::UpdateGravityLeft() {
    b2Vec2 gravity = m_world.GetGravity();
    if (gravity.x < 0) { // Going Left
        m_world.SetGravity(b2Vec2(0.f, -m_gravity_vel));
    } else if (gravity.x > 0) { // Going Right
        m_world.SetGravity(b2Vec2(0.f, m_gravity_vel));
    }

    if (gravity.y > 0) { // Going Up
        m_world.SetGravity(b2Vec2(-m_gravity_vel, 0.f));
    } else if (gravity.y < 0) { // Going Down
        m_world.SetGravity(b2Vec2(m_gravity_vel, 0.f));
    }

    sf::View view = m_window.getView();
    view.rotate(90.f);
    m_window.setView(view);
}

void Game::UpdateGravityRight() {
    b2Vec2 gravity = m_world.GetGravity();
    if (gravity.x < 0) { // Going Left
        m_world.SetGravity(b2Vec2(0.f, m_gravity_vel));
    } else if (gravity.x > 0) { // Going Right
        m_world.SetGravity(b2Vec2(0.f, -m_gravity_vel));
    }

    if (gravity.y > 0) { // Going Up
        m_world.SetGravity(b2Vec2(m_gravity_vel, 0.f));
    } else if (gravity.y < 0) { // Going Down
        m_world.SetGravity(b2Vec2(-m_gravity_vel, 0.f));
    }

    sf::View view = m_window.getView();
    view.rotate(-90.f);
    m_window.setView(view);
}

void Game::Start() {
    // TODO(yousifd): Performance Optimizations
    // TODO(yousifd): Rotate Camera
        // Instead of Rotating Instantly, set a value and interpolate to it based on elapsed time
    sf::Clock clock;
    sf::Time prev_time;

    // Ground
    GameObject ground(sf::Color::Red, 1280.f, 10.f, 1280.f / 2.f, 720.f, false, m_world);
    GameObject roof(sf::Color::Red, 1280.f, 10.f, 1280.f / 2.f, 0.f, false, m_world);
    GameObject left(sf::Color::Red, 10.f, 720.f, 0.f, 720.f / 2.f, false, m_world);
    GameObject right(sf::Color::Red, 10.f, 720.f, 1280.f, 720.f / 2.f, false, m_world);

    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    m_window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Escape:
                            m_window.close();
                            break;
                        case sf::Keyboard::A:
                            UpdateGravityLeft();
                            break;
                        case sf::Keyboard::D:
                            UpdateGravityRight();
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }

        m_window.clear();

        // Updates
        // TODO(yousifd): Figure out how to use elapsed_time to reduce dependance on cpu
        // Might not need to since physics happens on its own time.
        float elapsed_time = (clock.getElapsedTime() - prev_time).asSeconds();
        m_world.Step(1.f / 60.f, 6, 2);
        m_puzzle.Update(elapsed_time, m_window);
        m_player.Update(elapsed_time, m_window);

        ground.Update(elapsed_time, m_window);
        roof.Update(elapsed_time, m_window);
        left.Update(elapsed_time, m_window);
        right.Update(elapsed_time, m_window);

        sf::View view = m_window.getView();
        view.setCenter(m_player.GetPosition());
        m_window.setView(view);

        m_window.display();

        prev_time = clock.getElapsedTime();
    }
}
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({1280, 720}),
        "Niro");

    window.setFramerateLimit(60);

    sf::VertexArray tlo(sf::PrimitiveType::TriangleStrip, 4);

    tlo[0].position = {0.f, 0.f};
    tlo[1].position = {1280.f, 0.f};
    tlo[2].position = {0.f, 720.f};
    tlo[3].position = {1280.f, 720.f};

    auto Gradient = [&](sf::Color gora, sf::Color dol) {
        tlo[0].color = gora;
        tlo[1].color = gora;
        tlo[2].color = dol;
        tlo[3].color = dol;
    };

   
    bool alternateColor = false;


    Gradient(sf::Color(255, 213, 158), sf::Color(255, 107, 157));

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
      
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

           
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
               
                if (keyPressed->code == sf::Keyboard::Key::Escape)
                {
                    window.close();
                }

               
                if (keyPressed->code == sf::Keyboard::Key::F11)
                {
                    alternateColor = !alternateColor;

                    if (alternateColor)
                    {
                  
                        Gradient(sf::Color(70, 130, 255), sf::Color(160, 80, 255));
                    }
                    else
                    {
                        
                        Gradient(sf::Color(255, 213, 158), sf::Color(255, 107, 157));
                    }
                }
            }
        }

        window.clear(sf::Color(25, 25, 35));
        window.draw(tlo);
        window.display();
    }

    return 0;
}
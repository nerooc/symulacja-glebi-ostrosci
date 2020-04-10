#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>

float clamp(float x, float minVal, float maxVal) {
    return std::min(std::max(x, minVal), maxVal);
}

float smoothstep(float edge0, float edge1, float x) {
    float t = clamp((x - edge0) / (edge1 - edge0), 0.0, 1.0);
    return t * t * (3.0 - 2.0 * t);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(340, 600), "SFML works!");

    sf::Image depthTexture;
    depthTexture.loadFromFile("Flowers-depthmap.jpg");


    sf::Image photoTexture;
    photoTexture.loadFromFile("Flowers-alternative.jpg");

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(photoTexture.getSize().x, photoTexture.getSize().y));
    rect.setPosition(0, 0);
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    size_t sizeX = photoTexture.getSize().x;
    size_t sizeY = photoTexture.getSize().y;
    
    float*** summedAreaTable = new float** [sizeX];

    for (int i = 0; i < sizeX; i++)
    {
        summedAreaTable[i] = new float* [sizeY];

        for (int j = 0; j < sizeY; j++)
            summedAreaTable[i][j] = new float[3];
    }

    
    for (unsigned int y = 0; y < sizeY; ++y)
    {
        for (unsigned int x = 0; x < sizeX; ++x)
        {
            float valueX = photoTexture.getPixel(x, y).r;
            float valueY = photoTexture.getPixel(x, y).g;
            float valueZ = photoTexture.getPixel(x, y).b;
            if (y > 0) {
                valueX += summedAreaTable[x][y - 1][0];
                valueY += summedAreaTable[x][y - 1][1];
                valueZ += summedAreaTable[x][y - 1][2];
            }
            if (x > 0) {
                valueX += summedAreaTable[x - 1][y][0];
                valueY += summedAreaTable[x - 1][y][1];
                valueZ += summedAreaTable[x - 1][y][2];
            }
            if (x > 0 && y > 0) {
                valueX -= summedAreaTable[x - 1][y - 1][0];
                valueY -= summedAreaTable[x - 1][y - 1][1];
                valueZ -= summedAreaTable[x - 1][y - 1][2];
            }
            summedAreaTable[x][y][0] = valueX;
            summedAreaTable[x][y][1] = valueY;
            summedAreaTable[x][y][2] = valueZ;
        }
    }
    
    //back to photo
    sf::Image DOFphoto;
    DOFphoto.create(photoTexture.getSize().x, photoTexture.getSize().y);

    for (int i = 0; i < photoTexture.getSize().x; i++)
    {
        for (int j = 0; j < photoTexture.getSize().y; j++) {


            // Zmienna m to promieñ filtra.
            float m = 0.5;
            float max = 14.; //jak bardzo obraz sie rozmazuje przy zmianie odleglosc 
                            //to znaczy ze dla maksymalnej odleglosci 255 mieszamy kwadrat o boku  2*max    
                            //czyli liczymy sredni kolor z tego kwadratu i ustalamy kolor piksela(i, j) na ten sredni kolor
            int focus = 83; //odleglosc w ktorej obraz jest ostry - 83 to te kwiatki z przodu
                            // 0 rozmaze wszystko bo taka depth mapa
                            //255 zostawi tylko background ostry

            m =abs(( depthTexture.getPixel(i, j).r - focus)/255. * max);
            m = round(m);
         

            sf::Vector2i P0;
            sf::Vector2i P1;
            sf::Vector2i P2;
            sf::Vector2i P3;

            if (m == 0) {
                P0 = sf::Vector2i(round(clamp(i - 1, 0, sizeX - 1)),    round(clamp(j - 1, 0, sizeY - 1)));
                P1 = sf::Vector2i(round(clamp(i - 1, 0, sizeX - 1)),    j);
                P2 = sf::Vector2i(i,                                    round(clamp(j - 1, 0, sizeY - 1)));
                P3 = sf::Vector2i(i,                                    j);


            }
            else
            {
                P0 = sf::Vector2i(round(clamp(i - m, 0, sizeX-1)), round(clamp(j - m, 0, sizeY-1)));
                P1 = sf::Vector2i(round(clamp(i - m, 0, sizeX-1)), round(clamp(j + m, 0, sizeY-1)));
                P2 = sf::Vector2i(round(clamp(i + m, 0, sizeX-1)), round(clamp(j - m, 0, sizeY-1)));
                P3 = sf::Vector2i(round(clamp(i + m, 0, sizeX-1)), round(clamp(j + m, 0, sizeY-1)));
            }
            
            // Pobranie wartoœci z czterech naro¿ników.
            sf::Vector3i a = sf::Vector3i(summedAreaTable[P0.x][P0.y][0], summedAreaTable[P0.x][P0.y][1], summedAreaTable[P0.x][P0.y][2]);
            sf::Vector3i b = sf::Vector3i(summedAreaTable[P1.x][P1.y][0], summedAreaTable[P1.x][P1.y][1], summedAreaTable[P1.x][P1.y][2]);
            sf::Vector3i c = sf::Vector3i(summedAreaTable[P2.x][P2.y][0], summedAreaTable[P2.x][P2.y][1], summedAreaTable[P2.x][P2.y][2]);
            sf::Vector3i d = sf::Vector3i(summedAreaTable[P3.x][P3.y][0], summedAreaTable[P3.x][P3.y][1], summedAreaTable[P3.x][P3.y][2]);

            // Obliczenie sumy wszystkich pikseli wewn¹trz prostok¹ta.
            sf::Vector3i f = sf::Vector3i(a - b - c + d);

            int sideX, sideY;
            sideX = P3.x - P0.x;    sideX = sideX == 0 ? 1 : sideX;
            sideY = P3.y - P0.y;    sideY = sideY == 0 ? 1 : sideY;
            int square = sideX * sideY;
            // Dzielenie przez obszar.
            f = sf::Vector3i(f.x / square, f.y / square, f.z / square);

            // Przekazanie finalnego koloru.
            sf::Color color(f.x > 255? 255 : f.x, f.y > 255 ? 255 : f.y, f.z > 255 ? 255 : f.z);

            DOFphoto.setPixel(i, j, color);
        }
    }


    // deallocate memory
    for (int i = 0; i < sizeX; i++)
    {
        for (int j = 0; j < sizeY; j++)
            delete[] summedAreaTable[i][j];

        delete[] summedAreaTable[i];
    }
    delete[] summedAreaTable;
   
    sf::Texture normal;
    normal.loadFromImage(photoTexture);
    sf::Texture dof;
    dof.loadFromImage(DOFphoto);

    sf::Sprite spriteNorm, spriteDOF;
    spriteNorm.setTexture(normal);  spriteNorm.setPosition(0, 0);   spriteNorm.scale(0.5, 0.5);
    spriteDOF.setTexture(dof);      spriteDOF.setPosition(0, 0);    spriteDOF.scale(0.5, 0.5);
    std::cout << "Wcisnij i przytrzymaj B!!!!!!!!!!!!!!!!!!" << std::endl;
    std::cout << "w lini 85 i 88 mozesz zmienic parametry" << std::endl;
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))    window.draw(spriteDOF);
        else     window.draw(spriteNorm);
       
        window.display();
    }

    return 0;
}
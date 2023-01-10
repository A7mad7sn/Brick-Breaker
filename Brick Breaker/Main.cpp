#include <SFML/Graphics.hpp>
#include<iostream>
#include"Menu.h"
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;

int page_number;
int counter = 0;
int checkcount = 0;

int main()
{

    while (true)
    {
        RectangleShape paddle;
        paddle.setSize(Vector2f(120, 20));
        paddle.setOrigin(50, 10);
        paddle.setPosition(125, 375);
        paddle.setFillColor(Color::Yellow);

        CircleShape ball;
        ball.setRadius(20.0);
        ball.setOrigin(10, 10);
        ball.setPosition(125, 335);
        ball.setFillColor(Color::Red);

        sf::RenderWindow window_menu(sf::VideoMode(530, 700), " Menu ");
        sf::RenderWindow gameover(sf::VideoMode(530, 700), " Game Over ");
        gameover.setVisible(false);
        sf::RenderWindow Winner(sf::VideoMode(530, 700), " You Win ");
        Winner.setVisible(false);

        Texture u;
        if (!u.loadFromFile("C:/Users/HP Zbook/source/repos/Brick Breaker/Photos/menu_background.jpeg"))
            return EXIT_FAILURE;
        Sprite smenu(u);

        sf::Music music;
        if (!music.openFromFile("C:/Users/HP Zbook/source/repos/Brick Breaker/Music/Two.ogg"))
            return EXIT_FAILURE;

        music.play();

        menu m(530, 700);

        while (window_menu.isOpen())
        {
            sf::Event event;
            while (window_menu.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window_menu.close();
                    return 0;
                }
                if (event.type == sf::Event::KeyReleased)
                {
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        m.moveup();
                        break;
                    }
                    if (event.key.code == sf::Keyboard::Down)
                    {
                        m.movedown();
                        break;
                    }
                    //choose page
                    if (event.key.code == sf::Keyboard::Return)//enter
                    {

                        if (m.mainmenupressed() == 0)
                        {
                            window_menu.close();
                            page_number = 0;

                        }
                        if (m.mainmenupressed() == 1)
                        {
                            window_menu.close();
                            page_number = 1;
                        }
                        if (m.mainmenupressed() == 2)
                        {
                            window_menu.close();
                            page_number = 2;
                        }
                    }
                }

            }


            window_menu.clear();
            window_menu.draw(smenu);
            window_menu.draw(ball);
            window_menu.draw(paddle);
            m.draw(window_menu);
            window_menu.display();
        }

        if (page_number == 0)
        {

            //Music : 
            music.stop();
            sf::Music gamemusic;
            if (!gamemusic.openFromFile("C:/Users/HP Zbook/source/repos/Brick Breaker/Music/Ingame.ogg"))
                return EXIT_FAILURE;
            gamemusic.play();

            sf::Music passmusic;
            if (!passmusic.openFromFile("C:/Users/HP Zbook/source/repos/Brick Breaker/Music/MissionPassed.ogg"))
                return EXIT_FAILURE;


            //Gameplay Window:

            sf::RenderWindow window(sf::VideoMode(530, 700), "Brick Breaker");
            window.setFramerateLimit(60);
            


            //Used Font :
            Font gfont;

            if (!gfont.loadFromFile("C:/Users/HP Zbook/source/repos/Brick Breaker/Font/arial.ttf"))
                return EXIT_FAILURE;

            //Score counter :
            int counter = 0;
            String Score = to_string(counter);

            //InGameText:
            Text gtext;
            gtext.setFont(gfont);
            gtext.setFillColor(Color::White);
            gtext.setCharacterSize(30);
            gtext.setPosition(90, 5);
            gtext.setStyle(Text::Bold);
            gtext.setOutlineColor(Color::Black);
            gtext.setOutlineThickness(3.0);

            //Paddle
            RectangleShape paddle;
            paddle.setSize(Vector2f(150, 20));
            paddle.setOrigin(75, 10);
            paddle.setPosition(265, 655);
            paddle.setFillColor(Color::Yellow);

            //Ball
            CircleShape ball;
            ball.setRadius(10);
            ball.setOrigin(5, 5);
            ball.setPosition(265, 630);
            ball.setFillColor(Color::Red);
            float xstep = 5;
            float ystep = 5;

            //Textures :

            Texture t;
            if (!t.loadFromFile("C:/Users/HP Zbook/source/repos/Brick Breaker/Photos/ingame_background.jpg"))
                return EXIT_FAILURE;
            Sprite sBackground(t);

            Texture lside;
            if (!lside.loadFromFile("C:/Users/HP Zbook/source/repos/Brick Breaker/Photos/side.png"))
                return EXIT_FAILURE;
            Sprite lsides;
            lsides.setTexture(lside);
            lsides.setOrigin(2.5, 350);
            lsides.setPosition(5, 350);

            Texture rside;
            if (!rside.loadFromFile("C:/Users/HP Zbook/source/repos/Brick Breaker/Photos/side.png"))
                return EXIT_FAILURE;
            Sprite rsides;
            rsides.setTexture(rside);
            rsides.setOrigin(2.5, 350);
            rsides.setPosition(525, 350);

            Texture uside;
            if (!uside.loadFromFile("C:/Users/HP Zbook/source/repos/Brick Breaker/Photos/up side.png"))
                return EXIT_FAILURE;
            Sprite usides;
            usides.setTexture(uside);
            usides.setOrigin(265, 2.5);
            usides.setPosition(265, 45);

            Texture MissionPassed;
            if (!MissionPassed.loadFromFile("C:/Users/HP Zbook/source/repos/Brick Breaker/Photos/Respect.png"));
            Sprite sMissionPassed;
            sMissionPassed.setTexture(MissionPassed);
            sMissionPassed.setPosition(150, 250);
            sMissionPassed.setOrigin(100, 100);

            Texture Glasses;
            if (!Glasses.loadFromFile("C:/Users/HP Zbook/source/repos/Brick Breaker/Photos/GlassesOnly.png"))
                return EXIT_FAILURE;
            Sprite sGlasses;
            sGlasses.setTexture(Glasses);
            sGlasses.setOrigin(100, 100);
            sGlasses.setPosition(390, 280);

            //Bricks :
            RectangleShape Bricks[35];

            //whiteBricks
            for (int i = 0; i < 7; i++) {
                Bricks[i].setSize(Vector2f(68, 40));
                Bricks[i].setOrigin(20, 10);
                Bricks[i].setFillColor(Color::White);

                if (i == 0)
                {
                    Bricks[i].setPosition(33, 70);
                }
                else if (i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6)
                {
                    Bricks[i].setPosition(Bricks[i - 1].getPosition().x + 73, 70);
                }
            }
            //pinkBrricks
            for (int i = 7; i < 14; i++) {
                Bricks[i].setSize(Vector2f(68, 40));
                Bricks[i].setOrigin(20, 10);
                Bricks[i].setFillColor(Color::Magenta);
                if (i == 7)
                {
                    Bricks[i].setPosition(33, 115);
                }
                else if (i == 8 || i == 9 || i == 10 || i == 11 || i == 12 || i == 13)
                {
                    Bricks[i].setPosition(Bricks[i - 1].getPosition().x + 73, 115);
                }
            }
            //greenBricks
            for (int i = 14; i < 21; i++) {
                Bricks[i].setSize(Vector2f(68, 40));
                Bricks[i].setOrigin(20, 10);
                Bricks[i].setFillColor(Color::Green);
                if (i == 14)
                {
                    Bricks[i].setPosition(33, 160);
                }
                else if (i == 15 || i == 16 || i == 17 || i == 18 || i == 19 || i == 20)
                {
                    Bricks[i].setPosition(Bricks[i - 1].getPosition().x + 73, 160);
                }
            }
            //pinkBricks
            for (int i = 21; i < 28; i++) {
                Bricks[i].setSize(Vector2f(68, 40));
                Bricks[i].setOrigin(20, 10);
                Bricks[i].setFillColor(Color::Magenta);
                if (i == 21)
                {
                    Bricks[i].setPosition(33, 205);
                }
                else if (i == 22 || i == 23 || i == 24 || i == 25 || i == 26 || i == 27)
                {
                    Bricks[i].setPosition(Bricks[i - 1].getPosition().x + 73, 205);
                }
            }
            //whiteBricks
            for (int i = 28; i < 35; i++) {
                Bricks[i].setSize(Vector2f(68, 40));
                Bricks[i].setOrigin(20, 10);
                Bricks[i].setFillColor(Color::White);
                if (i == 28)
                {
                    Bricks[i].setPosition(33, 250);
                }
                else if (i == 29 || i == 30 || i == 31 || i == 32 || i == 33 || i == 34)
                {
                    Bricks[i].setPosition(Bricks[i - 1].getPosition().x + 73, 250);
                }
            }



            while (window.isOpen())
            {

                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();



                }
                bool startplaying = false;

                if (Keyboard::isKeyPressed(Keyboard::Space))
                {

                    startplaying = true;

                }




                if (startplaying)
                {
                    ball.move(xstep, ystep);
                }

                for (int i = 0; i < 35; i++)
                {

                    if (Bricks[i].getGlobalBounds().intersects(ball.getGlobalBounds()))
                    {
                        Bricks[i].move(5000, 5000);
                        counter++;
                        xstep = xstep;
                        ystep = -ystep;
                        Score = to_string(counter);
                        gtext.setString("Score : " + Score);
                    }
                }

                //restricting paddle movement :
                if (startplaying) {


                    if (!(paddle.getPosition().x == 445))
                    {
                        if (Keyboard::isKeyPressed(Keyboard::Right))
                        {
                            paddle.move(5, 0);
                        }
                    }
                    if (!(paddle.getPosition().x == 85)) {
                        if (Keyboard::isKeyPressed(Keyboard::Left))
                        {
                            paddle.move(-5, 0);
                        }
                    }

                }

                //restricting Ball Movement :
                if (ball.getPosition().x > 510)
                {
                    ball.move(xstep, ystep);
                    xstep = -5;
                }
                if (ball.getPosition().x < 15)
                {
                    ball.move(xstep, ystep);
                    xstep = 5;
                }

                if (ball.getPosition().y < 55)
                {
                    ystep = -ystep;
                }
                //Default State :
                if (!(ball.getPosition().y > 700 - ball.getRadius()) || !(counter == 35)) {
                    window.clear();
                    window.draw(sBackground);
                    window.draw(gtext);
                    window.draw(rsides);
                    window.draw(lsides);
                    window.draw(usides);
                    window.draw(ball);
                    window.draw(paddle);
                    //Drawing Bricks
                    for (int i = 0; i < 35; i++)
                    {
                        window.draw(Bricks[i]);
                    }
                    window.display();
                }

                // Losing State :
                if (ball.getPosition().y > 700 - ball.getRadius())
                {
                    window.setVisible(false);
                    gameover.setVisible(true);
                    gameover.draw(sBackground);
                    Text lose;
                    lose.setFont(gfont);
                    lose.setFillColor(Color::Red);
                    lose.setCharacterSize(50);
                    lose.setPosition(100, 350);
                    lose.setStyle(Text::Bold);
                    lose.setString("Game Over !!!\n Score : " + Score);
                    Text Back;
                    Back.setFont(gfont);
                    Back.setFillColor(Color::White);
                    Back.setCharacterSize(40);
                    Back.setPosition(30, 600);
                    Back.setStyle(Text::Bold);
                    Back.setString("Press (esc) to Back");
                    paddle.setSize(Vector2f(530, 120));
                    paddle.setOrigin(265, 50);
                    paddle.setPosition(265, 400);
                    gameover.draw(paddle);
                    gameover.draw(lose);
                    gameover.draw(Back);
                    gameover.display();

                    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                        gamemusic.stop();
                        gameover.close();
                        main();
                    }
                    while (gameover.pollEvent(event))
                    {
                        if (event.type == sf::Event::Closed)
                        {
                            gameover.close();
                            window.close();
                        }
                    }




                }

                // Winning State :
                if (counter == 35)
                {
                    gamemusic.stop();
                    passmusic.getStatus();
                    if (passmusic.getStatus() == 0) {
                        passmusic.play();
                        passmusic.setLoop(true);
                    }
                    Winner.setVisible(true);
                    window.setVisible(false);
                    Winner.clear();
                    Winner.draw(sBackground);
                    ball.setRadius(90);
                    ball.setOrigin(45, 45);
                    ball.setPosition(100, 200);
                    paddle.setSize(Vector2f(530, 120));
                    paddle.setOrigin(265, 50);
                    paddle.setPosition(265, 400);
                    Bricks[1].setSize(Vector2f(225, 50));
                    Bricks[1].setFillColor(Color::Yellow);
                    Bricks[1].setOrigin(100, 50);
                    Bricks[1].setPosition(390, 300);
                    Winner.draw(ball);
                    Winner.draw(paddle);
                    Winner.draw(Bricks[1]);
                    Winner.draw(sMissionPassed);
                    Winner.draw(sGlasses);
                    Text win;
                    win.setFont(gfont);
                    win.setFillColor(Color::Blue);
                    win.setCharacterSize(50);
                    win.setPosition(150, 350);
                    win.setStyle(Text::Bold);
                    win.setString("You Win !!\nScore : " + Score);
                    Text Back;
                    Back.setFont(gfont);
                    Back.setFillColor(Color::White);
                    Back.setCharacterSize(40);
                    Back.setPosition(30, 600);
                    Back.setStyle(Text::Bold);
                    Back.setString("Press (esc) to Back");
                    Winner.draw(win);
                    Winner.draw(Back);
                    Winner.display();
                    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                        passmusic.stop();
                        Winner.close();
                        main();
                    }
                    while (Winner.pollEvent(event))
                    {
                        if (event.type == sf::Event::Closed)
                        {
                            Winner.close();
                            window.close();
                        }
                    }

                }

                FloatRect bounds_ball = ball.getGlobalBounds();
                if (bounds_ball.intersects(paddle.getGlobalBounds())) {
                    ystep = -ystep;

                    if (ball.getPosition().x == paddle.getOrigin().x) {
                        ball.move(0, -ystep);
                    }
                }

            }




        }

        if (page_number == 1)
        {
            sf::RenderWindow window_credit(sf::VideoMode(530, 700), " Credits ");
            Texture k;
            if (!k.loadFromFile("C:/Users/HP Zbook/source/repos/Brick Breaker/Photos/menu_background.jpeg"))
                return EXIT_FAILURE;
            Sprite cmenu(k);

            Font cfont;
            if (!cfont.loadFromFile("C:/Users/HP Zbook/source/repos/Brick Breaker/Font/arial.ttf"))
                return EXIT_FAILURE;

            Text ctext;
            ctext.setFont(cfont);
            ctext.setFillColor(Color::Cyan);
            ctext.setCharacterSize(40);
            ctext.setPosition(125, 250);
            ctext.setStyle(Text::Bold);
            ctext.setString("Ahmed Hassan\nAbdalla Ayman\nAhmed Hossam\nAbdelrahman Hany\nAhmed Khalil\nMarwan Mamdouh");
            Text Back;
            Back.setFont(cfont);
            Back.setFillColor(Color::White);
            Back.setCharacterSize(40);
            Back.setPosition(30, 600);
            Back.setStyle(Text::Bold);
            Back.setString("Press (esc) to Back");

            while (window_credit.isOpen())
            {
                music.stop();
                sf::Event event;
                while (window_credit.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window_credit.close();
                }
                if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                    main();
                    window_credit.close();
                }
                window_credit.clear();
                window_credit.draw(cmenu);
                window_credit.draw(Back);
                window_credit.draw(ctext);
                window_credit.display();
            }
            if (page_number == 2)
            {
                //exit
                break;
            }

        }

        return 0;
    }
}

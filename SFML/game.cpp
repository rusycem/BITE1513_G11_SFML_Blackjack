#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include "betText.h"
#include "game.h"
#include "mainMenu.h"

using namespace sf;

int balance = 50;
bool betPlaced = false, betBarEnable = true, first = true, gameFinish = false;
int winRound = 0;
int playerNrOfCards = 0, dealerNrOfCards = 0;
int playerCards = 0, dealerCards = 0, numAces = 0, numAcesDealer = 0;

struct card
{
	int color, value;
};

card player[5], dealer[5];

int randomGenerator()
{
	int nr = rand() % 13 + 1;
	return nr;
}

int randomColor()
{
	int nr = rand() % 4 + 1;
	return nr;
}

void winCondition(textBox bet)
{
	if (dealerCards > playerCards && dealerCards <= 21)
	{
		winRound = 1;
		cout << "Lose\n";
		cout << "Player=" << playerCards << " Dealer=" << dealerCards << "\n";
		gameFinish = true;
	}
	else if (playerCards == 21 && dealerCards != 21)
	{
		winRound = 2;
		cout << "Blackjack\n";
		cout << "Player=" << playerCards << " Dealer=" << dealerCards << "\n";
		balance += 2 * bet.betValue;
		gameFinish = true;
	}
	else if (playerCards <= 21 && (dealerCards > 21 || playerCards > dealerCards))
	{
		winRound = 3;
		cout << "Win\n";
		cout << "Player=" << playerCards << " Dealer=" << dealerCards << "\n";
		balance += 2 * bet.betValue;
		gameFinish = true;
	}
	else if (playerCards > 21)
	{
		winRound = 4;
		cout << "Bust\n";
		cout << "Player=" << playerCards << " Dealer=" << dealerCards << "\n";
		gameFinish = true;
	}
	else
	{
		winRound = 5;
		cout << "Tie\n";
		cout << "Player=" << playerCards << " Dealer=" << dealerCards << "\n";
		balance += bet.betValue;
		gameFinish = true;
	}


}

void playerTurn()
{
	playerNrOfCards++;
	int card = randomGenerator();

	if (card >= 11 && card <= 13) {
		playerCards += 10;  // Assign a value of 10 to the royal cards
	}
	else if (card == 1) {
		numAces++;
		playerCards += 11;
	}
	else {
		playerCards += card;
	}

	// Adjust the value of Aces if necessary
	while (playerCards > 21 && numAces > 0) {
		playerCards -= 10;
		numAces--;
	}
	player[playerNrOfCards].value = card;
	card = randomColor();
	player[playerNrOfCards].color = card;
}



void dealerTurn()
{
	dealerNrOfCards++;
	int card = randomGenerator();

	if (card >= 11 && card <= 13) {
		dealerCards += 10;  // Assign a value of 10 to the royal cards
	}
	else if (card == 1) {
		numAcesDealer++;
		dealerCards += 11;
	}
	else {
		dealerCards += card;	
	}

	// Adjust the value of Aces if necessary
	while (dealerCards > 21 && numAces > 0) {
		dealerCards -= 10;
		numAcesDealer++;
	}
	dealer[dealerNrOfCards].value = card;
	card = randomColor();
	dealer[dealerNrOfCards].color = card;
}





int runGame()
{
	RenderWindow window(VideoMode(1300, 900), "Blackjack made by Group 11 (Irfan, Amir, Hmam, Aisyah)", Style::Titlebar | Style::Close);
	textBox bet;
	Clock clock;
	Time duration = sf::seconds(1.0f);
	Text text; //for result announcement text
	Font font;
	font.loadFromFile("fonts/Akhenaton-LYLD.ttf");
	text.setFont(font);
	text.setOutlineColor(Color::Black);
	text.setOutlineThickness(3);
	text.setPosition(550, 230);
	text.setCharacterSize(200);
	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t18, t19, t20, t21, t22, t23, t24, t25, t17;
	Texture t26, t27, t28, t29, t30, t31, t32, t33, t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47;
	Texture t48, t49, t50, t51, t52, t53, t54, t55, t56, t57, t58, t59, t60, t61, t62, t63, t64, t65, t66, t67, t68;

	t1.loadFromFile("cards/2_clover.jpg");
	t2.loadFromFile("cards/2_diamond.jpg");
	t3.loadFromFile("cards/2_heart.jpg");
	t4.loadFromFile("cards/2_spade.jpg");

	t5.loadFromFile("cards/3_clover.jpg");
	t6.loadFromFile("cards/3_diamond.jpg");
	t7.loadFromFile("cards/3_heart.jpg");
	t8.loadFromFile("cards/3_spade.jpg");

	t9.loadFromFile("cards/4_clover.jpg");
	t10.loadFromFile("cards/4_diamond.jpg");
	t11.loadFromFile("cards/4_heart.jpg");
	t12.loadFromFile("cards/4_spade.jpg");

	t13.loadFromFile("cards/5_clover.jpg");
	t14.loadFromFile("cards/5_diamond.jpg");
	t15.loadFromFile("cards/5_heart.jpg");
	t16.loadFromFile("cards/5_spade.jpg");

	t17.loadFromFile("cards/6_clover.jpg");
	t18.loadFromFile("cards/6_diamond.jpg");
	t19.loadFromFile("cards/6_heart.jpg");
	t20.loadFromFile("cards/6_spade.jpg");

	t21.loadFromFile("cards/7_clover.jpg");
	t22.loadFromFile("cards/7_diamond.jpg");
	t23.loadFromFile("cards/7_heart.jpg");
	t24.loadFromFile("cards/7_spade.jpg");

	t25.loadFromFile("cards/8_clover.jpg");
	t26.loadFromFile("cards/8_diamond.jpg");
	t27.loadFromFile("cards/8_heart.jpg");
	t28.loadFromFile("cards/8_spade.jpg");

	t29.loadFromFile("cards/9_clover.jpg");
	t30.loadFromFile("cards/9_diamond.jpg");
	t31.loadFromFile("cards/9_heart.jpg");
	t32.loadFromFile("cards/9_spade.jpg");

	t33.loadFromFile("cards/10_clover.jpg");
	t34.loadFromFile("cards/10_diamond.jpg");
	t35.loadFromFile("cards/10_heart.jpg");
	t36.loadFromFile("cards/10_spade.jpg");

	t37.loadFromFile("cards/ace_clover.jpg");
	t38.loadFromFile("cards/ace_diamond.jpg");
	t39.loadFromFile("cards/ace_heart.jpg");
	t40.loadFromFile("cards/ace_spade.jpg");

	t41.loadFromFile("cards/jack_clover.jpg");
	t42.loadFromFile("cards/jack_diamond.jpg");
	t43.loadFromFile("cards/jack_heart.jpg");
	t44.loadFromFile("cards/jack_spade.jpg");

	t45.loadFromFile("cards/king_clover.jpg");
	t46.loadFromFile("cards/king_diamond.jpg");
	t47.loadFromFile("cards/king_heart.jpg");
	t48.loadFromFile("cards/king_spade.jpg");

	t49.loadFromFile("cards/queen_clover.jpg");
	t50.loadFromFile("cards/queen_diamond.jpg");
	t51.loadFromFile("cards/queen_heart.jpg");
	t52.loadFromFile("cards/queen_spade.jpg");

	t53.loadFromFile("cards/(back_card).jpg");
	t54.loadFromFile("cards/bg1-1.jpg");
	t64.loadFromFile("cards/bg1-2.jpg");

	t55.loadFromFile("images/1.png");
	t56.loadFromFile("images/10.png");
	t57.loadFromFile("images/100.png");
	t58.loadFromFile("images/1000.png");
	t59.loadFromFile("images/max.png");

	t60.loadFromFile("images/double.png");
	t61.loadFromFile("images/hit.png");
	t62.loadFromFile("images/stand.png");
	t63.loadFromFile("images/place.png");
	t65.loadFromFile("cards/deck.png");
	t66.loadFromFile("images/reset.png");
	t67.loadFromFile("images/reload.png");
	t68.loadFromFile("images/exit.png");

	Sprite two_of_clubs(t1);
	Sprite two_of_diamonds(t2);
	Sprite two_of_hearts(t3);
	Sprite two_of_spades(t4);

	Sprite three_of_clubs(t5);
	Sprite three_of_diamonds(t6);
	Sprite three_of_hearts(t7);
	Sprite three_of_spades(t8);

	Sprite four_of_clubs(t9);
	Sprite four_of_diamonds(t10);
	Sprite four_of_hearts(t11);
	Sprite four_of_spades(t12);

	Sprite five_of_clubs(t13);
	Sprite five_of_diamonds(t14);
	Sprite five_of_hearts(t15);
	Sprite five_of_spades(t16);

	Sprite six_of_clubs(t17);
	Sprite six_of_diamonds(t18);
	Sprite six_of_hearts(t19);
	Sprite six_of_spades(t20);

	Sprite seven_of_clubs(t21);
	Sprite seven_of_diamonds(t22);
	Sprite seven_of_hearts(t23);
	Sprite seven_of_spades(t24);

	Sprite eight_of_clubs(t25);
	Sprite eight_of_diamonds(t26);
	Sprite eight_of_hearts(t27);
	Sprite eight_of_spades(t28);

	Sprite nine_of_clubs(t29);
	Sprite nine_of_diamonds(t30);
	Sprite nine_of_hearts(t31);
	Sprite nine_of_spades(t32);

	Sprite ten_of_clubs(t33);
	Sprite ten_of_diamonds(t34);
	Sprite ten_of_hearts(t35);
	Sprite ten_of_spades(t36);

	Sprite ace_of_clubs(t37);
	Sprite ace_of_diamonds(t38);
	Sprite ace_of_hearts(t39);
	Sprite ace_of_spades(t40);

	Sprite jack_of_clubs(t41);
	Sprite jack_of_diamonds(t42);
	Sprite jack_of_hearts(t43);
	Sprite jack_of_spades(t44);

	Sprite king_of_clubs(t45);
	Sprite king_of_diamonds(t46);
	Sprite king_of_hearts(t47);
	Sprite king_of_spades(t48);

	Sprite queen_of_clubs(t49);
	Sprite queen_of_diamonds(t50);
	Sprite queen_of_hearts(t51);
	Sprite queen_of_spades(t52);

	Sprite reload(t67);
	Sprite reset(t66);
	Sprite bet1(t55);
	Sprite bet10(t56);
	Sprite bet100(t57);
	Sprite bet1000(t58);
	Sprite betmax(t59);
	Sprite exit(t68);

	Sprite doubleButton(t60);
	Sprite hitButton(t61);
	Sprite standButton(t62);
	Sprite placeButton(t63);

	Sprite deck(t65);
	Sprite cardBack(t53);
	Sprite background1(t54);
	Sprite background2(t64);

	Sprite cardd;

	while (window.isOpen())
	{
		window.setFramerateLimit(60);
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
			if (e.type == Event::TextEntered)
			{
				bet.input(e, betBarEnable);
			}
			if (e.type == Event::MouseButtonPressed)
			{
				if (e.key.code == Mouse::Left)
				{
					float x = Mouse::getPosition(window).x;
					float y = Mouse::getPosition(window).y;
					// place button
					if (x >= 560 && y >= 525 && x <= 740 && y <= 585 && bet.betValue > 0 && bet.betValue <= balance && betPlaced == false)
					{
						betBarEnable = false;
						betPlaced = true;
						balance -= bet.betValue;
					}
					// hit button
					else if (x >= 605 && y >= 525 && x <= 705 && y <= 685 && betBarEnable == false)
					{
						if (betPlaced == true && playerCards < 21 && playerNrOfCards < 5)
						{
							playerTurn();
						}

					}
					// stand button
					else if (x >= 725 && y >= 525 && x <= 905 && y <= 585 && betBarEnable == false)
					{
						while (dealerCards < 17)
						{
							dealerTurn();
						}

						winCondition(bet);
					}
					// double button
					else if (x >= 355 && y >= 525 && y <= 585 && x <= 585 && betPlaced == true)
					{
						playerTurn();

						while (dealerCards < 17)
						{
							dealerTurn();
						}
						bet.betValue *= 2;
						balance -= bet.betValue;

						winCondition(bet);
					}
					//reload
					if (x >= 50 && y >= 360 && x <= 100 && y <= 410 && betBarEnable == true)
					{
						balance = 50;
					}
					//reset
					if (x >= 90 && y >= 540 && x <= 140 && y <= 590 && betBarEnable == true)
					{
						bet.betValue = 0;
						bet.addButton(0);
					}
					// bet 1
					if (x >= 90 && y >= 600 && x <= 140 && y <= 650 && betBarEnable == true)
					{
						bet.addButton(1);
					}
					// bet 10
					if (x >= 90 && y >= 660 && x <= 140 && y <= 710 && betBarEnable == true)
					{
						bet.addButton(10);
					}
					// bet 100
					if (x >= 90 && y >= 720 && x <= 140 && y <= 770 && betBarEnable == true)
					{
						bet.addButton(100);
					}
					// bet 1000
					if (x >= 90 && y >= 780 && x <= 140 && y <= 830 && betBarEnable == true)
					{
						bet.addButton(1000);
					}
					// bet max
					if (x >= 90 && y >= 840 && x <= 140 && y <= 890 && betBarEnable == true)
					{
						bet.betValue = 0;
						bet.addButton(balance);
					}
					//exit
					if (x >= 1200 && y >= 100 && x <= 1300 && y <= 200)
					{
						window.close();
						mainMenu();
					}
				}
			}
		}

		//Drawing All Assets
		window.clear(Color::Green);
		if (betPlaced == false)
		{
			window.draw(background1);
			placeButton.setPosition(560, 525);
			window.draw(placeButton);
		}
		else
		{
			window.draw(background2);
			doubleButton.setPosition(355, 525);
			window.draw(doubleButton);
			hitButton.setPosition(605, 525);
			window.draw(hitButton);
			standButton.setPosition(725, 525);
			window.draw(standButton);
		}
		reset.setPosition(90, 540);
		window.draw(reset);
		bet1.setPosition(90, 600);
		window.draw(bet1);
		bet10.setPosition(90, 660);
		window.draw(bet10);
		bet100.setPosition(90, 720);
		window.draw(bet100);
		bet1000.setPosition(90, 780);
		window.draw(bet1000);
		betmax.setPosition(90, 840);
		window.draw(betmax);

		//reload bal
		if (balance == 0)
		{
			reload.setPosition(50, 360);
			window.draw(reload);
		}

		exit.setPosition(1200, 100);
		window.draw(exit);

		

		//Win-Lose-Tie
		switch (winRound)
		{
		case 1:
			text.setString("Lose");
			window.draw(text);
			break;
		case 2:
			text.setPosition(455, 230);
			text.setFillColor(Color::Black);
			text.setOutlineColor(Color(218, 165, 32));
			text.setString("Blackjack");
			window.draw(text);
			break;
		case 3:
			text.setString("Win");
			window.draw(text);
			break;
		case 4:
			text.setPosition(520, 230);
			text.setString("Bust");
			window.draw(text);
			break;
		case 5:
			text.setString("Tie");
			window.draw(text);
			break;
		default:
			text.setString("Play");
			break;
		}
		//Bet placed and Draw Cards
		if (first == true && betPlaced == true)
		{
			playerTurn();
			playerTurn();
			dealerTurn();
			dealerTurn();

			first = false;
		}

		deck.setPosition(30, 30);
		window.draw(deck);


		string b, c, d;
		Text balanceText("Balance: " + to_string(balance), font, 45);
		Font font;
		font.loadFromFile("fonts/Akhenaton-LYLD.ttf");
		balanceText.setOutlineColor(Color::Black);
		balanceText.setOutlineThickness(2);
		balanceText.setPosition(30, 300);
		window.draw(balanceText);

		Text holdValue(to_string(playerCards), font, 55);
		holdValue.setOutlineColor(Color::Black);
		holdValue.setOutlineThickness(2);
		holdValue.setPosition(980, 500);

		Text playerText("Player:", font, 55);
		playerText.setOutlineColor(Color::Black);
		playerText.setOutlineThickness(2);
		playerText.setPosition(955, 430);
		window.draw(holdValue);
		window.draw(playerText);

		Text dealerText("Dealer:", font, 55);
		dealerText.setOutlineColor(sf::Color::Black);
		dealerText.setFillColor(sf::Color::Red);
		dealerText.setOutlineThickness(2);
		dealerText.setPosition(255, 430);

		Text holdValueD(std::to_string(dealerCards), font, 55);
		holdValueD.setOutlineColor(sf::Color::Black);
		holdValueD.setFillColor(sf::Color::Red);
		holdValueD.setOutlineThickness(2);
		holdValueD.setPosition(265, 500);

		if (gameFinish == true) {
			window.draw(holdValueD);
			window.draw(dealerText);
		}



		int position = 260;
		for (int i = 1; i <= playerNrOfCards; i++)
		{
			if (player[i].value == 1)
			{
				if (player[i].color == 1)
				{
					cardd = ace_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = ace_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = ace_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = ace_of_spades;
				}
			}
			if (player[i].value == 2)
			{
				if (player[i].color == 1)
				{
					cardd = two_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = two_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = two_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = two_of_spades;
				}
			}
			if (player[i].value == 3)
			{
				if (player[i].color == 1)
				{
					cardd = three_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = three_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = three_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = three_of_spades;
				}
			}
			if (player[i].value == 4)
			{
				if (player[i].color == 1)
				{
					cardd = four_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = four_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = four_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = four_of_spades;
				}
			}
			if (player[i].value == 5)
			{
				if (player[i].color == 1)
				{
					cardd = five_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = five_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = five_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = five_of_spades;
				}
			}
			if (player[i].value == 6)
			{
				if (player[i].color == 1)
				{
					cardd = six_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = six_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = six_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = six_of_spades;
				}
			}
			if (player[i].value == 7)
			{
				if (player[i].color == 1)
				{
					cardd = seven_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = seven_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = seven_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = seven_of_spades;
				}
			}
			if (player[i].value == 8)
			{
				if (player[i].color == 1)
				{
					cardd = eight_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = eight_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = eight_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = eight_of_spades;
				}
			}
			if (player[i].value == 9)
			{
				if (player[i].color == 1)
				{
					cardd = nine_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = nine_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = nine_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = nine_of_spades;
				}
			}
			if (player[i].value == 10)
			{
				if (player[i].color == 1)
				{
					cardd = ten_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = ten_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = ten_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = ten_of_spades;
				}
			}
			if (player[i].value == 11)
			{
				if (player[i].color == 1)
				{
					cardd = jack_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = jack_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = jack_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = jack_of_spades;
				}
			}
			if (player[i].value == 12)
			{
				if (player[i].color == 1)
				{
					cardd = queen_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = queen_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = queen_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = queen_of_spades;
				}
			}
			if (player[i].value == 13)
			{
				if (player[i].color == 1)
				{
					cardd = king_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = king_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = king_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = king_of_spades;
				}
			}
			cardd.setPosition(position, 630);
			position += 260;
			window.draw(cardd);
		}
		position = 260;
		for (int i = 1; i <= dealerNrOfCards; i++)
		{
			if (i == 2 && gameFinish == false)
			{
				cardd = cardBack;
			}
			else
			{
				if (i != 2 || gameFinish == true)
				{

					if (dealer[i].value == 1)
					{
						if (dealer[i].color == 1)
						{
							cardd = ace_of_clubs;
						}
						if (dealer[i].color == 2)
						{
							cardd = ace_of_diamonds;
						}
						if (dealer[i].color == 3)
						{
							cardd = ace_of_hearts;
						}
						if (dealer[i].color == 4)
						{
							cardd = ace_of_spades;
						}
					}
					else if (dealer[i].value >= 2 && dealer[i].value <= 10)
					{
						if (dealer[i].value == 2)
						{
							if (dealer[i].color == 1)
							{
								cardd = two_of_clubs;
							}
							if (dealer[i].color == 2)
							{
								cardd = two_of_diamonds;
							}
							if (dealer[i].color == 3)
							{
								cardd = two_of_hearts;
							}
							if (dealer[i].color == 4)
							{
								cardd = two_of_spades;
							}
						}
						if (dealer[i].value == 3)
						{
							if (dealer[i].color == 1)
							{
								cardd = three_of_clubs;
							}
							if (dealer[i].color == 2)
							{
								cardd = three_of_diamonds;
							}
							if (dealer[i].color == 3)
							{
								cardd = three_of_hearts;
							}
							if (dealer[i].color == 4)
							{
								cardd = three_of_spades;
							}
						}
						if (dealer[i].value == 4)
						{
							if (dealer[i].color == 1)
							{
								cardd = four_of_clubs;
							}
							if (dealer[i].color == 2)
							{
								cardd = four_of_diamonds;
							}
							if (dealer[i].color == 3)
							{
								cardd = four_of_hearts;
							}
							if (dealer[i].color == 4)
							{
								cardd = four_of_spades;
							}
						}
						if (dealer[i].value == 5)
						{
							if (dealer[i].color == 1)
							{
								cardd = five_of_clubs;
							}
							if (dealer[i].color == 2)
							{
								cardd = five_of_diamonds;
							}
							if (dealer[i].color == 3)
							{
								cardd = five_of_hearts;
							}
							if (dealer[i].color == 4)
							{
								cardd = five_of_spades;
							}
						}
						if (dealer[i].value == 6)
						{
							if (dealer[i].color == 1)
							{
								cardd = six_of_clubs;
							}
							if (dealer[i].color == 2)
							{
								cardd = six_of_diamonds;
							}
							if (dealer[i].color == 3)
							{
								cardd = six_of_hearts;
							}
							if (dealer[i].color == 4)
							{
								cardd = six_of_spades;
							}
						}
						if (dealer[i].value == 7)
						{
							if (dealer[i].color == 1)
							{
								cardd = seven_of_clubs;
							}
							if (dealer[i].color == 2)
							{
								cardd = seven_of_diamonds;
							}
							if (dealer[i].color == 3)
							{
								cardd = seven_of_hearts;
							}
							if (dealer[i].color == 4)
							{
								cardd = seven_of_spades;
							}
						}
						if (dealer[i].value == 8)
						{
							if (dealer[i].color == 1)
							{
								cardd = eight_of_clubs;
							}
							if (dealer[i].color == 2)
							{
								cardd = eight_of_diamonds;
							}
							if (dealer[i].color == 3)
							{
								cardd = eight_of_hearts;
							}
							if (dealer[i].color == 4)
							{
								cardd = eight_of_spades;
							}
						}
						if (dealer[i].value == 9)
						{
							if (dealer[i].color == 1)
							{
								cardd = nine_of_clubs;
							}
							if (dealer[i].color == 2)
							{
								cardd = nine_of_diamonds;
							}
							if (dealer[i].color == 3)
							{
								cardd = nine_of_hearts;
							}
							if (dealer[i].color == 4)
							{
								cardd = nine_of_spades;
							}
						}
						if (dealer[i].value == 10)
						{
							if (dealer[i].color == 1)
							{
								cardd = ten_of_clubs;
							}
							if (dealer[i].color == 2)
							{
								cardd = ten_of_diamonds;
							}
							if (dealer[i].color == 3)
							{
								cardd = ten_of_hearts;
							}
							if (dealer[i].color == 4)
							{
								cardd = ten_of_spades;
							}
						}
					}

					else if (dealer[i].value >= 11 && dealer[i].value <= 13)
					{
						if (dealer[i].value == 11)
						{
							if (dealer[i].color == 1)
							{
								cardd = jack_of_clubs;
							}
							if (dealer[i].color == 2)
							{
								cardd = jack_of_diamonds;
							}
							if (dealer[i].color == 3)
							{
								cardd = jack_of_hearts;
							}
							if (dealer[i].color == 4)
							{
								cardd = jack_of_spades;
							}
						}
						if (dealer[i].value == 12)
						{
							if (dealer[i].color == 1)
							{
								cardd = queen_of_clubs;
							}
							if (dealer[i].color == 2)
							{
								cardd = queen_of_diamonds;
							}
							if (dealer[i].color == 3)
							{
								cardd = queen_of_hearts;
							}
							if (dealer[i].color == 4)
							{
								cardd = queen_of_spades;
							}
						}
						if (dealer[i].value == 13)
						{
							if (dealer[i].color == 1)
							{
								cardd = king_of_clubs;
							}
							if (dealer[i].color == 2)
							{
								cardd = king_of_diamonds;
							}
							if (dealer[i].color == 3)
							{
								cardd = king_of_hearts;
							}
							if (dealer[i].color == 4)
							{
								cardd = king_of_spades;
							}
						}
					}
				}
			}
			cardd.setPosition(position, 30);
			position += 260;
			window.draw(cardd);
		}
		bet.drawBetBar(window);
		window.display();
		if (gameFinish == true)
		{
			sleep(seconds(3));
			text.setOutlineColor(Color::Black);
			text.setFillColor(Color::White);
			text.setOutlineThickness(3);
			text.setPosition(550, 230);

			winRound = 0;
			betBarEnable = true;
			betPlaced = false;
			playerCards = 0;
			playerNrOfCards = 0;
			dealerCards = 0;
			dealerNrOfCards = 0;
			numAces = 0;
			numAcesDealer = 0;
			first = true;
			gameFinish = false;
		}
	}
	return 0;
}

#include "Menu.h"

Menu::Menu():
	graphicManager(GerenciadorGrafico::getInstance())
{
	winclose = new sf::RectangleShape();
	font = new sf::Font();
	image = new sf::Texture();
	bg = new sf::Sprite();

	set_values();
}

Menu::~Menu()
{
	delete winclose;
	delete font;
	delete image;
	delete bg;
}

void Menu::set_values()
{
	pos = 0;
	pressed = theselect = false;
	font->loadFromFile("./ethn.otf");
	image->loadFromFile("menubackground.png");

	bg->setTexture(*image);

	pos_mouse = { 0,0 };
	mouse_coord = { 0, 0 };

	options = { "The Human War Game", "Fase 1", "Fase 2", "Options", "Quit" };
	texts.resize(5);
	coords = { {380,40},{540,191},{540,282},{525,370},{563,457} };
	sizes = { 30,28,24,24,24 };

	for (std::size_t i{}; i < texts.size(); ++i) {
		texts[i].setFont(*font);
		texts[i].setString(options[i]);
		texts[i].setCharacterSize(sizes[i]);
		texts[i].setOutlineColor(sf::Color::Black);
		texts[i].setPosition(coords[i]);
	}
	texts[1].setOutlineThickness(4);
	pos = 1;

	winclose->setSize(sf::Vector2f(23, 26));
	winclose->setPosition(1178, 39);
	winclose->setFillColor(sf::Color::Transparent);

}

void Menu::loop_events()
{
	sf::Event ev;

	while (graphicManager->getWindow()->pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed) 
		{
			graphicManager->closeWindow();
		}

		pos_mouse = sf::Mouse::getPosition(*graphicManager->getWindow());
		mouse_coord = graphicManager->getWindow()->mapPixelToCoords(pos_mouse);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed) 
		{
			if (pos < 4) 
			{
				++pos;
				pressed = true;
				texts[pos].setOutlineThickness(4);
				texts[pos - 1].setOutlineThickness(0);
				pressed = false;
				theselect = false;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed) {
			if (pos > 1) {
				--pos;
				pressed = true;
				texts[pos].setOutlineThickness(4);
				texts[pos + 1].setOutlineThickness(0);
				pressed = false;
				theselect = false;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
			theselect = true;

			if (pos == 4) 
			{
				graphicManager->closeWindow();
				exit(1);
			}
			std::cout << options[pos] << '\n';

			if (pos == 1) 
			{
				selectedFase = 1;
			}

			if (pos == 2) 
			{
				selectedFase = 2;
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (winclose->getGlobalBounds().contains(mouse_coord)) {
				//std::cout << "Close the window!" << '\n';
				graphicManager->closeWindow();
			}
		}
	}
}

void Menu::draw_all()
{
	graphicManager->clear();
	graphicManager->render(bg);

	for (auto t : texts) 
	{
		graphicManager->getWindow()->draw(t);
	}

	graphicManager->display();
}

int Menu::getFase()
{
	return selectedFase;
}

void Menu::run_menu()
{
	while (graphicManager->isWindowOpen() && selectedFase == 0) 
	{
		loop_events();
		draw_all();
	}
}

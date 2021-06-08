#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <windows.h>
using namespace sf;
	int gridLogic[12][12];
	int gridView[12][12];


int main()
{
    start:
	// Генератор случайных чисел
	srand(time(0));

	RenderWindow app(VideoMode(400, 400), "Minesweeper!");
	// Ширина клетки
	int w = 32;

	// Загрузка текстуры и создание спрайта
	Texture t;
	t.loadFromFile("images/tiles.jpg");
	Sprite s(t);

	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			gridView[i][j] = 10;
			if (rand() % 5 == 0)  gridLogic[i][j] = 9;
			else gridLogic[i][j] = 0;
		}

	// Подсчет мин вокруг каждой клетки
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			int n = 0;
			if (gridLogic[i][j] == 9) continue;
			if (gridLogic[i + 1][j] == 9) n++;
			if (gridLogic[i][j + 1] == 9) n++;
			if (gridLogic[i - 1][j] == 9) n++;
			if (gridLogic[i][j - 1] == 9) n++;
			if (gridLogic[i + 1][j + 1] == 9) n++;
			if (gridLogic[i - 1][j - 1] == 9) n++;
			if (gridLogic[i - 1][j + 1] == 9) n++;
			if (gridLogic[i + 1][j - 1] == 9) n++;
			gridLogic[i][j] = n;
		}
		bool loose = false;

	while (app.isOpen())
	{
		// Получаем координаты мышки относительно окна нашего приложения
		Vector2i pos = Mouse::getPosition(app);
		int x = pos.x / w;
		int y = pos.y / w;

		Event e;
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
                app.close();
            if (Keyboard::isKeyPressed(Keyboard::F12)){
                    goto start;
            }
			if (e.type == Event::MouseButtonPressed){
				// Если это - левая кнопка мыши, то открываем клетку
				if (e.key.code == Mouse::Left){
                gridView[x][y] = gridLogic[x][y];
				// Если это – правая кнопка мыши, то отображаем флажок
				}
				else if (e.key.code == Mouse::Right) gridView[x][y] = 11;
            }
		}

		// Устанавливаем белый фон
		app.clear(Color::White);

		for (int i = 1; i <= 10; i++)
			for (int j = 1; j <= 10; j++)
			{
				if (gridView[x][y] == 9){
                    gridView[i][j] = gridLogic[i][j];
                    loose = true;

				}

				// Вырезаем из спрайта нужный нам квадратик текстуры
				s.setTextureRect(IntRect(gridView[i][j] * w, 0, w, w));

				// Устанавливаем его заданную позицию…
				s.setPosition(i*w, j*w);

				// … и отрисовываем
				app.draw(s);
			}
    if(loose == true){
        Font font;
        font.loadFromFile("Calibri.ttf");
        Text text("Game is over!Type F12 to restart the game!", font, 30);
        text.setColor(Color::Red);
        app.draw(text);
	}
		// Отображаем всю композицию на экране
		app.display();
	}


	return 0;
}

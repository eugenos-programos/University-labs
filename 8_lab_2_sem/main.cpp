#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;
	int gridLogic[12][12];
	int gridView[12][12];

void open_all_sprites(int x,int y){
        gridView[x][y] = gridLogic[x][y];
        if (y > -1 && y > 0 && gridLogic[x][y + 1] == 0) open_all_sprites(x,y+1);
        if (x > 1 && gridLogic[x - 1][y] == 0) open_all_sprites(x-1,y);
        if (x > -1 &&gridLogic[x + 1][y] == 0) open_all_sprites(x+1,y);
        if (y > 1 && gridLogic[x][y - 1] == 0) open_all_sprites(x,y-1);
}


int main()
{
	// Генератор случайных чисел
	srand(time(0));

	RenderWindow app(VideoMode(400, 400), "Minesweeper!");
	// Ширина клетки
	int w = 32;

	for(int i = 0;i < 12;i++){
        for(int j = 0;j < 12;j++)
            printf("%d ",gridLogic[i][j]);
	}

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
			if (e.type == Event::MouseButtonPressed){
				// Если это - левая кнопка мыши, то открываем клетку
				if (e.key.code == Mouse::Left){
                        if(gridLogic[x][y] == 0){
                            if (gridLogic[x-1][y] == 0){
                                if(gridLogic[x-1][y+1] == 0){
                                    if(gridLogic[x][y+1]){
                                        open_all_sprites(x,y);
                                    }
                                }
                                else if(gridLogic[x-1][y-1] == 0){
                                    if(gridLogic[x][y-1] == 0){
                                        open_all_sprites(x,y);
                                    }
                                }
                            }
                            else if (gridLogic[x+1][y] == 0){
                                if(gridLogic[x+1][y+1] == 0){
                                    if(gridLogic[x][y+1] == 0){
                                        open_all_sprites(x,y);
                                    }
                                }
                                else if(gridLogic[x+1][y-1] == 0){
                                    if(gridLogic[x][y-1] == 0){
                                        open_all_sprites(x,y);
                                    }
                                }
                            }
                        }
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
				if (gridView[x][y] == 9) gridView[i][j] = gridLogic[i][j];

				// Вырезаем из спрайта нужный нам квадратик текстуры
				s.setTextureRect(IntRect(gridView[i][j] * w, 0, w, w));

				// Устанавливаем его заданную позицию…
				s.setPosition(i*w, j*w);

				// … и отрисовываем
				app.draw(s);
			}
		// Отображаем всю композицию на экране
		app.display();
	}

	return 0;
}

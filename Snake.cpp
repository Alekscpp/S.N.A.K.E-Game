#include"Snake.h"

int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console current dimensions

	MoveWindow(console, r.left, r.top, 200, 400, TRUE); // 800 width, 100 height
	srand(time(NULL));
	while (!gameOver)
	{
			_input();
			setArea();
			drawArea();

			Logic();
		
		
		
		
	}
	system("cls");
	std::cout << "\tGame Over \n\tSCORE: " << Score;
	return 0;
}

void setSnake() {

	switch (dir)
	{
	case edir::STOP:

		break;
	case edir::UP:
		snakePos.push_back(std::make_pair(snakePos[snakePos.size() - 1].first - 1,
			snakePos[snakePos.size() - 1].second));
		snakePos.erase(snakePos.begin(), snakePos.begin() + 1);
		if (arr[snakePos[snakePos.size() - 1].first][snakePos[snakePos.size() - 1].second] == '#' ||
			arr[snakePos[snakePos.size() - 1].first][snakePos[snakePos.size() - 1].second] == 'O')
			gameOver = true;
		for (size_t i = 0; i < snakePos.size() - 1; i++)
		{
			if (snakePos[i] == snakePos[snakePos.size() - 1])
				gameOver = true;
		}
		break;
	case edir::DOWN:
		snakePos.push_back(std::make_pair(snakePos[snakePos.size() - 1].first + 1,
			snakePos[snakePos.size() - 1].second));
		snakePos.erase(snakePos.begin(), snakePos.begin() + 1);
		if (arr[snakePos[snakePos.size() - 1].first][snakePos[snakePos.size() - 1].second] == '#' ||
			arr[snakePos[snakePos.size() - 1].first][snakePos[snakePos.size() - 1].second] == 'O')
			gameOver = true;
		for (size_t i = 0; i < snakePos.size() - 1; i++)
		{
			if (snakePos[i] == snakePos[snakePos.size() - 1])
				gameOver = true;
		}
		break;
	case edir::LEFT:
		snakePos.push_back(std::make_pair(snakePos[snakePos.size() - 1].first,
			snakePos[snakePos.size() - 1].second - 1));
		snakePos.erase(snakePos.begin(), snakePos.begin() + 1);
		if (arr[snakePos[snakePos.size() - 1].first][snakePos[snakePos.size() - 1].second] == '#' ||
			arr[snakePos[snakePos.size() - 1].first][snakePos[snakePos.size() - 1].second] == 'O')
			gameOver = true;
		for (size_t i = 0; i < snakePos.size() - 1; i++)
		{
			if (snakePos[i] == snakePos[snakePos.size() - 1])
				gameOver = true;
		}
		break;
	case edir::RIGHT:
		snakePos.push_back(std::make_pair(snakePos[snakePos.size() - 1].first,
			snakePos[snakePos.size() - 1].second + 1));
		snakePos.erase(snakePos.begin(), snakePos.begin() + 1);
		if (arr[snakePos[snakePos.size() - 1].first][snakePos[snakePos.size() - 1].second] == '#' ||
			arr[snakePos[snakePos.size() - 1].first][snakePos[snakePos.size() - 1].second] == 'O')
			gameOver = true;
		for (size_t i = 0; i < snakePos.size() - 1; i++)
		{
			if (snakePos[i] == snakePos[snakePos.size() - 1])
				gameOver = true;
		}
		break;
	default:
		break;
	}


	for (auto p : snakePos) {
		arr[p.first][p.second] = 'O';
	}
}


//	INSTAL AREA PARAMETERS

void setArea()
{
	for (size_t i = 0; i < width; i++)
	{
		for (size_t j = 0; j < heigth; j++)
		{

			if (i == 0 || i == 19 || j == 0 || j == 19)
				arr[i][j] = '#';
			else arr[i][j] = ' ';

		}

	}

	setSnake();
	setFruit();
}

//  FRUIT

void setFruit() {
	if (snakePos[snakePos.size() - 1] == fruit) {
		snakePos.push_back(fruit);

		Score += 10;


	start:
		int x = 1 + rand() % (width - 2);
		int y = 1 + rand() % (heigth - 2);
		for (auto p : snakePos) {
			if (p.first == x && p.second == y) {
				goto start;
			}
		}
		fruit.first = x;
		fruit.second = y;
	}
	arr[fruit.first][fruit.second] = 'F';
}
void drawArea() {

	system("cls");

	std::cout << "SCORE: " << Score << " " << "LEVEL " << Level << "\n";
	for (size_t i = 0; i < width; i++)
	{
		for (size_t j = 0; j < heigth; j++)
		{
			std::cout << arr[i][j];
		}
		std::cout << std::endl;
	}

}

void _input() {
	if (_kbhit()) {
		switch (_getch())
		{
		case 'w':
			dir = edir::UP;
			break;
		case 's':
			dir = edir::DOWN;
			break;
		case'd':
			dir = edir::RIGHT;
			break;
		case'a':
			dir = edir::LEFT;
			break;
		default:
			dir = edir::STOP;
			break;
		}
	}

}

void Logic() {
	int speed = 300;

	if (Score >= 30) { speed = 200; Level = 2; }
	if (Score >= 50) { speed = 100; Level = 3; }

	if (Score >= 70) { speed = 50;  Level = 4; }

	Sleep(speed);
}
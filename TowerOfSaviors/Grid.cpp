#include "Grid.h"

Grid::Grid()
{
	srand(time(0));

	// Set up Background
	bg_texture.loadFromFile("images/background.png");
	background.setTexture(bg_texture);
	runestones_texture.loadFromFile("images/diamonds.png");
	runestone_sprite.setTexture(runestones_texture);

	// Set up Offset for stones to move them down
	grid_offset.x = 0;
	grid_offset.y = 380;

	// Set up the all runestone
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			grid[i][j].kind = rand() % 6;
			grid[i][j].col = j;
			grid[i][j].row = i;
			grid[i][j].x = j * ts;
			grid[i][j].y = i * ts;
		}
	}
	// get underlying buffer
	std::streambuf* orig_buf = std::cout.rdbuf();

	// set null
	std::cout.rdbuf(NULL);

	while (checkMatch()) {
		deleteMatchedAndCollectNumber();
		fillEmptyGrid();
	}
	// restore buffer
	std::cout.rdbuf(orig_buf);
	for (int i = 0; i < 6; i++) {
		numberofstonedeleted[i] = 0;
	}
}

Grid::~Grid()
{

}

void Grid::deleteMatchedAndCollectNumber()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			if (grid[i][j].match) {
				grid[i][j].alpha = 0;
				numberofstonedeleted[grid[i][j].kind]++;
			}
		}
	}
}

bool Grid::checkMatch()
{
	bool matched = false;
	// check tile vertically
	for (int j = 0; j < 6; j++) { // for every column
		for (int i = 0; i < 3; i++) { // check till last three stone which i = 2
			if (!grid[i][j].match) {
				if (grid[i][j].kind == grid[i + 1][j].kind && grid[i][j].kind == grid[i + 2][j].kind) {
					for (int z = i; z < i + 3; z++) {
						std::cout << "Stone (" << j << "," << z << ") is matched\n";
						grid[z][j].match = 1;
					}
					matched = true;
					if (i != 2) {
						int n = i + 3;
						while (grid[i][j].kind == grid[n][j].kind && n != 5) {
							std::cout << "Stone (" << j << "," << n << ") is matched\n";
							grid[n][j].match = 1;
							n++;
						}
					}
				}
			}
		}
	}
	// check tile horizontally 
	for (int i = 0; i < 5; i++) { // check every row
		for (int j = 0; j < 4; j++) { // check till stone 3
			if (!grid[i][j].match) {
				if (grid[i][j].kind == grid[i][j + 1].kind && grid[i][j + 1].kind == grid[i][j + 2].kind) {
					for (int z = j; z < j + 3; z++) {
						std::cout << "Stone (" << z << "," << i << ") is matched\n";
						grid[i][z].match = 1;
					}
					matched = true;
					if (j != 3) {
						int n = j + 3;
						while (grid[i][j].kind == grid[i][n].kind && n != 6) {
							std::cout << "Stone (" << n << "," << i << ") is matched\n";
							grid[i][n].match = 1;
							n++;
						}
					}
				}
			}
		}
	}
	return matched;
}

void Grid::fillEmptyGrid()
{
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 6; j++){
			if (grid[i][j].match) {
				grid[i][j].kind = rand() % 6;
				grid[i][j].alpha = 255;
				grid[i][j].match = 0;
			}
		}
	}
	
}

void Grid::updateGrid(sf::Vector2i mouse_clicked, sf::Vector2i mouse_dragging)
{
	if ((clicked && released) || time_up) {
		int i = 1;
		while (checkMatch()) {
			deleteMatchedAndCollectNumber();
			fillEmptyGrid();
			std::cout << "Dissolved << " << i << " time\n";
			i++;
			std::cout << "Water\tEarth\tHeart\tDark\tFire\tLight\n";
			for (int arri = 0; arri < 6; arri++) {
				std::cout << numberofstonedeleted[arri] << "\t";
			}
			std::cout << "\n\n";
		}
		launchattack = true;
		clicked = false;
		released = false;
		time_up = false;
	}

	else if (clicked && spinning) {		
		x = (mouse_dragging.x - grid_offset.x) / ts;
		y = (mouse_dragging.y - grid_offset.y) / ts;
		// if moved to another tile
		if (x0 >= 0 && x0 <= 5 && y0 >= 0 && y0 <= 4) {
			if (x >= 0 && x <= 5 && y >= 0 && y <= 4) {
				if (x != x0 || y != y0)
				{
					swapStone(grid[y][x], grid[y0][x0]);
					x0 = x, y0 = y;
				}
			}
		}
	}

	else if (clicked && !spinning) {
		x0 = (mouse_clicked.x - grid_offset.x) / ts;
		y0 = (mouse_clicked.y - grid_offset.y) / ts;
		if(x0 >= 0 && x0 <=5 && y0 >= 0 && y0 <= 4)
			spinning = true;
	}

	

}

void Grid::draw(sf::RenderWindow& window)
{
	// Drawing background
	background.setPosition(0, 380);
	window.draw(background);

	// Drawing Runestones grid
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			piece p = grid[i][j];
			runestone_sprite.setTextureRect(sf::IntRect(p.kind * ts, 0, ts, ts));
			runestone_sprite.setColor(sf::Color(255, 255, 255, p.alpha));
			runestone_sprite.setPosition(p.x, p.y);
			runestone_sprite.move(grid_offset.x, grid_offset.y);
			window.draw(runestone_sprite);
		}
	}
}

void Grid::swapStone(piece& stone1, piece& stone2)
{
	std::swap(stone1.kind, stone2.kind);
}





#include "DXUT.h"
#include "GameManager.h"

GameManager::GameManager()
{
	m_sprite = IMAGE->FindImage("A");
	for (int i = 10; i < 142; i++) {
		for (int j = 10; j < 98; j++) {
			if (i == 10 && j <= 97 && j >= 10) {
				map[i][j] = 1;
			}
			if (i == 141 && j <= 97 && j >= 10) {
				map[i][j] = 1;
			}
			if (j == 10 && i <= 141 && i >= 10) {
				map[i][j] = 1;
			}
			if (j == 97 && i <= 141 && i >= 10) {
				map[i][j] = 1;
			}
		}
	}
}

void GameManager::Update()
{
	for (int i = 10; i < 142; i++) {
		for (int j = 10; j < 98; j++) {
			if (i == 10 && j <= 97 && j >= 10) {
				map[i][j] = 1;
			}
			if (i == 141 && j <= 97 && j >= 10) {
				map[i][j] = 1;
			}
			if (j == 10 && i <= 141 && i >= 10) {
				map[i][j] = 1;
			}
			if (j == 97 && i <= 141 && i >= 10) {
				map[i][j] = 1;
			}
			if (map[i][j] == 1) {
				if (map[i + 1][j] == 3 && map[i - 1][j] == 0 || map[i - 1][j] == 3 && map[i + 1][j] == 0) {
					map[i][j] = 3;
				}
				if (map[i][j+1] == 3 && map[i][j - 1] == 0 || map[i][j - 1] == 3 && map[i][j + 1] == 0) {
					map[i][j] = 3;
				}
			}
			if (map[i][j] == 2) {
				if (map[i + 1][j] == 3 || map[i - 1][j] == 3 || map[i][j + 1] == 3 || map[i][j - 1] == 3) {
					map[i][j] = 4;
				}
				if (map[i + 1][j] == 4) {
					if (map[i][j + 1] == 4 || map[i][j - 1] == 4) {
						map[i][j] = 4;
					}
				}
				if (map[i - 1][j] == 4) {
					if (map[i][j + 1] == 4 || map[i][j - 1] == 4) {
						map[i][j] = 4;
					}
				}
			}
			if (map[i][j] == 4) {

				if (map[i + 1][j] == 3 && map[i - 1][j] == 3) {
					map[i][j] = 3;
				}
				if (map[i][j + 1] == 3 && map[i][j - 1] == 3) {
					map[i][j] = 3;
				}
			}
		}
	}
}

void GameManager::Render()
{
}

void GameManager::LineDelete()
{
	for (int i = 10; i < 142; i++) {
		for (int j = 10; j < 98; j++) {
			if (map[i][j] == 1) {
				if (map[i + 1][j] == 3 && map[i - 1][j] == 0 || map[i - 1][j] == 3 && map[i + 1][j] == 0) {
					map[i][j] = 3;
				}
				if (map[i][j + 1] == 3 && map[i][j - 1] == 0 || map[i][j - 1] == 3 && map[i][j + 1] == 0) {
					map[i][j] = 3;
				}
			}
			if (map[i][j] == 2) {
				if (map[i + 1][j] == 3 || map[i - 1][j] == 3 || map[i][j + 1] == 3 || map[i][j - 1] == 3) {
					map[i][j] = 4;
				}
				if (map[i + 1][j] == 4) {
					if (map[i][j + 1] == 4 || map[i][j - 1] == 4) {
						map[i][j] = 4;
					}
				}
				if (map[i - 1][j] == 4) {
					if (map[i][j + 1] == 4 || map[i][j - 1] == 4) {
						map[i][j] = 4;
					}
				}
			}
			if (map[i][j] == 4) {
				if (map[i + 1][j] == 3 && map[i - 1][j] == 3) {
					map[i][j] = 3;
				}
				if (map[i][j + 1] == 3 && map[i][j - 1] == 3) {
					map[i][j] = 3;
				}
			}
		}
	}
}

void GameManager::PlayerDie()
{
	for (int i = 10; i < 142; i++) {
		for (int j = 10; j < 98; j++) {
			if (map[i][j] == 2) {
				map[i][j] = 0;
			}
		}
	}
}

void GameManager::Restartp()
{
	for (int i = 10; i < 142; i++) {
		for (int j = 10; j < 98; j++) {
			if (i == 10 && j <= 97 && j >= 10) {
				map[i][j] = 1;
			}
			if (i == 141 && j <= 97 && j >= 10) {
				map[i][j] = 1;
			}
			if (j == 10 && i <= 141 && i >= 10) {
				map[i][j] = 1;
			}
			if (j == 97 && i <= 141 && i >= 10) {
				map[i][j] = 1;
			}
		}
	}
}

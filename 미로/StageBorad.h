/* 이 해더 파일은 미로판의 구조와 각 스테이지 별 지형 정의,이동의 정의 ,각 값에 따라서 출력하는 상태를 표현합니다.
    0:빈공간 1:벽 2:플레이어 3:목적지 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define GAME_STAGE1 stange1()
#define GAME_STAGE2 stange2()
#define GAME_STAGE3 stange3()
#define GAME_STAGE4 stange4()
#define Print print()
#define WIN win()
#define STAGECLRER stageClear()

#define GOUP up()
#define GODOWN down()
#define GOLEFT left()
#define GORIGHT right()
#define CLEAR system("cls");

int playerX = 0;
int playerY = 0;

struct gameBoradSetting
{
	char gameBorad[25][79];
}gameBoradSetting;

void stange1() {
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 79; i++) {
			if ((j == 0) || (j == 2) || ((j == 1) && (i == 0)) || ((j == 1) && (i == 78))) {
				gameBoradSetting.gameBorad[j][i] = 1;
			}
		}
	}
	gameBoradSetting.gameBorad[1][1] = 2;
	gameBoradSetting.gameBorad[1][77] = 3;
	playerX = 1;
	playerY = 1;
}

void stange2() {
	for (int j = 0; j < 25; j++) {
		for (int i = 0; i < 79; i++) {
			if (((j == 24) || (j == 0) || (i == 8) || (i == 0) || (i == 78) || ((i % 4 == 0) && (j != 23)) || ((i % 4 == 2) && (j != 1))) && i < 9) {
				gameBoradSetting.gameBorad[j][i] = 1;
			}
			else {
				gameBoradSetting.gameBorad[j][i] = 0;
			}
		}
	}
	gameBoradSetting.gameBorad[23][1] = 2;
	gameBoradSetting.gameBorad[23][7] = 3;
	playerX = 1;
	playerY = 23;
}

void stange3() {
	for (int j = 0; j < 16; j++) {
		for (int i = 0; i < 16; i++) {
			if ((i == 0) || (i == 15) || (j == 15) || (j == 0) || ((i == 1) && ((j == 9) || (j == 11) || (j == 12) || (j == 13))) || ((i == 2) && ((j == 2) || (j == 3) || (j == 4) || (j == 5) || (j == 7) || (j == 8))) || ((i == 3) && ((j == 5) || (j == 9) || (j == 10) || (j == 11) || (j == 12) || (j == 13))) || ((i == 4) && ((j == 2) || (j == 3) || (j == 5))) || ((i == 5) && ((j == 2) || (j == 5) || (j == 6) || (j == 7) || (j == 9) || (j == 10) || (j == 11))) || ((i == 6) && ((j == 1) || (j == 2) || (j == 5) || (j == 7) || (j == 11) || (j == 12) || (j == 13) || (j == 14))) || ((i == 7) && ((j == 2) || (j == 3) || (j == 4) || (j == 5) || (j == 7) || (j == 8) || (j == 9) || (j == 11))) || ((i == 8) && ((j == 7) || (j == 12) || (j == 13))) || ((i == 9) && ((j == 1) || (j == 2) || (j == 3) || (j == 5) || (j == 6) || (j == 7) || (j == 10) || (j == 13))) || ((i == 10) && ((j == 1) || (j == 9) || (j == 10) || (j == 13))) || ((i == 11) && ((j == 1) || (j == 3) || (j == 4) || (j == 5) || (j == 8) || (j == 9) || (j == 12) || (j == 13))) || ((i == 12) && ((j == 2) || (j == 3) || (j == 5) || (j == 7))) || ((i == 13) && ((j == 1) || (j == 5) || (j == 6) || (j == 7) || (j == 8) || (j == 9) || (j == 10) || (j == 11) || (j == 12) || (j == 14))) || ((i == 14) && ((j == 3)))) {
				gameBoradSetting.gameBorad[j][i] = 1;
			}
			else {
				gameBoradSetting.gameBorad[j][i] = 0;
			}
		}
	}
	gameBoradSetting.gameBorad[14][1] = 2;
	gameBoradSetting.gameBorad[1][14] = 3;
	playerX = 1;
	playerY = 14;
}

void stange4() {
}

void stange5() {

}

void stange6() {

}

void print() {
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int j = 0; j < 25; j++) {
		for (int i = 0; i < 79; i++) {
			if (gameBoradSetting.gameBorad[j][i] == 1)
				printf("#");
			else if (gameBoradSetting.gameBorad[j][i] == 2) {
				SetConsoleTextAttribute(color,10);
				printf("P");
				SetConsoleTextAttribute(color, 7);
			}
			else if (gameBoradSetting.gameBorad[j][i] == 3) {
				SetConsoleTextAttribute(color, 14);
				printf("*");
				SetConsoleTextAttribute(color, 7);
			}
			else {
				if ((j != 24) && (i != 78)) {
					printf(" ");
				}
			}
			if ((i == 78) && (gameBoradSetting.gameBorad[j][0] != NULL)) {
				if ((j != 24) || (i != 78)) {
					printf("\n");
				}
			}
		}
	}
}

void left() {
	if (gameBoradSetting.gameBorad[playerY][playerX - 1] != 1) {
		gameBoradSetting.gameBorad[playerY][playerX] = 0;
		gameBoradSetting.gameBorad[playerY][playerX - 1] = 2;
		playerX = playerX - 1;
	}
}

void right() {
	if (gameBoradSetting.gameBorad[playerY][playerX + 1] != 1) {
		gameBoradSetting.gameBorad[playerY][playerX] = 0;
		gameBoradSetting.gameBorad[playerY][playerX + 1] = 2;
		playerX = playerX + 1;
	}
}

void up() {
	if (gameBoradSetting.gameBorad[playerY-1][playerX] != 1) {
		gameBoradSetting.gameBorad[playerY][playerX] = 0;
		gameBoradSetting.gameBorad[playerY-1][playerX] = 2;
		playerY = playerY - 1;
	}
}

void down() {
	if (gameBoradSetting.gameBorad[playerY+1][playerX] != 1) {
		gameBoradSetting.gameBorad[playerY][playerX] = 0;
		gameBoradSetting.gameBorad[playerY + 1][playerX] = 2;
		playerY = playerY + 1;
	}
}

void win() {
	CLEAR;
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < 5; i++) {
		SetConsoleTextAttribute(color, 9);
		printf("        *                        *                                  *          \n");
		printf("          *     *         *                         *                     *    \n");
		printf("    *                                                               *          \n");
		printf("            *                        *          *                              \n");
		printf("                      *                                               *        \n");
		printf("                           *               *               *                   \n");
		printf("       *          *                                                *       *   \n");
		printf("               *                                 *                             \n");
		printf("   *                 ■■■  ■  ■■■      ■      ■■■    *     *         \n");
		printf("        *   *        ■      ■  ■         ■■     ■  ■            *  *    \n");
		printf("                *    ■      ■  ■■■    ■  ■    ■■■        *           \n");
		printf("            *        ■      ■  ■       ■■■■   ■   ■   *          *    \n");
		printf("      *              ■■■  ■  ■■■  ■      ■  ■    ■          *    *  \n");
		printf("             *                        *                       *        *       \n");
		printf("          *      *             *                                  *            \n");
		printf("       *                                        *          *               *   \n");
		printf("   *       *       *                *        *        *          *     *       \n");
		printf("                                                                               \n");
		printf("         *     *         *     *        *                          *           \n");
		printf("                                               *     *         *          *    \n");
		printf("         *           *         *                                               \n");
		printf("   *        *                         *         *       *       *   *      *   \n");
		printf("        *              *      *              *              *      *           \n");
		printf("     *      *       *       *       *           *             *                \n");
		printf("    *         *      *       *          *                               *      \n");
		Sleep(1000);
		CLEAR;
		SetConsoleTextAttribute(color, 12);
		printf("        *                        *                                  *          \n");
		printf("          *     *         *                         *                     *    \n");
		printf("    *                                                               *          \n");
		printf("            *                        *          *                              \n");
		printf("                      *                                               *        \n");
		printf("                           *               *               *                   \n");
		printf("       *          *                                                *       *   \n");
		printf("               *                                 *                             \n");
		printf("   *                 ■■■  ■  ■■■      ■      ■■■    *     *         \n");
		printf("        *   *        ■      ■  ■         ■■     ■  ■            *  *    \n");
		printf("                *    ■      ■  ■■■    ■  ■    ■■■        *           \n");
		printf("            *        ■      ■  ■       ■■■■   ■   ■   *          *    \n");
		printf("      *              ■■■  ■  ■■■  ■      ■  ■    ■          *    *  \n");
		printf("             *                        *                       *        *       \n");
		printf("          *      *             *                                  *            \n");
		printf("       *                                        *          *               *   \n");
		printf("   *       *       *                *        *        *          *     *       \n");
		printf("                                                                               \n");
		printf("         *     *         *     *        *                          *           \n");
		printf("                                               *     *         *          *    \n");
		printf("         *           *         *                                               \n");
		printf("   *        *                         *         *       *       *   *      *   \n");
		printf("        *              *      *              *              *      *           \n");
		printf("     *      *       *       *       *           *             *                \n");
		printf("    *         *      *       *          *                               *      \n");
		Sleep(1000);
		CLEAR;
	}
}

void stageClear() {
	for (int j = 0; j < 25; j++) {
		for (int i = 0; i < 79; i++) {
			if ((j != 24) && (i != 78)) {
				gameBoradSetting.gameBorad[j][i] = 0;
			}
		}
	}
}

void removeCursor()

{

	CONSOLE_CURSOR_INFO cur;

	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);

	cur.bVisible = 0;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);

}
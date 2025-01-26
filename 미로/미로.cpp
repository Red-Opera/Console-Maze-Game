#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <mmsystem.h>
#include "StageBorad.h"
#pragma comment(lib,"winmm")
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 10
#define ENTER 13
#define Y 89
#define y 118
#define N 78
#define n 100
#define CLEAR system("cls");

int Select = 1;
char stage = 0;

void gameMain() {
	system("mode con cols=80 lines=25");
	printf("    ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓    \n");
	printf("    ┃                                                            ┃    \n");
	printf("    ┃            ■■■■■         ■■■■■■■■             ┃    \n");
	printf("    ┃            ■       ■  ■                    ■           ┃    \n");
	printf("    ┃            ■       ■  ■                    ■           ┃    \n");
	printf("    ┃            ■       ■  ■    ■■■■■■■■             ┃    \n");
	printf("    ┃            ■       ■  ■    ■                           ┃    \n");
	printf("    ┃            ■       ■  ■    ■                           ┃    \n");
	printf("    ┃            ■       ■  ■    ■■■■■■■■             ┃    \n");
	printf("    ┃            ■       ■  ■                                 ┃    \n");
	printf("    ┃            ■       ■  ■            ■                   ┃    \n");
	printf("    ┃            ■       ■  ■            ■                   ┃    \n");
	printf("    ┃            ■■■■■   ■    ■■■■■■■■             ┃    \n");
	printf("    ┃                                                            ┃    \n");
	printf("    ┃                                                            ┃    \n");
	printf("    ┃                                                            ┃    \n");
	printf("    ┃                            새로운 시작 ");
	if (Select == 1) printf(" ≪");
	else printf("    ");
    printf("	         ┃    \n");
	printf("    ┃                                                            ┃    \n");
	printf("    ┃                                                            ┃    \n");
	printf("    ┃                               계속  ");
	if (Select == 2) printf("    ≪");
	else printf("    ");
	printf("    	 	 ┃    \n");

	printf("    ┃                                                            ┃    \n");
	printf("    ┃                                                            ┃    \n");
	printf("    ┃                              끝내기  ");
	if (Select == 3) printf("   ≪");
	else printf("     ");
	printf("   확인 : Enter  ┃    \n");
	printf("    ┃                                                            ┃    \n");
	printf("    ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛   ");
}

void startPrint();

void nextStage1();

void nextStage2();

void nextStage3();

int main() {

	system("title 미로");

	removeCursor();

	FILE *onfile = fopen("MGS.GSV", "rb");

	int Choose = 0, reGame = 0;


	fscanf(onfile, "%d", &stage);
	fclose(onfile);

	gameMain();

	while (Choose != 13) {

		Choose = getch();

		switch (Choose) {

		case 72:
			if (Select > 1) { //올라가기
				CLEAR;
				Select--;
				gameMain();
			}
			break;
		case 80:
			if (Select < 3) { // 내려가기
				CLEAR;
				Select++;
				gameMain();
			}
			break;
		default:  
			break;
		}
	}

	if (Select == 1) { // 처음으로
		stage = 49;
	reset:
		nextStage1();
		onfile = fopen("MGS.GSV", "wb");
		nextStage2();
		fprintf(onfile, "%d", stage);
		fclose(onfile);
		onfile = fopen("MGS.GSV", "wb");
		nextStage3();
		fclose(onfile);
	}
	else if (Select == 2) {  // 계속
		CLEAR;
		if (onfile == NULL || feof(onfile) == EOF || stage == 0) {  // 파일이 없는 경우
			printf("저장된 파일이 없습니다.");
			Sleep(3000);
			CLEAR;
			printf("새로 시작 하시겠습니까? Y/N");
			while ((reGame != 89) && (reGame != 118) && (reGame != 78) && (reGame != 100)) {
				reGame = getch();

				switch (reGame)
				{
				case 89:        // Y
					goto reset;
				case 118:       // y
					goto reset;
				case 78:        // N
					exit(0);
				case 100:       // n
					exit(0);
				default:
					break;

				}
			}

		}
	}
	else if (Select == 3) {  // 끝내기 할 경우
		exit(0);
	}
	else {
		system("title ERROR");
		system("COLOR c");
		CLEAR;
		printf("ERROR");
		Sleep(4000);
		exit(0);
	} // 선택오류

	system("pause");

}

void startPrint() {
	int startGame = 0, starX, starY;

	Print;
	do {
		startGame = getch();

		switch (startGame) {
		case 72:
			GOUP;
			CLEAR;
			break;
		case 80:
			GODOWN;
			break;
		case 75:
			GOLEFT;
			break;
		case 77:
			GORIGHT;
			break;
		}
		
		for (int j = 0; j < 25; j++) {
			for (int i = 0; i < 79; i++) {
				if (gameBoradSetting.gameBorad[j][i] == 3) {
					starX = i;
					starY = j;
					CLEAR;
					Print;
					goto starend;
				}
				else if (gameBoradSetting.gameBorad[j][i] != 3) {
					starX = NULL;
					starY = NULL;
				}
			}
		}
		
	starend:
		if (starX == NULL) {
			CLEAR;
			PlaySound(TEXT("Victory.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			WIN;
			system("COLOR 7");
		}
		PlaySound(0, NULL, NULL);
	} while (starX != NULL);
}

void gameBoardClear() {
	for (int j = 0; j < 25; j++) {
		for (int i = 0; i < 79; i++)
			gameBoradSetting.gameBorad[j][i] = 0;
	}
}

void nextStage1() {
	CLEAR;
	printf("\n\n\n\n\n\n\n\n\n             ■■■      ■■■      ■        ■■■      ■■■     ■\n");
	printf("             ■            ■       ■■       ■          ■         ■\n");
	printf("             ■■■        ■      ■  ■      ■■■      ■■■     ■\n");
	printf("                 ■        ■     ■■■■     ■  ■      ■         ■\n");
	printf("             ■■■        ■    ■      ■    ■■■      ■■■     ■\n");
	Sleep(3000);
	gameBoardClear();
	GAME_STAGE1;
	CLEAR;
	startPrint();
}

void nextStage2() {
	
	CLEAR;
	printf("\n\n\n\n\n\n\n\n\n             ■■■      ■■■      ■        ■■■      ■■■     ■■■\n");
	printf("             ■            ■       ■■       ■          ■             ■\n");
	printf("             ■■■        ■      ■  ■      ■■■      ■■■     ■■■\n");
	printf("                 ■        ■     ■■■■     ■  ■      ■         ■\n");
	printf("             ■■■        ■    ■      ■    ■■■      ■■■     ■■■\n");
	Sleep(3000);
	gameBoardClear();
	GAME_STAGE2;
	stage++;
	CLEAR;
	startPrint();
}

void nextStage3() {
	CLEAR;
	printf("\n\n\n\n\n\n\n\n\n             ■■■      ■■■      ■        ■■■      ■■■     ■■■\n");
	printf("             ■            ■       ■■       ■          ■             ■\n");
	printf("             ■■■        ■      ■  ■      ■■■      ■■■     ■■■\n");
	printf("                 ■        ■     ■■■■     ■  ■      ■             ■\n");
	printf("             ■■■        ■    ■      ■    ■■■      ■■■     ■■■\n");
	Sleep(3000);
	gameBoardClear();
	GAME_STAGE3;
	stage++;
	CLEAR;
	startPrint();
}
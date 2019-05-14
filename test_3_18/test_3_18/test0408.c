#define _CRT_SECURE_NO_WARNINGS 1

#include<time.h>
#include"game.h"

void menu()
{
	printf("------------------------------------------\n");
	printf("----------  欢迎来到三子棋游戏   ---------\n");
	printf("----------      1.play           ---------\n");
	printf("----------      0.exit           ---------\n");
	printf("------------------------------------------\n");
}
void game()
{
	char board[ROW][COL] = { 0 };
	char ret = 0;
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		PlayMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C')
			break;
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else if (ret == 'Q')
	{
		printf("平局\n");
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (0);
	system("pause");
	return 0;
}

#include<stdio.h>
#include <stdlib.h>

int drink_soda(int money){
	int start = money;
	int num = money;
	while (start>1){
		num = num + start / 2;
		start = start / 2 + start % 2;
	}
	return num;
}
int main(){
	int money = 20;
	int num = 0;
	num = drink_soda(money);
	printf("%d\n", num);
	system("pause");
	return 0;
}
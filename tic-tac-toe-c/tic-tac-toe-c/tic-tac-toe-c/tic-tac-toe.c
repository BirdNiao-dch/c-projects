//一、游戏规则:
//3×3 的格子棋盘
//两个玩家:玩家1用 X, 玩家2用 Y, 轮流下
//谁先让横着、竖着、或斜着三个自己的符号连成一线, 谁就赢
//9 个格子下满还没人赢, 就是平局

//二、返回值设定:
//	0:还没结束，继续游戏
//	1:X赢
//	2:Y赢
//	3:平局

#include<stdio.h>
//先初始化棋盘，将棋盘的元素全部设为空格
void initBoard(char board[3][3]) {
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			board[i][j] = ' ';
		}
	}
}
//打印棋盘
void printBoard(char board[3][3]) {
	printf("    0   1   2\n");
	for (int i = 0;i < 3;i++) {
		printf("%d ", i);
		for (int j = 0;j < 3;j++) {
			printf("%c ", board[i][j]);
			if (j < 2)
				printf("|");
		}
		printf("\n");
		if (i < 2)
			printf(" ---+---+---\n");
	}

}
//判断输赢：
int checkWin(char board[3][3]) {
	//判断行
	for (int i = 0;i < 3;i++) {
		if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) { //第i行的数都相等且都不为空格(第一个条件是为了防止三个都是空格相等的情况)
			return board[i][0] == 'X' ? 1 : 2; //如果一行都是X，就返回1，否则返回2
		}
	}
	//判断列
	for (int j = 0;j < 3;j++) {
		if (board[0][j] != ' ' && board[0][j] == board[1][j] &&board[1][j] == board[2][j]) {
			return board[0][j] == 'X' ? 1 : 2;
		}
	}
	//判断两条对角线
	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		return board[0][0] == 'X' ? 1 : 2;
	}
	if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		return board[0][2] == 'X' ? 1 : 2;
	}
	//走到这说明没人赢，先看看有没有空格
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (board[i][j] == ' ') {
				return 0;
			}
		}
	}
	//走到这说明棋盘满了，平局
	return 3;
}

void playerMove(char board[3][3], char who) {
	int r, c;
	while (1) {
		printf("玩家 %c 下棋，请输入 行 列(0-2,如 1 2 ):",who);
		scanf("%d %d", &r, &c);
		if (r < 0 || r>2 || c < 0 || c>2) {
			printf("应在0-2之间，请重新输入\n");
			continue;
		}
		if (board[r][c] != ' ') {
			printf("该位置已有棋子，请重新输入\n");
			continue;
		}
		board[r][c] = who;
		break;
	}
}
//初始化棋盘→无限循环{显示→落子→判断胜负→没结束就换人}→显示结果→退出
int main(void) {
	char board[3][3];
	initBoard(board);

	char current = 'X';//当前玩家
	int result = 0;

	while (1) {
		//要改的传地址，只读的传副本。落子就必须改地址
		printBoard(board);//打印当前局势
		playerMove(board, current);

		result = checkWin(board);
		if (result != 0) {
			break;//分出胜负就跳出循环，否则继续
		}
		current = (current == 'X') ? 'Y' : 'X';//换人
	}
	printBoard(board);//打印最终棋盘
	if (result == 3) {
		printf("平局\n");
	}
	else {
		printf("玩家 %c 获胜!\n", result == 1 ? 'X' : 'Y');
	return 0;
}

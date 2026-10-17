#include<stdio.h>
void initBoard(char board[3][3]) {
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			board[i][j] = ' ';
		}
	}
}
void printBoard(char board[3][3]) {
	printf("   0   1   2\n");
	for (int i = 0;i < 3;i++) {
		printf("%d ", i);
		for (int j = 0;j < 3;j++) {
			printf("%c ", board[i][j]);
			if (j < 2)
				printf("|");
		}
		printf("\n");
		if (i < 2)
			printf("   ---+---+---\n");
	}
}
int checkWin(char board[3][3]) {
	//用for循环可以遍历每一行
	for (int i = 0;i < 3;i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
			return board[i][0] == 'X' ? 1 : 2;//这行的意思是问:"这个格子里的字符是 X 吗？"，得到是或不是 三目运算符 ?: 再根据这个答案决定返回1还是2
		}
	}
	for (int j = 0;j < 3;j++) {
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
			return board[0][j] == 'X' ? 1 : 2;
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
		return board[0][0] == 'X' ? 1 : 2;
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ') {
		return board[2][0] == 'X' ? 1 : 2;
	}
	//遍历整个数组如果有空的格子就返回0，之后在主函数中再写一句表达式使游戏继续进行
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (board[i][j] == ' ')
				return 0;
		}
	}
	//以上情况都不符合，平局
	return 3;
}
void playerMove(char board[3][3], char who) {
	int r, c;
	while (1) {
		printf("请玩家 %c 下棋：", who);
		scanf("%d %d", &r, &c);
		if (r < 0 || r>2 || c < 0 || c>2) {
			printf("请重新输入:");
			continue;
		}
		if (board[r][c] != ' ') {
			printf("该位置已有棋子，请重新输入:");
			continue;
		}
		board[r][c] = who;
		break;
	}
}
int main() {
	char board[3][3];
	initBoard(board);

	char current = 'X';
	int result = 0;

	while (1) {
		printBoard(board);
		playerMove(board, current);
		result = checkWin(board);
		if (result != 0) {
			break;
		}
		current = (current == 'X') ? 'O' : 'X';

	}
	printBoard(board);
	if (result == 1)
		printf("玩家X获胜");
	else if (result == 2)
		printf("玩家O获胜");
	else
		printf("平局");
	return 0;
}
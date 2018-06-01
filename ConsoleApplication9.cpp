// ConsoleApplication9.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "stdio.h"

int igo[3][3] = { { 0,0,0 },
{ 0, 0, 0},
{ 0, 0, 0} };

/*置く場所を選ぶ*/
void choise(int count) {

	int a = 0;
	int b = 0;

	do {
		printf("縦を選んでください\n");
		printf("上：0\t真ん中：1\t下：2\n");
		scanf_s("%d\n", &a);
		printf("%d", a);

		printf("横を選んでください\n");
		printf("左：0\t真ん中：1\t右：2\n");
		scanf_s("%d\n", &b);

	} while (igo[a][b] != 0);

	if (count == 1) {
		igo[a][b] = 1;
	}
	else {
		igo[a][b] = 2;
	}
	
}


/*勝敗判定をする*/
int judge() {
	/*たて*/
	int winner = 0;

	if ((igo[0][0] == igo[0][1])&& (igo[0][1] == igo[0][2])) {
		winner = igo[0][0];
	}
	else if ((igo[1][0] == igo[1][1])&&(igo[1][1] == igo[1][2])) {
		winner = igo[1][0];
	}
	else if ((igo[2][0] == igo[2][1])&&(igo[2][1] == igo[2][2])) {
		winner = igo[2][0];
	}

	/*よこ*/
	else if ((igo[0][0] == igo[1][0])&&(igo[1][0] == igo[2][0])) {
		winner = igo[0][0];
	}
	else if ((igo[0][1] == igo[1][1])&&(igo[1][1] == igo[2][1])) {
		winner = igo[0][1];
	}
	else if ((igo[0][2] == igo[1][2])&&(igo[1][2] == igo[2][2])) {
		winner = igo[0][2];
	}

	/*ななめ*/
	else if ((igo[0][0] == igo[1][1])&&(igo[1][1] == igo[2][2])) {
		winner = igo[0][0];
	}
	else if ((igo[2][0] == igo[1][1]) && (igo[1][1] == igo[0][2])) {
		winner = igo[2][0];
	}
	
	return winner;
}

/*碁盤の状況を出力*/
void output() {
	int a, b;

	for (a = 0; a < 3; a++) {
		for (b = 0; b < 3; b++) {
			printf("%d", igo[a][b]);
		}
		printf("\n");
	}
	
}



int main()
{
	int i = 1; //今何回目かカウントする変数

	output(); //一番最初の状態を出力

	for (i = 1; i <= 9; i++) {
		int count = i % 2;

		printf("%d回目\n", i);
		choise(count);
		output();
			
		/*勝敗判定：最短5回目で勝てるため(i >= 5)*/
		if (i >= 5) {
			int winner = judge();
			
			switch (winner) {
			case1:printf("player%dの勝ち",winner);
				break;
			case2:printf("player%dの勝ち",winner);
				break;
			default:
				break;
			}
		}
	}
	
    return 0;
}


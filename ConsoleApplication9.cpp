// ConsoleApplication9.cpp : �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "stdio.h"

int igo[3][3] = { { 0,0,0 },
{ 0, 0, 0},
{ 0, 0, 0} };

/*�u���ꏊ��I��*/
void choise(int count) {

	int a = 0;
	int b = 0;

	do {
		printf("�c��I��ł�������\n");
		printf("��F0\t�^�񒆁F1\t���F2\n");
		scanf_s("%d\n", &a);
		printf("%d", a);

		printf("����I��ł�������\n");
		printf("���F0\t�^�񒆁F1\t�E�F2\n");
		scanf_s("%d\n", &b);

	} while (igo[a][b] != 0);

	if (count == 1) {
		igo[a][b] = 1;
	}
	else {
		igo[a][b] = 2;
	}
	
}


/*���s���������*/
int judge() {
	/*����*/
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

	/*�悱*/
	else if ((igo[0][0] == igo[1][0])&&(igo[1][0] == igo[2][0])) {
		winner = igo[0][0];
	}
	else if ((igo[0][1] == igo[1][1])&&(igo[1][1] == igo[2][1])) {
		winner = igo[0][1];
	}
	else if ((igo[0][2] == igo[1][2])&&(igo[1][2] == igo[2][2])) {
		winner = igo[0][2];
	}

	/*�ȂȂ�*/
	else if ((igo[0][0] == igo[1][1])&&(igo[1][1] == igo[2][2])) {
		winner = igo[0][0];
	}
	else if ((igo[2][0] == igo[1][1]) && (igo[1][1] == igo[0][2])) {
		winner = igo[2][0];
	}
	
	return winner;
}

/*��Ղ̏󋵂��o��*/
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
	int i = 1; //������ڂ��J�E���g����ϐ�

	output(); //��ԍŏ��̏�Ԃ��o��

	for (i = 1; i <= 9; i++) {
		int count = i % 2;

		printf("%d���\n", i);
		choise(count);
		output();
			
		/*���s����F�ŒZ5��ڂŏ��Ă邽��(i >= 5)*/
		if (i >= 5) {
			int winner = judge();
			
			switch (winner) {
			case1:printf("player%d�̏���",winner);
				break;
			case2:printf("player%d�̏���",winner);
				break;
			default:
				break;
			}
		}
	}
	
    return 0;
}


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
	int win = 0;

	if ((igo[0][0] == igo[0][1])&& (igo[0][1] == igo[0][2])) {
		win = 1;
	}
	else if ((igo[1][0] == igo[1][1])&&(igo[1][1] == igo[1][2])) {
		win = 1;
	}
	else if ((igo[2][0] == igo[2][1])&&(igo[2][1] == igo[2][2])) {
		win = 1;
	}

	/*�悱*/
	else if ((igo[0][0] == igo[1][0])&&(igo[1][0] == igo[2][0])) {
		win = 1;
	}
	else if ((igo[0][1] == igo[1][1])&&(igo[1][1] == igo[2][1])) {
		win = 1;
	}
	else if ((igo[0][2] == igo[1][2])&&(igo[1][2] == igo[2][2])) {
		win = 1;
	}

	/*�ȂȂ�*/
	else if ((igo[0][0] == igo[1][1])&&(igo[1][1] == igo[2][2])) {
		win = 1;
	}
	else if ((igo[2][0] == igo[1][1])&&(igo[1][1] == igo[0][2])) {
		win = 1;
	}
	
	return win;
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
		int win = 0;

		/*��U*/
		if (count == 1) {
			printf("%d���\n", i);
			choise(count);
			output();
			
			/*���s����F�ŒZ5��ڂŏ��Ă邽��(i >= 5)*/
			if (i >= 5) {
				judge();
				if (judge() == 1) {
					printf("player 1�̏���!");
					break;
				}
			}
		}

		/*��U*/
		else {
			printf("%d���\n", i);
			choise(count);
			output();

			/*���s����F�ŒZ6��ڂŏ��Ă邽��(i >= 6)*/
			if (i >= 6) {
				judge();
				if (judge() == 1) {
					printf("player 2�̏���!");
					break;
				}
			}
		}
	}
	
    return 0;
}


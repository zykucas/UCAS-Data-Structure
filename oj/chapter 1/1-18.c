#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Grade
{
	char program;
	char gender;
	char school;
	int point;
};

int main() {
	int grade[5][3] = { 0 };
	struct Grade grd[30];
	char ch, c1, c2, c3, c4, chr1, chr2;
	int dt;
	int i = 0;
	while ((ch = getchar()) != EOF)
	{
		scanf("%c%c%c%c%c%d%c", &c1, &chr1, &c2, &chr2, &c3, &dt, &c4);
		grd[i].program = ch;
		grd[i].gender = chr1;
		grd[i].school = chr2;
		grd[i].point = dt;
		i++;
	}

	for (int j = 0; j < i; j++)
	{
		grade[grd[j].school - 'A'][2] += grd[j].point;
		if (grd[j].gender == 'M')
		{
			grade[grd[j].school - 'A'][0] += grd[j].point;
		}
		else
		{
			grade[grd[j].school - 'A'][1] += grd[j].point;
		}
	}

	int flag = 0;
	for (int j = 0; j < 5; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (grade[j][k] != 0)
			{
				flag++;
			}
		}
	}

	i = 1;

	for (int j = 0; j < 5; j++)
	{
		if (grade[j][0] != 0 && i != flag)
		{
			printf("%c %c %d\n", (char)('A' + j), 'M', grade[j][0]);
			i++;
		}
		else if (grade[j][0] != 0 && i == flag)
		{
			printf("%c %c %d", (char)('A' + j), 'M', grade[j][0]);
			i++;
		}

		if (grade[j][1] != 0 && i != flag)
		{
			printf("%c %c %d\n", (char)('A' + j), 'F', grade[j][1]);
			i++;
		}
		else if (grade[j][1] != 0 && i == flag)
		{
			printf("%c %c %d", (char)('A' + j), 'F', grade[j][1]);
			i++;
		}

		if (grade[j][2] != 0 && i != flag)
		{
			printf("%c %d\n", (char)('A' + j), grade[j][2]);
			i++;
		}
		else if (grade[j][2] != 0 && i == flag)
		{
			printf("%c %d", (char)('A' + j), grade[j][2]);
			i++;
		}
	}

	return 0;
}

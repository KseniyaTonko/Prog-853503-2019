/*
Air Comfort. �������� ���������� ���������� �������������; �����������, ��� ����� �������� ����� ��������
������������ ������ �������������� � ���������� ��������� ��������� ������������� ����� � ���������.
����� ���-�� ���� � ��������.
����� ���-�� ��������.
����� �����, �� ������� ��������� ��������.
������� � ����� ���������� �������: ����� ������� �����������, ��������� ����������� ����, ��������� ���������
��������� �����, ���������� ��������.
������ ����� ��������� �������.
�������� ���������� � �������� � ��������.
������ �� ���������.

��������� ������������ �������� ������ (2,15*1,50 �) = $100, ������� ���������.
��������� ��������� ����� (0,70*2,15 �) = $150, ������� ���������.
���� �������� ��������� ���� ������� �����, �� ��������� ������� ������������ ��������� ������������� 15% ��� ���������.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>


void printInf();
void WhatAction(const char *, int, const char *);
void PrintCosts(double, double, double, double, double, bool);
int GetNumber();

int main()
{
	setlocale(LC_ALL, "Rus");
	int windowNum, balconyNum, floor;
	double totalCost, area, windowCost, balconyCost, percent;
	bool wantToContinue = true;
	while (wantToContinue)				//���� ������������ ����� ���������� ������ � ���������
	{
		system("cls");
		totalCost = 0;
		area = 0;
		percent = 0;
		WhatAction("1.��������� ������ � ���������.\n2.���� ���������� ���� � ��������.\n", 2, "������� ���������� ���� � ��������: ");
		windowNum = GetNumber();		//���� ���������� ����
		area += 2.15*1.5*windowNum;		//���������� � ����� ������� ����������� ������� ����
		windowCost = windowNum * 100;	//������ ��������� ����������� ����
		WhatAction("1.��������� ������ � ���������.\n2.���� ���������� �������� � ��������.\n", 2, "������� ���������� �������� � ��������: ");
		balconyNum = GetNumber();		//���� ���-�� ��������
		area += 0.7*2.15*balconyNum;	//���������� � ����� ������� ����������� ������� ��������� �����
		balconyCost = balconyNum * 150;	//������ ��������� ����������� ��������
		WhatAction("1.��������� ������ � ���������.\n2.���� ������ �����.\n", 2, "������� ����� �����, �� ������� ��������� ��������: ");
		floor = GetNumber();			//���� ������ �����
		if (floor > 1)
			percent += 0.15*(windowNum * 100 + balconyNum * 150);		//���� ���� > �������, ������������� ��������
		totalCost = windowCost + balconyCost + percent;					//������ ����� ��������� �������
		PrintCosts(area, windowCost, balconyCost, percent, totalCost, wantToContinue);	//����� ����������� ����������
		wantToContinue = true;
	}
}

int GetNumber()
{
	int number = 0;
	char temp;
	while (scanf_s("%c", &temp))			//����������� ������ �������� �����
	{
		if (temp == '\n')					//���� ������ �����������, ������� ���������� �����
			return number;
		if ((temp < '0') || (temp > '9'))	//���� ����������� �� �����, �������� �� ������ � ��������� ����� ��� ���
		{
			while (temp != '\n')
				temp = getchar();
			printf_s("%s", "�������� ����. ���������� �����...\n");
			number = 0;
		}
		else
			number = number * 10 + (temp - '0');
	}
}

void printInf()
{
	system("cls");
	//����� ���������� � ��������
	printf_s("%s", "�������� Air Comfort. ��������� �������������.\n");
	printf_s("%s", "��������� ������������ �������� ������ (2,15*1,50 �) = $100, ������� ���������.\n");
	printf_s("%s", "��������� ��������� ����� (0,70*2,15 �) = $150, ������� ���������.\n");
	printf_s("%s", "���� �������� ��������� ���� ������� �����, �� ��������� �������\n");
	printf_s("%s", "������������ ��������� ������������� 15 % ��� ���������.\n");
	printf_s("%s", "������� �� ��������: +375-44-666-66-66\n");
}

void WhatAction(const char *str, int maxNum, const char *whatWillEnter)
{
	system("cls");
	printf_s("%s", "����� ��������:\n");
	printf_s("%s", str);
	int number = GetNumber();
	while ((number < 1) || (number > maxNum))				//��������, ������� �� ���������� �����
	{
		printf_s("%s", "�������� ����. ���������� �����...\n");
		number = GetNumber();
	}
	if (number == 1)
		exit(0);
	else
		printf_s("%s", whatWillEnter);
}

void PrintCosts(double area, double windowCost, double balconyCost, double percent, double totalCost, bool wantToContinue)
{
	system("cls");
	printf_s("%s", "����� ��������:\n1.��������� ������ � ���������.\n");
	printf_s("%s", "2.����� ������� �����������.\n");
	printf_s("%s", "3.��������� ����������� ����.\n");
	printf_s("%s", "4.��������� ��������� ����������� ������.\n");
	printf_s("%s", "5.���������� ��������.\n");
	printf_s("%s", "6.����� ��������� �������.\n");
	printf_s("%s", "7.������� ���������� � �������� � ��������.\n");
	printf_s("%s", "8.��������� ��������� ������� ��� ����� ��������.\n\n");
	int number = GetNumber();				//����� ��������
	while ((number < 1) || (number > 8))	//���� ������� �����, �� �������� � �������� �� 1 �� 8, ��������� ��������� ����
	{
		printf_s("%s", "�������� ����. ���������� �����...\n");
		number = GetNumber();
	}
	switch (number)							//�������� � ������������ � ��������� ���������
	{
	case(1):
		exit(0);
		break;
	case(2):
		printf_s("%s%f", "����� ������� ����������� = ", area);
		break;
	case(3):
		printf_s("%s%f", "��������� ����������� ���� = ", windowCost);
		break;
	case(4):
		printf_s("%s%f", "��������� ��������� ��������� ������ = ", balconyCost);
		break;
	case(5):
		printf_s("%s%f", "���������� �������� = ", percent);
		break;
	case(6):
		printf_s("%s%f", "����� ��������� ������� = ", totalCost);
		break;
	case(7):
		printInf();
		break;
	case(8):
		wantToContinue = false;
	}
	if (wantToContinue)		//���� ������������ ����� �������� ������ � �������, ������ ������� �������
	{
		getch();
		PrintCosts(area, windowCost, balconyCost, percent, totalCost, wantToContinue);
	}
}
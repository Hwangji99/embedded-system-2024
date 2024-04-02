/*
       File: linkedList ����2

         24-03-27

       Author: Ȳ��ȯ
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "proheader.h"

int main()
{
    int num;
    int id;
    char title[30];
    char author[10];
    char publisher[50];
    char renter[10];
    int year;

    // �޴��� �ݺ��Ͽ� ����ϰ� ������� ���ÿ� ���� ���� ����
    while (true) {
        showmenu();
        printf("�޴��� �����Ͻÿ�: ");
        scanf("%d", &num);

        switch (num) {
        case 1:
            addbook();
            printf("\n");
            break;
        case 2:
            //printf("�˻��� ������ ������ �Է��ϼ���: ");
            //scanf("%s", title);
            searbook(title);
            printf("\n");
            break;
        case 3:
            printf("������ ������ ������ �Է��ϼ���: ");
            scanf("%s", title);
            delbook(title);
            printf("\n");
            break;
        case 4:
            view();
            printf("\n");
            break;
        case 5:
            printf("������ �뿩�� ������ ��ȣ�� �Է��ϼ���: ");
            scanf("%d", &id);
            printf("�뿩�� ����: ");
            scanf("%s", renter);
            rentedBook(id);
            printf("\n");
            break;
        case 6:
            printf("������ �ݳ��� ������ ��ȣ�� �Է��ϼ���: ");
            scanf("%d", &id);
            returnBook(id);
            printf("\n");
            break;
        case 0:
            printf("���α׷��� �����մϴ�.\n");
            exit(0);
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n");
        }
    }

    return 0;
}

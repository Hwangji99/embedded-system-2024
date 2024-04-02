/*
       File: linkedList ����2

         24-03-27

       Author: Ȳ��ȯ
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "proheader.h"

Book* head = NULL;

void addbook()//char* tt, char* aa, char* publisher, int dd)
{
    Book* newBook = (Book*)malloc(sizeof(Book)); // ���ο� ������ ���� �޸� �Ҵ�

    printf("*************\n");

    // ���� ���� �Է� �ޱ�
    printf("���� ����: ");
    scanf("%s", newBook->title);
    printf("���� ��ȣ: ");
    scanf("%d", &newBook->id);
    printf("����: ");
    scanf("%s", newBook->author);
    printf("���ǻ�: ");
    scanf("%s", newBook->publisher);
    printf("���ǳ⵵: ");
    scanf("%d", &newBook->year);    // ������ ������ ���� ���� &�� �ٿ��� �Ѵ�

    newBook->next = NULL; // ���ο� ������ ���� ���� �����͸� �ʱ�ȭ

    if (head == NULL) {
        // ���� �������� ����ִٸ� ���ο� ������ ù ��° ������ ����
        head = newBook;
    }
    else {
        // �������� �̹� ������ �ִ� ���, ���� ����Ʈ�� ���� ���ο� ������ �߰�
        Book* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newBook;
    }

    printf("������ ��ϵǾ����ϴ�.\n");
}

void showmenu()
{
    printf("**** �޴� ****\n");
    printf("1. ��������(���)\n");
    printf("2. �����˻�\n");
    printf("3. ��������\n");
    printf("4. �������\n");
    printf("5. �����뿩\n");
    printf("6. �����ݳ�\n");
    printf("0. ����\n");
    printf("**************\n");
}

void searbook()
{
    // ������ �ϳ��� ��ϵ��� �ʾ��� ��� ó��
    if (head == NULL) {
        printf("��ϵ� ������ �����ϴ�.\n");
        return;
    }

    int choice, num;
    int result = 0;
    char keyword[50];
    printf("�˻��� ������ �����ϼ���:\n");
    printf("1. ����\n");
    printf("2. ���� ��ȣ\n");
    printf("3. ����\n");
    printf("4. ���ǻ�\n");
    printf("5. ���ǳ⵵\n");
    printf("��ȣ�� �Է��ϼ���: ");
    scanf("%d", &choice);

    if (choice == 1 || choice == 3 || choice == 4) {
        printf("�˻�� �Է��ϼ���: ");
        scanf("%s", keyword);
    }
    else if (choice == 2 || choice == 5) {
        printf("�˻�� �Է��ϼ���: ");
        scanf("%d", &num);
    }

    Book* current = head;
    bool found = false;

    while (current != NULL) {
        switch (choice) {
        case 1: // �������� �˻�
            if (strcmp(current->title, keyword) == 0) {
                found = true;
            }
            break;
        case 2: // ���� ��ȣ�� �˻�
            if (current->id == num) { // ���ڿ��� ������ ��ȯ�Ͽ� ��
                found = true;
            }
            break;
        case 3: // ���ڷ� �˻�
            if (strcmp(current->author, keyword) == 0) {
                found = true;
            }
            break;
        case 4: // ���ǻ�� �˻�
            if (strcmp(current->publisher, keyword) == 0) {
                found = true;
            }
            break;
        case 5: // ���ǳ⵵�� �˻�
            if (current->year == num) { // ���ڿ��� ������ ��ȯ�Ͽ� ��
                found = true;
            }
            break;
        default:
            printf("�߸��� �����Դϴ�.\n");
            return;
        }

        // �˻���� ��ġ�ϴ� ������ ã�� ��� �ش� ���� ���� ���
        if (found) {
            printf("������ �����մϴ�.  ");
            printf("���� ����: %s  ", current->title);
            printf("����: %s  ", current->author);
            printf("���ǻ�: %s  ", current->publisher);
            printf("���ǳ⵵: %d\n", current->year);
            found = false;
            result++;
        }

        current = current->next;
    }

    // ������ ã�� ���� ��� �޽��� ���
    if (result == 0) {
        printf("������ �������� �ʽ��ϴ�.\n");
    }
}

void delbook(char* title)
{
    if (head == NULL) {
        printf("��ϵ� ������ �����ϴ�.\n");
        return;
    }

    Book* current = head;
    Book* prev = NULL;

    // ������ ������ ã��
    while (current != NULL) {
        if (strcmp(current->title, title) == 0)
        {
            // ������ ������ ã��
            if (prev == NULL)
            {
                // ������ ������ ù ��° ������ ���
                head = current->next;
            }
            else
            {
                // ������ ������ �߰��̳� �������� �ִ� ���
                prev->next = current->next;
            }
        }
        // �޸� ����
        free(current);
        printf("������ �����Ǿ����ϴ�.\n");
        return;
    }
}

void view()
{
    Book* current = head;

    if (current == NULL) {
        printf("��ϵ� ������ �����ϴ�.\n");
        return;
    }

    printf("��ϵ� ���� ���\n");

    while (current != NULL) {
        printf("���� ��ȣ: %d  ", current->id);
        printf("���� ����: %s  ", current->title);
        printf("����: %s  ", current->author);
        printf("���ǻ�: %s  ", current->publisher);
        printf("���ǳ⵵: %d  ", current->year);
        printf("\n");
        current = current->next;
    }
}


void rentedBook(int pid) {
    Book* current = head;

    while (current != NULL) {
        if (current->id == pid) {
            if (current->rented) {
                printf("�̹� �뿩�� �����Դϴ�.\n");
                return;
            }
            else {
                current->rented = true;
                printf("������ �뿩�Ǿ����ϴ�.\n");
                return;
            }
        }
        current = current->next;
    }

    printf("�ش� ������ ã�� �� �����ϴ�.\n");
}

void returnBook(int pid) {
    Book* current = head;

    while (current != NULL) {
        if (current->id == pid) {
            if (current->rented) {
                current->rented = false;
                printf("������ �ݳ��Ǿ����ϴ�.\n");
                return;
            }
            else {
                printf("�� ������ �̹� �ݳ��Ǿ����ϴ�.\n");
                return;
            }
        }
        current = current->next;
    }

    printf("�ش� ������ ã�� �� �����ϴ�.\n");
}

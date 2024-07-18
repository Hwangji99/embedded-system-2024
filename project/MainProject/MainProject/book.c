/*
       File: linkedList ����1

         24-03-27

       Author: Ȳ��ȯ
*/

/* ���� ����Ʈ �ڷᱸ���� �������� ���α׷��� �ۼ��Ͻÿ� */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct Book {
    int id;
    char title[30];
    char author[10];
    char publisher[50];
    int year;
    struct Book* next;      // ���� ������ ����Ű�� ������
}  Book;

//Book *library = NULL; // �������� �������� ���ΰ� �ٸ� �Լ��� ��� ��� ����
Book* head = NULL;

void addbook();

void searbook();

void delbook();

void view();

void showmenu();

int main()
{
    // Book *library = NULL; // ������ �ʱ�ȭ
    int num;
    int id;
    char title[30];
    char author[10];
    char publisher[50];
    int year;

    // �޴��� �ݺ��Ͽ� ����ϰ� ������� ���ÿ� ���� ���� ����
    while (true) {
        showmenu();
        printf("�޴��� �����Ͻÿ�: ");
        scanf("%d", &num);

        switch (num) {
        case 1:
            //printf("���� ������ �Է��ϼ���: ");
            //scanf("%s", title);
            //printf("���� ID�� �Է��ϼ���: ");
            //scanf("%d", &id);
            addbook();
            printf("\n");
            break;
        case 2:
            //printf("�˻��� ������ ������ �Է��ϼ���: ");
            //scanf("%s", title);
            searbook();
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
        case 0:
            printf("���α׷��� �����մϴ�.\n");
            exit(0);
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n");
        }
    }

    return 0;
}

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
    int result = 0;      // �˻��� ����� ���� ��
    int choice, num;
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
        printf(" �˻�� �Է��ϼ���: ");
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
            if (current->id == num) {
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
            if (current->year == num) {
                found = true;
            }
            break;
        default:
            printf("�߸��� �����Դϴ�.\n");
            return;
        }

        // �˻���� ��ġ�ϴ� ������ ã�� ��� �ش� ���� ���� ���
        if (found) {
            printf("������ �����մϴ�.\n");
            printf("���� ����: %s\n", current->title);
            printf("����: %s\n", current->author);
            printf("���ǻ�: %s\n", current->publisher);
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

    // ������ ã�� ���� ��� �޽��� ���
    // printf("������ �������� �ʽ��ϴ�.\n");

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
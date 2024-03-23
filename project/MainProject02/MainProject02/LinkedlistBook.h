#ifndef __LINKED_LIST_BOOK_H__
#define __LINKED_LIST_BOOK_H__
#define DEBUG

#define FALSE 0
#define TRUE 1

typedef struct {
	char year;
	char month;
	char day;
}_stDate;

typedef struct _node {
	int price;
	int page;
	char title[30];
	char author[10];
	_stDate date;
	struct _node* prev;
	struct _node* next;
} NODE;

typedef struct {
	NODE* head;
	NODE* tail;
	NODE* curr;
	int numOfData;
} LIST;

typedef int (*_comp)(const void* arg1, const void* arg2);

void listInit(LIST* ptrlist);					// ����Ʈ �ʱ�ȭ			
void addNode(LIST* ptrlist, NODE* tempBook);	// ��� ����
int listCount(LIST* ptrlist);					// ��� ���� count
void deleteNode(LIST* ptrlist, int numToDelete);// Ư�� ��� �����
void delLastNode(LIST* ptrlist);				// ������ ������ ��� �����
void freeAllNode(LIST* ptrlist);				// ��� ��� �޸� �Ҵ� ����
void listSearch(LIST* ptrlist);					// ���ϴ� ��常 ã�� ���
void listPrint(LIST* ptrlist);					// ����Ʈ ��ü ���
void copyList(LIST* destination, LIST* source);	// ����Ʈ �����ϱ�
void putNPushNode(NODE* compNode, NODE* curr);	// Ư�� ��� ���ϴ� ��ġ�� �����ֱ�
//void swapNode(NODE* compNode, NODE* curr);	// ���� ���(�̻��)

void insertionSort(LIST* ptrlist, _comp criteria);
int compare_price(const NODE* arg1, const NODE* arg2);
int compare_page(const NODE* arg1, const NODE* arg2);
int compare_date(const NODE* arg1, const NODE* arg2);
int compare_title(const NODE* arg1, const NODE* arg2);
int compare_author(const NODE* arg1, const NODE* arg2);

void readFromFile(LIST* ptrlist);
void writeToFile(LIST* ptrlist);

int dispMenu(int numOfData);
void testAdd(LIST* ptrlist);
void listInsert(LIST* ptrlist);
void deleteMenu(LIST* ptrlist);
void listSearchForDel(LIST* ptrlist, int* searchedNum);
void sortMenu(LIST* ptrlist);

#endif
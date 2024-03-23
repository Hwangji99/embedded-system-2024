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

void listInit(LIST* ptrlist);					// 리스트 초기화			
void addNode(LIST* ptrlist, NODE* tempBook);	// 노드 삽입
int listCount(LIST* ptrlist);					// 노드 개수 count
void deleteNode(LIST* ptrlist, int numToDelete);// 특정 노드 지우기
void delLastNode(LIST* ptrlist);				// 마지막 데이터 노드 지우기
void freeAllNode(LIST* ptrlist);				// 모든 노드 메모리 할당 해제
void listSearch(LIST* ptrlist);					// 원하는 노드만 찾아 출력
void listPrint(LIST* ptrlist);					// 리스트 전체 출력
void copyList(LIST* destination, LIST* source);	// 리스트 복사하기
void putNPushNode(NODE* compNode, NODE* curr);	// 특정 노드 원하는 위치에 끼워넣기
//void swapNode(NODE* compNode, NODE* curr);	// 스왑 노드(미사용)

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
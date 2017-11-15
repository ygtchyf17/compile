#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Stack
{
  char var[256];       //変数
  int address;         //アドレス
  int type;            //種類
  struct Stack *next;  //次のレコードへのポインタ
};

enum Type { GLOB, LOC, PROC };

struct Stack *list_ptr;


void printTable(struct Stack *rec);
void printAll();
struct Stack *lookup(char *name, int type);
void delete(int type);
void insert(char *name, int type);
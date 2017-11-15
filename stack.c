#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

struct Stack *list_ptr = NULL;

/*
struct Stack
{
  char var[256];       //変数
  int address;         //アドレス
  int type;            //種類
  struct Stack *next;  //次のレコードへのポインタ
};

enum Type { GLOB, LOC, PLOC };

complete ver.
*/
void printTable(struct Stack *rec)
{
    int mode = rec->type;

    if( rec != NULL ){
      switch(mode){
        case GLOB:
        printf("%s\t%d\tglob\n",rec->var,rec->address);
        break;

        case LOC:
        printf("%s\t%d\tloc\n",rec->var,rec->address);
        break;

        case PROC:
        printf("%s\t%d\tproc\n",rec->var,rec->address);
        break;
      }
    }
}

void printAll(){

  struct Stack *rec;

  rec = list_ptr;
  while(1){
    printTable( rec );
    if( rec->next == NULL )
      break;
    rec = rec->next;
  }
  printf("\n");
}

void insert(char *name, int type)
{
  struct Stack *new, *rec;
  static int address = 0; //仮のアドレス

  //構造体作成
  new = (struct Stack *)malloc(sizeof(struct Stack));
  new->next = NULL;

  //要素代入
  strcpy((new->var),name);
  new->type = type;
  new->address = address;

  if(list_ptr == NULL){        //最初の要素の時
    list_ptr = new;
  }
  else{                 //そうじゃないとき
    rec = list_ptr;
    while( rec->next != NULL ){
      rec = rec->next;
    }
    rec->next = new;
  }
  address++;  //先頭アドレスを更新
  printf("insert\n");
  printf("---------------------------------\n");

  printAll();

}

//変数を検索して、すでに登録してあればその構造体のアドレスを返す
struct Stack *lookup(char *name, int type)
{
  struct Stack *rec;

  rec = list_ptr;
  while(1){
    if(strcmp((rec->var),name) == 0 && type == (rec->type))
      break;

    //一致しない場合の処理がまだ
    rec = rec->next;
  }
  return rec;
}


void delete(int type)
{
  struct Stack *tmp, *rec;

  //いきなり削除対象
  if(((list_ptr)->type) == LOC){
    tmp = list_ptr;
    list_ptr = (list_ptr)->next;
    free(tmp);
  }

  rec = ((list_ptr))->next;
    tmp = list_ptr;
    while(rec != NULL){
      if(rec->type == LOC){
        //削除対象だった
        tmp->next = rec->next;
        //free(rec);
        return;
      }
      else{
      //削除対象でない
      tmp = rec;
      rec = rec->next;
      }
    }

    printf("delete\n");
    printf("---------------------------------\n");
    printAll(list_ptr);
}
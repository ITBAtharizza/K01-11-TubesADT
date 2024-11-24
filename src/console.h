#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include "boolean.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/list/list.h"
#include "ADT/listdin/listdin.h"
#include "ADT/queue/queue.h"
#include "ADT/custom/custom.h"
#include "game/tebakAngka.h"
#include "game/wordl3.h"

void Start(List *list_user, ListDin *list_barang, int *where);

//load
void Load(char *filename, List *list_user, ListDin *list_barang, int *where);

//register
void Register(List *list_user);

//login
void Login(List *list_user, User *logged_in, boolean *log_stats);

//work
//fungsi work

//work challenge
void WorkChallenge(User *logged_in);
//store list
void StoreList(ListDin list_barang);

//store request
void Request(Queue *antrian, ListDin *list_barang);

//store supply
void Supply(Queue *antrian, ListDin *list_barang);

//store remove
void Remove(ListDin *list_barang);

//save
void Save(char *filename, List *list_user, ListDin *list_barang);

//quit
void Quit(List *list_user, ListDin *list_barang, boolean *running);

//help
void Help(int where);

//fungsi-fungsi pembantu
//fungsi IsWordEqual
boolean IsWordEqual(Word word, char *reference);

//fungsi WordToInt
int WordToInt(Word word);

//fungsi GoodsWithManyWords
void GoodsWithManyWords(char *goods, int *length, Word word);

void CopyString(char *dest, char *src);

void DisplayUser(List list_user);

#endif
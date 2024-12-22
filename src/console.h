#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include "boolean.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/list/list.h"
#include "ADT/listdin/listdin.h"
#include "ADT/queue/queue.h"
#include "ADT/map/map.h"
#include "ADT/stack/stack.h"
#include "ADT/custom/custom.h"
#include "game/tebakAngka/tebakAngka.h"
#include "game/wordl3/wordl3.h"
#include "game/QuantumWordl3/QuantumWordl3.h"

//start
void Start(List *list_user, ListDin *list_barang, int *where);

//load
void Load(char *filename, List *list_user, ListDin *list_barang, int *where);

//register
void Register(List *list_user);

//login
void Login(List *list_user, User *logged_in, boolean *log_stats);

//work
void Work(User *user);

//work challenge
void WorkChallenge(User *logged_in);

//store
//store list
void StoreList(ListDin list_barang);

//store request
void Request(Queue *antrian, ListDin *list_barang);

//store supply
void Supply(Queue *antrian, ListDin *list_barang);

//store remove
void Remove(ListDin *list_barang);

// profile
void Profile (User *user);

//cart
//cart add
void CartAdd(ListDin *List_Items, Map *Cart);

//cart remove
void CartRemove(ListDin *List_Items, Map *Cart);

//cart show
void CartShow(Map Cart);

//cart pay
void CartPay(Map *Cart, User *user, Stack *history);

//wishlist
//wishlist add
void WishlistAdd(ListDin *list_barang, LinkedList *wishlist);

//wishlist swap i j
void WishlistSwap(LinkedList *wishlist);

//wishlist remove ke-i
void WishlistRemoveI(LinkedList *wishlist);

//wishlist remove
void WishlistRemove(LinkedList *wishlist);

//wishlist clear
void WishlistClear(LinkedList *wishlist);

//history
void ShowHistory(Stack *history, int line);

//logout
void Logout(List *list_user_session, User *logged_in, boolean *log_stats, int *where);

//save
void Save(List *list_user, List *list_user_session, ListDin *list_barang, ListDin *list_barang_session, User *logged_in);

//quit
void Quit(List *list_user, List *list_user_session, ListDin *list_barang, ListDin *list_barang_session, User *logged_in, boolean *running);

//help
void Help(int where);

//bonus
void Bioweapon(Queue *antrian, ListDin *list_barang);

//fungsi-fungsi pembantu
//fungsi IsWordEqual
boolean IsWordEqual(Word word, char *reference);

//fungsi WordToInt
int WordToInt(Word word);

//fungsi GoodsWithManyWords
void GoodsWithManyWords(char *goods, int *length, Word word);

//fungsi DisplayUser
void DisplayUser(List list_user);


//fungsi DNAToRNA
Word DNAToRNA(Word DNA);

//fungsi IsCode
boolean IsCode(Word RNA, Word Code);

//fungsi DecodingRNA
void Decoding(char *column, char *decoded, int index);

//fungsi mencari substring
boolean IsInString(Word *decoded, Word *code);

//fungsi DumpUser data saat work dan workchallenge
void ReverseDumpUser(List *list_user, List *list_user_session);
void DumpLoggedIn(List *list_user_session, User *logged_in);
void DumpUser(List *list_user_session, List *list_user);

void DumpBarang(ListDin *list_barang_session, ListDin *list_barang);

void ReverseDumpBarang(ListDin *list_barang, ListDin *list_barang_session);

Word MultiWordWord();

int Lexical(char *str1, char *str2);

#endif
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "console.h"

int main(){
    char loadfile[50];

    List list_user;
    List list_user_session;
    ListDin list_barang;
    ListDin list_barang_session;
    Queue antrian;
    User logged_in;
    boolean log_stats = false;
    boolean running = true;
    int where = 0;

    CreateQueue(&antrian);
    list_user = MakeList();
    list_user_session = MakeList();
    list_barang = MakeListDin();
    list_barang_session = MakeListDin();
    
    system("cls");
    while (running){
        printf(">> ");
        STARTWORD(NULL);
        printf("\n");

        if (where == 0){
            if (IsWordEqual(currentWord, "START")){
                Start(&list_user, &list_barang, &where);
                ReverseDumpBarang(&list_barang, &list_barang_session);
                ReverseDumpUser(&list_user, &list_user_session);
            }

            if (IsWordEqual(currentWord, "LOAD")){
                STARTWORD(NULL);
                CopyString(loadfile, currentWord.TabWord);
                Load(loadfile, &list_user, &list_barang, &where);
                ReverseDumpBarang(&list_barang, &list_barang_session);
                ReverseDumpUser(&list_user, &list_user_session);
            }

            if (IsWordEqual(currentWord, "QUIT")){
                Quit(&list_user, &list_user_session, &list_barang, &list_barang_session, &logged_in, &running);
            }

            if (IsWordEqual(currentWord, "HELP")){
                Help(where);
            }
        }

        if (where == 1){
            if (IsWordEqual(currentWord, "REGISTER")){
                Register(&list_user_session);
            }
            
            if (IsWordEqual(currentWord, "LOGIN")){
                Login(&list_user_session, &logged_in, &log_stats);
                if (log_stats){
                    where = 2;
                }
            }

            if (IsWordEqual(currentWord, "QUIT")){
                Quit(&list_user, &list_user_session, &list_barang, &list_barang_session, &logged_in, &running);
            }

            if (IsWordEqual(currentWord, "HELP")){
                Help(where);
            }
        }

        if (where == 2){
            if (IsWordEqual(currentWord, "WORK")){
                if (isEndWord()){
                    Work(&logged_in);
                }
                else{
                    STARTWORD(NULL);
                    if (IsWordEqual(currentWord, "CHALLENGE")){
                        WorkChallenge(&logged_in);
                    }
                }
            }

            if (IsWordEqual(currentWord, "STORE")){
                STARTWORD(NULL);
                if (IsWordEqual(currentWord, "LIST")){
                    StoreList(list_barang_session);
                }
                if (IsWordEqual(currentWord, "REQUEST")){
                    if (isEndWord()){
                        Request(&antrian, &list_barang_session);
                    }
                    else{
                        STARTWORD(NULL);
                        if (IsWordEqual(currentWord, "BIOWEAPON")){
                            Bioweapon(&antrian, &list_barang_session);
                        }
                    }
                }
                if (IsWordEqual(currentWord, "SUPPLY")){
                    Supply(&antrian, &list_barang_session);
                }
                if (IsWordEqual(currentWord, "REMOVE")){
                    Remove(&list_barang_session);
                }
            }

            if (IsWordEqual(currentWord, "PROFILE")){
                Profile(&logged_in);
            }

            if (IsWordEqual(currentWord, "CART")){
                STARTWORD(NULL);
                if (IsWordEqual(currentWord, "ADD")){
                    CartAdd(&list_barang_session, &logged_in.keranjang);
                }
                if (IsWordEqual(currentWord, "REMOVE")){
                    CartRemove(&list_barang_session, &logged_in.keranjang);
                }
                if (IsWordEqual(currentWord, "SHOW")){
                    CartShow(logged_in.keranjang);
                }
                if (IsWordEqual(currentWord, "PAY")){
                    CartPay(&logged_in.keranjang, &logged_in, &logged_in.riwayat_pembelian);
                }
            }

            if (IsWordEqual(currentWord, "HISTORY")){
                STARTWORD(NULL);
                int line = WordToInt(currentWord);
                if (line < 0){
                    printf("Input tidak valid, kembali ke menu utama!\n\n");
                }
                ShowHistory(&logged_in.riwayat_pembelian, line);
            }

            if (IsWordEqual(currentWord, "WISHLIST")){
                STARTWORD(NULL);
                if (IsWordEqual(currentWord, "ADD")){
                    WishlistAdd(&list_barang, &logged_in.wishlist);
                }
                if (IsWordEqual(currentWord, "SWAP")){
                    WishlistSwap(&logged_in.wishlist);
                }
                if (IsWordEqual(currentWord, "REMOVE")){
                    if (isEndWord()){
                        WishlistRemove(&logged_in.wishlist);
                    }
                    else{
                        WishlistRemoveI(&logged_in.wishlist);
                    }
                }
                if (IsWordEqual(currentWord, "CLEAR")){
                    WishlistClear(&logged_in.wishlist);
                }
                if (IsWordEqual(currentWord, "SHOW")){
                    PrintInfoLinkedList(logged_in.wishlist);
                }
            }

            if (IsWordEqual(currentWord, "LOGOUT")){
                Logout(&list_user_session, &logged_in, &log_stats, &where);
            }

            if (IsWordEqual(currentWord, "SAVE")){
                Save(&list_user, &list_user_session, &list_barang, &list_barang_session, &logged_in);
            }

            if (IsWordEqual(currentWord, "QUIT")){
                Quit(&list_user, &list_user_session, &list_barang, &list_barang_session, &logged_in, &running);
            }
            
            if (IsWordEqual(currentWord, "HELP")){
                Help(where);
            }
        }
    }
}

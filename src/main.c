#include <stdio.h>
#include <stdlib.h>
#include "console.h"

int main(){
    char filename[50];

    List list_user;
    ListDin list_barang;
    Queue antrian;
    User logged_in;
    boolean log_stats = false;
    boolean running = true;
    int where = 0;

    CreateQueue(&antrian);
    list_user = MakeList();
    list_barang = MakeListDin();

    while (running){
        printf(">> ");
        STARTWORD(NULL);
        printf("\n");

        if (where == 0){
            if (IsWordEqual(currentWord, "START")){
                Start(&list_user, &list_barang, &where);
            }

            if (IsWordEqual(currentWord, "LOAD")){
                ADVWORD();
                for (int i = 0; i < currentWord.Length; i++){
                    filename[i] = currentWord.TabWord[i];
                }
                filename[currentWord.Length] = '\0';
                Load(filename, &list_user, &list_barang, &where);
                DisplayUser(list_user);
                StoreList(list_barang);
            }

            if (IsWordEqual(currentWord, "QUIT")){
                Quit(&list_user, &list_barang, &running);
            }

            if (IsWordEqual(currentWord, "HELP")){
                Help(where);
            }
        }

        if (where == 1){
            if (IsWordEqual(currentWord, "REGISTER")){
                Register(&list_user);
                DisplayUser(list_user);
            }
            
            if (IsWordEqual(currentWord, "LOGIN")){
                Login(&list_user, &logged_in, &log_stats);
                if (log_stats){
                    where = 2;
                }
            }

            if (IsWordEqual(currentWord, "QUIT")){
                Quit(&list_user, &list_barang, &running);
            }

            if (IsWordEqual(currentWord, "HELP")){
                Help(where);
            }
        }

        if (where == 2){
            if (IsWordEqual(currentWord, "WORK")){
                if (isEndWord()){
                    //fungsi work
                }
                else{
                    ADVWORD();
                    if (IsWordEqual(currentWord, "CHALLENGE")){
                        //fungsi work challenge
                    }
                }
            }

            if (IsWordEqual(currentWord, "STORE")){
                ADVWORD();
                if (IsWordEqual(currentWord, "LIST")){
                    StoreList(list_barang);
                }
                if (IsWordEqual(currentWord, "REQUEST")){
                    Request(&antrian, &list_barang);
                    displayQueue(antrian);
                }
                if (IsWordEqual(currentWord, "SUPPLY")){
                    Supply(&antrian, &list_barang);
                    StoreList(list_barang);
                }
                if (IsWordEqual(currentWord, "REMOVE")){
                    //fungsi store remove
                }
            }

            if (IsWordEqual(currentWord, "LOGOUT")){
                log_stats = false;
                where = 1;
            }

            if (IsWordEqual(currentWord, "SAVE")){
                ADVWORD();
                for (int i = 0; i < currentWord.Length; i++){
                    filename[i] = currentWord.TabWord[i];
                }
                filename[currentWord.Length] = '\0';

                save(filename, &list_user, &list_barang);
            }

            if (IsWordEqual(currentWord, "QUIT")){
                Quit(&list_user, &list_barang, &running);
            }
            
            if (IsWordEqual(currentWord, "HELP")){
                Help(where);
            }
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "console.h"

int main(){
    char loadfile[50];
    char savefile[50];

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
                DisplayUser(list_user);
                StoreList(list_barang);
            }

            if (IsWordEqual(currentWord, "LOAD")){
                STARTWORD(NULL);
                CopyString(loadfile, currentWord.TabWord);
                Load(loadfile, &list_user, &list_barang, &where);
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
                    Work(&logged_in);
                }
                else{
                    STARTWORD(NULL);
                    if (IsWordEqual(currentWord, "CHALLENGE")){
                        WorkChallenge(&logged_in);
                    }
                }
                DumpUser(&list_user, &logged_in);
                DisplayUser(list_user);
            }

            if (IsWordEqual(currentWord, "STORE")){
                STARTWORD(NULL);
                if (IsWordEqual(currentWord, "LIST")){
                    StoreList(list_barang);
                }
                if (IsWordEqual(currentWord, "REQUEST")){
                    if (isEndWord()){
                        Request(&antrian, &list_barang);
                        displayQueue(antrian);
                    }
                    else{
                        STARTWORD(NULL);
                        if (IsWordEqual(currentWord, "BIOWEAPON")){
                            Bioweapon(&antrian, &list_barang);
                            displayQueue(antrian);
                        }
                    }
                }
                if (IsWordEqual(currentWord, "SUPPLY")){
                    Supply(&antrian, &list_barang);
                    StoreList(list_barang);
                }
                if (IsWordEqual(currentWord, "REMOVE")){
                    Remove(&list_barang);
                    StoreList(list_barang);
                }
            }

            if (IsWordEqual(currentWord, "LOGOUT")){
                Logout(&logged_in, &log_stats, where);
            }

            if (IsWordEqual(currentWord, "SAVE")){
                STARTWORD(NULL);
                CopyString(savefile, currentWord.TabWord);
                Save(savefile, &list_user, &list_barang);
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
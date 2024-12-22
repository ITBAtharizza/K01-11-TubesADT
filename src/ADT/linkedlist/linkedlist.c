#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void CopyStringLL(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

boolean IsEmptyLinkedList (LinkedList L){
    return (First(L) == NilLL);
}

void CreateEmptyLinkedList (LinkedList *L){
    First(*L) = NilLL;
}

address AlokasiLinkedList (infotypeLL X){
    address P = malloc (sizeof(ElmtList));
    if (P != NilLL){
        CopyStringLL(Info(P), X);
        Next(P) = NilLL;
    }
    return P;
}

void DealokasiLinkedList (address *P){
    free(*P);
}

address SearchLinkedList (LinkedList L, infotypeLL X){
    address P = First(L);
    while (P != NilLL){
        if (Info(P) == X){
            return P;
        }
        P = Next(P);
    }
    return NilLL;
}

void InsVFirstLinkedList (LinkedList *L, infotypeLL X){
    address P = AlokasiLinkedList(X);
    if (P != NilLL){
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsVLastLinkedList (LinkedList *L, infotypeLL X){
    address P = AlokasiLinkedList(X);
    if (P != NilLL){
        if (IsEmptyLinkedList(*L)){
            InsVFirstLinkedList(L,X);
        } else {
            address Last = First(*L);
            while (Next(Last) != NilLL){
                Last = Next(Last);
            }
            Next(Last) = P;
        }
    }
}

void DelVFirstLinkedList (LinkedList *L, infotypeLL *X){
    address P = First(*L);  
    CopyStringLL(*X, Info(P));
    First(*L) = Next(P);
    Next(P) = NilLL;
    DealokasiLinkedList(&P);
}

void DelVLastLinkedList (LinkedList *L, infotypeLL *X){
    address P = First(*L);
    address Prec = NilLL;
    while (Next(P) != NilLL){
        Prec = P;
        P = Next(P);
    }
    CopyStringLL(*X, Info(P));
    if (Prec == NilLL){
        First(*L) = NilLL;
    } else {
        Next(Prec) = NilLL;
    }
    DealokasiLinkedList(&P);
}

void InsertFirstLinkedList (LinkedList *L, address P){
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfterLinkedList (LinkedList *L, address P, address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLastLinkedList (LinkedList *L, address P){
    if (IsEmptyLinkedList(*L)){
        InsertFirstLinkedList(L,P);
    } else {
        address Last = First(*L);
        while (Next(Last) != NilLL){
            Last = Next(Last);
        }
        InsertAfterLinkedList(L,P,Last);
    }
}

void DelFirstLinkedList (LinkedList *L, address *P){
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P) = NilLL;
}

void DelPLinkedList (LinkedList *L, infotypeLL X){
    address P = First(*L);
    address Prec = NilLL;
    while (P != NilLL && Info(P) != X){
        Prec = P;
        P = Next(P);
    }
    if (P != NilLL){
        if (Prec == NilLL){
            First(*L) = Next(P);
        } else {
            Next(Prec) = Next(P);
        }
        Next(P) = NilLL;
        DealokasiLinkedList(&P);
    }
}

void DelLastLinkedList (LinkedList *L, address *P){
    address Last = First(*L);
    address Prec = NilLL;
    while (Next(Last) != NilLL){
        Prec = Last;
        Last = Next(Last);
    }
    *P = Last;
    if (Prec == NilLL){
        First(*L) = NilLL;
    } else {
        Next(Prec) = NilLL;
    }
}

void DelAfterLinkedList (LinkedList *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = NilLL;     
}

void PrintInfoLinkedList (LinkedList L){
    if (IsEmptyLinkedList(L)){
        printf("WISHLIST KOSONG!\n\n");
        return;
    }
    
    address temp = L.First;
    printf("ISI WISHLIST: \n");
    printf("+----------------------------------------------------+\n");
    printf("|                      WISHLIST                      |\n");
    printf("+----------------------------------------------------+\n");

    while (temp != NilLL) {
        printf("| %-50s |\n", temp->info);
        temp = temp->next;
    }
    printf("+----------------------------------------------------+\n\n");
}

int NbElmtLinkedList (LinkedList L){
    int count = 0;
    address P = First(L);
    while (P != NilLL){
        count++;
        P = Next(P);
    }
    return count;
}

void InversListLinkedList (LinkedList *L){
    address P = First(*L);
    address Prec = NilLL;
    address NextP = NilLL;
    while (P != NilLL){
        NextP = Next(P);
        Next(P) = Prec;
        Prec = P;
        P = NextP;
    }
    First(*L) = Prec;
}  

void KonkatLinkedList (LinkedList *L1, LinkedList *L2, LinkedList *L3){
    address P = First(*L1);
    address P2 = First(*L2);
    while (P != NilLL){
        InsVLastLinkedList(L3,Info(P));
        P = Next(P);
    }
    while (P2 != NilLL){
        InsVLastLinkedList(L3,Info(P2));
        P2 = Next(P2);
    }
}

boolean IsMemberLinkedList(LinkedList L, infotypeLL X){
    address current = L.First;

    while (current != NilLL){
        if (IsSameString(current->info, X)){
            return true;
        }
        current = current->next;
    }

    return false;
}
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

boolean IsEmptyLinkedList (LinkedList L){
    return (First(L) == Nil);
}

void CreateEmptyLinkedList (LinkedList *L){
    First(*L) = Nil;
}

address AlokasiLinkedList (infotype X){
    address P = malloc (sizeof(ElmtList));
    if (P != Nil){
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void DealokasiLinkedList (address *P){
    free(*P);
}

address SearchLinkedList (LinkedList L, infotype X){
    address P = First(L);
    while (P != Nil){
        if (Info(P) == X){
            return P;
        }
        P = Next(P);
    }
    return Nil;
}

void InsVFirstLinkedList (LinkedList *L, infotype X){
    address P = AlokasiLinkedList(X);
    if (P != Nil){
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsVLastLinkedList (LinkedList *L, infotype X){
    address P = AlokasiLinkedList(X);
    if (P != Nil){
        if (IsEmptyLinkedList(*L)){
            InsVFirstLinkedList(L,X);
        } else {
            address Last = First(*L);
            while (Next(Last) != Nil){
                Last = Next(Last);
            }
            Next(Last) = P;
        }
    }
}

void DelVFirstLinkedList (LinkedList *L, infotype *X){
    address P = First(*L);  
    *X = Info(P);
    First(*L) = Next(P);
    Next(P) = Nil;
    DealokasiLinkedList(&P);
}

void DelVLastLinkedList (LinkedList *L, infotype *X){
    address P = First(*L);
    address Prec = Nil;
    while (Next(P) != Nil){
        Prec = P;
        P = Next(P);
    }
    *X = Info(P);
    if (Prec == Nil){
        First(*L) = Nil;
    } else {
        Next(Prec) = Nil;
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
        while (Next(Last) != Nil){
            Last = Next(Last);
        }
        InsertAfterLinkedList(L,P,Last);
    }
}

void DelFirstLinkedList (LinkedList *L, address *P){
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P) = Nil;
}

void DelPLinkedList (LinkedList *L, infotype X){
    address P = First(*L);
    address Prec = Nil;
    while (P != Nil && Info(P) != X){
        Prec = P;
        P = Next(P);
    }
    if (P != Nil){
        if (Prec == Nil){
            First(*L) = Next(P);
        } else {
            Next(Prec) = Next(P);
        }
        Next(P) = Nil;
        DealokasiLinkedList(&P);
    }
}

void DelLastLinkedList (LinkedList *L, address *P){
    address Last = First(*L);
    address Prec = Nil;
    while (Next(Last) != Nil){
        Prec = Last;
        Last = Next(Last);
    }
    *P = Last;
    if (Prec == Nil){
        First(*L) = Nil;
    } else {
        Next(Prec) = Nil;
    }
}

void DelAfterLinkedList (LinkedList *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;     
}

void PrintInfoLinkedList (LinkedList L){
    address P = First(L);
    printf("[");
    while (P != Nil){
        printf("%d",Info(P));
        if (Next(P) != Nil){
            printf(",");
        }
        P = Next(P);
    }
    printf("]\n");
}

int NbElmtLinkedList (LinkedList L){
    int count = 0;
    address P = First(L);
    while (P != Nil){
        count++;
        P = Next(P);
    }
    return count;
}

void InversListLinkedList (LinkedList *L){
    address P = First(*L);
    address Prec = Nil;
    address NextP = Nil;
    while (P != Nil){
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
    while (P != Nil){
        InsVLastLinkedList(L3,Info(P));
        P = Next(P);
    }
    while (P2 != Nil){
        InsVLastLinkedList(L3,Info(P2));
        P2 = Next(P2);
    }
}
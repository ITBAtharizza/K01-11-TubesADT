#include "map.h"

void CreateEmptyMap(Map *M){
    M->Count = Nil;
}

boolean IsEmptyMap(Map M){
    return (M.Count == Nil);
}

boolean IsFullMap(Map M){
    return (M.Count == MaxEl);
}

valuetype ValueMap(Map M, keytype k){
    int i = 0;
    while (i < M.Count && M.Elements[i].Key != k){
        i++;
    }
    if (i < M.Count){
        return M.Elements[i].Value;
    } else {
        return Undefined;
    }
}

void InsertMap(Map *M, keytype k, valuetype v){
    if(IsEmpty(*M)){
        M->Elements[0].Key = k;
        M->Elements[0].Value = v;
        M->Count++;
    } else {
        if (Value(*M, k) == Undefined){
            M->Elements[M->Count].Key = k;
            M->Elements[M->Count].Value = v;
            M->Count++;
        }
    }
}

void DeleteMap(Map *M, keytype k){
    if (Value(*M, k) != Undefined){
        int i = 0;
        while (i < M->Count && M->Elements[i].Key != k){
            i++;
        }
        int idx = i;
        while (idx < M->Count){
            M->Elements[idx] = M->Elements[idx+1];
            idx++;
        }
        M->Count--;
    }
}

boolean IsMemberMap(Map M, keytype k){
    int i = 0;
    boolean found = false;
    while (!found && i < M.Count) {
        if (M.Elements[i].Key == k) {
            found = true;
        } else {
            i++;
        }
    }
    return found;
}
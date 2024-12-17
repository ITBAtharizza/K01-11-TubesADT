#include "map.h"

void CreateEmptyMap(Map *M){
    M->Count = Nil;
}

boolean IsEmptyMap(Map M){
    return (M.Count == Nil);
}

boolean IsFullMap(Map M){
    return (M.Count == MaxElMap);
}

valuetype ValueMap(Map M, keytype k){
    int i = 0;
    while (i < M.Count && !IsSameString(M.Elements[i].Barang.name, k.name)){
        i++;
    }
    if (i < M.Count){
        return M.Elements[i].Quantity;
    } else {
        return Undefined;
    }
}

void InsertMap(Map *M, keytype barang, valuetype quantity){
    if(IsEmpty(*M)){
        M->Elements[0].Barang = barang;
        M->Elements[0].Quantity = quantity;
        M->Count++;
    } else {
        if (ValueMap(*M, barang) == Undefined){
            M->Elements[M->Count].Barang = barang;
            M->Elements[M->Count].Quantity = quantity;
            M->Count++;
        }
    }
}

void DeleteMap(Map *M, keytype k){
    if (ValueMap(*M, k) != Undefined){
        int i = 0;
        while (i < M->Count && !IsSameString(M->Elements[i].Barang.name, k.name)){
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
        if (IsSameString(M.Elements[i].Barang.name, k.name)) {
            found = true;
        } else {
            i++;
        }
    }
    return found;
}
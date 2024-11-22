#ifndef __REGISTER_H__
#define __REGISTER_H__

#include "list.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "boolean.h"

boolean TwoString(char *str1, char *str2);
void CopyString(char *dest, char *src);
void Register(List *list_user);

#endif
#ifndef __HISTORY_H__
#define __HISTORY_H__

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

void AddToHistory(Stack *history, infotype purchase);
void ShowHistory(Stack *history);

#endif
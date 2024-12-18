#ifndef MASTER_HEADER_ADT_H
#define MASTER_HEADER_ADT_H

/* Basic definitions first */
#include "boolean.h"
#include "custom.h"   

/* Basic ADTs without dependencies */
#include "mesinkarakter/mesinkarakter.h"
#include "mesinkata/mesinkata.h"

/* Data structures in dependency order */
#include "map/map.h"          
#include "stack/stack.h"       
#include "queue/queue.h"      
#include "listlinier/listlinier.h"  
#include "dynamiclist/dynamiclist.h" 
#include "List/List.h"         // Uses all previous ADTs

#endif
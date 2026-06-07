//
// Created by goncalo on 05/06/26.
//

#ifndef CLIENT_SERVER_C_BUCKET_H
#define CLIENT_SERVER_C_BUCKET_H
#include "node.h"

typedef struct bucket bucket;

int is_full(bucket* b);

node* get_oldest(bucket* bucket);

int replace(bucket* bucket, node* old, node* new);

int erase_from_bucket(bucket* bucket, node* node); //returns positive or negative

node* find_in_bucket(bucket* bucket, node* node);

void add_to_bucket(bucket* bucket, node* node);

#endif //CLIENT_SERVER_C_BUCKET_H

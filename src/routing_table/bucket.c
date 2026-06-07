//
// Created by goncalo on 05/06/26.
//

#include "../../includes/routing_table/bucket.h"
#include "../../includes/routing_table/node.h"

#define BUCKET_SIZE 20

struct bucket {
    node *nodes[BUCKET_SIZE];
    int count;
};

int is_full(bucket* bucket);

node* get_oldest(bucket* bucket);

int replace(bucket* bucket, node* old, node* new);

int erase_from_bucket(bucket* bucket, node* node); //returns positive or negative

node* find_in_bucket(bucket* bucket, node* node);

void add_to_bucket(bucket* bucket, node* node);

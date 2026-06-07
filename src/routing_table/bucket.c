//
// Created by goncalo on 05/06/26.
//

#include "../../includes/routing_table/bucket.h"

#include <time.h>

#include "../../includes/routing_table/node.h"

#define BUCKET_SIZE 20

struct bucket {
    node *nodes[BUCKET_SIZE];
    int count;
};

int is_full(bucket* b) {
    return b->count == BUCKET_SIZE;
};

node* get_oldest(bucket* b) {
    if (b->nodes[0]==NULL) return NULL;
    node* oldest= b->nodes[0];

    time_t time_oldest;
    get_last_seen(oldest,&time_oldest);


    for (int i = 1; i< b->count; i++) {
        node* current = b-> nodes[i];
        time_t last_seen;

        get_last_seen(current, &last_seen);

        if (time_oldest > last_seen) {
            time_oldest = last_seen;
            oldest = current;
        }
    }
    return oldest;
}

int replace(bucket* bucket, node* old, node* new);

int erase_from_bucket(bucket* bucket, node* node); //returns positive or negative

node* find_in_bucket(bucket* bucket, node* node);

void add_to_bucket(bucket* bucket, node* node);

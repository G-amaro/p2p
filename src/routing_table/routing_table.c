//
// Created by goncalo on 05/06/26.
//

#include "../../includes/routing_table/routing_table.h"
#include "../../includes/routing_table/bucket.h"

struct routing_table {
    bucket *buckets[160];
};


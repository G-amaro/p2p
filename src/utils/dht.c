//
// Created by goncalo on 04/06/26.
//

#include "../../includes/dht.h"
#include <stdint.h>

struct dht_value {
    uint8_t  pub_key[32];
    
};

struct dht_entry {
    uint8_t key[20]; //public X25519 key hashed by SHA-1
    dht_value* dht_value;
};



//
// Created by goncalo on 04/06/26.
//

#include "../../includes/dht.h"
#include <stdint.h>
#include <time.h>
#include "uthash.h"

typedef struct {
    uint8_t        pub_key[32];    // chave pública X25519
    struct in_addr addr;           // IP
    uint16_t       port;           // porta
    time_t         expires_at;     // quando este valor expira
} dht_value_t;

typedef struct {
    uint8_t     key[20];           // hash(pub_key) com SHA-1
    dht_value_t *value;
    UT_hash_handle hh;             // para o uthash
} dht_entry_t;



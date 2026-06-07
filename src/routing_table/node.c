//
// Created by goncalo on 05/06/26.
//

#include "../../includes/routing_table/node.h"
#include <stdint.h>
#include <arpa/inet.h>

struct node {
    uint8_t key[20];
    struct in_addr addr;
    uint16_t port;
    time_t last_seen;
};

node* node_create(uint8_t key[20], struct in_addr addr, uint16_t port);

void get_key(node* node, uint8_t out[20]);

struct in_addr get_addr(node* node);

void get_port(node* node, uint16_t* out);

void get_last_seen(node* node, time_t* out);

void node_update_last_seen(node *n);

void node_destroy(node *n);

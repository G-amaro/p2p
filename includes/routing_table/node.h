//
// Created by goncalo on 05/06/26.
//

#ifndef CLIENT_SERVER_C_NODE_H
#define CLIENT_SERVER_C_NODE_H
#include <stdint.h>
#include <time.h>
#include <arpa/inet.h>


typedef struct node node;

node* node_create(uint8_t key[20], struct in_addr addr, uint16_t port);

void get_key(node* node, uint8_t out[20]);

struct in_addr get_addr(node* node);

void get_port(node* node, uint16_t* out);

void get_last_seen(node* node, time_t* out);

void node_update_last_seen(node *n);

void node_destroy(node *n);


#endif //CLIENT_SERVER_C_NODE_H

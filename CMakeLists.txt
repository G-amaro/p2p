cmake_minimum_required(VERSION 4.2)
project(Client_Server_C C)

set(CMAKE_C_STANDARD 11)

add_executable(Client_Server_C
        src/main.c
        src/utils/dht.c
        includes/dht.h
        src/utils/utils.c
        src/routing_table/bucket.c
        includes/routing_table/bucket.h
        src/routing_table/node.c
        includes/routing_table/node.h
        src/routing_table/routing_table.c
        includes/routing_table/routing_table.h)

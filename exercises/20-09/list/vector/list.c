#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

#define DEFAULT_LENGTH 0
#define DEFAULT_CAPACITY 2

struct list {
  void** data;
  int length;
  int capacity;
};


struct list* list_create(void) {
    struct list* list = malloc(sizeof(list));
    list->length = DEFAULT_LENGTH;
    list->capacity = DEFAULT_CAPACITY;
    *list->data = malloc(sizeof(void *) * list->capacity);
    return list;
}

void list_free(struct list* list) {
    void** data = list->data;
    for (int i = 0; i < list->length; ++i) {
        free(data[i]);
    }
    free(data);
    free(list);
}

int list_insert_first(struct list* list, void* data) {
    int new_length = list->length + 1;

    if (new_length >= list->capacity) {
        //resize
        int new_capacity = list->capacity * 2;
        void** new_data = malloc(sizeof(void*) * new_capacity);
        list->data = memcpy(*new_data, *list->data, list->capacity);
    }

    list->data[list->length + 1] = data;
    return 0;
}

int list_insert_last(struct list* list, void* data) {
    struct list_node* node = list->head;

    while(node->next != NULL) {
        node = node->next;
    }

    struct list_node* next_node = malloc(sizeof(struct list_node));
    next_node->data = data;
    next_node->next = NULL;
    node->next = next_node;

    return 0;
}

int list_remove_first(struct list* list, void** dest) {
    struct list_node *old_head = list->head;
    if (old_head == NULL) {
        return 1;
    }
    *dest = old_head->data;
    list->head = old_head->next;
    free(old_head);
    return 0;
}

void list_map(struct list* list, map_fn f, void *aux) {
    struct list_node *node = list->head;
    while (node != NULL) {
        node->data = f(node->data, aux);
        node = node->next;
    }
}

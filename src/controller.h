#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "red-black-tree.h"
#include "linked-list.h"
#include "formatted_data.h"
#include "unformatted_data.h"


int update_list_entry(rb_tree *, char*, char*, float, int);
int create_tree_node(char*, rb_tree *);
int report_error();

int get_average_delay(rb_tree *, char *);
int get_max_inflight(rb_tree *);
void * fill_tree(void *);
int get_max_inflight_recursive(node *, char*, int );

typedef struct thread_args
 {
    rb_tree * tree;
    char * str1;
    char * str2;
    FILE * fp;
    pthread_mutex_t mutex_fp;
    char ** buffer;
}thread_args;


void *fill_tree(void * arg);

int init_buffer (thread_args *args);
int clear_buffer (thread_args *args);
int clean_memory(thread_args *);
int create_tree(thread_args *);

void printids(const char *);
void *thr_fn(void *);
#endif

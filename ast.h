#include "data_types.h"

// AST NODE
typedef struct ast_node{
    Type type;
    operators op;

    struct ast_node* left;
    struct ast_node* right;
}as_node;

// FUNCTION/PROCEDURE NODE
struct ast_subprogram_node{
    Type type;

    // struct ast_node* id;
    struct ast_node* args;
    struct ast_node* comp_statements;
};

// WHILE NODE
struct ast_while_node{
    operators op;

    struct ast_node* condition;
    struct ast_node* while_branch;
};

// IF/ELSE NODE
struct ast_if_node{
  operators op;

  struct ast_node* condition;
  struct ast_node* if_branch;
  struct ast_node* if_tail;
};

// FOR NODE
struct ast_for_node{
    operators op;

    range iter_space;

    struct ast_node* id;
    struct ast_node* start_condition;
    struct ast_node* end_condition;
    struct ast_node* statement;
};

// READ/WRITE NODE
struct ast_io_node{
    operators op;

    struct ast_node* read_write_list;
};

// WITH NODE
struct ast_with_node{
    operators op;

    struct ast_node* condition;
    struct ast_node* statement;
};

// FOR IDS
struct leaf_node_id{
    operators op;

    char* name;
    s_node* leaf; //for complex types
};

// FOR CONSTANTS
struct leaf_node_const{
    operators op;

    data_t value;
};


// FUNCTIONS
struct as_node* new_as_node(Type type, operators op, struct ast_node* left,struct ast_node* right);
void check_malloc(struct ast_node* temp);
as_node* new_ast_func_node(struct ast_node* args, struct ast_node* comp_statements);
as_node* new_ast_proc_node(struct ast_node* args, struct ast_node* comp_statements);
as_node* new_while_node(struct ast_node* condition, struct ast_node* while_branch);
as_node* new_if_node(struct ast_node* condition, struct ast_node* if_branch, struct ast_node* if_tail);
as_node* new_for_node(range iter, struct ast_node* id, struct ast_node* start, struct ast_node* end, struct ast_node* statement);
as_node* new_read_node(struct ast_node* list);
as_node* new_write_node(struct ast_node* list);
as_node* new_with_node(struct ast_node* condition, struct ast_node* statement);
as_node* new_leaf_id_node(s_node* leaf, char* name);
as_node* leaf_node_const(data_t value);
void free_ast_tree (as_node* ast_tree);
void print_preorder (as_node* root);
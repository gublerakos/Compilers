#include <stdlib.h>
#include "ast.h"
#include "data_types.h"

void check_malloc(struct ast_node* temp){
    if(!temp){
        perror("malloc");
    }
}

as_node* new_ast_node(Type type, operators op, struct ast_node* left,struct ast_node* right){
    struct ast_node* ast_node;
    
    ast_node = (as_node*)malloc(sizeof (as_node));
    check_malloc(ast_node);

    ast_node->type = type;
    ast_node->op = op;
    ast_node->left = left;
    ast_node->right = right;

    return ast_node;
}

as_node* new_ast_func_node(struct ast_node* args, struct ast_node* comp_statements){
    struct ast_subprogram_node* ast_node;
    
    ast_node = (struct ast_subprogram_node*)malloc(sizeof (struct ast_subprogram_node));
    if(!ast_node){
        perror("malloc");
    }

    ast_node->type = FUNCTION;
    ast_node->args = args;
    ast_node->comp_statements = comp_statements;

    return (as_node*)ast_node;
}

as_node* new_ast_proc_node(struct ast_node* args, struct ast_node* comp_statements){
    struct ast_subprogram_node* ast_node;
    
    ast_node = (struct ast_subprogram_node*)malloc(sizeof (struct ast_subprogram_node));
    if(!ast_node){
        perror("malloc");
    }

    ast_node->type = PROCEDURE;
    ast_node->args = args;
    ast_node->comp_statements = comp_statements;

    return (as_node*)ast_node;
}

as_node* new_while_node(struct ast_node* condition, struct ast_node* while_branch){
    struct ast_while_node* ast_node;

    ast_node = (struct ast_while_node*)malloc(sizeof (struct ast_while_node));
    if(!ast_node){
        perror("malloc");
    }

    ast_node->op = WHILE;
    ast_node->condition = condition;
    ast_node->while_branch = while_branch;

    return (as_node*)ast_node;
}

as_node* new_if_node(struct ast_node* condition, struct ast_node* if_branch, struct ast_node* if_tail){
    struct ast_if_node* ast_node;

    ast_node = (struct ast_if_node*)malloc(sizeof (struct ast_if_node));
    if(!ast_node){
        perror("malloc");
    }

    ast_node->op = IF;
    ast_node->condition = condition;
    ast_node->if_branch = if_branch;
    ast_node->if_tail = if_tail;

    return (as_node*)ast_node;
}

as_node* new_for_node(range iter, struct ast_node* id, struct ast_node* start, struct ast_node* end, struct ast_node* statement){
    struct ast_for_node* ast_node;

    ast_node = (struct ast_for_node*)malloc(sizeof (struct ast_for_node));
    if(!ast_node){
        perror("malloc");
    }

    ast_node->op = FOR;
    ast_node->iter_space = iter;
    ast_node->id = id;
    ast_node->start_condition = start;
    ast_node->end_condition = end;
    ast_node->statement = statement;

    return (as_node*)ast_node;
}

as_node* new_read_node(struct ast_node* list){
    struct ast_io_node* ast_node;

    ast_node = (struct ast_io_node*)malloc(sizeof (struct ast_io_node));
    if(!ast_node){
        perror("malloc");
    }

    ast_node->op = READ;
    ast_node->read_write_list = list;

    return (as_node*)ast_node;
}

as_node* new_write_node(struct ast_node* list){
    struct ast_io_node* ast_node;

    ast_node = (struct ast_io_node*)malloc(sizeof (struct ast_io_node));
    if(!ast_node){
        perror("malloc");
    }

    ast_node->op = WRITE;
    ast_node->read_write_list = list;

    return (as_node*)ast_node;
}

as_node* new_with_node(struct ast_node* condition, struct ast_node* statement){
    struct ast_with_node* ast_node;

    ast_node = (struct ast_with_node*)malloc(sizeof (struct ast_with_node));
    if(!ast_node){
        perror("malloc");
    }

    ast_node->op = WITH;
    ast_node->condition = condition;
    ast_node->statement = statement;;

    return (as_node*)ast_node;
}

as_node* new_leaf_id_node(s_node* leaf, char* name){
    struct leaf_node_id* ast_node;

    ast_node = (struct leaf_node_id*)malloc(sizeof (struct leaf_node_id));
    if(!ast_node){
        perror("malloc");
    }

    ast_node->op = ID;
    ast_node->leaf = leaf;
    ast_node->name = name;

    return (as_node*)ast_node;
}

as_node* leaf_node_const(data_t value){
    struct leaf_node_const* ast_node;

    ast_node = (struct leaf_node_const*)malloc(sizeof (struct leaf_node_const));
    if(!ast_node){
        perror("malloc");
    }

    ast_node->op = CONST;
    ast_node->value = value;

    return (as_node*)ast_node;
}

void free_ast_tree (as_node* ast_tree){
    if(!ast_tree){
        return;
    }

    switch (ast_tree->op){
    case FUNCTION:
        struct ast_subprogram_node* node = (struct ast_subprogram_node*)ast_tree;
        if(node->args){
            free_ast_tree(node->args);
        }
        if(node->comp_statements){
            free_ast_tree(node->comp_statements);
        }
        break;
    case PROCEDURE:
        struct ast_subprogram_node* node = (struct ast_subprogram_node*)ast_tree;
        if(node->args){
            free_ast_tree(node->args);
        }
        if(node->comp_statements){
            free_ast_tree(node->comp_statements);
        }
        break;
    case WHILE:
        struct ast_while_node* while_node = (struct ast_while_node*)ast_tree;
        if(while_node->condition){
            free_ast_tree(while_node->condition);
        }
        if(while_node->while_branch){
            free_ast_tree(while_node->while_branch);
        }
        break;
    case IF:
        struct ast_if_node* if_node = (struct ast_if_node*)ast_tree;
        if(if_node->condition){
            free_ast_tree(if_node->condition);
        }
        if(if_node->if_branch){
            free_ast_tree(if_node->if_branch);
        }
        if(if_node->if_tail){
            free_ast_tree(if_node->if_tail);
        }
        break;
    case FOR:
        struct ast_for_node* for_node = (struct ast_for_node*)ast_tree;
        if(for_node->id){
            free_ast_tree(for_node->id);
        }
        if(for_node->start_condition){
            free_ast_tree(for_node->start_condition);
        }
        if(for_node->end_condition){
            free_ast_tree(for_node->end_condition);
        }
        if(for_node->statement){
            free_ast_tree(for_node->statement);
        }
        break;
    case READ:
        struct ast_io_node* read_node = (struct ast_io_node*)ast_tree;
        if(read_node->read_write_list){
            free_ast_tree(read_node->read_write_list);
        }
        break;
    case WRITE:
        struct ast_io_node* write_node = (struct ast_io_node*)ast_tree;
        if(write_node->read_write_list){
            free_ast_tree(write_node->read_write_list);
        }
        break;
    case WITH:
        struct ast_with_node* with_node = (struct ast_with_node*)ast_tree;
        if(with_node->condition){
            free_ast_tree(with_node->condition);
        }
        if(with_node->statement){
            free_ast_tree((with_node->statement);
        }
        break;
    case CONST:

        break;
    case ID:
        struct leaf_node_id* id_node = (struct leaf_node_id*)ast_tree;
        if(id_node->leaf){
            free_s_node(id_node->leaf);
        }
        if(id_node->name){
            free(id_node->name);
        }
        break;
    default:
        as_node* df_node = ast_tree;

        if(free_ast_tree(df_node->left)){
            free_ast_tree(df_node->left);
        }
        if(free_ast_tree(df_node->right)){
            free_ast_tree(df_node->right);
        }
    }    

    free(ast_tree);
}

void print_preorder(as_node* root){
	switch (root->op){
        // expression nodes
    case ADD:
		print_preorder(root->left);
		printf("+ ");
        print_preorder(root->right);
		break;
	case MINUS:
		print_preorder(root->left);
		printf("- ");
        print_preorder(root->right);
		break;
	case OR:
		print_preorder(root->left);
		printf("|| ");
        print_preorder(root->right);
		break;
    case MULT:
	    print_preorder(root->left);
		printf("* ");
        print_preorder(root->right);
		break;
    case DIV:
	    print_preorder(root->left);
		printf("DIV ");
        print_preorder(root->right);
		break;
    case MOD:
	    print_preorder(root->left);
		printf("MOD ");
        print_preorder(root->right);
		break;
    case DIVIDE:
	    print_preorder(root->left);
		printf("/ ");
        print_preorder(root->right);
		break;
    case AND:
	    print_preorder(root->left);
		printf("AND ");
        print_preorder(root->right);
		break;
    case NOT:
	    print_preorder(root->left);
		printf("NOT ");
        print_preorder(root->right);
		break;
    case IN:
	    print_preorder(root->left);
		printf("IN ");
        print_preorder(root->right);
		break;
    case EQU:
	    print_preorder(root->left);
		printf("= ");
        print_preorder(root->right);
		break;
    case GREATER:
	    print_preorder(root->left);
		printf("> ");
        print_preorder(root->right);
		break;
    case LESS:
	    print_preorder(root->left);
		printf("< ");
        print_preorder(root->right);
		break;
    case GREATER_EQU:
	    print_preorder(root->left);
		printf(">= ");
        print_preorder(root->right);
		break;
    case LESS_EQU:
	    print_preorder(root->left);
		printf("<= ");
        print_preorder(root->right);
		break;
    case LESS_GREATER:
	    print_preorder(root->left);
		printf("<> ");
        print_preorder(root->right);
		break;
    case DOT:
	    print_preorder(root->left);
		printf(". ");
        print_preorder(root->right);
		break;
    case DOTDOT:
	    print_preorder(root->left);
		printf(".. ");
        print_preorder(root->right);
		break;
    case ASSIGN:
	    print_preorder(root->left);
		printf(":= ");
        print_preorder(root->right);
		break;
    case PROCEDURE:
	case FUNCTION:
		printf("FUNCTION ");
		if (root->left){
			print_preorder(root->left);
		}
		if(root->right){
            print_preorder(root->right);
        }
        break;
    case WHILE:
        struct ast_while_node* while_node = (struct ast_while_node*)root;
        printf("WHILE ");
        if(while_node->condition){
			printf("(");
			print_preorder(while_node->condition);
            printf(")");
		}
        if(while_node->while_branch){
			printf("DO ");
			print_preorder(while_node->while_branch);
		}
        break;
    case IF:
        struct ast_if_node* if_node = (struct ast_if_node*)root;
        if(if_node->condition){
            printf("(");
            print_preorder(if_node->condition);
            printf(")");
        }
		printf("THEN ");
		if (if_node->if_branch){
			print_preorder(if_node->if_branch);
		}
		if(if_node->if_tail){
			printf("ELSE ");
			print_preorder(if_node->if_tail);
		}
		break;
    case FOR:
        struct ast_for_node* for_node = (struct ast_for_node*)root;
		printf("FOR ");
		if (for_node->id){
            printf("ID := ");
			print_preorder(for_node->id);
		}
        printf("(");
		if(for_node->start_condition){
            print_preorder(for_node->start_condition);
        }
        if(for_node->end_condition){
            print_preorder(for_node->end_condition);
        }
		printf(")");
		printf("DO ");
		if (for_node->statement){
			print_preorder(for_node->statement);
		}
		break;
    case READ:
        struct ast_io_node* read_node = (struct ast_io_node*)root;
        printf("READ ");
        if(read_node->read_write_list){
            print_preorder(read_node->read_write_list);
        }
        break;
    case WRITE:
        printf("WRITE ");
        struct ast_io_node* write_node = (struct ast_io_node*)root;
        if(write_node->read_write_list){
            print_preorder(write_node->read_write_list);
        }
        break;
    case WITH:
        struct ast_with_node* with_node = (struct ast_with_node*)root;
        printf("WITH ");
        if(with_node->condition){
            print_preorder(with_node->condition);
        }
		printf("DO ");
		if (with_node->statement){
			print_preorder(with_node->statement);
		}
		break;
    case CONST:
        struct leaf_node_const* const_node = (struct leaf_node_const*)root;
		printf("%d", const_node->value);
		break;
	case ID:
        struct leaf_node_id* id_node = (struct leaf_node_id*)root;
		printf(" ID ");
		if (!id_node->leaf){
			printf(" %s ", id_node->name);
		}
		else{
            switch (id_node->leaf->node_type){
            case RECORD:
                switch (id_node->leaf->ss_node.enum_record_t->data){
                    case INTEGER:
                        printf("%d\n", id_node->leaf->data.int_data);
                        break;
                    case REAL:
                        printf("%lf\n", id_node->leaf->data.double_data);
                        break;
                    case BOOLEAN:
                        if(id_node->leaf->data.boolean_data == TRUE){
                            printf("TRUE\n");
                        }
                        else{
                            printf("FALSE\n");
                        }
                        break;
                    case CHAR:
                        printf("%c\n", id_node->leaf->data.char_data);
                        break;
                    default:
                        break;
                    }
                break;
            case ENUM:
				printf("(");
				for (id_node->leaf->next)
					printf(" %s ", id_node->leaf->data);
                printf(")");
				break;
			case SUBRANGE:
                // printf(" % ", id_node->leaf->data);
                break;
		    default : 
                break;
			}
        }
    }    

	return;
}
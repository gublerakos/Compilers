#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "data_types.h"
#include "sizes.h"
#include "hashtbl.h"

HASHTBL *hashtbl;

// define
s_node* constants_init(Type type){
    s_node* node;

    node = (snode*)malloc(sizeof(s_node));
    if(!node){
        perror("malloc");
    }

    node->node_type = type;
    switch (type){
    case INTEGER:
        node->size = INT_SIZE;
        break;
    case CHAR:
        node->size = CHAR_SIZE;
        break;
    case BOOLEAN:
        node->size = BOOL_SIZE;
        break;
    case REAL:
        node->size = REAL_SIZE;
        break;
    case STRING:
        node->size = strlen(node->data.str_data)*CHAR_SIZE;
        break;
    default:
        break;
    }

    return node;
}

// LIST FUNCTIONS
List* list_init(List* list){

    list = (List*)malloc(sizeof(List));
    if(!list){
        perror("malloc");
    }
    list->field = NULL;
    list->next = NULL;

    return list;
}

List* list_add(List* head, List* new_node){

    new_node = (List*)malloc(sizeof(List));
    if(!list){
        perror("malloc");
    }

    new_node->next = head;
    new_node->field = NULL;
    head = new_node;

    return head;
}

List* list_add_field(List* head, s_node* node){
    List* temp;
    List* curr;

	curr = head;
	temp = head->next;
	while(!temp){
        if(temp->field != NULL){
            curr->field = node;
			curr->data = node->node_type;
			break;
		}
        curr = temp;
		temp = temp->next;
	}
    if(curr->field == NULL){
        curr->field = node;
		curr->data = node->node_type;
	}

    return head;
}
// Compute dimensions of array
array_t* manage_dims(array_t* array, s_node* dims){

    s_node* curr;

    for(curr = array->dims_ptr; curr->next != NULL; curr = curr->next);
    array->dims++;
    curr->next = dims;

    return array;
}
// Initialise super_node as type ARRAY etc
s_node* create_array_t(array_t* array, s_node* dims){
    s_node* new_node;

    new_node = (s_node*)malloc(sizeof(s_node));
    if(!new_node){
        perror("malloc");
    }

	new_node->node_type = ARRAY;
    new_node->ss_node.array_t.dims = array->dims;
    new_node->ss_node.array_t.subtype = array->subtype;
	new_node->ss_node.array_t.dims_ptr = array->dims_ptr;
    new_node->ss_node.array_t.sub_array = array->sub_array;
	new_node->size = get_size(array);
    new_node->data = dims->data;

	return new_node;
}
// Compute size 
int get_size(array_t* array){
	s_node *curr = array->dims_ptr;
	int size = 0;

	for (curr = array->dims_ptr; curr->next != NULL; curr = curr->next){
	    size = size + curr->size;
    }
	return size;
}

s_node* create_subrange(s_node* start, s_node* end){
	s_node *curr;

	curr = (s_node*)malloc(sizeof(s_node));
    if(!curr){
        perror("malloc");
    }
    curr->node_type = SUBRANGE;
	curr->ss_node.subrange_t.subtype = start->node_type;

	curr->ss_node.subrange_t.start = start;
    curr->ss_node.subrange_t.end = end;
    
    // ?????!!!!!!!!!!!!???????????????? func to check wether start is same type as end ========================
    
    // enum
    if(start->node_type == ENUM){
        List* list;
        
        list = end->ss_node.enum_record_t;
        curr->size = list->value * INT_SIZE;
    }
    else{    //int, char, bool
        switch (start->node_type){
        case INTEGER:
			curr->size = (end->data.int_data - start->data.int_data + 1)*INT_SIZE;
			break;
		case CHAR:
            curr->size = (end->data.char_data - start->data.char_data + 1)*CHAR_SIZE;
            break;
        case BOOLEAN:
			curr->size = 2 * BOOL_SIZE;
			break;
        default:
			curr->size = 0;
			break;
		}
    }

	return curr;
}

s_node* create_set_t(s_node* node){
    s_node* curr;

    curr = (s_node*)malloc(sizeof(s_node));
    if(!curr){
        perror("malloc");
    }

    curr->node_type = SET;
    curr->ss_node.set_t.subtype = node->node_type;

    switch (node->node_type){
    case CHAR:
		curr->ss_node.set_t.size = 128 * CHAR_SIZE;
		break;
	case BOOLEAN:
        curr->ss_node.set_t.size = 2 * BOOL_SIZE;
        break;
    case ENUM:
        curr->ss_node.set_t.size = node->ss_node.enum_record_t->value;
        if(curr->ss_node.set_t.size > 128){
            printf("\tERROR -> ENUM IN SET: SIZE > 128\n");
        }
        break;
    case SUBRANGE:
        curr->ss_node.set_t.size = node->size;
        if(curr->ss_node.set_t.size > 128){
            printf("\tERROR -> SUBRANGE IN SET: SIZE > 128\n");
        }
        break;
    default:
        break;
    }

    return curr;
}

s_node* create_enum_t(List* list){
    s_node* curr;
    List* enumList;

    curr = (s_node*)malloc(sizeof(s_node));
    if(!curr){
        perror("malloc");
    }

    curr->node_type = ENUM;

    enumList = list;
    enumList->value = 1;
    while(!(enumList->next)){
        enumList->value = enumList->value + 1;
        enumList = enumList->next;
    }
    // enumList->data = list->data;
    // enumList->field = list->field;
    // enumList->next = list->next;

    curr->ss_node.enum_record_t = enumList;

    return curr;
}
// RECORD
s_node* create_record_t(List* list){
    s_node* curr;
    List* recList;

    curr = (s_node*)malloc(sizeof(s_node));
    if(!curr){
        perror("malloc");
    }

    curr->node_type = RECORD;

    recList = list;
    recList->value = 1;
    while(!(recList->next)){
        recList->value = recList->value + 1;
        recList = recList->next;
    }
    // recList->data = list->data;
    // recList->field = list->field;
    // recList->next = list->next;

    curr->ss_node.enum_record_t = recList;

    return curr;
}



s_node* create_function(List* args, Type retval){
    s_node* curr;
    List* temp;    //to store args in hashtbl

    curr = (s_node*)malloc(sizeof(s_node));
    if(!curr){
        perror("malloc");
    }
    curr->node_type = FUNCTION_NAME;
    curr->ss_node.subprogram_t.return_value = retval;
    curr->ss_node.subprogram_t.args = args;

    // HASHTBL 

    return curr;
}

s_node* create_procedure(List* args){
    s_node* curr;
    List* temp;    //to store args in hashtbl

    curr = (s_node*)malloc(sizeof(s_node));
    if(!curr){
        perror("malloc");
    }

    curr->node_type = PROCEDURE_NAME;
    curr->ss_node.subprogram_t.return_value = NOVALUE;
    curr->ss_node.subprogram_t.args = args

    // HASHTBL

    return curr;
}

void free_s_node(s_node* node){
    List *temp;

    switch (node->node_type){
    case ARRAY:
        if(dims_ptr){
			free_s_node(dims_ptr);
		}
        if(sub_array){
            free_s_node(sub_array);
		}
		break;
    case SET:
        if(content){
			free_s_node(content);
		}
		break;
    case SUBRANGE:
        if(node->ss_node.subrange_t.subtype == ENUM){		
            while(node->ss_node.subrange_t.start){
                temp = node->ss_node.subrange_t.start;
                node->ss_node.subrange_t.start = temp->next;
				free(temp->field);
                free(temp);
			}
		}
        else{
            free_s_node(node->ss_node.subrange_t.start);
		    free_s_node(node->ss_node.subrange_t.end);
        }
		break;
    case PROCEDURE_NAME:
	case FUNCTION_NAME:
        while(node->ss_node.subprogram_t.args){
            temp = node->ss_node.subprogram_t.args;
            node->ss_node.subprogram_t.args = temp->next;
            free(temp->field);
            free(temp);
        }
        while(node->ss_node.subprogram_t.local){
            temp = node->ss_node.subprogram_t.local;
            node->ss_node.subprogram_t.local = temp->next;
            free(temp->field);
            free(temp);
        }
        break;
    case RECORD:
    case ENUM:
        while(node->ss_node.enum_record_t){
            temp = node->ss_node.enum_record_t;
            node->ss_node.enum_record_t = temp->next;
		    free(temp->field);
            free(temp);
	    }
        break;
    default:
		printf("hello\n");
		break;
	}
	free_s_node(node);
}

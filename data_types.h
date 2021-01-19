// DIVIDE = /
typedef enum operators_enum{ADD, MINUS, OR, MULT, DIV, MOD, DIVIDE, AND, NOT, IN, EQU, GREATER, LESS, GREATER_EQU,
                            LESS_EQU, LESS_GREATER, DOT, DOTDOT, ASSIGN, IF, ELSE, THEN, FOR, WHILE, WITH, DO,
                            READ, WRITE, FUNCTION, PROCEDURE, CONST, ID} operators;
typedef enum type_enum{INTEGER, REAL, BOOLEAN, CHAR, STRING, ARRAY, RECORD, SET, FUNCTION_NAME, PROCEDURE_NAME,
                       PROGRAM_NAME, ENUM, SUBRANGE, NOVALUE, VAR} Type;
typedef enum range_enum{DOWNTO, TO} range;

typedef union data_types{
    int int_data;
    bool boolean_data;
    char char_data;
    double double_data;
    char* str_data;
}data_t;

typedef struct list_t{
    Type data;
    int value;                  //for enum
    struct list_t* next;        
    struct super_node* field;   //for complex fields of record(like array)
}List;

typedef struct super_node{
    Type node_type;
    int size;
    data_t data;

    typedef union struct_node{
        // ARRAY
        typedef struct array_type{
            Type subtype;
            int dims;
            struct super_node* dims_ptr;
            struct super_node* sub_array;
        }array_t;
        // SET
        typedef struct set_type{
            int size;
            Type subtype;
            struct super_node* content;
        }set_t;
        // SUBRANGE
        typedef struct subrange_type{
            Type subtype;
            struct super_node* start;
            struct super_node* end;
        }subrange_t;
        // ENUMERATION + RECORD
        List* enum_record_t;
        // FUNCTION/PROCEDURE
        typedef struct subprogram_type{
            List* args;
            List* local;
            Type return_value;
        }subprogram_t;
    }ss_node;  

    struct super_node* next;

}s_node;

s_node* constants_init(Type type);

// LIST FUNCTIONS
List* list_init(List* list);
List* list_add(List* head, List* new_node);
List* list_add_field(List* head, s_node* node);

s_node* create_array_t(array_t* array, s_node* dims);
array_t* manage_dims(array_t* array, s_node* dims);
int get_size(array_t* array);

s_node* create_subrange(s_node* start, s_node* end);
s_node* create_set_t(s_node* node);
s_node* create_enum_t(List* list);
s_node* create_record_t(List* list);
s_node* create_function(List* var, Type retval);
s_node* create_procedure(List* var);
void free_s_node(s_node* node);

/* The authors of this work have released all rights to it and placed it
in the public domain under the Creative Commons CC0 1.0 waiver
(http://creativecommons.org/publicdomain/zero/1.0/).

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Retrieved from: http://en.literateprograms.org/Hash_table_(C)?oldid=19638
*/

#include"hashtbl.h"

#include<string.h>
#include<stdio.h>
#include "sizes.h"

static char *mystrdup(const char *s)
{
	char *b;
	if(!(b=malloc(strlen(s)+1))) return NULL;
	strcpy(b, s);
	return b;
}

static hash_size def_hashfunc(const char *key)
{
	hash_size hash=0;
	
	while(*key) hash+=(unsigned char)*key++;

	return hash;
}

HASHTBL *hashtbl_create(hash_size size, hash_size (*hashfunc)(const char *))
{
	HASHTBL *hashtbl;

	if(!(hashtbl=malloc(sizeof(HASHTBL)))) return NULL;

	if(!(hashtbl->nodes=calloc(size, sizeof(struct hashnode_s*)))) {
		free(hashtbl);
		return NULL;
	}

	hashtbl->size=size;

	if(hashfunc) hashtbl->hashfunc=hashfunc;
	else hashtbl->hashfunc=def_hashfunc;

	return hashtbl;
}

void hashtbl_destroy(HASHTBL *hashtbl)
{
	hash_size n;
	struct hashnode_s *node, *oldnode;
	
	for(n=0; n<hashtbl->size; ++n) {
		node=hashtbl->nodes[n];
		while(node) {
			free(node->key);
			oldnode=node;
			node=node->next;
			free(oldnode);
		}
	}
	free(hashtbl->nodes);
	free(hashtbl);
}


int hashtbl_insert(HASHTBL *hashtbl, const char *key, void *data ,int scope)
{
	struct hashnode_s *node;
	hash_size hash=hashtbl->hashfunc(key)%hashtbl->size;


	node=hashtbl->nodes[hash];
	while(node) {
		if(!strcmp(node->key, key) && (node->scope == scope)) {
			node->data=data;
			return 0;
		}
		node=node->next;
	}

	if(!(node=malloc(sizeof(struct hashnode_s)))) return -1;
	if(!(node->key=mystrdup(key))) {
		free(node);
		return -1;
	}
	node->data=data;
	node->scope = scope;
	node->next=hashtbl->nodes[hash];
	hashtbl->nodes[hash]=node;
	printf("\t\t\t\t\tHASHTBL_INSERT(): KEY = %s, HASH = %ld,  \tDATA = %s, SCOPE = %d\n", key, hash, (char*)data, scope);


	return 0;
}

int hashtbl_remove(HASHTBL *hashtbl, const char *key,int scope)
{
	struct hashnode_s *node, *prevnode=NULL;
	hash_size hash=hashtbl->hashfunc(key)%hashtbl->size;

	node=hashtbl->nodes[hash];
	while(node) {
		if((!strcmp(node->key, key)) && (node->scope == scope)) {
			free(node->key);
			if(prevnode) prevnode->next=node->next;
			else hashtbl->nodes[hash]=node->next;
			free(node);
			return 0;
		}
		prevnode=node;
		node=node->next;
	}

	return -1;
}

void *hashtbl_get(HASHTBL *hashtbl, int scope)
{
	int rem;
	hash_size n;
	struct hashnode_s *node, *oldnode;
		
	for(n=0; n<hashtbl->size; ++n) {
		node=hashtbl->nodes[n];
		while(node) {
			if(node->scope == scope) {
				printf("\t\t\t\t\tHASHTBL_GET():\tSCOPE = %d, KEY = %s,  \tDATA = %s\n", node->scope, node->key, (char*)node->data);
				oldnode = node;
				node=node->next;
				rem = hashtbl_remove(hashtbl, oldnode->key, scope);
			}else
				node=node->next;
		}
	}
	
	if (rem == -1)
		printf("\t\t\t\t\tHASHTBL_GET():\tThere are no elements in the hash table with this scope!\n\t\tSCOPE = %d\n", scope);
	
	return NULL;
}

// NEW FUNCTIONS
struct hashnode_s* hashtbl_lookup(HASHTBL *hashtbl, const char *key, int scope){
	struct hashnode_s *node;
	hash_size hash=hashtbl->hashfunc(key)%hashtbl->size;

	node=hashtbl->nodes[hash];
	for (int i = scope; i > 0; i--){
		while (node){
			if (!strcmp(node->key, key) && (node->scope == i)){
				return node;
			}
			node = node->next;	
		}
	}
	return NULL;
}
// HASHTBL INSERT FUNCTION FOR BASIC TYPES.
// RETURNS 0 ON SUCCESS AND -1 ON FAILURE.
int basic_insert(HASHTBL *hashtbl, const char *key, int scope, Type type, data_t data){
	struct hashnode_s *node;
	hash_size hash=hashtbl->hashfunc(key)%hashtbl->size;
	// s_node* new_node;

	node=hashtbl->nodes[hash];
	while(node) {
		if(!strcmp(node->key, key) && (node->scope == scope)) {
			node->data=data;
			return 0;
		}
		node=node->next;
	}

	if(!(node=malloc(sizeof(struct hashnode_s)))) return -1;

	node->hs_node = (s_node*)malloc(sizeof(s_node));
    if(!node->hs_node){
        perror("malloc");
    }

	if(!(node->key=mystrdup(key))) {
		free(node);
		return -1;
	}

	// node->hs_node = new_node;
	node->hs_node->node_type = type;
	node->hs_node->data = data;
    node->hs_node->next = NULL;

	switch (type){
		case INTEGER:
			node->hs_node->size = INT_SIZE; 
			break;
		case BOOLEAN:
			node->hs_node->size = BOOL_SIZE;
			break;
		case REAL:
			node->hs_node->size = REAL_SIZE;
			break;
		case CHAR:
			node->hs_node->size = CHAR_SIZE; 
			break;
		case STRING:
			node->hs_node->size = CHAR_SIZE*strlen(data.str_data); 
			break;
		default:
			break;
	}

	node->scope = scope;
	node->next=hashtbl->nodes[hash];
	hashtbl->nodes[hash]=node;

	printf("\t\t\t\t\tBASIC_INSERT(): KEY = %s, HASH = %ld, SCOPE = %d, SIZE = %d\n", key, hash, scope, node->hs_node->size);

	switch (type){
		case INTEGER:
			printf("Type = INTEGER, Data = %d\n", data.int_data);
			break;
		case BOOLEAN:
			printf("Type = BOOLEAN, Data = %d\n", data.boolean_data);
			break;
		case REAL:
			printf("Type = REAL, Data = %.3lf\n", data.real_data);
			break;
		case CHAR:
			printf("Type = CHAR, Data = %c\n", data.char_data);
			break;
		case STRING:
			printf("Type = STRING, Data = %s\n", data.str_data);
			break;
		default:
			break;
	}
	return 0;
}

int complex_insert(HASHTBL *hashtbl, const char *key, int scope, s_node* cnode){
	struct hashnode_s *node;
	hash_size hash=hashtbl->hashfunc(key)%hashtbl->size;


	node=hashtbl->nodes[hash];
	while(node) {
		if(!strcmp(node->key, key) && (node->scope == scope)) {
			node->data=data;
			return 0;
		}
		node=node->next;
	}

	if(!(node=malloc(sizeof(struct hashnode_s)))) return -1;
	if(!(node->key=mystrdup(key))) {
		free(node);
		return -1;
	}

	node->hs_node = (s_node*)malloc(sizeof(s_node));
    if(!node->hs_node){
        perror("malloc");
    }

	node->hs_node = cnode;

	switch (cnode->node_type){
		case ARRAY:
			printf("Type = ARRAY\n");
			break;
		case RECORD:
			printf("Type = RECORD\n");
			break;
		case SET:
			printf("Type = SET\n");
			break;
		case FUNCTION_NAME:
			printf("Type = FUNCTION_NAME\n");
			break;
		case PROCEDURE_NAME:
			printf("Type = PROCEDURE_NAME\n");
			break
		case PROGRAM_NAME:
			printf("Type = PROGRAM_NAME\n");
			break;
		case ENUM:
			printf("Type = ENUM\n");
			break;
		case SUBRANGE:
			printf("Type = SUBRANGE\n");
			break;
		default:
			break;
	}

	node->data=data;
	node->scope = scope;
	node->next=hashtbl->nodes[hash];
	hashtbl->nodes[hash]=node;
	printf("\t\t\t\t\tHASHTBL_INSERT(): KEY = %s, HASH = %ld, SCOPE = %d, SIZE = %d\n", key, hash, scope, node->hs_node->size);


	return 0;
}




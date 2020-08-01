# 0x02-heap_insert

## General Requirements
1. Allowed editors: vi, vim, emacs
2. All your files will be compiled on Ubuntu 14.04 LTS
3. Your programs and functions will be compiled with gcc 4.8.4 using the flags `-Wall` `-Werror` `-Wextra` and -`pedantic`
4. All your files should end with a new line
5. A README.md file, at the root of the folder of the project, is mandatory
6. Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
7. You are not allowed to use global variables
8. No more than 5 functions per file
9. You are allowed to use the standard library
10. In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
11. The prototypes of all your functions should be included in your header file called binary_trees.h
12. Don’t forget to push your header file
13. All your header files should be include guarded

### New Node

Write a function that creates a binary tree node:
#### Specific Requirements
1. Prototype: `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)`
2. `parent` is a pointer to the parent node of the node to create
3. `value` is the value to put in the new node
4. When created, a node does not have any children
5. Your function must return a pointer to the new node, or `NULL` on failure

```
alex@/tmp/binary_trees$ cat 0-main.c 
#include <stdlib.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);

    root->left = binary_tree_node(root, 12);
    root->left->left = binary_tree_node(root->left, 6);
    root->left->right = binary_tree_node(root->left, 16);

    root->right = binary_tree_node(root, 402);
    root->right->left = binary_tree_node(root->right, 256);
    root->right->right = binary_tree_node(root->right, 512);

    binary_tree_print(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
alex@/tmp/binary_trees$ ./0-node
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (016)     (256)     (512)
alex@/tmp/binary_trees$
```
Expected file: [0-binary_tree_node.c](./0-binary_tree_node.c)


### Heap - Insert

Write a function that inserts a value into a Max Binary Heap:
#### Specific Requirements
1. Prototype: `heap_t *heap_insert(heap_t **root, int value)`
2. `root` is a double pointer to the root node of the Heap
3. `value` is the value store in the node to be inserted
4. Your function must return a pointer to the inserted node, or `NULL` on failure
5. If the address stored in `root` is `NULL`, the created node must become the root node.
6. You have to respect a `Max Heap` ordering
7. ou are allowed to have up to `6` functions in your file

```
alex@/tmp/binary_trees$ cat 1-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    heap_t *root;
    heap_t *node;

    root = NULL;
    node = heap_insert(&root, 98);
    printf("Inserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 402);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 12);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 46);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 128);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 256);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 512);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 50);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    return (0);
}

alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 1-main.c 1-heap_insert.c 0-binary_tree_node.c -o 1-heap_insert
alex@/tmp/binary_trees$ ./1-heap_insert
Inserted: 98
(098)

Inserted: 402
  .--(402)
(098)

Inserted: 12
  .--(402)--.
(098)     (012)

Inserted: 46
       .--(402)--.
  .--(098)     (012)
(046)

Inserted: 128
       .-------(402)--.
  .--(128)--.       (012)
(046)     (098)

Inserted: 256
       .-------(402)-------.
  .--(128)--.         .--(256)
(046)     (098)     (012)

Inserted: 512
       .-------(512)-------.
  .--(128)--.         .--(402)--.
(046)     (098)     (012)     (256)

Inserted: 50
            .-------(512)-------.
       .--(128)--.         .--(402)--.
  .--(050)     (098)     (012)     (256)
(046)
alex@/tmp/binary_trees$
```
Expected file: [1-heap_insert.c](./1-heap_insert.c), [0-binary_tree_node.c](./0-binary_tree_node.c)
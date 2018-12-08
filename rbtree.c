#include <stdio.h>
#include <stdlib.h>

#define BLACK 0
#define RED 1
#define LEFT 3
#define RIGHT 4


typedef struct rb_tree
{
  int data;
  int color;
  struct rb_tree *left, *right;
}rbtree;

void left_left_rotation(rbtree **grand_parent);
void right_right_rotation(rbtree **grand_parent);
void left_rotate(rbtree **grand_parent);
void right_rotate(rbtree **grand_parent);
void balance_tree(rbtree *main_root, rbtree **grand_parent, int r_value);
int rb_create_tree(rbtree *main_root, rbtree **root, int data);
rbtree *rb_insert_tree(rbtree *root, int data);
void rb_in_order(rbtree *root);

int case_1(rbtree *m_root, rbtree **root);
int case_2(rbtree *m_root, rbtree **root);
int case_3(rbtree *m_root, rbtree **root);
int case_4(rbtree *m_root, rbtree **root);
int case_5(rbtree *m_root, rbtree **root);
int case_6(rbtree *m_root, rbtree **root);
int select_case(rbtree *m_root, rbtree **root);


// Left line rotation to right
void left_left_rotation(rbtree **grand_parent)
{
  rbtree *parent = (*grand_parent)->left;

  (*grand_parent)->left = parent->right;
  parent->right = *grand_parent;
  *grand_parent = parent;
  
  // Recolor
  parent->color = BLACK;
  parent->right->color = RED;

}

// Right line rotation to left
void right_right_rotation(rbtree **grand_parent)
{
  rbtree *parent = (*grand_parent)->right;

  (*grand_parent)->right = parent->left;
  parent->left = *grand_parent;
  *grand_parent = parent;

  // Recolor
  parent->color = BLACK;
  parent->left->color = RED;
}

// Left traingle rotate 
void left_rotate(rbtree **grand_parent)
{
  rbtree *parent = (*grand_parent)->left;
  rbtree *child = (*grand_parent)->left->right;

  (*grand_parent)->left = child;
  parent->right = child->left;
  child->left = parent;

}

// Right triangle rotate
void right_rotate(rbtree **grand_parent)
{
  rbtree *parent = (*grand_parent)->right;
  rbtree *child = (*grand_parent)->right->left;

  (*grand_parent)->right = child;
  parent->left = child->right;
  child->right = parent;

}

// Balance tree
void balance_tree(rbtree *main_root, rbtree **grand_parent, int r_value)
{
  // If left child is red
  if (r_value == LEFT)
  {
    // If parent's sibling is red
    if ((*grand_parent)->right != NULL && (*grand_parent)->right->color == RED)
    {
      // Recolor the parent and its sibling
      (*grand_parent)->left->color = BLACK;
      (*grand_parent)->right->color = BLACK;

      // Rocolor the grandparent
      if (*grand_parent != main_root)
      {
        (*grand_parent)->color = RED;
      }
    }

    // If the sibling is black or absent
    else if ((*grand_parent)->right == NULL || (*grand_parent)->right->color == BLACK)
    {
      // Check for parents's left child's color
      if ((*grand_parent)->left->left != NULL && (*grand_parent)->left->left->color == RED)
      {
        // Left line rotation to right 
        left_left_rotation(grand_parent);
      }
  
      // Check parent's right child's color
      else if ((*grand_parent)->left->right != NULL && (*grand_parent)->left->right->color == RED)
      {
        // Left triangle rotate
        left_rotate(grand_parent);

        // Left line rotation to right
        left_left_rotation(grand_parent);
      }
    }
  }

  // If right child is red
  if (r_value == RIGHT)
  {
    // If parent's sibling is red
    if ((*grand_parent)->left != NULL && (*grand_parent)->left->color == RED)
    {

      // Recolor the parent and the sibling
      (*grand_parent)->right->color = BLACK;
      (*grand_parent)->left->color = BLACK;

      // Recolor the grandparent
      if (*grand_parent != main_root)
      {
        (*grand_parent)->color = RED;
      }
    }

    // If the parent's sibling is black or absent
    else if((*grand_parent)->left == NULL || (*grand_parent)->left->color == BLACK)
    {
      
      // Check for parent's right child's color
      if ((*grand_parent)->right->right != NULL && (*grand_parent)->right->right->color == RED)
      {
        // Right line rotation to left
        right_right_rotation(grand_parent);
      }

      // Check for parent's left child's color
      else if ((*grand_parent)->right->left != NULL && (*grand_parent)->right->left->color == RED)
      {
        // Right triangle rotation
        right_rotate(grand_parent);

        // Right line rotation to left
        right_right_rotation(grand_parent);
      }
    }

  }
}

// Create and insert new node other than the root
int rb_create_tree(rbtree *main_root, rbtree **root, int data)
{
  int r_value;

  // Create new node
  if (*root == NULL)
  {
    *root = malloc(sizeof(rbtree));
    (*root)->left = NULL;
    (*root)->right = NULL;
    (*root)->data = data;
    (*root)->color = RED;
    return (*root)->color;
  }

  // Insert data to the right
  if (data > (*root)->data)
  {
    r_value = rb_create_tree(main_root, &(*root)->right, data);

    // Balance the tree
    if (r_value == CHECK)
    {
      balance_tree(main_root, root, RIGHT);
      return (*root)->color;
    }
  }

  // Insert data to the left
  else if (data < (*root)->data)
  {
    r_value = rb_create_tree(main_root, &(*root)->left, data);
  
    // Balance the tree
    if (r_value == CHECK)
    {
      balance_tree(main_root, root, LEFT);
      return (*root)->color;
    }
  }

  else
    printf("Data already exists..!!\n");

  // Check for red-red violation
  if ((*root)->color == r_value && r_value == RED)
    return CHECK;
  
  return (*root)->color;
}

// Create root and insert new node
rbtree *rb_insert_tree(rbtree *root, int data)
{
  // Create root
  if (root == NULL)
  {
    root = malloc(sizeof(rbtree));
    (root)->left = NULL;
    (root)->right = NULL;
    (root)->data = data;
    (root)->color = BLACK;
    return root;
  }

  else
  {
    // Insert nodes other than root
    rb_create_tree(root, &root, data);
    return root;
  }
}



int case_1(rbtree *m_root, rbtree **root)
{
  if (*root == m_root)
    return STOP;
}

int case_2(rbtree *m_root, rbtree **root)
{
  right_right_rotation(root);
  select_case(m_root, &(*root)->left);
}

int case_flag;

int case_3(rbtree *m_root, rbtree **root)
{
  (*root)->right->color = RED;

  if (*root == m_root)
    case_1(m_root, root);
  else 
    case_flag = 1;
}

int case_4(rbtree *m_root, rbtree **root)
{
  (*root)->color = BLACK;
  (*root)->right->color = RED;

  return STOP;
}

int case_5(rbtree *m_root, rbtree **root)
{
  right_rotate(root);

  (*root)->right->color = BLACK;
  (*root)->right->right->color = RED;
  select_case(m_root, root);
}

int case_6(rbtree *m_root, rbtree **root)
{
  int flag_1 = 1;

  if (*root == m_root)
    flag_1 = 0;
  
  rbtree *parent = (*root)->right;

  (*root)->right = parent->left;
  parent->left = *root;
  *root = parent;

  parent->right->color = BLACK;
  parent->right->color = BLACK;

  if (parent->left->left == NULL && flag_1)
    parent->color =  RED;

  return STOP;
}

int select_case(rbtree *m_root, rbtree **root)
{

  if((*root)->color == BLACK && (*root)->right->color == RED)
  {
    if ((*root)->right->right == NULL && (*root)->right->left == NULL || (*root)->right->right->color == BLACK && (*root)->right->left->color == BLACK)
      case_2(m_root, root);
  }

  else if ((*root)->color == BLACK && (*root)->right->color ==  BLACK)
  {
    if ((*root)->right->right == NULL && (*root)->right->left == NULL || (*root)->right->right->color == BLACK && (*root)->right->left->color == BLACK)

      case_3(m_root, root);
  }

  else if ((*root)->color == RED)
    case_4(m_root, root);

  else if ((*root)->color == BLACK && (*root)->right->color ==  BLACK && (*root)->right->left->color == RED && (*root)->right->right == NULL || (*root)->right->right->color == BLACK )
    case_5(m_root, root);

  else if ((*root)->right->color == BLACK && (*root)->right->right != NULL && (*root)->right->right->color == RED)
    case_6(m_root, root);
}


#include <stdio.h>
#include <stdlib.h>
//Given:::
//Zyguel Cabogoy; University of San Carlos; BSIT -1;
typedef struct node{
   int data;
   struct node *link;
}cell, *List;
//Start of Program;;
void initialize(List *head){
   *head = NULL;
}

void traverse(List head){
   List cur = head;
   while(cur != NULL){
      printf("%d ", cur->data);
      cur = cur->link;
   }
   printf("\n");
}

int is_sorted(List head){
   List cur = head;
   while(cur != NULL && cur->link != NULL){
      if(cur->data > cur->link->data){
         return 0;
      }
      cur = cur->link;
   }
   return 1;
}

void insert_at_beginning(List *head, int data){
   List new_node = (List)malloc(sizeof(cell));
   new_node->data = data;
   new_node->link = *head;
   *head = new_node;
}

void insert_at_end(List *head, int data){
   List new_node = (List)malloc(sizeof(cell));
   new_node->data = data;
   new_node->link = NULL;
   if(*head == NULL){
      *head = new_node;
      return;
   }
   List cur = *head;
   while(cur->link != NULL){
      cur = cur->link;
   }
   cur->link = new_node;
}

void insert_in_sorted_position(List *head, int data){
   if(*head == NULL || (*head)->data >= data){
      insert_at_beginning(head, data);
      return;
   }
   List new_node = (List)malloc(sizeof(cell));
   new_node->data = data;
   List cur = *head;
   while(cur->link != NULL && cur->link->data < data){
      cur = cur->link;
   }
   new_node->link = cur->link;
   cur->link = new_node;
}

int search(List head, int target){
   int position = 1;
   List cur = head;
   while(cur != NULL){
      if(cur->data == target){
         return position;
      }
      position++;
      cur = cur->link;
   }
   return 0;
}

void remove_node(List *head, int target){
   List cur = *head;
   if(cur == NULL){
      return;
   }
   if(cur->data == target){
      *head = cur->link;
      free(cur);
      return;
   }
   while(cur->link != NULL && cur->link->data != target){
      cur = cur->link;
   }
   if(cur->link == NULL){
      return;
   }
   List to_remove = cur->link;
   cur->link = to_remove->link;
   free(to_remove);
}

void remove_even_numbers(List *head)
{
   List cur = *head;
   List prev = NULL;
   while(cur != NULL){
      if(cur->data % 2 == 0){
         if(prev == NULL){
            *head = cur->link;
         } else{
            prev->link = cur->link;
         }
         List to_remove = cur;
         cur = cur->link;
         free(to_remove);
      } else{
         prev = cur;
         cur = cur->link;
      }
   }
}

int main(void){
   List head = NULL;
   int choice, data, target, position;

   initialize(&head);

   while(1){
      printf("Enter Command#:\n");
      printf("1. Traverse the list\n");
      printf("2. Check if the list is sorted\n");
      printf("3. Insert an element at the beginning\n");
      printf("4. Insert an element at the end\n");
      printf("5. Insert an element in sorted position\n");
      printf("6. Search for an element\n");
      printf("7. Remove the first instance of an element\n");
      printf("8. Remove all even numbers\n");
      printf("9. Quit\n");
      scanf("%d", &choice);

      if(choice == 1){
         traverse(head);
      } else if(choice == 2){
         if(is_sorted(head)){
            printf("The list is sorted\n");
         } else{
            printf("The list is not sorted\n");
         }
      } else if(choice == 3){
         printf("Enter the element to insert: ");
         scanf("%d", &data);
         insert_at_beginning(&head, data);
      } else if(choice == 4){
         printf("Enter the element to insert: ");
         scanf("%d", &data);
         insert_at_end(&head, data);
      } else if(choice == 5){
         printf("Enter the element to insert: ");
         scanf("%d", &data);
         insert_in_sorted_position(&head, data);
      } else if(choice == 6){
         printf("Enter the target element: ");
         scanf("%d", &target);
         position = search(head, target);
         if(position == 0){
            printf("Element not found\n");
         } else{
            printf("Element found at position %d\n", position);
         }
      } else if(choice == 7){
         printf("Enter the target element: ");
         scanf("%d", &target);
         remove_node(&head, target);
      } else if(choice == 8){
         remove_even_numbers(&head);
      } else if(choice == 9){
         break;
      } else{
         printf("Invalid choice\n");
      }
   }

   return 0;
}

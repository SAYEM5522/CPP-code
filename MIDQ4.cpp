// C++ program to remove vowels
// Nodes in a linked list
#include <bits/stdc++.h>
using namespace std;

// A linked list node
struct Node
{
  char data;
  struct Node *next;
};

// Head Node
struct Node *head;

// Function to add new node to the
// List
Node *newNode(char key)
{
  Node *temp = new Node;
  temp->data = key;
  temp->next = NULL;
  return temp;
}

// Utility function to print the
// linked list
void printlist(Node *head)
{
  if (!head)
  {
    cout << "Empty List\n";
    return;
  }
  while (head != NULL)
  {
    cout << head->data << " ";
    if (head->next)
      cout << "-> ";
    head = head->next;
  }
  cout << endl;
}

// Utility function for checking vowel
bool isVowel(char x)
{
  return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U');
}

// Function to remove the vowels Node
void removeVowels()
{
  struct Node *ptr = head;

  while (ptr != NULL)
  {

    if (isVowel(ptr->data))
      ptr = ptr->next;

    else
      break;
  }
  struct Node *prev = ptr;

  head = ptr;

  ptr = ptr->next;

 
  while (ptr != NULL)
  {

    if (isVowel(ptr->data))
    {

     
      ptr = ptr->next;

  
      while (ptr != NULL)
      {

     
        if (isVowel(ptr->data))
        {
          ptr = ptr->next;
        }
     
        else
          break;
      }


      if (ptr == NULL)
      {
        prev->next = NULL;
        break;
      }

      // Case 2: change the next
      // link of prev to current
      // consonant pointing to
      // ptr
      else
      {
        prev->next = ptr;
      }
    }

    // Move prev and ptr to next
    // for next iteration
    prev = prev->next;
    ptr = ptr->next;
  }
}

// Driver code
int main()
{
  // Initialise the Linked List
  head = newNode('a');
  head->next = newNode('b');
  head->next->next = newNode('c');
  head->next->next->next = newNode('e');
  head->next->next->next->next = newNode('f');
  head->next->next->next->next->next = newNode('g');
  head->next->next->next->next->next->next = newNode('i');
  head->next->next->next->next->next->next->next = newNode('o');

  // Print the given Linked List
  printf("Linked list before :\n");
  printlist(head);

  removeVowels();

  // Print the Linked List after
  // removing vowels
  printf("Linked list after :\n");
  printlist(head);

  return 0;
}

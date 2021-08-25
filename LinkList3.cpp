#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};

class LinkList
{
private:
  node *head, *tail;

public:
  LinkList();
  void add_node(int n);

  node *getnode()
  {
    return head;
  }
  static void display(node *head)
  {
    
    int diff;
    if (head != NULL)
    {
      while (head != NULL)
      {
        diff = (head->data - head->next->data);
      
        head = head->next;
        cout << "Difference between two adjacent keys : " << diff << endl;
      }
    }


  }
};
LinkList::LinkList()
{

  head = NULL;
  tail = NULL;
}
void LinkList::add_node(int n)
{
  node *tmp = new node;
  tmp->data = n;
  tmp->next = NULL;
  if (head == NULL)
  {
    head = tmp;
    tail = tmp;
  }
  else
  {
    tail->next = tmp;
    tail = tail->next;
  }
}

int main()
{
  LinkList obj1;
  obj1.add_node(1);
  // obj1.add_node(3);
  // obj1.add_node(4);
  // obj1.add_node(4);

  LinkList::display(obj1.getnode());
}

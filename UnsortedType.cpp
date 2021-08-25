#include <iostream>
using namespace std;
template <class ItemType>
class UnsortedType
{
  struct NodeType
  {
    ItemType info;
    NodeType *next;
  };

public:
  UnsortedType();
  ~UnsortedType();
  bool IsFull();
  int LengthIs();
  void MakeEmpty();
  void RetrieveItem(ItemType &,
                    bool &);
  void InsertItem(ItemType);
  void DeleteItem(ItemType);
  void ResetList();
  void GetNextItem(ItemType &);

private:
  NodeType *listData;
  int length;
  NodeType *currentPos;
};
template <class ItemType>
UnsortedType<ItemType>::UnsortedType()
{
  length = 0;
  listData = NULL;
  currentPos = NULL;
}
template <class ItemType>
int UnsortedType<ItemType>::LengthIs()
{
  return length;
}
template <class ItemType>
bool UnsortedType<ItemType>::IsFull()
{
  NodeType *location;
  try
  {
    location = new NodeType;
    delete location;
    return false;
  }
  catch (bad_alloc &exception)
  {
    return true;
  }
}
template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType
                                            item)
{
  NodeType *location;
  location = new NodeType;
  location->info = item;
  location->next = listData;
  listData = location;
  length++;
}
template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType
                                            item)
{
  NodeType *location = listData;
  NodeType *tempLocation;
  if (item == listData->info)
  {
    tempLocation = location;
    listData = listData->next;
  }
  else
  {
    while (!(item == (location->next)->info))
      location = location->next;
    tempLocation = location->next;
    location->next = (location->next)->next;
  }
  delete tempLocation;
  length--;
}
template <class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType &
                                              item,
                                          bool &found)
{
  NodeType *location = listData;
  bool moreToSearch = (location != NULL);
  found = false;
  while (moreToSearch && !found)
  {
    if (item == location->info)
      found = true;
    else
    {
      location = location->next;
      moreToSearch = (location != NULL);
    }
  }
}
template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
{
  NodeType *tempPtr;
  while (listData != NULL)
  {
    tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
  }
  length = 0;
}
template <class ItemType>
UnsortedType<ItemType>::~UnsortedType()
{
  MakeEmpty();
}
int main()
{
  UnsortedType<int> un;
  un.InsertItem(5);
  un.InsertItem(7);
  un.InsertItem(6);
  un.InsertItem(9);
  
  for (int i = 0; i < un.LengthIs(); i++)
  {
    un.GetNextItem(x);
    cout << x << " ";
  }
}
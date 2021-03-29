#include <iostream>

using namespace std;

template <class T>
class my_list
{
private:
  struct node
  {
    T data;
    node *next;
  };
  node *head = nullptr;
  node *tail = nullptr;
  node *prev_tail = nullptr;
  int length;

public:
  void push_back(T new_value)
  {
    node *curr = new node;
    curr->data = new_value;
    curr->next = nullptr;
    if (!head)
    {
      head = new node;
      tail = new node;
      head = tail = curr;
      return;
    }
    prev_tail = tail;
    tail->next = curr;
    tail = curr;
    length++;
  }

  bool empty()
  {
    return head == nullptr;
  }

  T back()
  {
    return (tail->data);
  }

  T front()
  {
    return (head->data);
  }

  int size()
  {
    return length;
  }

  void clear()
  {
    node *curr = head;
    while (curr)
    {
      if (curr->next != nullptr)
        node *next = curr->next;
      delete curr;
    }
  }
  void push_front(T new_value)
  {
    node *curr = new node;
    curr->data = new_value;
    if (!head)
    {
      head = new node;
      tail = new node;
      curr->next = nullptr;
      head = tail = curr;
      return;
    }
    curr->next = head;
    head = curr;
    length++;
  }

  void remove(T val)
  {
    node *curr = head;
    node *prev = curr;
    while (curr->data != val)
    {
      prev = curr;
      curr = curr->next;
    }

    prev->next = curr->next;
    delete curr;
  }

  bool contains(T val)
  {
    node *curr = head;
    while (curr)
    {
      if (curr->data == val)
        return true;
      curr = curr->next;
    }
    return false;
  }

  void pop_back()
  {
    node *curr = head;
    node *prev = curr;
    while (curr->next)
    {
      prev = curr;
      curr = curr->next;
    }
    prev->next = nullptr;
    delete curr;
  }

  void pop_front()
  {
    node *curr = head;
    node *del = curr;
    curr = curr->next;

    head = curr;
    delete del;
    length--;
  }

  void reverse()
  {
    node *newHead = nullptr;
    while (head)
    {
      node *next = head->next;
      head->next = newHead;
      newHead = head;
      head = next;
    }
    head = newHead;
  }
  void display()
  {
    node *curr = head;
    while (curr)
    {
      cout << curr->data << " ";
      curr = curr->next;
    }
  }
};

int main()
{
  my_list<int> ls;
  ls.push_back(1);
  ls.push_back(2);
  ls.push_back(3);
  ls.display();
  cout << "\n";
  ls.reverse();
  ls.display();

  return 0;
}

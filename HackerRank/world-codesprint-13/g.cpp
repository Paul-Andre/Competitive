#include <bits/stdc++.h>
using namespace std


int sqrt_n;
// Here I create some kind of square-root decomposition linked list;
//
//

template<class Data> 

struct LinkedList {
  Node *begin;
  Node *end;

  struct Node {
    Node *next;
    Node *prev;
    Data data;

    Node(Data d): data(d) {}
  };

  LinkedList() {
    begin = end = nullptr;
  }

  // Split off the linked list starting at node
  LinkedList<Data> *split(Node *node) {
    LinkedList<Data> *new_list = new LinkedList<Data>();

    if (node == nullptr) {
      new_list->begin = nullptr;
      new_list->end = nullptr;
      return new_list;
    }

    new_list->begin = node;
    new_list->end = end;

    end = node->prev;
    if (node->prev != nullptr) {
      node->prev->next = nullptr;
    }
    node->prev = nullptr;

    while(node != nullptr) {
      node->parent = new_list;
      node = node->next;
    }

    return new_list;
  }
  
  // Joins the list to the end of the current this list
  // Consumes list
  void join(LinkedList<Data> *list) {
    end->next = list->begin;
    if (list->begin != nullptr) {
      list->begin->prev = end;
    }
    end = list->end;

    Node *node = begin;
    while(node!=nullptr) {
      node->parent = this;
      node = node->next;
    }

  }

};


class Info{
  int size;
  int black_cnt;
  int min_tree_node;

  Info() {
    size = 0;
    black_cnt = 0;
    min_tree_node = 123456789;
  }
};

Info join(Info a, Info b) {
  Info ret;
  ret.size = a.size + b.size;
  ret.black_cnt = a.black_cnt + b.black_cnt;
  ret.min_tree_node = min(a.min_tree_node, b.min_tree_node);
  return ret;
}


template<class Info>
struct SqrtList {

  struct Inner {
    Info info;
    LinkedList<Info> *list;

    void recalculate_info() {
      LinkedList<Info>::Node *ptr = list->begin;
      info = Info();
      while(ptr!= nullptr) {
        info = join(info, ptr->info);
      }
    }
  }

  LinkedList<Inner> *list;

  SqrtList<Info> split(LinkedList<Inner>::Node *node) {
    LinkedList<Inner> *b = list.split(node->parent);
    LinkedList<Inner> *c = b.split(node->parent->next);

    Inner bx = b->data;
    Inner by;
    by.list = bx.list->split(node);
    bx.recalculate_info();
    by.recalculate_info();

    list->join(b);

    LinkedList<Inner> *ret = new LinkedList<Inner>();
    LinkedList<Inner>::Node *n = new LinkedList<Inner>::Node(by);
    ret->begin = ret->end = n;
    ret->join(c);
    return ret;
  }

}


int main(){
  

}



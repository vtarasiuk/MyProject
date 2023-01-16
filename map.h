#ifndef MAP_H
#define MAP_H

#include "framework.h"

class Map
{
private:
  class List
  {
  public:
    class Node
    {
    public:
      long ikey, ivalue;
      std::string lpkey, lpvalue;
      Node* next;
      Node();
      ~Node();
    };


    Node* head;
    List* next;
    unsigned int length;
    // template in the future
    List();
    ~List();
  };
  
  unsigned int size;
  List* head;
public:
  Map();
  ~Map();
  int get_size(void);
};

Map::Map()
{
  this->size = 0;
  this->head = nullptr;
}

Map::~Map() {}

Map::List::List()
{
  this->length = 0;
  this->head = nullptr;
  this->next = nullptr;
}

Map::List::~List() {}

Map::List::Node::Node()
{
  this->ikey = this->ivalue = 0;
  this->lpkey = this->lpvalue = "";
  this->next = nullptr;
}

Map::List::Node::~Node() {}

#endif
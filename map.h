#ifndef MAP_H
#define MAP_H

#include "framework.h"

class Map
{
private:
    class Node
    {
    public:
      long ikey, ivalue;
      std::string lpkey, lpvalue;
      Node* next;
      
      Node()
      {
        printf("NODE CONSTRUCTOR\n");
        this->ikey = this->ivalue = 0;
        this->lpkey = this->lpvalue = "";
        this->next = nullptr;
      }
      ~Node()
      {
        printf("NODE DESTRUCTOR\n");
      }
    };
    // template in the future
    unsigned int size;
    Node* head;
public:
  Map()
  {
    printf("MAP CONSTRUCTOR\n");
    this->size = 0;
    this->head = nullptr;
  }
  ~Map()
  {
    printf("MAP DESTRUCTOR\n");
    Node* current = this->head;
    while (current != nullptr)
    {
      this->head = current->next;
      delete current;
      current = this->head;
    }
  }
  int get_size(void);
  void insert(int, std::string);
  void insert(std::string, int);
  void insert(int, int);
  void insert(std::string, std::string);
  void print(void);
};

#endif
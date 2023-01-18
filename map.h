#ifndef MAP_H
#define MAP_H

#include "framework.h"

class Map
{
public:
  class List
  {
  private:
    class Node
    {
    public:
      long ikey, ivalue;
      std::string lpkey;
      Node* next; // depth
      
      Node(std::string&, int&);
      ~Node();
    };

    Node* head;
    List* nextList; // next list
    unsigned int length;
  public:
    List(std::string&, int&);
    List(int, std::string);
    List(int, int);
    List(std::string, std::string);
    ~List();

    unsigned int getLength();
    List* getNext(void);
    void setNextTo(List*);
    void printList();
  };

  Map();
  ~Map();
  // int operator[] (const int&) const;
  // int operator[] (const std::string&) const;

  int get_size(void);
  void insert(std::string, int);
  void insert(int, int);
  void print(void);

private:
  // template in the future
  unsigned int size;
  List* headList;
};

#endif
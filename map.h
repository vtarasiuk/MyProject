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
      long ivalue;
      Node* next; // same keys
      
      Node(int&);
      ~Node();
    };

    Node* head;
    List* nextList;
    unsigned int length;
    std::string lpkey;
    int ikey;

  public:
    List(std::string&, int&);
    ~List();

    void listAdd(int);
    bool isSameKey(std::string);
    unsigned int getLength();
    List* getNext(void);
    void setNextTo(List*);
    void printList();
  };

  Map();
  ~Map();
  // int operator[] (const int&) const;
  // int operator[] (const std::string&) const;

  int keyIndex(std::string);
  int get_size(void);
  void insert(std::string, int);
  //void insert(int, int);
  void print(void);
  unsigned int countNodes();

private:
  // template in the future
  unsigned int size;
  List* headList;

  void addDublicate(int, int);
};

#endif
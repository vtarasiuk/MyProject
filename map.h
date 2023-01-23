#ifndef MAP_H
#define MAP_H

#include "framework.h"

class Map
{
protected:
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

  unsigned int countNodes();
  int keyIndex(std::string);
  void addDublicate(int, int);

public:
  Map();
  ~Map();
  // int operator[] (const int&) const;
  // int operator[] (const std::string&) const;

  int get_size(void);
  void insert(std::string, int);
  //void insert(int, int);
  void print(void);

private:
  // template in the future
  unsigned int size;
  List* headList;
};

#endif
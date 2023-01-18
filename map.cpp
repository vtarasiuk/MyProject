#include "map.h"
#include "framework.h"

Map::Map()
{
  //printf("MAP CONSTRUCTOR\n");
  this->size = 0;
  this->headList = nullptr;
}

Map::~Map()
{
  //printf("MAP DESTRUCTOR\n");
  List* temp = this->headList, *current;
  while (temp != nullptr)
  {
    current = temp->getNext();
    delete temp;
    temp = current;
  }
  this->headList = nullptr;
}

Map::List::~List()
{
  Node* temp = this->head, *current;
  while (temp != nullptr)
  {
    current = temp->next;
    delete temp;
    temp = current;
  }
  this->head = nullptr;
}

Map::List::Node::Node(std::string& key, int& value)
{
  //printf("NODE CONSTRUCTOR\n");
  this->lpkey = key;
  this->ivalue = value;
  this->next = nullptr;

  this->ikey = 0;
}

Map::List::Node::~Node()
{
  /*printf("NODE DESTRUCTOR\n");*/
  this->next = nullptr;
}

int Map::get_size(void)
{
  return this->size;
}

unsigned int Map::List::getLength()
{
  return this->length;
}

Map::List* Map::List::getNext()
{
  return this->nextList;
}

void Map::List::setNextTo(List* nextList)
{
  if (!this->nextList) this->nextList = nextList;
}

Map::List::List(std::string& key, int& value) // fill
{
  this->head = new Node(key, value);
  this->nextList = nullptr;
  this->length = 1;
}

void Map::insert(std::string key, int value)
{
  if (!this->headList)
  {
    this->headList = new List(key, value); // ifnDefine
    this->size++;
    return;
  }
  // ifnDefine
  // ifnDefine add Node() func!!!
  // ifnDefine
  List* current = this->headList;
  while (current->getNext() != nullptr)
  {
    current = current->getNext();
  }

  current->setNextTo(new Map::List(key, value));
  this->size++;
}

void Map::List::printList() // just for std::string, int
{
  Node* current = this->head;
  unsigned int counter = 1;

  while (current != nullptr)
  {
    std::cout << "\t  NODE " << counter << std::endl;
    std::cout << "\tKEY: " << current->lpkey << std::endl;
    std::cout << "\tVALUE: " << current->ivalue << std::endl;
    std::cout << "\tNEXTNODE: " << current->next << std::endl << std::endl;
    current = current->next;
    counter++;
  }
}

void Map::print()
{
  List* current = this->headList;
  unsigned int counter = 1;
  // bool isKeyStr;
  while (current != nullptr)
  {
    //isKeyStr = (current->lpkey == "") ? false : true; current[???]
    if (current->getLength() > 1) /*current->printList();*/ return;

    std::cout << "  LIST " << counter << std::endl;
    std::cout << "LENGTH: " << current->getLength() << std::endl;
    std::cout << "NEXT: " << current->getNext() << std::endl << std::endl;

    current->printList();

    current = current->getNext();
    counter++;
  }
  std::cout << "SIZE: " << this->size << "\n\n";
}
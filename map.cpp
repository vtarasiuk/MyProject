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

Map::List::List(std::string& key, int& value)
{
  this->head = new Node(value);
  this->nextList = nullptr;
  this->length = 1;
  this->ikey = 0;
  this->lpkey = key;
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

Map::List::Node::Node(int& value)
{
  //printf("NODE CONSTRUCTOR\n");
  this->ivalue = value;
  this->next = nullptr;
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

int Map::keyIndex(std::string key)
{
  List* current = this->headList;
  unsigned int counter = 0;

  while (current != nullptr)
  {
    if (current->isSameKey(key)) return counter;
    current = current->getNext();
    counter++;
  }

  return -1;
}

bool Map::List::isSameKey(std::string key)
{
  return (this->lpkey == key);
}

void Map::addDublicate(int index, int value)
{
  List* current = this->headList;
  int counter = 0;

  while (counter < index)
  {
    current = current->getNext();
    counter++;
  }

  current->listAdd(value);
}

void Map::List::listAdd(int value)
{
  Node* current = this->head;
  if (current->ivalue == value) return;
  
  while (current->next != nullptr)
  {
    if (current->ivalue == value) return;
    current = current->next;
  }

  current->next = new Node(value);
  this->length++;
}

void Map::insert(std::string key, int value)
{
  if (!this->headList)
  {
    this->headList = new List(key, value);
    this->size++;
    return;
  }

  int dublicate = this->keyIndex(key);
  if (dublicate != -1)
  {
    this->addDublicate(dublicate, value);
    return;
  }

  List* current = this->headList;
  while (current->getNext() != nullptr)
  {
    current = current->getNext();
  }

  current->setNextTo(new Map::List(key, value));
  this->size++;
}

void Map::List::printList()
{
  Node* current = this->head;
  unsigned int counter = 1;

  while (current != nullptr)
  {
    std::cout << "\t  NODE №" << counter << std::endl;
    std::cout << "\tKEY: " << this->lpkey << std::endl;
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

  while (current != nullptr)
  {
    std::cout << "LIST №" << counter << std::endl;
    std::cout << "LENGTH: " << current->getLength() << std::endl;
    std::cout << "NEXT: " << current->getNext() << std::endl << std::endl;

    current->printList();

    current = current->getNext();
    counter++;
  }
  std::cout << "SIZE: " << this->size << std::endl;
  std::cout << "NODES: " << this->countNodes() << std::endl << std::endl;
}

unsigned int Map::countNodes()
{
  List* current = this->headList;
  unsigned int nodes = 0;

  while (current != nullptr)
  {
    nodes += current->getLength();
    current = current->getNext();
  }
  return nodes;
}
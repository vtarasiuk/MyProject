#include "map.h"
#include "framework.h"

int Map::get_size(void)
{
  return this->size;
}

void Map::insert(std::string key, int value)
{
  if (!this->head)
  {
    this->head = new Node();
    this->head->lpkey = key;
    this->head->ivalue = value;
    this->size++;
    return;
  }

  Node* current = this->head;
  while (current->next != nullptr)
  {
    current = current->next;
  }
  current->next = new Node();
  current->next->lpkey = key;
  current->next->ivalue = value;
  this->size++;
}

void Map::insert(int key, int value)
{
  if (!this->head)
  {
    this->head = new Node();
    this->head->ikey = key;
    this->head->ivalue = value;
    this->size++;
    return;
  }

  Node* current = this->head;
  while (current->next != nullptr)
  {
    current = current->next;
  }
  current->next = new Node();
  current->next->ikey = key;
  current->next->ivalue = value;
  this->size++;
}

void Map::print()
{
  Node* current = this->head;
  bool isKeyStr;
  while (current != nullptr)
  {
    isKeyStr = (current->lpkey == "") ? false : true;
    
    if (isKeyStr)
    {
      std::cout << "KEY: " << current->lpkey << " (string)" << std::endl;
      std::cout << "VALUE: " << current->ivalue << std::endl;
      std::cout << "PNEXT: " << current->next << std::endl << std::endl;
    }
    else
    {
      std::cout << "KEY: " << current->ikey << std::endl;
      std::cout << "VALUE: " << current->ivalue << std::endl;
      std::cout << "PNEXT: " << current->next << std::endl << std::endl;
    }

    current = current->next;
  }
  std::cout << "SIZE: " << this->size << "\n\n";
}

int Map::operator[] (const int& key) const
{
  Node* current = this->head;
  while (current != nullptr)
  {
    if (current->ikey == key) return current->ivalue;
    current = current->next;
  }
  throw std::out_of_range("The key doesn't exist");
  return 1;
}

int Map::operator[] (const std::string& key) const
{
  Node* current = this->head;
  while (current != nullptr)
  {
    if (current->lpkey == key) return current->ivalue;
    current = current->next;
  }
  throw std::out_of_range("The key doesn't exist");
  return 1;
}
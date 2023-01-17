#include "map.h"
#include "framework.h"

int Map::get_size(void)
{
  return this->size;
}

void Map::insert(int key, std::string value) {}
void Map::insert(std::string key, int value) {}
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

void Map::insert(std::string key, std::string value) {}

void Map::print()
{
  Node* current = this->head;
  bool isKeyStr, isValStr;
  while (current != nullptr)
  {
    isKeyStr = (current->lpkey == "") ? false : true;
    isValStr = (current->lpvalue == "") ? false : true; 
    
    if (isKeyStr && isValStr)
    {
      std::cout << "KEY: " << current->lpkey << std::endl;
      std::cout << "VALUE: " << current->lpvalue << std::endl;
      std::cout << "PNEXT: " << current->next << std::endl << std::endl;
    }
    else if (isKeyStr)
    {
      std::cout << "KEY: " << current->lpkey << std::endl;
      std::cout << "VALUE: " << current->ivalue << std::endl;
      std::cout << "PNEXT: " << current->next << std::endl << std::endl;
    }
    else if (isValStr)
    {
      std::cout << "KEY: " << current->ikey << std::endl;
      std::cout << "VALUE: " << current->lpvalue << std::endl;
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
//stable.h

#ifndef STABLE_H
#define STABLE_H

#include "synch.h"
#include "bitmap.h"

#define MAX_SEMAPHORE 10

class Sem{
  char name[50];
  Semaphore *sem;

 public:
  Sem(char* na,int i){
    strcpy(this->name,na);
    sem = new Semaphore(name,i);
  }
  ~Sem(){delete sem;}
  void wait(){sem->P();}
  void signal(){sem->V();}
  char* GetName(){return name;}
}; 

class STable {

 private:
  BitMap* bm;
  Sem* semTab[MAX_SEMAPHORE];

 public:
  STable();
  ~STable();
  int create(char* name, int init);
  int wait(char *name);
  int signal(char *name);

};
#endif

// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() {
  first = nullptr;
  countOp = 0;
}
void Train::addCage(bool light) {
  if (first != nullptr) {
      last->next = new Cage;
      last->next->prev = last;
      last = last->next;
      last->next = first;
      first->prev = last;
      last->light = light;
    } else {
      first = new Cage;
      first->next = first;
      first->prev = first;
      first->light = light;
      last = first;
    }
    countOp = 0;
  }
int Train::getLength() {
  int count = 1;
  Cage* cur = first;
  cur -> light = true;
  while (cur) {
    cur = cur -> next;
    if (cur->light == false) {
    ++count;
    ++countOp;
    }
    if (cur -> light == true) {
      cur -> light = false;
      ++countOp;
      for (int i = count; i > 0; --i) {
        cur = cur -> prev;
        ++countOp;
      }
      if (cur -> light == false) {
        return count;
      } else {
        count = 1;
      }
    }
  }
  return 0;
}
int Train::getOpCount() {
  return countOp;
}

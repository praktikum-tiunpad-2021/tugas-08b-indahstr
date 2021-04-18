#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  T data;
  T priority;
  Element *next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  Element<T> * head;
  Element<T> * tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  Queue<T> q;
  q.head = nullptr;
  q.tail = nullptr;
  return q;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  Element<T> * prev = nullptr;
  Element<T> * pHelp = q.head;
  Element<T> * newElement;
  newElement = new Element<T>;
  newElement->data = value;
  newElement->priority = priority;
  newElement->next = nullptr;

  if (pHelp == nullptr && q.tail == nullptr) {
    q.head = newElement;
    q.tail = newElement;
  } else {
    while (newElement->priority <= pHelp->priority) {
      if (pHelp->next == nullptr) {
        break;
      }
      prev = pHelp;
      pHelp = pHelp->next;
    }
    if (pHelp == q.head && newElement->priority > pHelp->priority) {
      newElement->next = pHelp;
      q.head = newElement;
    } else if (pHelp == q.tail && newElement->priority < pHelp->priority) {
      pHelp->next = newElement;
      q.tail = newElement;
    } else {
      prev->next = newElement;
      newElement->next = pHelp;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  return q.head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  Element<T> * pDelete;
  if (q.head == nullptr && q.tail == nullptr) {
    pDelete = nullptr;
  } else if (q.head->next == nullptr) {
    pDelete = q.head;
    q.head = nullptr;
    q.tail = nullptr;
  } else {
    pDelete = q.head;
    q.head = q.head->next;
    pDelete->next = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat

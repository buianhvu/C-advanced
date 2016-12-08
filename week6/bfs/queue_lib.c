#include "queue_lib.h"

Queue new_Queue()
{
  Queue new;
  new = new_dllist();
  return new;
}
void Enqueue(Queue queue, int v)
{
  dll_append(queue, new_jval_i(v));
}

int isQueueEmpty(Queue queue)
{
  return dll_empty(queue);
}

int getVertexFromQueue(Queue queue)
{
  Queue node;
  int v;
  node =  dll_first(queue);
  v = jval_i(node->val);
  dll_delete_node(node);
  return v;
}

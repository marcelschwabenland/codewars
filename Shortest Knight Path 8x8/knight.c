#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_SIZE 256

// structure to represent a position on the chessboard
struct position {
  int x;
  int y;
};

// structure to represent a queue
struct queue {
  struct position positions[QUEUE_SIZE];
  int head;
  int tail;
};

// function to add a position to the queue
void enqueue(struct queue *q, struct position p) {
  q->positions[q->tail] = p;
  q->tail = (q->tail + 1) % QUEUE_SIZE;
}

// function to remove a position from the queue
struct position dequeue(struct queue *q) {
  struct position p = q->positions[q->head];
  q->head = (q->head + 1) % QUEUE_SIZE;
  return p;
}

// function to check if the queue is empty
bool is_empty(struct queue *q) { return q->head == q->tail; }

short knight(const char *p1, const char *p2) {
  // convert positions from algebraic notation to coordinates
  int x1 = p1[0] - 'a';
  int y1 = p1[1] - '1';
  int x2 = p2[0] - 'a';
  int y2 = p2[1] - '1';

  // use BFS to find the shortest path
  int dx[] = {1, 2, 2, 1, -1, -2, -2, -1}; // x-offsets for knight's moves
  int dy[] = {2, 1, -1, -2, -2, -1, 1, 2}; // y-offsets for knight's moves
  bool visited[8][8];                  // 2D array to track visited positions
  memset(visited, 0, sizeof(visited)); // initialize all elements to false
  struct queue q = {.head = 0, .tail = 0}; // initialize queue
  enqueue(&q, (struct position){.x = x1,
                                .y = y1}); // add starting position to queue
  visited[y1][x1] = true;                  // mark starting position as visited
  int steps = 0;                           // initialize step counter
  while (!is_empty(&q)) {                  // continue until queue is empty
    int size = q.tail - q.head;
    for (int i = 0; i < size; i++) {
      struct position p = dequeue(&q); // remove position from front of queue
      if (p.x == x2 &&
          p.y == y2) { // check if current position is the destination
        return steps;  // return number of steps if destination is reached
      }
      for (int j = 0; j < 8; j++) { // try all possible knight's moves
        int x = p.x + dx[j];
        int y = p.y + dy[j];
        if (x >= 0 && x < 8 && y >= 0 && y < 8 &&
            !visited[y][x]) { // check if move is valid
          enqueue(&q, (struct position){.x = x,
                                        .y = y}); // add new position to queue
          visited[y][x] = true;                   // mark position as visited
        }
      }
    }
    steps++; // increment step counter
  }
  return -1; // return -1 if destination is not reached
}

int main(void) {
  // test 1: start and end positions are adjacent
  int steps = knight("a3", "b5");
  printf("From a3 to b5 a minimum of %d steps have been calculated (expected "
         "1).\n",
         steps);
  assert(steps == 1);
  // test 2: start and end positions are on opposite corners of the board
  steps = knight("a1", "h8");
  printf("From a1 to h8 a minimum of %d steps have been calculated (expected "
         "6).\n",
         steps);
  assert(steps == 6);
  // test 3: start and end positions are on the same rank
  steps = knight("b7", "e4");
  printf("From b7 to e4 a minimum of %d steps have been calculated (expected "
         "2).\n",
         steps);
  assert(steps == 2);
  // test 4: start and end positions are on the same file
  steps = knight("c3", "c6");
  printf("From c3 to c6 a minimum of %d steps have been calculated (expected "
         "2).\n",
         steps);
  assert(steps == 2);
  // test 5: start and end positions are the same
  steps = knight("a1", "a1");
  printf("From a1 to a1 a minimum of %d steps have been calculated (expected "
         "0).\n",
         steps);
  assert(steps == 0);
  // test 6: start and end positions are separated by an odd number of ranks and
  // files
  steps = knight("d4", "e6");
  printf("From d4 to e6 a minimum of %d steps have been calculated (expected "
         "2).\n",
         steps);
  assert(steps == 2);
  // test 7: start and end positions are separated by an even number of ranks
  // and files
  steps = knight("a2", "c4");
  printf("From a2 to c4 a minimum of %d steps have been calculated (expected "
         "2).\n",
         steps);
  assert(steps == 2);
  // test 8: start and end positions are not connected
  steps = knight("a1", "h7");
  printf("From a1 to h7 a minimum of %d steps have been calculated (expected "
         "-1).\n",
         steps);
  return 0;
}

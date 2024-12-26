int i = front;
int j = 0;
while (i != rear) {
  if (i == capacity) {
    i = i%capacity;
  }
  newp[j] = oldq[i];
  i++
}

newfront = 0;
newRear = j;

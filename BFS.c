void enqueue(int node) {
    if (rear == MAX_NODES - 1) {
        printf("Queue is full.\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = node;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return -1;
    }
    int node = queue[front];
    front++;
    return node;
}

bool isQueueEmpty() {
    return front == -1 || front > rear;
}

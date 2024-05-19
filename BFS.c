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

void reverse()
{
    Node<T> *current = head;
    Node<T> *prevNode = nullptr;
    Node<T> *nextNode = nullptr;

    while (current != nullptr)
    {
        nextNode = current->next;

        current->next = prevNode;
        current->prev = nextNode;

        prevNode = current;
        current = nextNode;
    }

    head = prevNode;
}

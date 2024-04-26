T find(int k)
{
    if (k <= 0)
    {
        cout << "Invalid value of k" << endl;
        return;
    }

    Node<T> *current = head->prev;

    for (int i = 1; i < k && current != head; ++i)
    {
        current = current->prev;
    }

    if (current == head)
    {
        cout << "K is greater than list's nodes" << endl;
        return;
    }

    return current->value;
}
   // void insertAtEnd(int value)
    // {
    //     Node *New = new Node(value);
    //     if (head == NULL)
    //     {
    //         head = New;
    //     }
    //     else
    //     {
    //         Node *ptr = head;
    //         while (ptr->next != NULL)
    //         {
    //             ptr = ptr->next;
    //         }
    //         ptr->next = New;
    //     }
    // }


    void insertBeforeValue(int DATA , int before){
      Node* ptr = head;
      int i = 0;
      while(ptr->data!=before){
         ptr = ptr->next;
         i++;
      }
      insertAtIndex(i,DATA);
    }
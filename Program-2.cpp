#include <iostream>
class Node {
private:
    int item;
    Node* next;

public:
    Node() {
    }

    void Insertion(int val) {
        Node* newNode = new Node();
        newNode->item = val;
        newNode->next = next;
        next = newNode;
    }
    void Deletion() {
        if (next == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = next;
        next = next->next;
        delete temp;
    }
    void Display() {
        Node* curr = next;
        while (curr != nullptr) {
            std::cout << curr->item << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
    int Search(int val) {
        Node* curr = next;
        int index = 1;
        while (curr != nullptr) {
            if (curr->item == val) {
                return index;
            }
            curr = curr->next;
            index++;
        }
        return -1;
    }
    void Delete(int val) {
        Node* prev = this;
        Node* curr = next;
        while (curr != nullptr) {
            if (curr->item == val) {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};

int main() {
    Node my_list;

  
    my_list.Insertion(5);
    my_list.Insertion(10);
    my_list.Insertion(15);
    my_list.Insertion(20);
    my_list.Display();

   
    my_list.Deletion();
    my_list.Display(); 

   
    int search_val = 15;
    int search_result = my_list.Search(search_val);
    std::cout << search_result << std::endl;

    
    int missing_val = 30;
    int missing_result = my_list.Search(missing_val);
    std::cout << missing_result << std::endl;

    
    int delete_val = 10;
    my_list.Delete(delete_val);
    my_list.Display(); 

    
    int missing_delete_val = 25;
    my_list.Delete(missing_delete_val);
    my_list.Display(); 

    return 0;
}

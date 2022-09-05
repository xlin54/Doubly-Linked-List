#include<iostream>
using namespace std;
class Node{
        public:
            Node* prev;
            int key;
            int data;
            Node* next;

            Node(){
                prev = NULL;
                key = 0;
                data = 0;
                next = NULL;
            }

            Node(int key, int data){
                prev = NULL;
                key = key;
                data = data;
                next = NULL;
            }
};
class doubly_linked_list{
    public:
        Node* head = NULL;
        Node* rear = NULL;
        //Node* next = NULL;
        Node* temp = NULL;

        void append(Node* newbie){
            if(head == NULL && rear == NULL){
                head = rear = newbie;
            }else if(head == rear){ 
                rear->next = newbie;
                newbie->prev = rear;
                rear = newbie;
            }else{
                // temp = head;
                // while(temp->next !=NULL){
                //     temp = temp->next;
                // }
                rear->next = newbie;
                newbie->prev = rear;
                rear = newbie;
            }   
        }

        void prepend(Node* newbie){
            if(head == NULL && rear == NULL){
                head = rear = newbie;
            }else if(head == rear){
                head->prev = newbie;
                newbie->next = head;
                head = newbie;
            }else{
                head->prev = newbie;
                newbie->next = head;
                head = newbie;
            }
        }

        void insert_at_position(int position, Node* newbie){
            int index = -1;
            if(head == NULL && rear == NULL && position == 0){
                head = rear = newbie;
                //index++;    // empty not position 0, one ele, more than one ele (f/nf) // front, btw, end
            }else{
                temp = head;
                while(temp!= NULL){
                    index++;
                    if(index == position-1 && temp->next != NULL){
                        Node* after = temp->next;
                        temp->next = newbie;
                        newbie->prev = temp;
                        newbie->next = after;
                        after->prev = newbie;
                        cout<<" | "<<newbie->key<<", "<<newbie->data<<" | "<<" added at ";
                        cout<<position<<endl;
                        //break;
                        // if(newbie->next == NULL){
                        //     rear = newbie;
                        // }
                        break;
                    }else if(index == position-1 && temp->next == NULL){ 
                        temp->next = newbie;
                        newbie->prev = temp;
                        rear = newbie;
                    }else{
                        temp = temp->next;
                        //break;
                    }
                }
                if(head == NULL && rear == NULL && temp == NULL && position!= 0){
                    cout<<"error, empty list, can not insert at any position other than ";
                    cout<<" starting position zero "<<endl;
                }else if(position == 0 && head != NULL && rear != NULL){ 
                    prepend(newbie);
                }else if(temp == NULL){
                    cout<<" error, the position you entered does not exist after ";
                    cout<<" traversing through the entire list "<<endl;
                }
            }
        }

        void delete_ny_key(int key){
            if(head == NULL && rear == head){
                cout<<" error, empty list, nothing to delete"<<endl;
                return;
            }
            temp = head;
            while(temp!= NULL && temp->key != key){
                temp = temp->next;
            }
            if(temp->key == key){
                if(head-> key == key){
                    Node* secondPlace = head->next;
                    head->next = NULL;
                    secondPlace->prev = NULL;
                    head = secondPlace;
                }else if(temp->next!=NULL ){
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    temp->prev = NULL;    
                    temp->next = NULL;            
                }else{
                    rear = temp->prev;
                    temp->prev->next = NULL;
                    temp->prev = NULL;

                }
                cout<<temp<<" is deleted or detached "<<endl;
            }else{
                cout<<" error, the node with the specific key cab bot be found";
                cout<<" after traversing the entire list"<<endl;
            }
        }

        void display(){
            temp = head;
            while(temp!= NULL){
                cout<<"| "<<temp->key<<", "<<temp->data<<" |  -->   ";
                temp = temp->next;
            }
        }
};

int main(){
    Node* n1 = new Node();
    n1->key = 1;
    n1->data = 200;
    Node* n2 = new Node();
    n2->key = 2;
    n2->data = 400;
    Node* n3 = new Node();
    n3->key = 3;
    n3->data = 600;
    Node* n4 = new Node();
    n4->key = 4;
    n4->data = 800;
    Node* n5 = new Node();
    n5->key = 5;
    n5->data = 1000;
    doubly_linked_list dll1;
    dll1.append(n1);
    dll1.append(n2);
    dll1.append(n3);

    dll1.prepend(n4);

    dll1.insert_at_position(0, n5);

    dll1.delete_ny_key(1);
    dll1.display();
    return 0;
}
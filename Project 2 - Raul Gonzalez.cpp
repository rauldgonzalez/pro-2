//Project #2: 10/03/18
//Student: Raul Gonzalez ; SMC ID: 1630082

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;


//----- Given code: [Linear list]
template<class T>
class LinearList
{
private:
    int length;
    int MaxSize;
    T *element;
public:
    LinearList(int MaxLinearSize=10);
    ~LinearList(){delete[]element;}
    int isEmpty()const{return length==0;}
    int Length()const{return length;}
    int Find(int k,T&x)const;
    int Search(const T&x)const;
    void Delete(int k,T&x);
    void Insert(int k,const T&x);
    void Output(char file_name[]);
};
template<class T>
LinearList<T>::LinearList(int MaxListSize)
{
    MaxSize=MaxListSize;
    element=new T[MaxSize];
    length=0;
}
template<class T>
int LinearList<T>::Find(int k,T&x)const
{
    if(k<1||k>length)
        return 0;
    x=element[k-1];
    return 1;
}
template<class T>
int LinearList<T>::Search(const T&x)const
{
    for(int i=0;i<length;i++)
        if(element[i]==x)
            return ++i;
    return 0;
}
template<class T>
void LinearList<T>::Delete(int k,T&x)
{
    if(Find(k,x))
    {
        for(int i=k;i<length;i++)
            element[i-1]=element[i];
        length--;
    }
    else
        cout<<"out of bounds\n";
}
template<class T>
void LinearList<T>::Insert(int k,const T&x)
{
    if(k<0||k>length)
        cout<<"out of bounds\n";
    if(length==MaxSize)
        cout<<"no memory\n";
    for(int i=length-1;i>=k;i--)
        element[i+1]=element[i];
    element[k]=x;
    length++;
}

template<class T>
 void LinearList<T>::Output( char file_name[] )
{
    if(isEmpty()) {
        cout<<"list is empty\n";
    } else {
        ofstream DataFile;
        DataFile.open( file_name );
        for(int i=0;i<length;i++) {
            cout<<element[i]<<"\n";
            DataFile << element[i] << "\n";
        }
        DataFile.close();
    }
}
void menu()
{
    cout<<"\n MENU\n" ;
    cout<<"-----------\n";
    cout<<"1.Length\n";
    cout<<"2.Find\n";
    cout<<"3.Search\n";
    cout<<"4.Delete\n";
    cout<<"5.Insert\n";
    cout<<"6.Output\n";
    cout<<"-------------\n";
}
//End of given code


//-------------------------------------------

//Custom Linked-list class: [not all bugs fixed]
class linked_list {

    private:
    //Variables:
        struct node {
            int data;
            node *link;
        };

        node *head, *tail;

    //----- Private functions:

                    //---- Node insertion:

        void add_last( int value ) {

            if( length == 0 ) {
                head = new node;
                head->data = value;
                head->link = NULL;
                //cout << head->data << endl;
            } else if (length == 1) {
                tail = new node;
                tail->data = value;
                tail->link = NULL;
                //
                head->link = tail;
                //cout << tail->data << endl;
            } else {
                tail->link = new node;
                tail = tail->link;
                tail->data = value;
                tail->link = NULL;
                //cout << tail->data << endl;
            }
            length += 1;
        } //End of add_last

        //
        void add_front( int value ) {
            if( length == 0 ) {
                add_last( value );
            } else if( length == 1 ) {
                tail = head;
                head = new node;
                head->data = value;
                head->link = tail;
                //cout << head->data << endl;
                length += 1;
            } else {
                node *temp;
                temp = new node;
                temp->data = value;
                temp->link = head;
                head = temp;
                //cout << head->data << endl;
                length += 1;
            }
        } //End of add_front


                        //---- Node Removal:

        void remove_last( void ) {
                if( length > 1 ) {
                    node *curr;
                    curr = head;
                    for( int index = 1; index < (length-1); index += 1 ) {
                        curr = curr->link;
                        //cout << "Pre deletion link: " << curr->data << endl;
                    }
                    delete (curr->link);
                    curr->link = NULL;
                }
                else {
                    delete head;
                    head = NULL;
                }
        } //End of remove last

        //
        void remove_first( void ) {
            if( length != 1 ) {
                node *temp;
                temp = head->link;
                //
                delete head;
                head = temp;
            } else {
                delete head;
                head = NULL;
            }
        } //End of remove first


    public:
    //Variables:
        int length;

     //----- Public functions:

        // Constructor and destructor
        linked_list() {
            head = NULL;
            tail = NULL;
            length = 0;
        }

        ~linked_list () {
            cout << "class removed" << endl;
        }

                //------ Node insertion:

        void insert_node( int value , int pos ) {
            if( pos >= 0 ) {
                if( pos == 0 ) {
                    add_front( value );
                }
                else if( (pos>=1) && (pos<length) ) {
                    //cout << "inside list" << endl;
                    node *curr;
                    curr = head;
                    for( int index = 1; index < length ; index += 1 ) {
                        if( index == pos ) {
                            node *temp;
                            temp = new node;
                            temp->data = value;
                            //
                            temp->link = (curr->link);
                            curr->link = temp;
                            //
                            break;
                            //cout << "Out of for loop" << endl;
                            }
                        curr = curr->link;
                        //cout << "scanning " << index << endl;
                    }
                    length +=1;
                }
                else {
                    //cout << "Outside list - adding empty spaces" << endl;
                    for( int index = length ; index <= pos ; index += 1 ) {
                            if( index < pos ) {
                                add_last( 0 );
                            } else {
                                add_last( value );
                            }
                    }
                }
            } else {
                cout << "Cannot accept negative index" << endl;
            }
        }   //End of insert node


                //------ Node deletion:

        void delete_link( int pos ) {
            if( pos >= 0 ) {
                if( (pos >= 0) && (pos < length) ) {
                    if( pos == 0 ) {
                        //cout << "removing first" << endl;
                        remove_first();
                    }
                    else if ( (pos > 0) && (pos < (length-1) ) ) {
                        //cout << "removing middle" << endl;
                        node *curr;
                        curr = head;
                        for( int index = 1; index < (length-1) ; index += 1 ) {
                            if( index == pos ) {
                                node *temp;
                                temp = curr->link->link;
                                //
                                delete curr->link;
                                //
                                curr->link = temp;
                                //
                                break;
                            }
                            curr = curr->link;
                        }
                    }
                    else {
                        cout << "removing last" << endl;
                        remove_last();
                    }
                    //
                    length -= 1;
                }
                else {
                    cout << "No data to delete" << endl;
                }
            } else {
                cout << "Cannot accept negative index" << endl;
            }
        } //End of delete_link


                //-----Printing and saving:

        void output_list ( void ) {
            if( length != 0) {
                node *curr;
                curr = head;
                //
                for( int index = 0; index < length ; index += 1)  {
                    cout << curr->data << endl;
                    curr = curr->link;
                }
            }
            else {
                cout << "No data to print" << endl;
            }
        } //End of print list

        void output_list( char file_name[] ) {
            if( length != 0) {
                ofstream DataFile;;
                DataFile.open( file_name );
                //
                node *curr;
                curr = head;
                //
                for( int index = 0; index < length ; index += 1)  {
                    cout << curr->data << endl;
                    //
                    DataFile << curr->data << "\n";
                    curr = curr->link;
                }
                DataFile.close();
            }
            else {
                cout << "No data to print and save" << endl;
            }
        } //End of output_list

}; //End of class



//Main function:
int main()
{
    //---- Part 1: linear list [Given]

    cout << "-- Linear list: \nLinear list output: " << endl;
    LinearList <int> NewList;

    //#1: Create a list of the following elements:
    //[11,10,9,8,7,6,5,4,3,2,1]

    NewList.Insert(0, 11);
    NewList.Insert(1, 10);
    NewList.Insert(2, 9);
    NewList.Insert(3, 8);
    NewList.Insert(4, 7);
    NewList.Insert(5, 6);
    NewList.Insert(6, 5);
    NewList.Insert(7, 4);
    NewList.Insert(8, 3);
    NewList.Insert(9, 2);
    //Last entry is not loaded properly ?
    //NewList.Insert(10, 11);

    //#2: Delete element #5 (counting from 0):
    int temp = 6;
    NewList.Delete(5, temp);

    //#3: Insert element 100 at position 8 (counting from 0):
    temp = 100;
    NewList.Insert(8, temp);

    //#4: Modify the Output function to save the list to a file. The name of the file is provided as an argument:
    NewList.Output("Raul.Gonzalez.aList.txt");
    cout << endl;


    //---- Part 2: linked list [custom]
    cout << "-- Part 2: Linked list." << endl;
    linked_list listA;

    //#1: Create a list of the following elements:
    //    [11,10,9,8,7,6,5,4,3,2,1]
    listA.insert_node(11, 0);
    listA.insert_node(10, 1);
    listA.insert_node(9, 2);
    listA.insert_node(8, 3);
    listA.insert_node(7, 4);
    listA.insert_node(6, 5);
    listA.insert_node(5, 6);
    listA.insert_node(4, 7);
    listA.insert_node(3, 8);
    listA.insert_node(2, 9);
    listA.insert_node(1, 10);

    //#2: Delete element #5 (counting from 0):
    listA.delete_link(5);

    //#3: Insert element 100 at position 8 (counting from 0):
    listA.insert_node(100, 8);

    //#4: Modify the Output function to save the list to a file. The name of the file is provided as an argument:
    cout << "Linked list output:" << endl;
    listA.output_list("Raul.Gonzalez.lList.txt");

    return 0;
}


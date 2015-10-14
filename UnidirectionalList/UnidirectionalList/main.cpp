#include <iostream>

using namespace std;

template <class T>
class UnidirectionalList {

public:

    struct Single_List {//структура данных
        int Data; //информационное поле
        Single_List *Next; //адресное поле
    };

    Single_List *Head; //указатель на первый элемент списка

        //создание однонаправленного списка (добавления в конец)
    void Make_Single_List(T n,Single_List **Head){
        if (n > 0) {
            (*Head) = new Single_List();
                //выделяем память под новый элемент
            cout << "Введите значение ";
            cin  >> (*Head)->Data;
                //вводим значение информационного поля
            (*Head)->Next = NULL;//обнуление адресного поля
            Make_Single_List(n - 1, &((*Head)->Next));
        }
    }

        //печать однонаправленного списка
    void Print_Single_List(Single_List* Head) {
        if (Head != NULL) {
            cout << Head->Data << "\t";
            Print_Single_List(Head->Next);
                //переход к следующему элементу
        }
        else cout << "\n";
    }

        //поиск элемента в однонаправленном списке
    bool Find_Item_Single_List(Single_List* Head, T DataItem){
        Single_List *ptr; //вспомогательным указатель
        ptr = Head;
        while (ptr != NULL){//пока не конец списка
            if (DataItem == ptr->Data) return true;
            else ptr = ptr->Next;
        }
        return false;
    }

    /*освобождение памяти, выделенной под однонаправленный список*/
    void Delete_Single_List(Single_List* Head){
        if (Head != NULL){
            Delete_Single_List(Head->Next);
            delete Head;
        }
    }
};

int main(int argc, const char * argv[]) {
    UnidirectionalList<int> list;

    list.Make_Single_List(3, &(list.Head));
    list.Print_Single_List(list.Head);

    if (list.Find_Item_Single_List(list.Head, 1)) {
        cout << "Found" << endl;
    }

    list.Delete_Single_List(list.Head);

    return 0;
}

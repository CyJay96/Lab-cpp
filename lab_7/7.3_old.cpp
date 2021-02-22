#include <iostream> // for cin cout
using namespace std;
struct Node // описание элемента списка
{           // аналогичен стеку и очереди
    int d;
    Node *p; // указатель на следующий элемент списка
};
void find_eq(Node *, int, Node *&);
void find_gt(Node *, int, Node *&);
void add(Node *&, int);
void vyvod(Node *);
void del(Node *&, int);
void main(void)
{
    Node *top = NULL;
    add(top, 1); // заносим первый элемент в список
    for (int i = 5; i > 1; i--)
        add(top, i); // добавляем элементы в список
    // ключи вводятся по убыванию,
    // но в список заносятся по возрастанию
    vyvod(top);  // выводим содержимое списка на экран
    del(top, 3); // удаляем элемент списка с ключом = 3
    vyvod(top);  // выводим содержимое списка на экран
}
// функция нахождения элемента c ключом =key
// top - адрес начала списка
// ppv - адрес элемента списка, указывающего на найденный
void find_eq(Node *top, int key, Node *&ppv)
{
    Node *pv = top;
    ppv = top;
    //поиск элемента c ключом = key
    while (pv && pv->d != key)
    {
        ppv = pv; // запоминаем адрес предыдущего элемента
        pv = pv->p;
    }
}
// функция нахождения элемента c ключом >key
// top - адрес начала списка
// ppv - адрес элемента списка, указывающего на найденный
void find_gt(Node *top, int key, Node *&ppv)
{
    Node *pv = top;
    ppv = top;
    //поиск элемента c ключом > key
    while (pv && pv->d <= key)
    {
        ppv = pv; // запоминаем адрес предыдущего элемента
        pv = pv->p;
    }
}
//функция занесения элемента c ключом key в список
// по возрастанию ключей
// top - указатель начала списка
void add(Node *&top, int key)
{
    Node *ppv = NULL;
    Node *nv = new Node; // образуем новый элемент списка
    nv->d = key;
    nv->p = NULL;
    if (!top)     // если список пуст
        top = nv; // первый элемент списка
    else
    {
        if (top->d >= key) // вставляем в начало списка
        {
            nv->p = top;
            top = nv;
        }
        else
        {
            find_gt(top, key, ppv);
            // поиск по ключу места для нового элемента
            nv->p = ppv->p;
            // вставляем между элементами с адресами ppv и pv
            ppv->p = nv;
        }
    }
}
// функция просмотра и вывода элементов списка на экран
void vyvod(Node *top)
{
    while (top)
    {
        cout << top->d << ' ';
        top = top->p;
    }
    cout << "\n";
}
// функция удаления элемента c ключом key
// top - указатель начала списка
void del(Node *&top, int key)
{
    Node *pv, *ppv;
    // поиск элемента с ключом = key
    find_eq(top, key, ppv);
    pv = ppv->p;
    if (pv) // если нашли
    {
        if (top->d == key) // удаляем первый элемент
            top = top->p;
        else
            ppv->p = pv->p; // удаляем элемент из середины
        // или конца списка
        delete pv; // освобождение памяти
    }
}
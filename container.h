#ifndef CONTAINER_H
#define CONTAINER_H
#include "myexception.h"
#include "validator.h"

template <typename T>
class Container {
public:
    class iterator; // foward declare

private:
    class node {
        /*
         * tutto è private e ci sono due classi friend
         * per vincolare node a essere usato solo in Container<T>
        */

        T* info;
        node* previous, * next;

        /* costruttore nodo
         * info: puntatore al nodo da inserire
         * previous: nodo precedente
         * next: nodo successivo
         */
        node(T* info, node* previous = nullptr, node* next = nullptr)
            : info(info), previous(previous), next(next) {
            if (previous)
                previous->next = this;
            if (next)
                next->previous = this;
        }

        // evito di avere un costruttore di copia
        node(const node&) = delete;

        // abolisco l'assegnamento
        node& operator = (const node&) = delete;

        // distruttore
        ~node() {
            if (info)
                delete info;
        }

        friend class Container;
        friend class iterator;
    };

    //inizio e fine coda
    node* first, * last;

public:
    /* classe per spostarsi all'interno del
     * container
     */
    class iterator {
        /*valido tutti gli oggetti
         */
        class accept_all : public Validator<T> {
            // qui implemento i metodi virtuali puri di Validator<T>
            bool operator () (const T&) const { return true; }
            accept_all* clone() const { return new accept_all; }
        };
        Validator<T>* validate;
        node* current;

        /* costruttore per scorrere il container con solo oggetti validati
         */
        iterator(node* first, Validator<T>* validate = nullptr) : validate(validate), current(first) {
            if (!validate)
                this->validate = new accept_all;
            // vai avanti fino al primo elemento validato
            if (current && !(*(this->validate))(*(current->info)))
                operator ++();
        }

        // elimina l'oggetto, privata solo utilizzabile da Container<T>
        void trash() const {
            if (!current)
                return;
            if (current->previous)
                current->previous->next = current->next;
            if (current->next)
                current->next->previous = current->previous;
            delete current;
        }


        friend class Container;

    public:

        iterator(const iterator& it)
            : validate(it.validate->clone()), current(it.current) {}

        // Assignment operator per finire la rule of three
        iterator& operator = (const iterator& it) {
            if (validate)
                delete validate;
            validate = it.validate->clone();
            current = it.current;
        }

        // delete dell' oggetto
        virtual ~iterator() {
            delete validate;
        }

        // per verificare se l'iteratore ha finito il container, cast a bool
        operator bool() const {
            return current;
        }

        //  passa al nodo seguente nella sequenza
        // (ho scelto di non fare anche l'operatore postfisso it++, ma tenere solo ++it )
        T* operator ++() {
            if (current)
                do { current = current->next; } while (current && !(*validate)(*(current->info)));
            return current ? current->info : nullptr;
        }

        // accedi all'elemento come referenza
        T& operator * () const { return *(current->info); }

        // accedi all'elemento come puntatore
        T* operator ->() const { return current->info; }
    };

    // container vuoto
    Container() : first(nullptr), last(nullptr) {}

    // non permetto la costruzione di copia
    Container(const Container<T>& rhs) = delete;
    virtual ~Container() {
        while (first)
            remove(begin());
    }

    // inserisce un elemento all' inizio della lista
    void push_front(T* info) {
        first = new node(info, nullptr, first);
        if (!last)
            last = first;
    }

    //  inserisce un elemento all' inizio della lista
    void push_front(const T& info) {
        push_front(new T(info));
    }

    // inserisce un elemento alla fine della lista
    void push_back(T* info) {
        last = new node(info, last, nullptr);
        if (!first)
            first = last;
    }

    // per inserisce un elemento alla fine della lista
    void push_back(const T& info) {
        push_back(new T(info));
    }

    /* serve ad iterare su Container
       fa un controllo con validate sul nodo first per vedere se è valido
     */
    iterator select(Validator<T>* validate) const {
        return iterator(first, validate);
    }

    // iteratore all inizio di una lista
    iterator begin() const {
        return iterator(first);
    }

    // iteratore all ultimo oggetto della lista
    iterator end() const {
        return iterator(last);
    }

    /* per rimuovere un oggetto dalla lista;
       serve controllare se sia all inizio o alla fine
       per far si che fist e last puntino a valori validi
    */
    void remove(iterator it) {
        if (it.current == first)
            first = first->next;
        else if (it.current == last)
            last = last->previous;
        it.trash();
    }
    //libero il container
    void free(){
        while(first){
            first->~node();
            first = first->next;
        }
    }
};

#endif // CONTAINER_H

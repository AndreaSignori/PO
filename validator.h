#ifndef VALIDATOR_H
#define VALIDATOR_H

/*
 * class Validator
 * classe base astratta che controlla se ciò che sta all'interno
 * delle parentesi è valido o no restituendo un bool.
 */
template <typename T>
class Validator {
public:
    // distruttore virtuale, perchè base della gerarchia
    virtual ~Validator() {}

    // metodo clone per clonare l'istanza
    virtual Validator<T>* clone() const = 0;

    // overload di operator() per ritornare il bool di controllo
    virtual bool operator () (const T &) const = 0;
};

#endif // VALIDATOR_H

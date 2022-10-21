#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <iomanip>

namespace Item {

class Item {

    private: 

        std::string _nome;
        double _preco;

    protected:

        void set_nome(std::string nome);
        void set_preco(double preco);

    public: 

        Item();
        Item(std::string nome, double preco);
        ~Item();

        std::string get_nome();
        double get_preco(); 

        void print_dados();   

};

}

#endif
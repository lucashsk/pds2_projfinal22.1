#include "Item.hpp"

namespace Item {

    const std::string ESPACAMENTO_LISTAGEM = "    ===   ";

    void Item::set_nome(std::string nome)   { this->_nome = nome;   }
    void Item::set_preco(double preco)      { this->_preco = preco; }

    double Item::get_preco()        { return this->_preco;  }
    std::string Item::get_nome()    { return this->_nome;   }

    Item::Item () {}
    Item::Item(std::string nome, double preco) {
        
        set_nome(nome); set_preco(preco);
    }

    Item::~Item() {

        set_nome("");   set_preco(0.0);
    }

    void Item::print_dados() {

        std::cout << "|Item|: " <<std::setw(20) << std::left
            << get_nome() << ESPACAMENTO_LISTAGEM; 

        std::cout  << std::setw(10) << std::left
            << std::setprecision(2) << std::fixed
            << "|Preço|: R$ " << get_preco() << std::endl;

    }

}
#include "Frigobar.hpp"
#include <algorithm>

namespace Frigobar
{

    double Frigobar::get_valor_consumido() { return this->_valor_consumido; }

    bool Frigobar::ordem_alfabetica(Item::Item item1, Item::Item item2) {
        return item1.get_nome().front() < item2.get_nome().front();
    }

    void Frigobar::repor_todos_os_itens() {

        std::vector<Item::Item> bebida;
        std::vector<Item::Item> comida;

        Item::Item bebida1("Refrigerante - Lata", 5.50); bebida.push_back(bebida1);
        Item::Item bebida2("Agua - 500ml", 4.00); bebida.push_back(bebida2);
        Item::Item bebida3("Suco - Lata", 6.00); bebida.push_back(bebida3);
        Item::Item bebida4("Cerveja - Long Neck", 10.00); bebida.push_back(bebida4);
        Item::Item bebida5("Vinho - Garrafa", 80.00); bebida.push_back(bebida5);


        Item::Item comida1("Chocolate - Barrinha", 4.00); comida.push_back(comida1);
        Item::Item comida2("Pacote de Chips", 5.00); comida.push_back(comida2);
        Item::Item comida3("Amendoim", 6.00); comida.push_back(comida3);
        Item::Item comida4("Bolinho", 2.50); comida.push_back(comida4);
        Item::Item comida5("Barrinha de cereal", 3.00); comida.push_back(comida5);

        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++) 
                inserir_comida(comida[i]);
        
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++) 
                inserir_bebida(bebida[i]);   
    }

    Frigobar::Frigobar() {

        this->_valor_consumido = 0;
        repor_todos_os_itens();
    }

    Frigobar::~Frigobar() {

        this->_comidas.clear();
        this->_bebidas.clear();
    }

    void Frigobar::inserir_comida(Item::Item comida) {

        if (this->_comidas.size() < Frigobar::CAPACIDADE_COMIDAS)
            this->_comidas.push_back(comida);
        // else lançamento de exceção
    }

    void Frigobar::inserir_bebida(Item::Item bebida) {

        if (this->_bebidas.size() < Frigobar::CAPACIDADE_BEBIDAS)
            this->_bebidas.push_back(bebida);
        // else lançamento de exceção
    }
    // -> tentar ver depois como faz por operator
    void Frigobar::print_itens_disponiveis() {
        std::cout << "\n*** ITENS DISPONÍVEIS \n";

        int i = 1;

        std::cout << "\n* COMIDAS \n\n";
        

        std::vector<Item::Item>::iterator it;
        for (it = this->_comidas.begin(); it < this->_comidas.end(); ++it) {

            if (i < 10)
                std::cout << "0" << i << ". ";
            else
                std::cout << i << ". ";

            it->print_dados(); // alterar possivelment indicando a quantidade
            i++;
        }

        /*

        std::sort (this->_bebidas.begin(), this->_bebidas.end());
        */

        std::cout << "\n* BEBIDAS \n\n";

        for (it = this->_bebidas.begin(); it < this->_bebidas.end(); ++it) {

            if (i < 10)
                std::cout << "0" << i << ". ";
            else
                std::cout << i << ". ";

            it->print_dados(); // alterar possivelment indicando a quantidade
            i++;
        }
        std::cout << std::endl;
    }

    void Frigobar::retirar_item(int id) {

        int tam_vec_comidas = static_cast<int>(this->_comidas.size());

        std::vector<Item::Item>::iterator item_da_posicao;

        if (id <= tam_vec_comidas) {
            item_da_posicao = this->_comidas.begin() + (id - 1);
            _valor_consumido += item_da_posicao->get_preco();
            this->_comidas.erase(item_da_posicao);
        }

        else {
            item_da_posicao = this->_bebidas.begin()+( (id-1) - this->_comidas.size() );
            _valor_consumido += item_da_posicao->get_preco();
            this->_bebidas.erase(item_da_posicao);
            // isso pq as comidas sao listadas antes
        }
    }

}

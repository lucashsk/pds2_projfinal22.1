#ifndef FRIGOBAR_HPP
#define FRIGOBAR_HPP

#include "Item.hpp"
#include <vector>
#include <map>

namespace Frigobar {

    class Frigobar {

        static const int CAPACIDADE_BEBIDAS = 20;
        static const int CAPACIDADE_COMIDAS = 30;

        private:

            /*
            std::map<std::string, Item::Item> comidas;
            std::map<std::string, Item::Item> bebidas;
            */
        
            std::vector<Item::Item> _comidas;
            std::vector<Item::Item> _bebidas;
            double _valor_consumido;

            void inserir_comida(Item::Item comida);
            void inserir_bebida(Item::Item bebida);
            void repor_todos_os_itens();

            bool ordem_alfabetica(Item::Item item1, Item::Item item2);

        
        public:

            Frigobar();
            ~Frigobar();

            void retirar_item(int id);

            void print_itens_disponiveis();

            double get_valor_consumido();
    };

}

#endif
#ifndef HOTEL_HPP
#define HOTEL_HPP

#include "Quarto.hpp"
#include <map>

namespace Hotel {

    class Hotel {

        friend class Sistema;

        private:

            std::map<int, Quarto::Quarto*> _quartos;  

            void adicionar_quarto(int num, int tipo); 
            void preencher_quartos();         

        public:

            Hotel();
            ~Hotel();

            bool quarto_ocupado (int num_do_quarto);

            void print_quartos(bool somente_disponiveis = false);
            void print_quartos_disponiveis();
            void pesquisar_estado_de_ocupacao(int num_do_quarto);

            Quarto::Quarto* get_quarto(int num_do_quarto);
            
    };
}

#endif 
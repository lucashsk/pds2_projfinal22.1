#ifndef QUARTO_HPP
#define QUARTO_HPP

#include "Item.hpp"
#include "Frigobar.hpp"
#include "FormataDados.hpp"

namespace Quarto {

enum tipo_do_quarto {
    PADRAO_1_CAMA,
    PADRAO_2_CAMAS,
    PADRAO_3_CAMAS,
    SUITE_LUXO,
    SUITE_PREMIUM,
    NONE
};

enum preco_diaria {
    PRECO_PADRAO1 = 150,
    PRECO_PADRAO2 = 225,
    PRECO_PADRAO3 = 300,
    PRECO_LUXO = 500,
    PRECO_PREMIUM = 1000
};
class Quarto {

    private:

        int  _tipo;
        int _num_do_quarto;
        bool _estado_de_ocupacao;
        bool _estado_de_reserva;

        Frigobar::Frigobar* _frigobar;

        void set_num_do_quarto(int numero);
        void set_tipo(int tipo);

    public: 

        Quarto();
        Quarto(int numero, int tipo);
        ~Quarto();

        void set_ocupacao(bool estado);
        void set_reserva(bool estado);

        bool is_ocupado();
        bool is_reservado();

        int get_num_do_quarto();
        double get_preco_diaria();
        std::string get_tipo_do_quarto();
        std::string get_data_inicio_da_reserva();
        std::string get_data_fim_da_reserva();

        void ocupar();
        void liberar();  
        void print_dados();

        Frigobar::Frigobar* acessar_frigobar(); 
    
};

}

#endif 
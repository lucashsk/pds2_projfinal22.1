#ifndef RESERVA_HPP
#define RESERVA_HPP

#include "DadosCadastrais.hpp"
#include "Quarto.hpp"

namespace Reserva {

class Reserva {

    private:

        int _id;
        std::string _data_de_inicio;
        std::string _data_final;

        Quarto::Quarto* _quarto;

        void set_data_de_inicio(std::string data_de_inicio);
        void set_data_final(std::string data_final);


    public:

        static int contador_id;

        Reserva();
        Reserva(std::string data_de_inicio, std::string data_final, 
            Quarto::Quarto* quarto);
        ~Reserva();

        double calcular_preco();

        std::string get_data_de_inicio();
        std::string get_data_final();
        std::string get_tipo_de_quarto();
        int get_num_quarto();
        int get_id();

        void print_dados();
        void print_simples();

};

}

#endif
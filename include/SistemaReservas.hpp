#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include "Hotel.hpp"
#include "Reserva.hpp"
#include <map>

namespace Sistema {

    class Sistema {

        private:

            std::map<int, Reserva::Reserva*> _reservas;
            Hotel::Hotel* _hotel;

        public:

            Sistema();
            ~Sistema();

            void fazer_reserva(std::string data_de_inicio,
                std::string data_final, int id_quarto);
            void remover_reserva(int id);
            void consultar_reserva(int id);
            void printar_todas_reservas();

            Hotel::Hotel& consultas_quartos();

    };
}

#endif
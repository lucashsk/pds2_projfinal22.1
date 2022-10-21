#include "SistemaReservas.hpp"

namespace Sistema {

Sistema::Sistema() {

    this->_hotel = new Hotel::Hotel;
}

Sistema::~Sistema() {

    for (int i = this->_reservas.size(); i > 0; i--) 
            remover_reserva(i);
        
    delete this->_hotel;
}

void Sistema::fazer_reserva(std::string data_de_inicio,
    std::string data_final, int id_quarto) {

    if (!this->_hotel->quarto_ocupado(id_quarto)) {
        this->_reservas.insert(std::pair<int,Reserva::Reserva*>
                (Reserva::Reserva::contador_id, 
                    new Reserva::Reserva(data_de_inicio, 
                        data_final, this->_hotel->get_quarto(id_quarto))));
        this->_hotel->get_quarto(id_quarto)->ocupar();
    }
    else { //EXCEPTION SE DER TEMPO
        std::cout << "O quarto desejado encontra-se indisponível no momento." 
            << std::endl;
        exit(1);
    }
}

void Sistema::remover_reserva(int id) {

    if (this->_reservas[id] != nullptr) {
        delete this->_reservas[id];
        this->_reservas.erase(id);
        std::cout << "A reserva de n° " << id << " foi removida com sucesso.\n";
    }
    else { 
        std::cout << "Não há nenhuma reserva com esse número cadastrada no sistema." 
        << std::endl; // OUTRO CASO DE EXCEPTION SE DER TEMPO
        exit(1);
    }
}

void Sistema::consultar_reserva(int id) {

    this->_reservas[id]->print_dados();
}

void Sistema::printar_todas_reservas() {

    if (this->_reservas.size() != 0)
        for (auto it : this->_reservas)
            it.second->print_simples();
    else std::cout << "Ainda não há reservas cadastradas no sistema." 
        << std::endl << "Todos os quartos encontram-se disponíveis." 
        << std::endl;
}

 Hotel::Hotel& Sistema::consultas_quartos() {

    return *this->_hotel;
 }

}
#include "Reserva.hpp"

const std::string DATA_NENHUMA = "00/00/0000";
namespace Reserva {

int Reserva::contador_id = 9000; //arbitrario

void Reserva::set_data_de_inicio(std::string data_de_inicio) { 
    this->_data_de_inicio = Formata::formata_data(data_de_inicio);  
}
void Reserva::set_data_final(std::string data_final) { 
    this->_data_final = Formata::formata_data(data_final);          
}

std::string Reserva::get_data_de_inicio()   { return this->_data_de_inicio;                 }
std::string Reserva::get_data_final()       { return this->_data_final;                     }
std::string Reserva::get_tipo_de_quarto()   { return this->_quarto->get_tipo_do_quarto();   }
int Reserva::get_num_quarto()               { return this->_quarto->get_num_do_quarto();    }
int Reserva::get_id()                       { return this->_id;                             }

Reserva::Reserva() {}
Reserva::Reserva(std::string data_inicio, std::string data_fim, 
    Quarto::Quarto* quarto) {

    this->_id = Reserva::contador_id+1; Reserva::contador_id++;
    set_data_de_inicio(data_inicio);
    set_data_final(data_fim);
    this->_quarto = quarto;
}

Reserva::~Reserva() {

    set_data_de_inicio(DATA_NENHUMA);
    set_data_final(DATA_NENHUMA);
    this->_quarto->liberar();
    this->_quarto = nullptr;
}

double Reserva::calcular_preco() {
    
    double preco = 0;
    preco += this->_quarto->get_preco_diaria();
    preco += this->_quarto->acessar_frigobar()->get_valor_consumido();

    return preco;
}

void Reserva::print_dados() {

    std::cout << "\n# INFORMAÇÕES DA RESERVA - ID = "
        << this->get_id() << std::endl;

    this->_quarto->print_dados();

    std::cout 
        << "|Data do check-in|: " << get_data_de_inicio() << std::endl
        << "|Data do check-out|: " << get_data_final() << "\n" << std::endl;
}

void Reserva::print_simples() {

    std::cout << std::endl
        << "ID da reserva: " << this->get_id() << "\t" 
        << "N° do quarto atribuído: " << this->get_num_quarto()
        << std::endl;
}

}
#include "Quarto.hpp" 

namespace Quarto {

//setters
void Quarto::set_num_do_quarto(int numero)  { this->_num_do_quarto = numero;        }
void Quarto::set_ocupacao(bool estado)      { this->_estado_de_ocupacao = estado;   }    
void Quarto::set_reserva(bool estado)       { this->_estado_de_reserva = estado;    }
void Quarto::set_tipo(int tipo)             { this->_tipo = tipo;                   }

//getters
bool Quarto::is_ocupado()                   { return this->_estado_de_ocupacao;     }
bool Quarto::is_reservado()                 { return this->_estado_de_reserva;      }
int Quarto::get_num_do_quarto()             { return this->_num_do_quarto;          }

std::string Quarto::get_tipo_do_quarto() { 

    switch (this->_tipo) {
        case PADRAO_1_CAMA:
            return "PADRAO_1_CAMA";
            break;
        case PADRAO_2_CAMAS: 
            return "PADRAO_2_CAMAS";
            break;
        case PADRAO_3_CAMAS:
            return "PADRAO_3_CAMAS";
            break;
        case SUITE_LUXO:
            return "SUITE_LUXO";
            break;
        case SUITE_PREMIUM:
            return "SUITE_PREMIUM"; 
            break;
        default:
            return "NONE";    
    }      
}

double Quarto::get_preco_diaria() {
  
       switch (this->_tipo) {
        case PADRAO_1_CAMA:
            return PRECO_PADRAO1;
            break;
        case PADRAO_2_CAMAS: 
            return PRECO_PADRAO2;
            break;
        case PADRAO_3_CAMAS:
            return PRECO_PADRAO3;
            break;
        case SUITE_LUXO:
            return PRECO_LUXO;
            break;
        case SUITE_PREMIUM:
            return PRECO_PREMIUM; 
            break;
        default:
            return 0;    
    }      
}

//construtores e destrutores
Quarto::Quarto() {}
Quarto::Quarto (int numero, int tipo) {
    set_num_do_quarto(numero); 
    set_tipo(tipo);
    set_ocupacao(false);
    set_reserva(false);

    this->_frigobar = new Frigobar::Frigobar;
}

Quarto::~Quarto() {
    set_num_do_quarto(0); 
    set_tipo(NONE);
    set_ocupacao(false);
    set_reserva(false);

    delete this->_frigobar;
}

//metodos
void Quarto::ocupar()   { set_ocupacao(true);   }
void Quarto::liberar()  { set_ocupacao(false);  }

Frigobar::Frigobar* Quarto::acessar_frigobar() { return this->_frigobar; }

void Quarto::print_dados() {
    
    std::cout 
        << "\n|Número do quarto|: " << get_num_do_quarto() << std::endl
        << "|Preço da diária|: R$ " << std::setprecision(2) << std::fixed
        << get_preco_diaria() << std::endl
        << "|Tipo do quarto|: " << get_tipo_do_quarto() << std::endl;
}

}
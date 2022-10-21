#include "Hotel.hpp"
#include <iomanip> //setw e setfill
#include <sstream>

namespace Hotel {

    // referencia a partir do numero de quartos PADRAO1_CAMA
    const int QTD_QUARTOS_REF = 50;
    const int REF_ANDAR = 1000;
    const int IMPRESSOES_pLINHA = 10;

    Hotel::Hotel() {

        preencher_quartos();
    }

    Hotel::~Hotel() {
         
        for (int i = this->_quartos.size(); i > 0; i--) {
            delete this->_quartos[i];
            this->_quartos.erase(i);
        }
    }

    void Hotel::adicionar_quarto(int num, int tipo) {

        this->_quartos.insert(std::pair<int,Quarto::Quarto*>
            (num, new Quarto::Quarto(num, tipo)));
    }

    void Hotel::preencher_quartos() {
  
        int qtd_quartos = QTD_QUARTOS_REF;
        for (int tipo = Quarto::PADRAO_1_CAMA; tipo <= Quarto::SUITE_PREMIUM; tipo++){
            for (int indice = 1; indice <= qtd_quartos; indice++) {
                this->adicionar_quarto((REF_ANDAR*(tipo+1))+indice, tipo); //correcao, tipo0 = 0
            } qtd_quartos -= 5;
        }
    }

    void Hotel::print_quartos(bool somente_disponiveis) {

        std::cout << "\n===QUARTOS NO HOTEL===";

        int numero = 0; 
        int andar = 0; 
        int andar_anterior = 0;
        int impressoes = 0;

        for (auto it : this->_quartos) { 

            numero = it.second->get_num_do_quarto();

            andar = numero/REF_ANDAR;
            if (andar > andar_anterior) {
                std::cout << "\n\n" << andar << "° ANDAR" << "\n\n";
                andar_anterior = andar;
                impressoes = 0;
            }   

            if (somente_disponiveis) {
                if (!it.second->is_ocupado())
                    std::cout << numero << " | ";
                else std::cout << "----" << " | ";
            } else std::cout << numero << " | ";

            impressoes++;
            if (impressoes == IMPRESSOES_pLINHA) {
                std::cout << std::endl;
                impressoes = 0;
            }
        }
        std::cout << std::endl;
    }

    void Hotel::print_quartos_disponiveis() { print_quartos(true); }

    void Hotel::pesquisar_estado_de_ocupacao(int num_do_quarto) {

        std::cout << "\nO quarto n° " << num_do_quarto << " encontra-se ";
        if (this->_quartos[num_do_quarto]->is_ocupado())
            std::cout << "OCUPADO\n\n";
        else std::cout << "DISPONÍVEL\n\n";

    }

    bool Hotel::quarto_ocupado(int num_do_quarto) {

        if (this->_quartos[num_do_quarto]->is_ocupado())
            return true;
        else return false;
    }

    Quarto::Quarto* Hotel::get_quarto(int num_do_quarto) {

        return this->_quartos[num_do_quarto];
    }
}
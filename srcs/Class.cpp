#include "Class.h"

Periodicas::Periodicas(int computacao, int periodo, int deadline, char letra){
    this->computacao = computacao;
    this->periodo = periodo;
    this->deadline = deadline;
    this->letraP = letra;
}

Periodicas::Periodicas(){
    this->computacao = 0;
    this->periodo = 0;
    this->deadline = 0;
    this->auxComputacao = 0;
    this->letraP = ' ';
}

Periodicas::~Periodicas(){
}

int Periodicas::getComputacao(){
    return this->computacao;
}

int Periodicas::getPeriodo(){
    return this->periodo;
}

int Periodicas::getDeadline(){
    return this->deadline;
}

char Periodicas::getLetra(){
    return this->letraP;
}

int Periodicas::getAuxComputacao(){
    return this->auxComputacao;
}

void Periodicas::setAuxComputacao(){
    this->auxComputacao = this->computacao;
}

Aperiodicas::Aperiodicas(int computacao, int chegada, char letra){
    this->computacao = computacao;
    this->chegada = chegada;
    this->letraAP = letra;
}

Aperiodicas::Aperiodicas(){
    this->computacao = 0;
    this->chegada = 0;
    this->letraAP = ' ';
}

Aperiodicas::~Aperiodicas(){
}

int Aperiodicas::getComputacao(){
    return this->computacao;
}   

int Aperiodicas::getChegada(){
    return this->chegada;
}

char Aperiodicas::getLetra(){
    return this->letraAP;
}

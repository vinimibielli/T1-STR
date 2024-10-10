#include "./include/Class.h"

Periodicas::Periodicas(int computacao, int periodo, int deadline, char letra, int pid){
    this->computacao = computacao;
    this->periodo = periodo;
    this->deadline = deadline;
    this->letraP = letra;
    this->pid = pid;

}

Periodicas::Periodicas(){
    this->computacao = 0;
    this->periodo = 0;
    this->deadline = 0;
    this->letraP = ' ';
    this->pid = -1;
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

int Periodicas::getPid(){
    return this->pid;
}

void Periodicas::setPid(int pid){
    this->pid = pid;
}   

Aperiodicas::Aperiodicas(int chegada, int computacao, char letra, int pid){
    this->computacao = computacao;
    this->chegada = chegada;
    this->letraAP = letra;
    this->pid = pid;
}

Aperiodicas::Aperiodicas(){
    this->computacao = 0;
    this->chegada = 0;
    this->letraAP = ' ';
    this->pid = -1;
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

int Aperiodicas::getPid(){
    return this->pid;
}

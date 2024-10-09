#include <iostream>
#include <string>
#include "CPU.h"

Cpu::Cpu() {
	grid = "";
	numPreemp = numContSwitch = 0;
	pid = -1;
	symbol = ' ';
	comput = 0;
	time = 0;
	deadline = -1;
}

Cpu::~Cpu() {}

void Cpu::load(int p, char s, int c, int d) {
	symbol = s;
	deadline = d;
	if (pid == -1)
		pid = p;
	else {
		if (pid != p) {
			pid = p;
			++numContSwitch;
			if (comput > 0)
				++numPreemp;
		}
	}
	comput = c;
}

void Cpu::run() {
	if (pid != -1) {
		if (deadline!=-1 && time>=deadline)
			grid.append(1, tolower(symbol));
		else
			grid.append(1, symbol);
		++time;
		comput--;
	}
	else {
		++time;
		grid.append(1, '_');
	}
}

std::string Cpu::getGrid() {
	return grid;
}

int Cpu::getNumPreemp() {
	return numPreemp;
}

int Cpu::getNumContSwitch() {
	return numContSwitch;
}

void Cpu::execute(std::vector<Periodicas> periodicas, std::vector<Aperiodicas> aperiodicas){
    std::vector<Periodicas> TP = periodicas;
    std::vector<Aperiodicas> TA = aperiodicas;

    std::cout << aperiodicas[0].getLetra() << std::endl;

    for(int i = 0; i < periodicas.size(); i++){
        std::cout << "Tarefa " << periodicas[i].getLetra() << ": (" << periodicas[i].getComputacao() << ", " << periodicas[i].getPeriodo() << ", " << periodicas[i].getDeadline() << ")" << std::endl;
    }

    for(int i = 0; i < aperiodicas.size(); i++){
        std::cout << "Tarefa " << aperiodicas[i].getLetra() << ": (" << aperiodicas[i].getComputacao() << ", " << aperiodicas[i].getChegada() << ")" << std::endl;
    }
}
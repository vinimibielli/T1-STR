#ifndef CPU_H
#define CPU_H
#include <string>
#include <vector>
#include "Class.h"

class Cpu {
private:
	int pid;
	char symbol;
	int numPreemp;
	int numContSwitch;
	std::string grid;
	int comput;
	int deadline;
	unsigned int time;
public:
	Cpu();
	~Cpu();
	void load(int p, char s, int c, int d);
	void run();
	std::string getGrid();
	int getNumPreemp();
	int getNumContSwitch();
    void execute(std::vector<Periodicas> periodicas, std::vector<Aperiodicas> aperiodicas);
};

#endif

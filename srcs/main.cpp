#include <iostream>
#include <string>
#include <vector>
#include "CPU.h"

std::vector<Periodicas> ordeningPeriodicas(std::vector<Periodicas> periodicas)
{
    std::vector<Periodicas> ordenadas = periodicas;
    int menor = 0;
    for (int i = 0; i < ordenadas.size(); i++)
    {
        menor = ordenadas[i].getPeriodo();
        for (int j = i; j < ordenadas.size(); j++)
        {
            if (ordenadas[j].getPeriodo() < menor)
            {
                Periodicas aux = ordenadas[i];
                ordenadas[i] = ordenadas[j];
                ordenadas[j] = aux;
            }
        }
    }

    return ordenadas;
}

std::vector<Aperiodicas> ordeningAperiodicas(std::vector<Aperiodicas> aperiodicas)
{
    std::vector<Aperiodicas> ordenadas = aperiodicas;
    int menor = 0;
    for (int i = 0; i < ordenadas.size(); i++)
    {
        menor = ordenadas[i].getChegada();
        for (int j = i; j < ordenadas.size(); j++)
        {
            if (ordenadas[j].getChegada() < menor)
            {
                Aperiodicas aux = ordenadas[i];
                ordenadas[i] = ordenadas[j];
                ordenadas[j] = aux;
            }
        }
    }

    return ordenadas;
}

int main()
{

    std::vector<Periodicas> periodicas;
    std::vector<Aperiodicas> aperiodicas;
    int numTP, numTA, tempo, computacao, periodo, deadline, chegada;
    char letra = 'A';
    Cpu cpu;
    int pid = 0;

    std::cout << "Digite o tempo total de execucao, o numero de tarefas periodicas e o numero de tarefas aperiodicas: " << std::endl;
    std::cin >> tempo >> numTP >> numTA;

    if (numTP == 0 && numTA == 0)
    {
        std::cout << "Nao ha tarefas a serem executadas." << std::endl;
        return 0;
    }

    if (numTP > 0)
    {
        std::cout << "Digite o tempo de computacao, o periodo e o deadline das tarefas periodicas: " << std::endl;

        for (int i = 0; i < numTP; i++)
        {
            std::cin >> computacao >> periodo >> deadline;
            if (computacao == 0 || periodo == 0 || deadline == 0)
            {
                i--;
                continue;
            }
            Periodicas p(computacao, periodo, deadline, letra, pid);
            periodicas.push_back(p);
            letra++;
            pid++;
        }
    }

    if (numTA > 0)
    {
        std::cout << "Digite o tempo de chegada e de computacao das tarefas aperiodicas: " << std::endl;

        for (int i = 0; i < numTA; i++)
        {
            std::cin >> chegada >> computacao;
            Aperiodicas a(chegada, computacao, letra, pid);
            aperiodicas.push_back(a);
            letra++;
            pid++;
        }
    }

    std::vector<Periodicas> ordenadasTP = ordeningPeriodicas(periodicas);
    std::vector<Aperiodicas> ordenadasTA = ordeningAperiodicas(aperiodicas);

    for(int i = 0; i < periodicas.size(); i++){
        std::cout << "Tarefa " << periodicas[i].getLetra() << ": (" << periodicas[i].getComputacao() << ", " << periodicas[i].getPeriodo() << ", " << periodicas[i].getDeadline() << ")" << std::endl;
    }

    for(int i = 0; i < aperiodicas.size(); i++){
        std::cout << "Tarefa " << aperiodicas[i].getLetra() << ": (" << aperiodicas[i].getComputacao() << ", " << aperiodicas[i].getChegada() << ")" << std::endl;
    }

	cpu.execute(ordenadasTP, ordenadasTA, tempo, pid);

	// cpu.load((0<<5)|0,'A',4,10);
	// cpu.run();
	// cpu.run();
	// cpu.run();
	// cpu.run();
	// cpu.load((0<<5)|1,'B',8,20);
	// cpu.run();
	// cpu.run();
	// cpu.run();
	// cpu.run();
	// cpu.run();
	// cpu.run();
	// cpu.load((1<<5)|0,'A',4,20);
	// cpu.run();
	// cpu.run();
	// cpu.run();
	// cpu.run();
	// cpu.load((0<<5)|1,'B',2,20);
	// cpu.run();
	// cpu.run();
	// cpu.load((0<<5)|2,'C',1,-1);
	// cpu.run();
	// cpu.load((0<<5)|3,'D',1,-1);
	// cpu.run();
	// cpu.load(26,'.',100000,-1);
	// cpu.run();
	// cpu.run();
	// cpu.load((2<<5)|0,'A',4,30);



	std::cout << cpu.getGrid() << std::endl;
	std::cout << cpu.getNumContSwitch() << " " << cpu.getNumPreemp() << std::endl;

	return 0;
    }


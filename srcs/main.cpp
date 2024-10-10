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
    std::vector<std::pair<int,std::pair<std::vector<Periodicas>, std::vector<Aperiodicas>>>> total;
    int numTP, numTA, tempo, computacao, periodo, deadline, chegada;
    char letra = 'A';
    Cpu cpu;
    int pid = 0;

    while(true){
    std::cout << "Digite o tempo total de execucao, o numero de tarefas periodicas e o numero de tarefas aperiodicas: " << std::endl;
    std::cin >> tempo >> numTP >> numTA;

    if (numTP == 0 && numTA == 0 && tempo == 0)
    {
        break;
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
    total.push_back(std::make_pair(tempo, std::make_pair(ordenadasTP, ordenadasTA)));
    periodicas.clear();
    aperiodicas.clear();
    letra = 'A';
    pid = 0;

    }

    std::cout << "Total de tarefas: " << total.size() << std::endl;

    for(int i = 0; i < total.size(); i++){

    cpu = Cpu();

    for(int j = 0; j < total[i].second.first.size(); j++){
        std::cout << "Tarefa " << total[i].second.first[j].getLetra() << ": (" << total[i].second.first[j].getComputacao() << ", " << total[i].second.first[j].getPeriodo() << ", " << total[i].second.first[j].getDeadline() << ")" << std::endl;
    }

    for(int j = 0; j < total[i].second.second.size(); j++){
        std::cout << "Tarefa " << total[i].second.second[j].getLetra() << ": (" << total[i].second.second[j].getComputacao() << ", " << total[i].second.second[j].getChegada() << ")" << std::endl;
    }

	cpu.execute(total[i].second.first, total[i].second.second, total[i].first, total[i].second.second[0].getPid());

	std::cout << cpu.getGrid() << std::endl;
	std::cout << cpu.getNumPreemp() << " " << cpu.getNumContSwitch() << std::endl;
    for(auto i : cpu.getgridTempo()){
        std::cout << i.second << " (" << i.first.first << " " << i.first.second << ")" << std::endl;
    }
    }

	return 0;
    }


#include <iostream>
#include <fstream>

using namespace std;

/***************************************************************/
/*
 * Principio da reponsabilidade unica
 * Refere-se ao cuidado em não atribuir mais reponsabilidades do que o necessario,
 * onde, ao inves disso, criar funções que poderão ser utilizadas
 * de maneira mais genericas, reaproveitando codigo
 */
// Estrutura Contato
struct Contato
{
    string nome;
    string telefone;

    // Construtor da esturutar
    explicit Contato(const string &nome, const string &telefone) : nome{nome}, telefone{telefone} {}

    // Não recomendado pois a persistencia não deve ser de responsabilidade do contato
    // void salva (string nome_arquivo);
};

/**
 * Metodo que faz parte da estrutra do contato
 * Comentado pois de acordo com o principio de responsabilidade unica,
 * a persistencia nao deveria ser de responsabilidade de Contato
 */
/*
void Contato::salva(string arquivo)
{
    ofstream ofs(arquivo);
    ofs << "Nome: " << nome << " - Telefone: " << telefone << endl;
}
*/

/**
 * Estutura reponsavel pela persistencia dos registros
 * Maneira mais recomendada pois se houver mais de um tipo de registro,
 * as funções de persistencia podem ser adicionadas aqui, mantendo a persistencia
 * dos registros sob responsabilidade de uma unica estrutura
 */
struct PersisteRegistro
{
    static void salva(Contato &contato, string arquivo)
    {
        ofstream ofs(arquivo);
        ofs << "Nome: " << contato.nome << " - Telefone: " << contato.telefone << endl;
    }
};

void CriaRegistro()
{
    Contato contato_1{"Jose da Silva", "(42) 9999-8888"};

    //contato_1.salva("agenda.txt");

    PersisteRegistro persist;
    persist.salva(contato_1, "agenda.txt");
}


int main()
{
    cout << "Hallison Oliveira - Design Patterns em C++" << endl;

    
}
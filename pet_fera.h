#ifndef _PETFERA_H_
#define _PETFERA_H_

#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <sstream>
#include <algorithm> // Para utilizar o std::transform e std::toupper
#include <sstream> 	// Converter cadeias de caracters em int
#include <fstream> // Arquivo

using namespace std;

// Declaração da classe abstrata Animal.
class ANIMAL{
	protected:
		int id;
		string classe;
		string nome;
		string nome_cientifico;
		char sexo;
		double tamanho;
		string dieta;
		string veterinario;
		string tratador;
		string nome_batismo;
	public:
		virtual int getId() = 0;
		string getClasse();
		string getNome();
		string getNome_cientifico();
		char getSexo();
		double getTamanho();
		string getDieta();
		string getVeterinario();
		string getTratador();
		string getNome_batismo();
		// Construtor.
		ANIMAL(int i, string c, string no, string n, char s, double tam, string die, string vet, string trat, string nome);
		// Destrutor.
		~ANIMAL();
};

// Declaração da classe abstrata Animal Silvestre.
class ANIMAL_SILVESTRE{
	protected:
		string autorizacao_IBAMA;
	public:
		// Getter.
		virtual string getAutorizacao_IBAMA() = 0;
		// Construtor.
		ANIMAL_SILVESTRE(string aut);
		// Destrutor.
		~ANIMAL_SILVESTRE();
};

// Declaração da classe Animal Nativo.
class ANIMAL_NATIVO: public ANIMAL, ANIMAL_SILVESTRE{
	protected:
		string uf_origem;
		string autorizacao;
	public:
		// Getters.
		string getUf_origem();
		string getAutorizacao();
		string getAutorizacao_IBAMA();
		virtual int getId() = 0;
		// Construtor.
		ANIMAL_NATIVO(int i, string c, string no, string n, char s, double tam, string die, string vet, string trat, string nome, string aut, string u, string a);
		// Destrutor.
		~ANIMAL_NATIVO();
};

// Declaração da classe Animal Exótico.
class ANIMAL_EXOTICO: public ANIMAL, ANIMAL_SILVESTRE{
	protected:
		string pais_origem;
		string autorizacao;
	public:
		// Getters.
		string getPais_origem();
		string getAutorizacao();
		string getAutorizacao_IBAMA();
		// Construtor.
		ANIMAL_EXOTICO(int i, string c, string no, string n, char s, double tam, string die, string vet, string trat, string nome, string aut, string p, string a);
		// Destrutor.
		~ANIMAL_EXOTICO();
};

// Declaração da classe Anfíbio.
class ANFIBIO{
	protected:
		int total_mudas;
		string ultima_muda;
	public:
		// Gettters
		int getTotal_mudas();
		string getUltima_muda();
		// Construtor.
		ANFIBIO(int mudas, string data); 
		// Destrutor.
		~ANFIBIO();

};

// Declaração da classe Anfíbio Nativo.
class ANFIBIO_NATIVO: public ANIMAL_NATIVO, ANFIBIO{
	public:
		// Construtor.
		ANFIBIO_NATIVO(int i, string c, string no, string n, char s, double tam, string die, string vet, string trat, string nome, int mudas, string data, string aut, string u, string a);
		ANFIBIO_NATIVO();
		// Destrutor.
		~ANFIBIO_NATIVO();
		int getId();

		friend ostream& operator << (ostream &out, ANFIBIO_NATIVO &m);
		friend ofstream& operator << (ofstream &out, ANFIBIO_NATIVO &m);
		
};

// Declaração da classe Anfíbio Exótico.
class ANFIBIO_EXOTICO: public ANIMAL_EXOTICO, ANFIBIO{
	public:
		// Construtor.
		ANFIBIO_EXOTICO();

		ANFIBIO_EXOTICO(int i, string c, string no, string n, char s, double tam, string die, string vet, string trat, string nome, int mudas, string data, string aut, string pais, string a);

		// Destrutor.
		~ANFIBIO_EXOTICO();
		int getId();


		friend ostream& operator << (ostream &out, ANFIBIO_EXOTICO &m);
		friend ofstream& operator << (ofstream &out, ANFIBIO_EXOTICO &m);
		
};

// Declaração da classe Mamífero.
class MAMIFERO{
	protected:
		string cor_pelo;
	public:
		// Getters.
		//int getId();
		string getCor_pelo();
		// Construtor.
		MAMIFERO(string cor);
		// Destrutor.
		~MAMIFERO();

};

// Declaração da classe Mamífero Nativo.
class MAMIFERO_NATIVO: public ANIMAL_NATIVO, MAMIFERO{
	public:
		// Construtor.
		MAMIFERO_NATIVO();
		MAMIFERO_NATIVO(int i, string c, string no, string n, char s, double tam, string die, string vet, string trat, string nome, string cor, string aut, string u, string a);
		// Destrutor.
		~MAMIFERO_NATIVO();
		int getId();

		friend ostream& operator << (ostream &out, MAMIFERO_NATIVO &m);
		friend ofstream& operator << (ofstream &out, MAMIFERO_NATIVO &m);
};

// Declaração da classe Mamífero Exótico.
class MAMIFERO_EXOTICO: public ANIMAL_EXOTICO, MAMIFERO{
	public:
		// Construtor.
		MAMIFERO_EXOTICO();
		MAMIFERO_EXOTICO(int i, string c, string no, string n, char s, double tam, string die, string vet, string trat, string nome, string cor, string aut, string pais, string a);
		// Destrutor.
		~MAMIFERO_EXOTICO();
		int getId();

		friend ostream& operator << (ostream &out, MAMIFERO_EXOTICO &m);
		friend ofstream& operator << (ofstream &out, MAMIFERO_EXOTICO &m);
};

// Declaração da classe Réptil.
class REPTIL{
	protected:
		bool venenoso;
		string tipo_veneno;
	public:
		// Getters.
		bool getVenenoso();
		string getTipo_veneno();
		// Construtor.
		REPTIL(bool v, string t);
		// Destrutor.
		~REPTIL();

		friend ostream& operator << (ostream &out, REPTIL &r);
};

// Declaração da classe Réptil Nativo.
class REPTIL_NATIVO: public ANIMAL_NATIVO, REPTIL{
	public:
		// Construtor.
		REPTIL_NATIVO();
		REPTIL_NATIVO(int i, string c, string no, string n, char s, double tam, string die, string vet, string trat, string nome, bool v, string t, string aut, string u, string a);
		// Destrutor.
		~REPTIL_NATIVO();
		int getId();

		friend ostream& operator << (ostream &out, REPTIL_NATIVO &r);
		friend ofstream& operator << (ofstream &out, REPTIL_NATIVO &r);
};

// Declaração da classe Réptil Exótico.
class REPTIL_EXOTICO: public ANIMAL_EXOTICO, REPTIL{
	public:
		// Construtor.
		REPTIL_EXOTICO();
		REPTIL_EXOTICO(int i, string c, string no, string n, char s, double tam, string die, string vet, string trat, string nome, bool v, string t, string aut, string pais, string a);
		// Destrutor.
		~REPTIL_EXOTICO();
		int getId();

		friend ostream& operator << (ostream &out, REPTIL_EXOTICO &r);
		friend ofstream& operator << (ofstream &out, REPTIL_EXOTICO &r);
};

// Declaração da classe Ave.
class AVE{
	private:
		double tamanho_bico;
		double envergadura;
	public:
		// Getters.
		double getTamanho_bico();
		double getEnvergadura();
		// Construtor.
		AVE(double t, double e);
		// Destrutor.
		~AVE();

};

// Declaração da classe Ave Nativa.
class AVE_NATIVO: public ANIMAL_NATIVO, AVE{
	public:
		// Construtor.
		AVE_NATIVO();
		AVE_NATIVO(int i, string c, string no, string n, char s, double tam, string die, string vet, string trat, string nome, double t, double e, string aut, string u, string a);
		// Destrutor.
		~AVE_NATIVO();
		int getId();
		
		friend ostream& operator << (ostream &out, AVE_NATIVO &a);
		friend ofstream& operator << (ofstream &out, AVE_NATIVO &v);
};

// Declaração da classe Ave Exótica.
class AVE_EXOTICO: public ANIMAL_EXOTICO, AVE{
	public:
		// Construtor.
		AVE_EXOTICO();
		AVE_EXOTICO(int i, string c, string no, string n, char s, double tam, string die, string vet, string trat, string nome, double t, double e, string aut, string pais, string a);
		// Destrutor.
		~AVE_EXOTICO();
		int getId();

		friend ostream& operator << (ostream &out, AVE_EXOTICO &a);
		friend ofstream& operator << (ofstream &out, AVE_EXOTICO &v);
};

// Declaração da classe abstrata Funcionário.
class FUNCIONARIO{
	protected:
		int id;
		string nome;
		long int cpf;
		int idade;
		string tipo_sanguineo;
		char fator_rh;
		string especialidade;
	public:
		// Setters.
		void setId(int i);
		void setNome(string n);
		void setCpf(long int c);
		void setIdade(int i);
		void setTipo_sanguineo(string t);
		void setFator_rh(char f);
		void setEspecialidade(string e);
		// Getters.
		virtual int getId() = 0;
		string getNome();
		long int getCpf();
		int getIdade();
		string getTipo_sanguineo();
		char getFator_rh();
		string getEspecialidade();

};

// Declaração da classe Veterinário.
class VETERINARIO: public FUNCIONARIO{
	private:
		string crmv;
	public:
		// Construtor..
		VETERINARIO(int i, string n, long int c, int ida, string t, char f, string e, string cr);
		VETERINARIO();
		// Setters..
		void setCrmv(string c);
		// Getters..
		string getCrmv();
		int getId();

		friend ostream& operator << (ostream &out, VETERINARIO &v);
		friend ofstream& operator << (ofstream &out, VETERINARIO &v);

};

// Declaração da classe Tratador.
class TRATADOR: public FUNCIONARIO{
	private:
		int nivel_seguranca;
	public:
		// Construtor.
		TRATADOR(int i, string n, long int c, int ida, string t, char f, string e, int nivel);
		TRATADOR();
		// Setters.
		void setNivel_seguranca(int nivel);
		// Getters.
		int getNivel_seguranca();
		int getId();

		friend ostream& operator << (ostream &out, TRATADOR &t);
		friend ofstream& operator << (ofstream &out, TRATADOR &t);

};

// Função de carregamento de todos os arquivos.
void carregar_arquivos(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex, map <int, VETERINARIO> &vets, map <int, TRATADOR> &tratadores);

// Sobrecarga de função de checagem de condições.
bool check_CPF(map <int, TRATADOR> &tratadores, long int cpf);//verifica se o cpf já está cadastrado.
bool check_CPF(map <int, VETERINARIO> &vets, long int cpf);
bool check_vet(map <int, VETERINARIO> &vets, string nome);
bool check_tratador(map <int, TRATADOR> &tratadores, string nome);
bool verifica_ID(map <int, TRATADOR> &tratadores, string id_string, char &sucesso); //verifica se o Id digitado é int positivo e único;
bool verifica_seguranca(string nivel_seg_string, char &sucesso); //verifica se o nível de segurança é válido;
bool verifica_ID(map <int, VETERINARIO> &vets, string id_string, char &sucesso);//verifica se o Id digitado é int positivo e único;
bool verifica_nome(string &nome, char &sucesso);//verifica se o nome digitado possui somente letras;
bool verifica_CPF(string cpf_string, char &sucesso);//verifica se o cpf contêm apenas inteiros positivos;
bool verifica_idade(string idade_string, char &sucesso);//verifica se a idade contêm apenas inteiros positivos;
bool verifica_tipo_sang(string &tipo_sang_string, char &sucesso);//verifica se o tipo sanguineo está dentro das opções existentes;
bool verifica_fator(string fator_rh_string, char &sucesso);//verifica se o fator é + ou -;
bool verifica_especialidade(string especialidade, char &sucesso);//verifica se especialidade contêm apenas letras;
bool verifica_CRMV(map <int, VETERINARIO> &vets, string crmv, char &sucesso);//verifica se o crmv foi inserido no formato correto;
bool verifica_dieta(string &dieta, char &sucesso);//verifica se a dieta foi inserida no formato correto;
bool verifica_ID(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, char tipo, string id_string, char &sucesso); //verifica id caso o anfibios seja nativo ou exótico;
bool verifica_tamanho(string tamanho_string, char &sucesso); //Verifica se o tamanho do animal é um double;
bool verifica_inteiro(string total_mudas_string, char &sucesso); //Verifica se a string passada só tem numeros inteiros;
bool verifica_data(string ultima_muda, char &sucesso); //Verifica se a data está no formato correto.
bool verifica_autorizacao(string autorizacao, char &sucesso); //Verifica se a autorizacao foi inserida corretamente;
bool verifica_origem(string &origem, char &sucesso); //Verifica se foi passado uma string.
bool verifica_nome_cient(string &nome, char &sucesso); //Verifica se o nome cientifico foi passado de forma correta, diferente do nome convencional o nome cientifico pode ter '-';

// Sobrecarga de função do cadastramento.
void cadastrar_func(map <int, VETERINARIO> &vets, map <int, TRATADOR>  &tratadores);
void cadastrar(map <int, VETERINARIO> &vets);
void cadastrar(map <int, TRATADOR>  &tratadores);
void cadastrar_animal(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex, map <int, VETERINARIO> vets, map <int, TRATADOR> tratadores); 
void cadastrar(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, VETERINARIO> vets, map <int, TRATADOR> tratadores);
void cadastrar(map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, VETERINARIO> vets, map <int, TRATADOR> tratadores);
void cadastrar(map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, VETERINARIO> vets, map <int, TRATADOR> tratadores);
void cadastrar(map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex, map <int, VETERINARIO> vets, map <int, TRATADOR> tratadores);

// Sobrecarga de função de edição.
void editar_animais(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex);
void editar(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex);
void editar(map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex);
void editar(map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex);
void editar(map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex);
void editar_func(map <int, VETERINARIO> &vets, map <int, TRATADOR> &tratadores);
void editar(map <int, VETERINARIO> &vets);
void editar(map <int, TRATADOR> &tratadores);

// Sobrecarga de função de remoção.
void remover_animal(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex);
void remover(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex);
void remover(map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex);
void remover(map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex);
void remover(map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex);
void remover_funcionario(map <int, VETERINARIO> &vets, map <int, TRATADOR>  &tratadores);
void remover(map <int, VETERINARIO> &vets);
void remover(map <int, TRATADOR>  &tratadores);

// Sobrecarga de função de pesquisa e impressão por classe.
void pesquisar_classe(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex);
void imprimir_classe(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex);
void imprimir_classe(map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex);
void imprimir_classe(map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex);
void imprimir_classe(map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex );

// Funções de pesquisa e impressão por funcionario responsável.
void consulta_p_func(map <int, VETERINARIO> &vets, map <int, TRATADOR>  &tratadores, map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex);
void consulta_p_tratador(map <int, TRATADOR> &tratadores, map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex);
void consulta_p_veterinario(map <int, VETERINARIO> &vets, map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex);
void imprime_animais(char tipo, string nome, map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex);

#endif




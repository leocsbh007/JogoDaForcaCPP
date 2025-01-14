#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <locale>

using namespace std;

map <char, bool> chutou;
vector <char> chutes_errados;
string s_palavraSorteada;

bool bLetraExiste(char chute){    
    for(char letra : s_palavraSorteada)
    {
        if (letra == chute){
            return true;
        }
    }
    return false;
}

bool bNaoAcertou(){
    for (char letra : s_palavraSorteada){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}

bool bNaoEnforcou(){
    return chutes_errados.size() < 5;
}

void vImprimeCabecalho(){
    cout << "***********************" << endl;
    cout << "*****JOGO DA FORCA*****" << endl;
    cout << "***********************" << endl;      
}

void vPrintErrors (){    
    cout << "Chutes Errados: ";
    for (char letra : chutes_errados){
        
        cout << letra << " ";
    }         
    cout << endl;
}

void vPrintWord(){ 

    for (char letra : s_palavraSorteada)
    {
        if(chutou[letra]){
            cout << letra << " ";
        }
        else{
            cout << "_ ";
        }
    }
    cout << endl;
}

void vKick(){
    
    cout << "Seu Chute: ";
    char chute;
    cin >> chute;
    chute = toupper(chute);

    chutou[chute] = true;

    if (bLetraExiste(chute)){
        cout << "Você acertou! Seu chute esta na palavra" << endl;
    }
    else {
        cout << "Você errou! Seu chute não esta na palavra" << endl;
        chutes_errados.push_back(chute);
    }

    cout << endl;
}

vector<string> vecLeArquivo(){
    ifstream if_arquivo;
    int i_quantidadePalavras;    
    if_arquivo.open("palavras.txt");

    if (if_arquivo.is_open()){
        if_arquivo >> i_quantidadePalavras;
        vector<string> vec_palvrasArquivo;
    
        for (int i = 0; i < i_quantidadePalavras; i++ ){
            string s_palavraLida;
            if_arquivo >> s_palavraLida;        
            vec_palvrasArquivo.push_back(s_palavraLida);
        }
        if_arquivo.close();
        return vec_palvrasArquivo;
    }
    else {
        cout << "Não foi possivel acessar o banco de palavras." << endl;
        exit(0);
    }
}

void vSorteiaPalavra(){
    vector<string> s_palavras = vecLeArquivo();

    srand(time(NULL)); // Seta o periodo de tempo - semente dos números aleatórios:
    int i_IndicePalavra = rand() % s_palavras.size(); // Escolhe o indece da palavra usando o rand e resto de divisão com o tam do vetor
                                                    // O Valor sempre será (size - 1)
    s_palavraSorteada = s_palavras[i_IndicePalavra];
}

void vSalvaArquivo(string s_novaPalavra){
    vector<string> vec_novaListaPalavras = vecLeArquivo();
    ofstream of_arquivo;    

    of_arquivo.open("palavras.txt");

    if (of_arquivo.is_open()){  
        of_arquivo << vec_novaListaPalavras.size() + 1 << endl;

        for(string s_palavra : vec_novaListaPalavras){
            of_arquivo << s_palavra << endl;
        }
        of_arquivo << s_novaPalavra << endl;

        of_arquivo.close();
    }
    else {
        cout << "Não foi possivel acessar o banco de palavras." << endl;
        exit(0);
    }
}

void vAdicionaPalavra(){
    string s_novaPalavra;
    cout << "Digite a Nova palavra: ";
    cin >> s_novaPalavra;
    // Transforma todos os caracteres para maiusculo
    for (char &c_letra : s_novaPalavra){
        c_letra = toupper(static_cast <unsigned > (c_letra));
    }
    vSalvaArquivo(s_novaPalavra);
}

int main(){    
    setlocale(LC_ALL, "Portuguese_Brazil");
    vImprimeCabecalho();
    vSorteiaPalavra();    
    
    while (bNaoAcertou() && bNaoEnforcou())
    {
        vPrintErrors();
        vPrintWord();
        vKick();        
    }

    cout << "FIM DE JOGO!" << endl;
    cout << "A palavra secreta era: " << s_palavraSorteada << endl;
    if(bNaoAcertou()){
        cout << "Você perdeu. Tente novamente!" << endl;
    }
    else {
        cout << "Parabéns você Venceu!" << endl;
        cout << "Deseja adicionar uma nova palavra ao banco de palavras? (S/N): ";
        
        char c_opcao;
        cin >> c_opcao;
        c_opcao = toupper(c_opcao);
        if (c_opcao == 'S'){
            vAdicionaPalavra();
        }
        cout << "Obrigado por Participar!!!" << endl;       
    }

    return 0;
}
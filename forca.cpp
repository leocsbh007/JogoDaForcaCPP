#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <locale>

using namespace std;

map <char, bool> chutou;
vector <char> chutes_errados;
const string PALAVRA_SECRETA = "MELANCIA";



bool letra_existe(char chute){    
    for(char letra : PALAVRA_SECRETA)
    {
        if (letra == chute){
            return true;
        }
    }
    return false;
}

bool nao_acertou(){
    for (char letra : PALAVRA_SECRETA){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}

bool nao_enforcou(){
    return chutes_errados.size() < 5;
}

void imprime_cabecalho(){
    cout << "***********************" << endl;
    cout << "*****JOGO DA FORCA*****" << endl;
    cout << "***********************" << endl;      
}

void print_errors (){    
    cout << "Chutes Errados: ";
    for (char letra : chutes_errados){
        
        cout << letra << " ";
    }         
    cout << endl;
}

void print_word(){ 

    for (char letra : PALAVRA_SECRETA)
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

void kick(){
    
    cout << "Seu Chute: ";
    char chute;
    cin >> chute;
    
    chutou[chute] = true;

    if (letra_existe(chute)){
        cout << "Você acertou! Seu chute esta na palavra" << endl;
    }
    else {
        cout << "Você errou! Seu chute não esta na palavra" << endl;
        chutes_errados.push_back(chute);
    }

    cout << endl;
}

int main(){    
    setlocale(LC_ALL, "Portuguese_Brazil");
    imprime_cabecalho();
    
    
    while (nao_acertou() && nao_enforcou())
    {
        print_errors();
        print_word();
        kick();        
    }

    cout << "FIM DE JOGO!" << endl;
    cout << "A palavra secreta era: " << PALAVRA_SECRETA << endl;
    if(nao_acertou()){
        cout << "Você perdeu. Tente novamente!" << endl;
    }
    else {
        cout << "Parabéns você Venceu!" << endl;

    }

    

    return 0;
}
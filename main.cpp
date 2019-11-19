#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;
/////////////////////////////////////////////////////////////////////////////////////Estruturas
struct item{
    string vocabulo;
    string classificacao;
    string definicao;
};
struct NO{
    item info;
    NO *esquerda;
    NO *direita;
};
struct ArvoreBinaria{
    NO *raiz;
};
void CreateArvore(ArvoreBinaria &mytree){
    mytree.raiz = NULL;
}
/////////////////////////////////////////////////////////////////////////////////////Auxiliares
string Compara(string v1,string v2){    //Compara Strings para determinar seu valor para ordenação em arvore
    int cont=0,valor=0,valor1=0,valor2=0;
    int tamanho1=strlen(v1.c_str()),tamanho2=strlen(v2.c_str());    //Armazena o tamanho das strings (Strlen)
    if(tamanho1 == tamanho2){   //Caso em que string tem mesmo tamanho: Compara strings até encontrar um caracter diferente
        while(v1.at(cont) == v2.at(cont)){
            cont +=1;
        }
    }
    else if(tamanho1 > tamanho2){   //Compara string até encontrar charactere diferente ou o tamanho da string 2 se esgotar
        for(int i=0;i<tamanho2;i++){
            if(v1.at(cont)==v2.at(cont)){cont += 1;}
            else {goto Jump;}   //Muda a direção do programa para a parte de atribuição de valor caso alguma letra seja diferente
        }
        return v1;  //caso o limite tenha chegado, a palavra maior terá maior valor, logo ela é retornada
    }
    else{
        for(int i=0;i<tamanho1;i++){
            if(v1.at(cont)==v2.at(cont)){cont += 1;}
            else {goto Jump;}
        }
        return v2;
    }
    Jump:   //Marcador de GOTO
    switch(v1.at(cont)){    //Atribuição de valor da primeira string
        case 'a':valor+=1;break;case 'b':valor+=2;break;case 'c':valor+=3;break;case 'd':valor+=4;break;
        case 'e':valor+=5;break;case 'f':valor+=6;break;case 'g':valor+=7;break;case 'h':valor+=8;break;
        case 'i':valor+=9;break;case 'j':valor+=10;break;case 'k':valor+=11;break;case 'l':valor+=12;break;
        case 'm':valor+=13;break;case 'n':valor+=14;break;case 'o':valor+=15;break;case 'p':valor+=16;break;
        case 'q':valor+=17;break;case 'r':valor+=18;break;case 's':valor+=19;break;case 't':valor+=20;break;
        case 'u':valor+=21;break;case 'v':valor+=22;break;case 'w':valor+=23;break;case 'x':valor+=24;break;
        case 'y':valor+=25;break;case 'z':valor+=26;break;
        }
        valor1 = valor; //passa o valor encontrado para uma variavel separada
        valor =0;   //reseta o contador
    switch(v2.at(cont)){    //atribuição de valor para a string 2
        case 'a':valor+=1;break;case 'b':valor+=2;break;case 'c':valor+=3;break;case 'd':valor+=4;break;
        case 'e':valor+=5;break;case 'f':valor+=6;break;case 'g':valor+=7;break;case 'h':valor+=8;break;
        case 'i':valor+=9;break;case 'j':valor+=10;break;case 'k':valor+=11;break;case 'l':valor+=12;break;
        case 'm':valor+=13;break;case 'n':valor+=14;break;case 'o':valor+=15;break;case 'p':valor+=16;break;
        case 'q':valor+=17;break;case 'r':valor+=18;break;case 's':valor+=19;break;case 't':valor+=20;break;
        case 'u':valor+=21;break;case 'v':valor+=22;break;case 'w':valor+=23;break;case 'x':valor+=24;break;
        case 'y':valor+=25;break;case 'z':valor+=26;break;
    }
    valor2 = valor;
    if(valor1 > valor2){return v1;}   //retorna a string de maior valor para correta inserção em arvore
    else if(valor1<valor2){return v2;}
}
/////////////////////////////////////////////////////////////////////////////////////Operações
void Cadastrar(NO *&SubRaiz, string vocabulo,string classificacao,string definicao){
    NO *novoNO;
    if(SubRaiz == NULL){
        novoNO = new NO;
        novoNO->info.vocabulo = vocabulo;
        novoNO->info.classificacao = classificacao;
        novoNO->info.definicao = definicao;
        novoNO->esquerda = NULL;
        novoNO->direita = NULL;
        SubRaiz = novoNO;
    }
    else{//Muda o nó de acordo com o valor da string(função Compara)
        string maior;
        maior = Compara(SubRaiz->info.vocabulo,vocabulo);
        if(maior == ""){cout<<"Vocabulo ja adicionado:"<<endl;return;}
        else if(maior == SubRaiz->info.vocabulo){
            Cadastrar(SubRaiz->esquerda,vocabulo,classificacao,definicao);
        }
        else{
            Cadastrar(SubRaiz->direita,vocabulo,classificacao,definicao);
        }
    }

}
void Consultar(NO *&SubRaiz,string vocabulo){
    if(SubRaiz ==NULL){
        cout<<"Elemento nao encontrado!"<<endl;
    }
    else if(SubRaiz->info.vocabulo == vocabulo){
        cout<<"Vocabulo:"<<SubRaiz->info.vocabulo<<endl;
        cout<<"Classificacao:"<<SubRaiz->info.classificacao<<endl;
        cout<<"Significado:"<<SubRaiz->info.definicao<<endl;
    }
    else{   //Muda o nó de acordo com o valor da string(função Compara)
        string maior;
        maior = Compara(SubRaiz->info.vocabulo,vocabulo);
        if(maior == SubRaiz->info.vocabulo){
            Consultar(SubRaiz->esquerda,vocabulo);
        }
        else{
            Consultar(SubRaiz->direita,vocabulo);
        }
    }
}
void Corrigir(NO *&SubRaiz,string vocabulo){
    if(SubRaiz ==NULL){
        cout<<"Elemento nao encontrado!"<<endl;
    }
    else if(SubRaiz->info.vocabulo == vocabulo){
        string newclassificacao,newdefinicao;
        cout<<"Informe a nova Classificacao do vocabulo:";cin>>newclassificacao;
        cout<<"Informe a nova Definicao do vocabulo:";cin>>newdefinicao;
        SubRaiz->info.classificacao = newclassificacao;
        SubRaiz->info.definicao = newdefinicao;
        cout<<endl;
    }
    else{//Muda o nó de acordo com o valor da string(função Compara)
        string maior;
        maior = Compara(SubRaiz->info.vocabulo,vocabulo);
        if(maior == SubRaiz->info.vocabulo){
            Corrigir(SubRaiz->esquerda,vocabulo);
        }
        else{
            Corrigir(SubRaiz->direita,vocabulo);
        }
    }
}
void Remover(NO *&SubRaiz,string vocabulo){
    NO *aux1,*aux2;
    if(SubRaiz == NULL){
        cout<<"Elemento nao encontrado!"<<endl;
    }
    else if(SubRaiz->info.vocabulo == vocabulo){
        if(SubRaiz->esquerda==NULL && SubRaiz->direita==NULL){
            delete SubRaiz;
            return;
        }
        else if(SubRaiz->esquerda == NULL){
            aux1=SubRaiz->direita;
            delete SubRaiz;
            SubRaiz = aux1;
            return;
        }
        else if(SubRaiz->direita == NULL){
            aux1=SubRaiz->esquerda;
            delete SubRaiz;
            SubRaiz = aux1;
            return;
        }
        else{
            aux1 = SubRaiz;
            aux2 = SubRaiz->esquerda;
            while(aux2->direita != NULL){
                aux1 = aux2;
                aux2 = aux2->direita;   //elemento mais a direita da subarvore a esquerda do nó a ser retirado
            }
            if(aux1!=SubRaiz){
                aux1->direita = aux2->esquerda;
                aux2->esquerda = SubRaiz->esquerda;
            }
            aux1->direita = SubRaiz->direita;
            delete SubRaiz;
            SubRaiz = aux2;
        }
    }
    else{//Muda o nó de acordo com o valor da string(função Compara)
        string maior;
        maior = Compara(SubRaiz->info.vocabulo,vocabulo);
        if(maior == SubRaiz->info.vocabulo){
            Remover(SubRaiz->esquerda,vocabulo);
        }
        else{
            Remover(SubRaiz->direita,vocabulo);
        }
    }
}
void Imprimir(NO *&SubRaiz){
    if(SubRaiz != NULL){
        Imprimir(SubRaiz ->esquerda);
        cout<<SubRaiz->info.vocabulo<<":  "<<SubRaiz->info.classificacao<<"|"<<SubRaiz->info.definicao<<endl;
        Imprimir(SubRaiz -> direita);
    }
}
///////////////////////////////////////////////////////////////////////////////////////Main
int main(){
    ArvoreBinaria mytree;
    CreateArvore(mytree);

    int escolha,valor;
    jump1:  //Marcador de escolha de opção
    cout<<"informe a acao que se deseja fazer:(1:Cadastrar,2:consultar,3:corrigir,4:remover:,5:imprimir,0:Sair)";
    cin>> escolha;
    switch(escolha){
        case 1:{
            string vocabulo,classificacao,definicao;
            cout<<"infome o vocabulo:";cin>>vocabulo;
            cout<<"informe a classificacao:";cin>>classificacao;
            cout<<"informe a definicao:";cin>>definicao;
            Cadastrar(mytree.raiz,vocabulo,classificacao,definicao);
            break;
        }
        case 2:{
            string consulta;
            cout<<"Informe o vocabulo a ser consultado:";
            cin>>consulta;
            Consultar(mytree.raiz,consulta);break;
        }
        case 3:{
            string vocabulo;
            Imprimir(mytree.raiz);
            cout<<"informe o vocabulo a ser corrigido:";
            cin>> vocabulo;
            Corrigir(mytree.raiz,vocabulo);break;
        }
        case 4:{
            string vocabulo;
            cout<<"Informe o vocabulo a ser removido:";
            cin>>vocabulo;
            Remover(mytree.raiz,vocabulo);
        }
        case 5:Imprimir(mytree.raiz);break;

        case 0:return 0;break;

        default:cout<<"Comando Invalido!";break;
    }
    goto jump1;
    return 0;
}

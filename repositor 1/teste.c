#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
struct supervisor
{
 char nome[50];
 char setor[50];
 int idade;
 char email[50];
 int telefone;
 int salario;
};
struct funcionario
{
 char nome[50];
 char setor[50];
 int idade;
 char email[50];
 int telefone;
 int salario;
};
struct cliente
{
 char nome[50];
 char setor[50];
 int idade;
 char email[50];
 int telefone;
 int salario;
};
struct produto
{
 char produto[50];
 int codigo;
 int quantidade;
};
//////////////////////// PARA TAREFAS DIARIAS/////////////////
struct funcao
{
 char segunda[50];
 char terca[50];
 char quarta[50];
 char quinta[50];
 char sexta[50];
 char setor[50];
};
//////////////////// SENHA/////////////////////
typedef struct{
 char login[30];
 char senha[30];
 int permissao;
}
pessoa;
pessoa p[1];
////////////PROTOTIPOS DO MENU PRINCIPAL////////////////
void MenuGerente();
void MenuSupervisor();
void MenuFuncionario();
void MenuCadastro();
/////////////////MENU GERENTE///////////////
void ImprimaFuncionario();
void ImprimaCliente();
void ImprimaSupervisor();
//////////// MENU SUPERVISOR/////////////////
void FuncaoTi();
void FuncaoRh();
void FuncaoEst();
/////////////////////Menu do funcionario///////////////////
void ImprimaTarTi();
void ImprimaTarRh();
void ImprimaTarEst();
/////////////////////////Menu DE CADASTRO/////////////////
void CadastroFuncionario();
void CadastroCliente();
void CadastroSupervisor();
void ImprimaProdutos();
void retornodastar();
void ImprimaRel();
int main()
{
 setlocale(LC_ALL, "portuguese");
 char login[30];
 char senha[30];
 strcpy(p[0].login, "aris");
 strcpy(p[0].senha, "aris");
 printf("\n\n\n\n\n\n\n\n\t\t\t\t\t login:");
 scanf("%s", login);
 printf("\n\t\t\t\t\t senha:");
 scanf("%s", senha);
 if ((!strcmp(login, p[0].login)) && (!strcmp(senha,p[0].senha))){ //strcmp compara login
 printf("Usuario logado");
 system ("cls");
 int resp;
 do
 {
 printf("**************** MENU PRINCIPAL ***************\n");
 printf("* *\n");
 printf("* \t\t1 - Gerente *\n");
 printf("* \t\t2 - Supervisor *\n");
 printf("* \t\t3 - Funcionario *\n");
 printf("* \t\t4 - Cadastrar *\n");
 printf("* \t\t0 - Para sair *\n");
 printf("***********************************************\n\n");
 printf("Digite a opção selecionada:");
 scanf("%d", &resp);
 switch(resp)
 {
 case 1:
 {
 system("cls");
 MenuGerente();
 break;
 }
 case 2:
 {
 system("cls");
 MenuSupervisor();
 break;
 }
 case 3:
 {
 system("cls");
 MenuFuncionario();
 break;
 }
 case 4:
 {
 system("cls");
 MenuCadastro();
 break;
 }
 case 0:
 {
 system("cls");
 printf("Até mais!");
 break;
 }
 system("pause");
 }
 }while(resp);
 }
 else{
 printf("Login e/ou senha incorreta");
 }
 system("cls");
}
/////////////////////////////////// Menu gerente //////////////////////////////
void MenuGerente()
{
 char login[30];
 char senha[30];
 strcpy(p[0].login, "gerencia");
 strcpy(p[0].senha, "arisger");
 printf("\n\n\n\n\n\n\n\n\t\t\t\t\t login:");
 scanf("%s", login);
 printf("\n\t\t\t\t\t senha:");
 scanf("%s", senha);
 if ((!strcmp(login, p[0].login)) && (!strcmp(senha,p[0].senha))){
 printf("Usuario logado");
 int resp;
 system("cls");
 do
 {
 printf("** MENU DO GERENTE****\n");
 printf("* *\n");
 printf("* \t\t1 - Lista Funcionarios *\n");
 printf("* \t\t2 - Lista de Clientes *\n");
 printf("* \t\t3 - Lista de Supervisor *\n");
 printf("* \t\t4 - Lista de Produtos *\n");
 printf("* \t\t0 - Menu Principal *\n");
 printf("********\n\n");
 printf("Digite a opção selecionada:");
 scanf("%d" , &resp);
 switch(resp)
 {
 case 1:
 {
 system("cls");
 ImprimaFuncionario();
 break;
 }
 case 2:
 {
 system("cls");
 ImprimaCliente();
 break;
 }
 case 3:
 {
 system("cls");
 ImprimaSupervisor();
 break;
 }
 case 4:
 {
 system("cls");
 ImprimaProdutos();
 break;
 }
 case 0:
 {
 system("cls");
 printf("Até mais!");
 break;
 }
 system("pause");
 }
 }while(resp);
 }
 else{
 printf("Login e/ou senha incorretos\n");
 }
 system("cls");
}
/////////////////// FUNÇOES DO MENU DE GERENTE///////////////
void ImprimaFuncionario()
{
 struct funcionario a;
 FILE *CadFunfPtr = fopen("cadfun.txt" , "rb");
 if (CadFunfPtr == NULL)
 {
 exit (0);
 }
 fread(&a,sizeof (struct funcionario), 1, CadFunfPtr );
 while( !feof(CadFunfPtr))
 {
 fread(&a,sizeof (struct funcionario), 1, CadFunfPtr);
 printf("=======================================\n");
 printf("\t nome: %s \n" , a.nome);
 printf("\t setor:%s \n" , a.setor);
 printf("\t idade: %d \n" , a.idade);
 printf("\t email: %s \n" , a.email);
 printf("\t salario: %d \n" , a.salario);
 printf("\t telefone: %d \n" , a.telefone);
 printf("=======================================\n\n");
 fread(&a,sizeof (struct funcionario), 1, CadFunfPtr);
 }
 fclose(CadFunfPtr);
}
void ImprimaCliente()
{
 struct cliente a;
 FILE *CadClifPtr = fopen("cadCli.txt" , "rb");
 if (CadClifPtr == NULL)
 {
 exit (0);
 }
 fread(&a,sizeof (struct cliente), 1, CadClifPtr );
 while( !feof(CadClifPtr))
 {
 fread(&a,sizeof (struct cliente), 1, CadClifPtr);
 printf("=======================================\n");
 printf("*\tnome: %s \n" , a.nome);
 printf("*\tidade: %d \n" , a.idade);
 printf("*\temail: %s \n" , a.email);
 printf("\t telefone: %d \n" , a.telefone);
 printf("======================================\n\n");
 fread(&a,sizeof (struct cliente), 1, CadClifPtr);
 }
 fclose(CadClifPtr);
}
void ImprimaSupervisor()
{
 struct supervisor a;
 FILE *CadSupfPtr = fopen("cadSup.txt" , "rb");
 if (CadSupfPtr == NULL)
 {
 exit (0);
 }
 fread(&a,sizeof (struct supervisor), 1, CadSupfPtr );
 while( !feof(CadSupfPtr))
 {
 fread(&a,sizeof (struct supervisor), 1, CadSupfPtr);
 printf("*=======================================\n");
 printf("\t nome: %s \n" , a.nome);
 printf("\t idade: %d \n" , a.idade);
 printf("\t email: %s \n" , a.email);
 printf("\t salario: %d \n" , a.salario);
 printf("\t telefone: %d \n" , a.telefone);
 printf("=======================================\n\n");
 fread(&a,sizeof (struct supervisor), 1, CadSupfPtr);
 }
 fclose(CadSupfPtr);
}
void ImprimaProdutos()
{
 struct produto a;
 FILE *CadprofPtr = fopen("cadpro.txt" , "rb");
 if (CadprofPtr == NULL)
 {
 exit (0);
 }
 fread(&a,sizeof (struct produto), 1, CadprofPtr );
 while( !feof(CadprofPtr))
 {
 fread(&a,sizeof (struct produto), 1, CadprofPtr );
 printf("=============================\n");
 printf("nome: %s \n" , a.produto);
 printf("codigo:%d \n" , a.codigo);
 printf("idade: %d \n" , a.quantidade);
 printf("=============================\n");
 fread(&a,sizeof (struct produto), 1, CadprofPtr);
 }
 fclose(CadprofPtr);
}
////////////////////////////// Menu Do Supervisor///////////////////////
void MenuSupervisor()
{
 char login[30];
 char senha[30];
 strcpy(p[0].login, "supervisor");
 strcpy(p[0].senha, "arisup");
 printf("\n\n\n\n\n\n\n\n\t\t\t\t\t login:");
 scanf("%s", login);
 printf("\n\t\t\t\t\t senha:");
 scanf("%s", senha);
 if ((!strcmp(login, p[0].login)) && (!strcmp(senha,p[0].senha))){
 printf("Usuario logado");
 system("cls");
 int resp;
 do
 {
 printf("*** MENU DO SUPERVISOR ***\n");
 printf("------------------------------------------------------------------\n");
 printf("* \tSelecione o funcionario e designe suas tarefas semanais *\n");
 printf("------------------------------------------------------------------\n");
 printf("* \t\t1 - T.I *\n");
 printf("* \t\t2 - R.H *\n");
 printf("* \t\t3 - Relatorio das tarefas diarias *\n");
 printf("* \t\t0 - Menu Principal *\n");
 printf("********\n\n");
 printf("Digite a opção selecionada:");
 scanf("%d" , &resp);
 switch(resp)
 {
 case 1:
 {
 system("cls");
 FuncaoTi();
 break;
 }
 case 2:
 {
 system("cls");
 FuncaoRh();
 break;
 }
 case 3:
 {
 system("cls");
 ImprimaRel();
 break;
 }
 case 0:
 {
 system("cls");
 printf("Até mais!");
 break;
 }
 system("pause");
 }
 }while(resp);
 }
 else{
 printf("Login e/ou senha incorretos");
 }
 system("cls");
}
//////////////////////////// FUNÇOES DO MENU SUPERVISOR////////////////////////////
void FuncaoTi()
{
 FILE *FunTifPtr = fopen("FunTi.txt" , "wb");
 if(FunTifPtr == NULL)
 {
 return 1;
 }
 struct funcao a;
 fflush(stdin);
 printf("Tarefa de segunda:\n");
 gets(a.segunda);
 fflush(stdin);
 printf("Tarefa de terça:\n");
 gets(a.terca);
 fflush(stdin);
 printf("Tarefa de quarta:\n");
 gets(a.quarta);
 fflush(stdin);
 printf("Tarefa de quinta:\n");
 gets(a.quinta);
 fflush(stdin);
 printf("Tarefa de sexta:\n");
 gets(a.sexta);
 fflush(stdin);
 printf("=============================\n");
 printf("\t segunda:%s \n ", a.segunda);
 printf("\t terça:%s \n" , a.terca);
 printf("\t quarta:%s \n", a.quarta);
 printf("\t quinta:%s \n", a.quinta);
 printf("\t sexta:%s \n" , a.sexta);
 printf("=============================\n");
 fwrite(&a, sizeof (struct funcao), 1,FunTifPtr);
 //fprintf(FunTifPtr , "%s , %s , %s , %s , %s" , a.segunda , a.terca , a.quarta , a.quinta, a.sexta);
 fclose(FunTifPtr);
}
void FuncaoRh()
{
FILE *FunRhfPtr = fopen("FunRh.txt" , "wb");
 if(FunRhfPtr == NULL)
 {
 return 1;
 }
 struct funcao a;
 fflush(stdin);
 printf("Tarefa de segunda:\n");
 gets(a.segunda);
 fflush(stdin);
 printf("Tarefa de terça:\n");
 gets(a.terca);
 fflush(stdin);
 printf("Tarefa de quarta:\n");
 gets(a.quarta);
 fflush(stdin);
 printf("Tarefa de quinta:\n");
 gets(a.quinta);
 fflush(stdin);
 printf("Tarefa de sexta:\n");
 gets(a.sexta);
 fflush(stdin);
 printf("=============================\n");
 printf("\t segunda:%s \n ", a.segunda);
 printf("\t terça:%s \n" , a.terca);
 printf("\t quarta:%s \n", a.quarta);
 printf("\t quinta:%s \n", a.quinta);
 printf("\t sexta:%s \n" , a.sexta);
 printf("=============================\n");
 fwrite(&a, sizeof (struct funcao), 1,FunRhfPtr);
 //fprintf(FunRhfPtr , "%s , %s , %s , %s , %s" , a.segunda , a.terca , a.quarta , a.quinta, a.sexta);
 fclose(FunRhfPtr);
}
void FuncaoEst()
{
 FILE *CadprofPtr = fopen("cadpro.txt" , "ab");//////cria um arquivo txt
 if(CadprofPtr == NULL)
 {
 CadprofPtr = fopen("cadpro.txt" , "wb");
 if(CadprofPtr == NULL)
 {
 return 1;
 }
 }
 struct produto a;
 printf("digite o nome do Produto:\n");
 scanf("%s", a.produto);
 fflush(stdin);
////////////////// codigo ////////////////////////
 printf("digite o codigo do Produto:\n");
 scanf("%d", &a.codigo);
 fflush(stdin);
 /////////////// quantidade ////////
 printf("digite a quantidade de produtos:\n");
 scanf("%d" , &a.quantidade);
 fflush(stdin);
 printf("=============================\n");
 printf("nome: %s \n" , a.produto);
 printf("codigo:%d \n" , a.codigo);
 printf("idade: %d \n" , a.quantidade);
 printf("=============================\n");
 fwrite(&a, sizeof (struct produto), 1,CadprofPtr);
 fclose(CadprofPtr);
}
void MenuFuncionario()
{
 char login[30];
 char senha[30];
 strcpy(p[0].login, "funcionario");
 strcpy(p[0].senha, "arisfun");
 printf("\n\n\n\n\n\n\n\n\t\t\t\t\t login:");
 scanf("%s", login);
 printf("\n\t\t\t\t\t senha:");
 scanf("%s", senha);
 if ((!strcmp(login, p[0].login)) && (!strcmp(senha,p[0].senha))){
 printf("Usuario logado");
 system("cls");
 int resp;
 do
 {
 printf("*** MENU DE FUNCIONARIO*****\n");
 printf("----------------------------------------------------------------\n");
 printf("* \t\t Veja suas tarefas semanais *\n");
 printf("----------------------------------------------------------------\n");
 printf("* \t\t1 - T.I *\n");
 printf("* \t\t2 - R.H *\n");
 printf("* \t\t3 - ESTOQUE (cadastro de produtos) *\n");
 printf("* \t\t4 - Retorno das tarefas diarias *\n");
 printf("* \t\t0 - Para sair *\n");
 printf("********\n\n");
 printf("Digite a opção selecionada:");
 scanf("%d" , &resp);
 switch(resp)
 {
 case 1:
 {
 system("cls");
 ImprimaTarTI();
 break;
 }
 case 2:
 {
 system("cls");
 ImprimaTarRh();
 break;
 }
 case 3:
 {
 system("cls");
 FuncaoEst();
 break;
 }
 case 4:
 {
 system("cls");
 retornodastar();
 break;
 }
 case 0:
 {
 system("cls");
 printf("Até mais!");
 break;
 }
 system("pause");
 }
 }while(resp);
 }
 else{
 printf("Login e/ou senha incorretos");
 }
 system("cls");
}
///////////////// FUNÇÕES DO MENU DE FUNCIONARIO//////////////////////////////
void ImprimaTarTI()
{ struct funcao a;
 FILE *FunTifPtr = fopen("FunTi.txt" , "rb");
 if (FunTifPtr == NULL)
 {
 exit (0);
 }
 fread(&a,sizeof (struct funcao), 1, FunTifPtr );
 while( !feof(FunTifPtr))
 {
 fread(&a,sizeof (struct funcao), 1, FunTifPtr );
 printf("=============================\n");
 printf("\t segunda:%s \n ", a.segunda);
 printf("\t terça:%s \n" , a.terca);
 printf("\t quarta:%s \n", a.quarta);
 printf("\t quinta:%s \n", a.quinta);
 printf("\t sexta:%s \n" , a.sexta);
 printf("=============================\n");
 fread(&a,sizeof (struct funcao), 1, FunTifPtr);
 }
 fclose(FunTifPtr);
}
void ImprimaTarRh()
{
 struct funcao a;
 FILE *FunRhfPtr = fopen("FunRh.txt" , "rb");
 if (FunRhfPtr == NULL)
 {
 exit (0);
 }
 fread(&a,sizeof (struct funcao), 1, FunRhfPtr );
 while( !feof(FunRhfPtr))
 {
 fread(&a,sizeof (struct funcao), 1, FunRhfPtr );
 printf("=============================\n");
 printf("\t segunda:%s \n ", a.segunda);
 printf("\t terça:%s \n" , a.terca);
 printf("\t quarta:%s \n", a.quarta);
 printf("\t quinta:%s \n", a.quinta);
 printf("\t sexta:%s \n" , a.sexta);
 printf("=============================\n");
 fread(&a,sizeof (struct funcao), 1, FunRhfPtr);
 }
 fclose(FunRhfPtr);
}
void ImprimaRel()
{
 struct funcao a;
 FILE *RetTarfPtr = fopen("RetTar.txt" , "rb");
 if (RetTarfPtr == NULL)
 {
 exit (0);
 }
 fread(&a,sizeof (struct funcao), 1, RetTarfPtr );
 while( !feof(RetTarfPtr))
 {
 fread(&a,sizeof (struct funcao), 1, RetTarfPtr );
 printf("=============================\n");
 printf("\t setor: %s \n" , a.setor);
 printf("\t segunda:%s \n ", a.segunda);
 printf("\t terça:%s \n" , a.terca);
 printf("\t quarta:%s \n", a.quarta);
 printf("\t quinta:%s \n", a.quinta);
 printf("\t sexta:%s \n" , a.sexta);
 printf("=============================\n");
 fread(&a,sizeof (struct funcao), 1, RetTarfPtr);
 }
 fclose(RetTarfPtr);
}
void retornodastar()
{
 FILE *RetTarfPtr = fopen("RetTar.txt" , "wb");
 if(RetTarfPtr == NULL)
 {
 return 1;
 }
 struct funcao a;
 fflush(stdin);
 printf("Digite [OK] para tarefa feita ou [NF] para tarefa não realizada, caso tenha alguma observação digite ela no mesmo espaço\n\n");
 printf("Digite seu setor:");
 gets(a.setor);
 fflush(stdin);
 printf("Tarefa de segunda:\n");
 gets(a.segunda);
 fflush(stdin);
 printf("Tarefa de terça:\n");
 gets(a.terca);
 fflush(stdin);
 printf("Tarefa de quarta:\n");
 gets(a.quarta);
 fflush(stdin);
 printf("Tarefa de quinta:\n");
 gets(a.quinta);
 fflush(stdin);
 printf("Tarefa de sexta:\n");
 gets(a.sexta);
 fflush(stdin);
 printf("=============================\n");
 printf("\t setor: %s \n" , a.setor);
 printf("\t segunda:%s \n ", a.segunda);
 printf("\t terça:%s \n" , a.terca);
 printf("\t quarta:%s \n", a.quarta);
 printf("\t quinta:%s \n", a.quinta);
 printf("\t sexta:%s \n" , a.sexta);
 printf("=============================\n");
 fwrite(&a, sizeof (struct funcao), 1,RetTarfPtr);
 //fprintf(RetTarfPtr , "%s , %s , %s , %s , %s" , a.segunda , a.terca , a.quarta , a.quinta, a.sexta);
 fclose(RetTarfPtr);
}
//////////////////////////////////////// MENU DE CADASTRO/////////////////////////////////////
void MenuCadastro()
{
 char login[30];
 char senha[30];
 strcpy(p[0].login, "aris");
 strcpy(p[0].senha, "aris");
 printf("\n\n\n\n\n\n\n\n\t\t\t\t\t login:");
 scanf("%s", login);
 printf("\n\t\t\t\t\t senha:");
 scanf("%s", senha);
 if ((!strcmp(login, p[0].login)) && (!strcmp(senha,p[0].senha))){
 printf("Usuario logado");
 system("cls");
 int resp;
 do
 {
 printf("*** MENU DE CADASTRO *****\n");
 printf("* \t\t1 - Cadastrar Supervisor *\n");
 printf("* \t\t2 - Cadastrar Cliente *\n");
 printf("* \t\t3 - Cadastrar Funcionario *\n");
 printf("* \t\t0 - Menu Principal *\n");
 printf("********\n\n");
 printf("Digite a opção selecionada:");
 scanf("%d" , &resp);
 switch(resp)
 {
 case 1:
 {
 system("cls");
 CadastroSupervisor();
 break;
 }
 case 2:
 {
 system("cls");
 CadastroCliente();
 break;
 }
 case 3:
 {
 system("cls");
 CadastroFuncionario();
 break;
 }
 case 0:
 {
 system("cls");
 printf("Até mais!");
 break;
 }
 system("pause");
 }
 }while(resp);
 }
 else{
 printf("Login e/ou senha incorretos");
 }
 system("cls");
}
///////////////////////////// PROTOTIPOS MENU DE CADASTRAMENTO//////////////////////////
void CadastroFuncionario()
{
 FILE *CadFunfPtr = fopen("cadfun.txt" , "ab");
 if(CadFunfPtr == NULL){
 return 1;
 }
 struct funcionario a;
 fflush(stdin);
 printf("digite o nome do funcionario:\n");
 scanf("%s", a.nome);
 fflush(stdin);
 /////////////////// setor///////a
 printf("digite o setor do funcionario:\n");
 scanf("%s", a.setor);
 fflush(stdin);
 /////////////// idade ////////
 printf("digite a idade do funcionario:\n");
 scanf("%d", &a.idade);
 fflush(stdin);
 //////////////email/////////
 printf("Digite o email do funcionario:\n");
 gets(a.email);
 fflush(stdin);
 /////////////////////// salario///////////////
 printf("digite o salario do funcionario:\n");
 scanf("%d", &a.salario);
 fflush(stdin);
 /////////////////// telefone ////////////
 printf("digite o telefone do funcionario:\n");
 scanf("%d" , &a.telefone);
 fflush(stdin);
 system("cls");
 printf("=======================================\n");
 printf("\t nome: %s \n" , a.nome);
 printf("\t setor:%s \n" , a.setor);
 printf("\t idade: %d \n" , a.idade);
 printf("\t email: %s \n" , a.email);
 printf("\t salario: %d \n" , a.salario);
 printf("\t telefone: %d \n" , a.telefone);
 printf("=======================================\n\n");
 //fprintf(CadFunfPtr, "%s , %d , %s, %d\n" , a.nome , a.idade, a.email, a.telefone );
 fwrite(&a, sizeof (struct funcionario), 1,CadFunfPtr);
 fclose(CadFunfPtr);
}
void CadastroSupervisor()
{
 FILE *CadSupfPtr = fopen("cadSup.txt" , "ab");
 if(CadSupfPtr == NULL)
 {
 CadSupfPtr = fopen("cadSup.txt" , "wb");
 if(CadSupfPtr == NULL)
 {
 return 1;
 }
 }
 struct supervisor a;
 printf("digite o nome do supervisor:\n");
 scanf("%s", a.nome);
 fflush(stdin);
 /////////////// idade ////////
 printf("digite a idade do supervisor:\n");
 scanf("%d" , &a.idade);
 fflush(stdin);
 //////////////email/////////
 printf("Digite o email do supervisor:\n");
 gets(a.email);
 fflush(stdin);
 /////////////////////// salario///////////////
 printf("digite o salario do supervisor:\n");
 scanf("%d", &a.salario);
 fflush(stdin);
 /////////////////// telefone ////////////
 printf("digite o telefone do supervisor:\n");
 scanf("%d" , &a.telefone);
 printf("=======================================\n");
 printf("\t nome: %s \n" , a.nome);
 printf("\t idade: %d \n" , a.idade);
 printf("\t email: %s \n" , a.email);
 printf("\t salario: %d \n" , a.salario);
 printf("\t telefone: %d \n" , a.telefone);
 printf("*=======================================\n\n");
 //fprintf(CadGerfPtr, "%s , %d , %s, %d" , a.nome , a.idade, a.email, a.telefone );
 fwrite(&a, sizeof (struct supervisor), 1,CadSupfPtr);
 fclose(CadSupfPtr);
}
void CadastroCliente()
{
 FILE *CadClifPtr = fopen("cadCli.txt" , "ab");
 if(CadClifPtr == NULL)
 {
 CadClifPtr = fopen("cadCli.txt" , "wb");
 if(CadClifPtr == NULL)
 {
 return 1;
 }
 }
 struct cliente a;
 printf("digite o nome do cliente:\n");
 scanf("%s", a.nome);
 fflush(stdin);
 /////////////// idade ////////
 printf("digite a idade do cliente:\n");
 scanf("%d" , &a.idade);
 fflush(stdin);
 //////////////email/////////
 printf("Digite o email do cliente:\n");
 gets(a.email);
 fflush(stdin);
 /////////////////// telefone ////////////
 printf("digite o telefone do cliente:\n");
 scanf("%d" , &a.telefone);
 printf("=======================================\n");
 printf("*\tnome: %s \n" , a.nome);
 printf("*\tidade: %d \n" , a.idade);
 printf("*\temail: %s \n" , a.email);
 printf("*\ttelefone: %d \n" , a.telefone);
 printf("======================================\n\n");
 //fprintf(CadGerfPtr, "%s , %d , %s, %d" , a.nome , a.idade, a.email, a.telefone );
 fwrite(&a, sizeof (struct cliente), 1,CadClifPtr);
 fclose(CadClifPtr);
}
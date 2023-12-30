#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// Biblioteca para funcionar a limpeza do buffer com __fpurge()
#include <stdio_ext.h>
#include <ctype.h>

// Count para a quantidade de filmes que há no catálogo
int qtd_filmes_cadastrados = 30;
// Count para a quantidade de filmes do carrinho
int qtd_itens_carrinho = 0;

// Struct Filme com a informação dos filmes presentes no catálogo
typedef struct
{
    char titulo[200], diretor[100];
    int ano;
    char genero;
    double preco;
} Filme;

// Há no máximo, 50 filmes no catálogo, sendo 30 já pré-cadastrados
Filme vet_filmes[50];
// Quantidade m[axima de filmes que podem ser adicionados no carrinho
Filme vet_carrinho[10];

// Layout do nome da locadora
void nome_locadora()
{
    // Ativar o modo de texto em negrito
    printf("\x1b[1m");
    // Ativa a cor amarela
    printf("\033[33m");
    printf("\n----------------------------------------------------------------------------\n");
    printf("---------------------------- BANEMO'S MOVIES -------------------------------\n");
    printf("----------------------------------------------------------------------------\n");
    // Restaurar para forma padrão
    printf("\x1b[0m");
}

// Menu principal (escolha entre usuário e proprietário)
void menu_principal()
{
    // Ativar o modo de texto em negrito
    printf("\x1b[1m");
    printf("\n");
    printf("----------------------------------------------------------------------------\n");
    printf("                             MODO DE ACESSO                                 \n");
    printf("----------------------------------------------------------------------------\n");
    printf("\033[0m"); // tira a cor amarela
    printf("\t[1] PROPRIETÁRIO \t\t\t [2] USUÁRIO ");
    // Restaurar para forma padrão
    printf("\x1b[0m");
}

// Menu com as escolhas para o usuário
void menu_usuario()
{
    // Ativar o modo de texto em negrito
    printf("\x1b[1m");
    // Ativa a cor amarela
    printf("\033[33m");
    printf("\n----------------------------------------------------------------------------\n");
    printf("                             MENU DO USUÁRIO                                \n");
    printf("----------------------------------------------------------------------------\n");
    // Restaurar para forma padrão
    printf("\x1b[0m");
    // Ativar o modo de texto em negrito
    printf("\x1b[1m");
    printf("[1] Buscar no catálogo.\n[2] Mostrar catálogo completo.\n[3] Inserir no carrinho.\n");
    printf("[4] Excluir do carrinho.\n[5] Mostrar carrinho.\n[6] Finalizar compra.\n[7] Sair.\n");
    // Restaurar para forma padrão
    printf("\x1b[0m");
}

// Menu com as escolhas do usuário
void menu_proprietario()
{
    // Ativar o modo de texto em negrito
    printf("\x1b[1m");
    // Ativa a cor amarela
    printf("\033[33m");
    printf("\n----------------------------------------------------------------------------\n");
    printf("                          MENU DO PROPRIETÁRIO                              \n");
    printf("----------------------------------------------------------------------------\n");
    // Restaurar para forma padrão
    printf("\x1b[0m");
    // Ativar o modo de texto em negrito
    printf("\x1b[1m");
    // Ativar o modo de texto em negrito
    printf("\x1b[1m");
    printf("\n[1] Cadastrar filme.\n[2] Retirar do catálogo.\n[3] Mostrar catálogo completo.\n[4] Sair.\n");
    // Restaurar para forma padrão
    printf("\x1b[0m");
}

// Função para mostrar por quais meios de busca dos filmes
void busca()
{
    // Ativar o modo de texto em negrito
    printf("\x1b[1m");
    printf("\nBuscar por:\n");
    printf("[1] Gênero.\n[2] Título.\n[3] Ano de lançamento.\n");
    // Restaura para forma padrão
    printf("\x1b[0m");
}

// Função para mostrar por quais meios é possível retirar o filme do catálogo
void retirar_catalogo()
{
    // Ativar o modo de texto em negrito
    printf("\x1b[1m");
    printf("[1] Título.\n[2] Diretor.\n");
    // Restaura para forma padrão
    printf("\x1b[0m");
}

// Função para cadastrar um filme que o proprietário adiciona no catálogo
Filme cadastrar_filme()
{
    // Ativar o modo de texto em negrito
    printf("\x1b[1m");
    // Ativar a cor azul
    printf("\033[34m");
    printf("\n-------------------------- INCLUIR NO CATÁLOGO -----------------------------\n");
    // Restaura para forma padrão
    printf("\x1b[0m");
    // Foi criada a variavél filme do tipo Filme para receber as informações digitadas
    Filme filme;
    __fpurge(stdin);
    bool esta_no_catalogo;
    // Repete, caso o filme digitado esteja no cadastro
    do
    {
        esta_no_catalogo = false;
        printf("Título: ");
        fgets(filme.titulo, 200, stdin);
        __fpurge(stdin);
        int tam = strlen(filme.titulo);
        // Convertendo o nome do filme para maiusculo
        for (int i = 0; i < tam; i++)
        {
            filme.titulo[i] = toupper(filme.titulo[i]);
        }
        // Verifica se o filme está no catálogo
        for (int i = 0; i < qtd_filmes_cadastrados; i++)
        {
            if (strcmp(filme.titulo, vet_filmes[i].titulo) == 0)
            {
                esta_no_catalogo = true;
                printf("\nEsse filme já está no catálogo. Tente novamente!\n\n");
            }
        }
    } while (esta_no_catalogo);
    printf("Diretor: ");
    fgets(filme.diretor, 100, stdin);
    __fpurge(stdin);
    // Convertendo o nome do diretor para maiusculo
    int tam5 = strlen(filme.diretor);
    for (int i = 0; i < tam5; i++)
    {
        filme.diretor[i] = toupper(filme.diretor[i]);
    }
    printf("Ano de lançamento: ");
    scanf("%d", &filme.ano);
    __fpurge(stdin);
    printf("Preço: ");
    scanf("%lf", &filme.preco);
    __fpurge(stdin);
    bool invalido;
    // Repete até ser digitado um gênero válido
    do
    {
        invalido = false;
        printf("Gêneros:\nA- Ação.\tI- Infantil.\nB- Biografia.\tM- Musical.\nC- Comédia.\tR- Romance.\nD- Drama.\tS- Suspense.\nF- Fantasia.\tT- Terror.\nInforme um dos gêneros: ");
        scanf("%c", &filme.genero);
        __fpurge(stdin);
        // Caso seja diferente de todas as opções
        if (filme.genero != 'A' && filme.genero != 'I' && filme.genero != 'B' && filme.genero != 'M' && filme.genero != 'C' && filme.genero != 'R' && filme.genero != 'D' && filme.genero != 'S' && filme.genero != 'F' && filme.genero != 'T')
        {
            printf("\nOpção inválida. Tente novamente!\n\n");
            // Caso inválido seja true, haverá a repetição do do-while
            invalido = true;
        }
    } while (invalido);
    // Retorna a variável filme do tipo Filme
    return filme;
}

// Função para mostrar os filmes
void mostrar_filme(Filme filme)
{
    char genero[15];
    // Ativar o modo de texto em negrito
    printf("\x1b[1m");
    // Ativar a cor azul
    printf("\033[34m");
    printf("\n============================================================================\n");
    // Restaura para forma padrão
    printf("\x1b[0m");
    printf("Título : %s\n", filme.titulo);
    printf("Diretor: %s\n", filme.diretor);
    // Passa todos os carecteres para seus respectivos significados
    if (filme.genero == 'A')
    {
        strcpy(genero, "AÇÃO");
    }
    else if (filme.genero == 'C')
    {
        strcpy(genero, "COMÉDIA");
    }
    else if (filme.genero == 'S')
    {
        strcpy(genero, "SUSPENSE");
    }
    else if (filme.genero == 'D')
    {
        strcpy(genero, "DRAMA");
    }
    else if (filme.genero == 'T')
    {
        strcpy(genero, "TERROR");
    }
    else if (filme.genero == 'R')
    {
        strcpy(genero, "ROMANCE");
    }
    else if (filme.genero == 'F')
    {
        strcpy(genero, "FANTASIA");
    }
    else if (filme.genero == 'M')
    {
        strcpy(genero, "MUSICAL");
    }
    else if (filme.genero == 'B')
    {
        strcpy(genero, "BIOGRAFIA");
    }
    else
    {
        strcpy(genero, "INFANTIL");
    }
    printf("Ano lançamento: %d\tGenêro: %s\t\tPreço: R$ %.2lf\n", filme.ano, genero, filme.preco);
    // Ativar o modo de texto em negrito
    printf("\x1b[1m");
    // Ativar a cor azul
    printf("\033[34m");
    printf("============================================================================\n");
    // Restaura para forma padrão
    printf("\x1b[0m");
}

// Função para preencher os filmes pré cadastrados
void filmes_pre_cadastrados()
{
    // atribuindo as informações
    char vet_titulo[30][200] = {"12 HORAS\n", "13 MINUTOS\n", "A ACOMPANHANTE\n", "ANABELLE 2 - A CRIAçãO DO MAL\n", "A QUEDA\n", "AVATAR: O CAMINHO DA áGUA\n", "CAZUZA, O TEMPO NãO PARA\n", "DURO DE MATAR\n", "FILHOS DE NINGUéM\n", "GATO DE BOTAS 2: O úLTIMO PEDIDO\n", "HIGH SCHOOL MUSICAL\n", "INVOCAçãO DO MAL 2\n", "JOGOS MORTAIS 2\n", "JUNTOS E MISTURADOS\n", "LA LA LAND: CANTANDO ESTAçõES\n", "LULA, O FILHO DO BRASIL\n", "MAIS QUE AMIGOS\n", "O CóDIGO DA VINCI\n", "O HOBBIT: A DESOLAçãO DE SMAUG\n", "O PODEROSO CHEFINHO\n", "O SENHOR DOS ANéIS: A SOCIEDADE DO ANEL\n", "O SORRISO DE MONA LISA\n", "PINóQUIO\n", "RáPIDA VINGANçA\n", "SHREK PARA SEMPRE\n", "TIM MAIA\n", "TREM-BALA\n", "TODO MUNDO EM PâNICO\n", "V DE VINGANçA\n", "VELOZES E FURIOSOS 9\n"};
    char vet_diretores[30][200] = {"HEITOR DHALIA\n", "LINDSAY GOSSLING\n", "WILL SLOCOMBE\n", "DAVID F. SANDBERG\n", "SCOTT MAN\n", "JAMES CAMERON\n", "WALTER CARVALHO\n", "JHON MCTIERNAN\n", "ADEWALE AKINNUOYE-AGBAJE\n", "JOEL CRAWFORD\n", "KENNY ORTEGA\n", "JAMES WAN\n", "DARREN LYNN BOUSMAN\n", "FRANK CORACI\n", "DAMIEN CHAZELLE\n", "FáBIO BARRETO\n", "NICHOLAS STOLLER\n", "RON HOWARD\n", "PETER JACKSON\n", "TOM MCGRATH\n", "PETER JACKSON\n", "MIKE NEWELL\n", "ROBERT ZEMECKIS\n", "GEORGE TILLMAN JR.\n", "MIKE MITCHELL\n", "MAURO LIMA\n", "DAVID LEITCH\n", "KEENEN IVORY WAYANS\n", "JAMES MCTEIGUE\n", "JUSTIN LIN\n"};
    char vet_generos[30] = {'S', 'S', 'R', 'T', 'D', 'F', 'B', 'A', 'D', 'I', 'M', 'T', 'T', 'C', 'M', 'B', 'R', 'S', 'F', 'I', 'F', 'R', 'M', 'A', 'I', 'B', 'C', 'C', 'D', 'A'};
    int vet_anos[30] = {2012, 2021, 2015, 2017, 2022, 2004, 1988, 2018, 2022, 2006, 2017, 2005, 2014, 2016, 2009, 2022, 2006, 2013, 2017, 2001, 2003, 2022, 2010, 2010, 2014, 2022, 2000, 2005, 2021};
    double vet_precos[30] = {9.45, 14.23, 7.89, 10.76, 12.34, 8.67, 15.12, 6.98, 11.56, 16.78, 7.21, 13.45, 17.32, 10.01, 6.78, 12.89, 8.45, 14.67, 9.12, 16.23, 7.34, 11.78, 15.67, 6.45, 13.89, 9.56, 17.01, 8.23, 12.45, 10.67};
    // Preenchendo a struct com os valores pré-definidos
    for (int i = 0; i < 30; i++)
    {
        strcpy(vet_filmes[i].titulo, vet_titulo[i]);
        strcpy(vet_filmes[i].diretor, vet_diretores[i]);
        vet_filmes[i].genero = vet_generos[i];
        vet_filmes[i].ano = vet_anos[i];
        vet_filmes[i].preco = vet_precos[i];
    }
}

int main()
{
    // Chama a função nome_locadora
    nome_locadora();
    // Chama a função filmes_pre_cadastrados
    filmes_pre_cadastrados();
    // op: opção do menu principal
    // opp: opção do menu proprietario
    // opu: opção de menu usuário
    int op, opp, opu;
    float preco_total = 0.0;

    while (1)
    {
        // Chama a função menu_principal
        menu_principal();
        printf("\n\nDigite o acesso desejado: ");
        scanf("%d", &op);
        // Caso a escolha tenha sido 1(proprietário)
        if (op == 1)
        {
            // Senha para entrar no modo proprietário
            char senha[10] = {"BANEMOS"};
            char senha_digitada[100];
            // Ativar o modo de texto em negrito
            printf("\x1b[1m");
            // Ativar a cor azul
            printf("\033[34m");
            printf("\n==================== DIGITE A SENHA DO PROPRIETÁRIO ========================\n");
            // Desativar a cor azul
            printf("\033[0m");
            printf("\nSENHA: ");
            scanf("%s", senha_digitada);
            if (strcmp(senha_digitada, senha) != 0)
            {
                // Ativar o modo de texto em negrit0
                printf("\x1b[1m");
                // Ativar a cor azul
                printf("\033[34m");
                printf("\n============================================================================\n");
                // restaura para forma padrão
                printf("\x1b[0m");
                // Ativar o modo de texto em negrit0
                printf("\x1b[1m");
                // Ativar a cor vermelha
                printf("\x1b[31m");
                printf("\n\t\t ______________________________________\n");
                printf("\t\t|                                      |\n");
                printf("\t\t|    SENHA INCORRETA. ACESSO NEGADO    |\n");
                printf("\t\t|______________________________________|\n\n");
                // Desativa a cor vermelha
                printf("\x1b[0m");
            }
            else
            {
                // Ativar o modo de texto em negrit0
                printf("\x1b[1m");
                // Ativar a cor azul
                printf("\033[34m");
                printf("\n============================================================================\n\n");
                // restaura para forma padrão
                printf("\x1b[0m");
                // Ativar o modo de texto em negrit0
                printf("\x1b[1m");
                printf("\n========================= PERFIL PROPRIETÁRIO ==============================\n");
                // restaura para forma padrão
                printf("\x1b[0m");
                // Repete enquanto o usuário não escolher sair
                do
                {
                    // Chama a função menu_proprietario
                    menu_proprietario();
                    printf("Digite a opção desejada do menu: ");
                    scanf("%d", &opp);
                    __fpurge(stdin);
                    // Caso a escolha seja 1
                    if (opp == 1)
                    {
                        // Caso o proprietário tente cadastrar mais do que 20 filmes. Não é possível
                        if (qtd_filmes_cadastrados == 50)
                        {
                            printf("\n\t\tO número máximo de filmes já foram inseridos!\n");
                            // Caso seja possível adicionar mais filmes
                        }
                        else
                        {
                            bool ja_existe;
                            // Repete enquanto o proprietário tentar cadastar um filme já existente no catálogo
                            do
                            {
                                Filme filme_aux;
                                // A variável auxiliar recebe a função cadastrar_filme
                                filme_aux = cadastrar_filme();
                                __fpurge(stdin);
                                // Verifica se o filme já está no catálogo
                                ja_existe = false;
                                for (int i = 0; i < qtd_filmes_cadastrados; i++)
                                {
                                    int resultado = strcmp(filme_aux.titulo, vet_filmes[i].titulo);
                                    if (resultado == 0)
                                    {
                                        ja_existe = true;
                                    }
                                }
                                if (ja_existe)
                                {
                                    printf("Filme já cadastrado. Tente novamente!\n");
                                    // Caso o filme não esteja no catálogo
                                }
                                else
                                {
                                    // Caso a quantidade de filmes seja 0 ele vai direto para a posição 0.
                                    int index = 0;
                                    if (qtd_filmes_cadastrados > 0)
                                    {
                                        for (int i = 0; i < qtd_filmes_cadastrados; i++)
                                        {
                                            if (strcmp(vet_filmes[i].titulo, filme_aux.titulo) > 0)
                                            {
                                                // Salva o index do filme que, na ordem, está depois dele
                                                index = i;
                                                break;
                                            }
                                        }
                                        // O filme é inserido no vetor em ordem alfabética
                                        for (int i = qtd_filmes_cadastrados; i > index; i--)
                                        {
                                            strcpy(vet_filmes[i].titulo, vet_filmes[i - 1].titulo);
                                        }
                                        strcpy(vet_filmes[index].titulo, filme_aux.titulo);
                                    }
                                    vet_filmes[index] = filme_aux;
                                    qtd_filmes_cadastrados++;
                                    mostrar_filme(vet_filmes[index]); // mostra o filme que acabou de ser cadastrado
                                    printf("\x1b[1m");                // colocou texto em negrito
                                    printf("\033[34m");               // colocou tesxto em azul
                                    printf("\n\n-------------------------- ADICIONADO AO CATÁLOGO ---------------------------\n\n");
                                    printf("\x1b[0m"); // restaurou a forma padrão
                                }
                            } while (ja_existe);
                        }

                        // Caso o proprietário escolha a opção 2
                    }
                    else if (opp == 2)
                    {
                        int op_excluir;
                        bool opcao_invalida;
                        if (qtd_filmes_cadastrados == 0)
                        {
                            printf("\n\tDeve ter pelo menos um filme cadastrado antes que ocorra a exclusão.\n");
                            // Caso haja pelo menos um filme cadastrado no catálogo
                        }
                        else
                        {
                            printf("\x1b[1m"); // colocou texto em negrito
                            printf("\n-------------------------- EXCLUIR DO CATÁLOGO -----------------------------\n");
                            // Repete enquanto o proprietário digitar algo diferente das opções mostradas
                            do
                            {
                                __fpurge(stdin);
                                // Verifica se o usuario escolheu uma opção diferente de 1 e 2
                                opcao_invalida = false;
                                printf("\x1b[1m"); // colocou texto em negrito
                                printf("[1] Título.\n[2] Diretor.\n");
                                printf("\x1b[0m"); // restaurou a forma padrão
                                printf("Digite qual será o critério de exclusão: ");
                                __fpurge(stdin);
                                scanf("%d", &op_excluir);
                                __fpurge(stdin);

                                // Caso o oprorpietário tenha escolhido a opção 1
                                if (op_excluir == 1)
                                {
                                    char titulo_para_excluir[200];
                                    printf("Digite o título do filme que deseja excluir: ");
                                    fgets(titulo_para_excluir, 200, stdin);
                                    __fpurge(stdin);
                                    // Convertendo o nome do filme a ser excluido tudo para maiusculo
                                    int tam = strlen(titulo_para_excluir);
                                    for (int i = 0; i < tam; i++)
                                    {
                                        // Verifica se é letra do alfabeto e converte para tudo maiusculo
                                        if ((titulo_para_excluir[i] >= 'a' && titulo_para_excluir[i] <= 'z') || (titulo_para_excluir[i] >= 'A' && titulo_para_excluir[i] <= 'Z'))
                                        {
                                            titulo_para_excluir[i] = toupper(titulo_para_excluir[i]);
                                        }
                                    }
                                    bool esta_na_lista = false;
                                    // Verificando se o filme está presente no catálogo
                                    for (int i = 0; i < qtd_filmes_cadastrados; i++)
                                    {
                                        if (strcmp(titulo_para_excluir, vet_filmes[i].titulo) == 0)
                                        {
                                            esta_na_lista = true;
                                        }
                                    }
                                    // Caso o filme esteja no catálogo
                                    if (esta_na_lista)
                                    {
                                        printf("\nO filme a ser excluído é:\n");
                                        for (int i = 0; i < qtd_filmes_cadastrados; i++)
                                        {
                                            if (strcmp(titulo_para_excluir, vet_filmes[i].titulo) == 0)
                                            {
                                                // Printa de forma organizada o filme na posição i a ser excluído
                                                mostrar_filme(vet_filmes[i]);
                                            }
                                        }
                                        __fpurge(stdin);
                                        // Pede uma confirmação para que seja excluído
                                        int confirma_excluir;
                                        // Repete enquanto o usuário digitar uma opção diferente das ofertadas
                                        do
                                        {
                                            printf("\n\nVocê deseja mesmo excluir o filme acima do catálogo?[0-NÃO|1-SIM] ");
                                            scanf("%d", &confirma_excluir);
                                            __fpurge(stdin);
                                            // Caso o usuário confirme excluir o filme
                                            if (confirma_excluir == 1)
                                            {
                                                for (int i = 0; i < qtd_filmes_cadastrados; i++)
                                                {
                                                    if (strcmp(vet_filmes[i].titulo, titulo_para_excluir) == 0)
                                                    {
                                                        // Sobrescreve os filmes, retirando aquele que o proprietário excluiu
                                                        for (int j = i; j < qtd_filmes_cadastrados - 1; j++)
                                                        {
                                                            strcpy(vet_filmes[j].titulo, vet_filmes[j + 1].titulo);
                                                            strcpy(vet_filmes[j].diretor, vet_filmes[j + 1].diretor);
                                                            vet_filmes[j].ano = vet_filmes[j + 1].ano;
                                                            vet_filmes[j].genero = vet_filmes[j + 1].genero;
                                                            vet_filmes[j].preco = vet_filmes[j + 1].preco;
                                                        }
                                                        // Como há um filme a menos, a quantidadede filmes deve ser diminuída
                                                        qtd_filmes_cadastrados--;
                                                    }
                                                }
                                                printf("\x1b[1m");  // coloca em negrito
                                                printf("\033[91m"); // coloca em vermelho
                                                printf("\n\t\tO filme foi excluído com sucesso.\n");
                                                printf("\x1b[0m"); // restaura a forma padrão
                                                // Caso o proprietário não deseje confirmar a exclusão do filme
                                            }
                                            else if (confirma_excluir == 0)
                                            {
                                                printf("\nNão ocorrerá a exclusão do filme.\n");
                                                __fpurge(stdin);
                                                // Caso o proprietário tenha digitado algo diferente das opções
                                            }
                                            else
                                            {
                                                printf("Digite uma opção válida. Tente novamente!\n");
                                                __fpurge(stdin);
                                            }
                                        } while (confirma_excluir != 1 && confirma_excluir != 0);
                                        __fpurge(stdin);
                                        // Caso o título digitado não esteja na lista
                                    }
                                    else
                                    {
                                        printf("\nO título digitado não se encontra na lista, logo, não é possível excluir.\n");
                                        // Volta pro menu
                                    }

                                    // Caso a escolha tenha sido 2
                                }
                                else if (op_excluir == 2)
                                {
                                    __fpurge(stdin);
                                    // excluir por diretor do filme
                                    // mostra quais são os possíveis a serem excluidos e pede uma confirmação
                                    char diretor_para_excluir[100];
                                    printf("Digite o nome do diretor que deseja excluir da plataforma: ");
                                    fgets(diretor_para_excluir, 100, stdin);
                                    __fpurge(stdin);
                                    // convertendo o nome do diretor a ser excluido tudo para maiusculo
                                    int tam = strlen(diretor_para_excluir);
                                    for (int i = 0; i < tam; i++)
                                    {
                                        // verifica se é letra do alfabeto e converte para tudo maiusculo
                                        if ((diretor_para_excluir[i] >= 'a' && diretor_para_excluir[i] <= 'z') || (diretor_para_excluir[i] >= 'A' && diretor_para_excluir[i] <= 'Z'))
                                        {
                                            diretor_para_excluir[i] = toupper(diretor_para_excluir[i]);
                                        }
                                    }
                                    // apos converter para maiusculo verifica se esse diretor esta presente na lista de filmes
                                    // aqui eu parto de que ele nao esta na lista
                                    bool esta_na_lista = false;
                                    for (int i = 0; i < qtd_filmes_cadastrados; i++)
                                    {
                                        if (strcmp(diretor_para_excluir, vet_filmes[i].diretor) == 0)
                                        {
                                            // caso encontrar esse diretor na lista de filmes então ele está na lista
                                            esta_na_lista = true;
                                        }
                                    }
                                    // se estiver na lista
                                    if (esta_na_lista)
                                    {
                                        printf("\n\t\tO(s) filme(s) a ser excluído:\n");
                                        for (int i = 0; i < qtd_filmes_cadastrados; i++)
                                        {
                                            if (strcmp(diretor_para_excluir, vet_filmes[i].diretor) == 0)
                                            {
                                                mostrar_filme(vet_filmes[i]);
                                            }
                                        }
                                        __fpurge(stdin);
                                        // pede uma confirmação para que seja excluído
                                        int confirma_excluir;
                                        do
                                        {
                                            printf("Você deseja mesmo excluir o(s) filme(s) acima do catálogo(1-sim 0-nao)? ");
                                            __fpurge(stdin);
                                            scanf("%d", &confirma_excluir);
                                            __fpurge(stdin);
                                            if (confirma_excluir == 1)
                                            {
                                                // O usuário realmente quer excluir o(s) filme(s)
                                                // caso hover repetição serão excluidas todas as repetições.
                                                // agora para que ocorra a exclusão de todas as ocorrências desse diretor de filmes
                                                // deve-se ter uma variável que checa se ainda tem algum filme no catalogo que seja desse diretor
                                                bool esta_no_catalogo;
                                                do
                                                {
                                                    esta_no_catalogo = false;
                                                    for (int i = 0; i < qtd_filmes_cadastrados; i++)
                                                    {
                                                        if (strcmp(vet_filmes[i].diretor, diretor_para_excluir) == 0)
                                                        {
                                                            for (int j = i; j < qtd_filmes_cadastrados - 1; j++)
                                                            {
                                                                strcpy(vet_filmes[j].titulo, vet_filmes[j + 1].titulo);
                                                                strcpy(vet_filmes[j].diretor, vet_filmes[j + 1].diretor);
                                                                vet_filmes[j].ano = vet_filmes[j + 1].ano;
                                                                vet_filmes[j].genero = vet_filmes[j + 1].genero;
                                                                vet_filmes[j].preco = vet_filmes[j + 1].preco;
                                                            }
                                                            esta_no_catalogo = true;
                                                            qtd_filmes_cadastrados--;
                                                        }
                                                    }
                                                } while (esta_no_catalogo);
                                                __fpurge(stdin);
                                                printf("\x1b[1m");  // coloca em negrito
                                                printf("\033[91m"); // coloca em vermelho
                                                printf("\n\tO(s) filme(s) desse(a) diretor(a) foi(ão) excluído(s) com sucesso.\n");
                                                printf("\x1b[0m"); // restaura a forma padrão
                                            }
                                            else if (confirma_excluir == 0)
                                            {
                                                // O usuário não deseja mais excluir o filme
                                                printf("\nNão ocorrerá a exclusão do filme.\n");
                                            }
                                            else
                                            {
                                                printf("Digite uma opção válida. Tente novamente!\n");
                                            }
                                        } while (confirma_excluir != 1 && confirma_excluir != 0);
                                    }
                                    else
                                    {
                                        __fpurge(stdin);
                                        // se nao estiver na lista
                                        printf("O nome diretor digitado não se encontra na lista.\nLogo não é possível excluir nenhum filme.\n");
                                        // volta pro menu
                                    }
                                }
                                else
                                {
                                    printf("\nOpção inválida. Tente novamente!\n");
                                    opcao_invalida = true;
                                }
                            } while (opcao_invalida);
                        }
                    }
                    else if (opp == 3)
                    {
                        // mostrar todo o catálogo de filmes
                        if (qtd_filmes_cadastrados > 0)
                        {
                            printf("\x1b[1m");  // Ativar o modo de texto em negrito
                            printf("\033[33m"); // Ativa a cor amarela
                            printf("\n-------------------------- FILMES NO CATÁLOGO ------------------------------\n");
                            printf("\x1b[0m"); // Ativar o modo de texto em negrito
                            for (int i = 0; i < qtd_filmes_cadastrados; i++)
                            {
                                mostrar_filme(vet_filmes[i]);
                            }
                        }
                        else
                        {
                            printf("\n\t\tAinda não foram cadastrados filmes no catálogo.\n");
                        }
                    }
                    else if (opp == 4)
                    {
                        // sair
                        printf("\n====================== SAIU DO PERFIL PROPRIETÁRIO ==========================\n");
                        system("clear"); // caso fosse em windows seria cls ao invés de clear, serve para limpar a tela do usuário
                        nome_locadora();
                    }
                    else
                    {
                        // opcao digitada nao foi 1,2,3 ou 4
                        printf("Opção inválida. Tente novamente!\n");
                    }
                } while (opp != 4);
            }
        }
        else if (op == 2)
        {
            printf("\x1b[1m"); // Ativar o modo de texto em negrito
            printf("\n============================ PERFIL USUÁRIO ================================\n");
            printf("\x1b[0m"); // Ativar o modo de texto em negrito
            do
            {
                menu_usuario();
                printf("Digite a opção desejada do menu: ");
                scanf("%d", &opu);
                __fpurge(stdin);

                if (opu == 1)
                {
                    // caso a opcao do usuario for a 1 ou seja a de buscar
                    int op_busca;
                    busca(); // aparece o menu de possiveis modos de busca
                    printf("Digite o modo que deseja buscar: ");
                    scanf("%d", &op_busca);
                    __fpurge(stdin);
                    // colocar um while para enquanto for inválida pedir pra digitar novamente

                    if (op_busca == 1)
                    {
                        // realiza a busca de um filme
                        printf("\nREALIZAR BUSCA POR GÊNERO:\n");
                        bool esta_na_lista, invalido;
                        char genero_busca;
                        do
                        {
                            printf("Gêneros:\nA- Ação.\tI- Infantil.\nB- Biografia.\tM- Musical.\nC- Comédia.\tR- Romance.\nD- Drama.\tS- Suspense.\nF- Fantasia.\tT- Terror.\nInforme um dos gêneros: ");
                            printf("\nDigite o gênero de filme que deseja buscar: ");
                            scanf("%c", &genero_busca);
                            __fpurge(stdin);
                            esta_na_lista = false;
                            invalido = false;
                            if (genero_busca != 'A' && genero_busca != 'I' && genero_busca != 'B' && genero_busca != 'M' && genero_busca != 'C' && genero_busca != 'R' && genero_busca != 'D' && genero_busca != 'S' && genero_busca != 'F' && genero_busca != 'T')
                            {
                                printf("\nOpção inválida. Tente novamente!\n\n");
                                invalido = true;
                            }
                            else
                            {
                                for (int i = 0; i < qtd_filmes_cadastrados; i++)
                                {
                                    if (genero_busca == vet_filmes[i].genero)
                                    {
                                        // verifica se tem filme na lista cujo gênero é o buscado
                                        esta_na_lista = true;
                                    }
                                }
                                // se estiver na lista
                                if (esta_na_lista)
                                {
                                    printf("\n\t\tO(s) filme(s) desse gênero é/são:\n");
                                    for (int i = 0; i < qtd_filmes_cadastrados; i++)
                                    {
                                        if (genero_busca == vet_filmes[i].genero)
                                        {
                                            mostrar_filme(vet_filmes[i]);
                                        }
                                    }
                                }
                            }
                        } while (invalido);
                    }
                    else if (op_busca == 2)
                    {
                        printf("\n---------------------- REALIZAR BUSCA POR TÍTULO ---------------------------\n");
                        bool esta_na_lista;
                        char titulo_busca[200];
                        printf("\nDigite o título do filme que deseja buscar: ");
                        fgets(titulo_busca, 200, stdin);
                        __fpurge(stdin);
                        esta_na_lista = false;
                        int tam3 = strlen(titulo_busca);
                        for (int i = 0; i < tam3; i++)
                        {
                            titulo_busca[i] = toupper(titulo_busca[i]);
                        }
                        for (int i = 0; i < qtd_filmes_cadastrados; i++)
                        {
                            if (strcmp(titulo_busca, vet_filmes[i].titulo) == 0)
                            {
                                // verifica se tem filme na lista cujo gênero é o buscado
                                esta_na_lista = true;
                            }
                        }
                        // se estiver na lista
                        if (esta_na_lista)
                        {
                            printf("\n\t\tO filme buscado foi:\n");
                            for (int i = 0; i < qtd_filmes_cadastrados; i++)
                            {
                                if (strcmp(titulo_busca, vet_filmes[i].titulo) == 0)
                                {
                                    mostrar_filme(vet_filmes[i]);
                                }
                            }
                        }
                        else
                        {
                            printf("\n\nO filme não foi encontrado!\n");
                        }
                    }
                    else if (op_busca == 3)
                    {
                        printf("REALIZAR BUSCA POR ANO DE LANÇAMENTO:\n");
                        bool esta_na_lista;
                        int ano_busca;
                        printf("\nDigite o ano de produção dos filmes que deseja buscar: ");
                        scanf("%d", &ano_busca);
                        __fpurge(stdin);
                        esta_na_lista = false;
                        for (int i = 0; i < qtd_filmes_cadastrados; i++)
                        {
                            if (ano_busca == vet_filmes[i].ano)
                            {
                                // verifica se tem filme na lista cujo gênero é o buscado
                                esta_na_lista = true;
                            }
                        }
                        // se estiver na lista
                        if (esta_na_lista)
                        {
                            printf("\n\t\tO(s) filme(s) do ano buscado é/são:\n");
                            for (int i = 0; i < qtd_filmes_cadastrados; i++)
                            {
                                if (ano_busca == vet_filmes[i].ano)
                                {
                                    mostrar_filme(vet_filmes[i]);
                                }
                            }
                        }
                        else
                        {
                            printf("\n\n\t\tNão existem filmes em catálogo para o ano digitado.\n");
                        }
                    }
                    else
                    {
                        printf("\n\n\t\tOpção inválida.\n");
                    }
                }
                else if (opu == 2)
                {
                    /// mostrar todo o catálogo de filmes
                    if (qtd_filmes_cadastrados > 0)
                    {
                        printf("\n------------------------- FILMES NO CATÁLOGO -------------------------------\n");
                        for (int i = 0; i < qtd_filmes_cadastrados; i++)
                        {
                            mostrar_filme(vet_filmes[i]);
                        }
                    }
                    else
                    {
                        printf("\n\t\tAinda não foram cadastrados filmes no catálogo.\n");
                    }
                }
                else if (opu == 3)
                {
                    if (qtd_itens_carrinho == 10)
                    {
                        printf("\n\t\tO número máximo de itens já foi adicionado no carrinho!");
                        // caso não seja mais possível adicionar filmes
                    }
                    else
                    {
                        // inserir no carrinho
                        printf("\n-------------------------- ADICIONAR NO CARRINHO ---------------------------\n");
                        bool nao_existe;
                        char verifica_titulo[200];
                        int posicao;
                        // aqui é feita a busca para saber se o filme existe ou nao no catálogo
                        do
                        {
                            printf("Digite o título do filme que deseja inserir: ");
                            nao_existe = true;
                            fgets(verifica_titulo, 200, stdin);
                            // criar função para colocar maiúsculo
                            int tam4 = strlen(verifica_titulo);
                            for (int i = 0; i < tam4; i++)
                            {
                                verifica_titulo[i] = toupper(verifica_titulo[i]);
                            }
                            for (int i = 0; i < qtd_filmes_cadastrados; i++)
                            {
                                if (strcmp(verifica_titulo, vet_filmes[i].titulo) == 0)
                                {
                                    nao_existe = false;
                                    posicao = i;
                                }
                            }
                            if (nao_existe)
                            {
                                printf("Filme não encontrado no catálogo. Tente novamente!\n");
                            }
                        } while (nao_existe);
                        bool nao_esta_no_carrinho = true;
                        if (qtd_itens_carrinho == 0)
                        {
                            vet_carrinho[qtd_itens_carrinho] = vet_filmes[posicao];
                            qtd_itens_carrinho++;
                            printf("\n------------------------- ADICIONADO COM SUCESSO ---------------------------\n");
                        }
                        else
                        {
                            for (int i = 0; i < qtd_itens_carrinho; i++)
                            {
                                if (strcmp(verifica_titulo, vet_carrinho[i].titulo) == 0)
                                {
                                    printf("\nFilme já adicionado no carrinho.\n");
                                    nao_esta_no_carrinho = false;
                                }
                            }
                            if (nao_esta_no_carrinho)
                            {
                                vet_carrinho[qtd_itens_carrinho] = vet_filmes[posicao];
                                qtd_itens_carrinho++;
                                printf("\n----------------------- ADICIONADO NO CARRINHO -----------------------------\n");
                            }
                        }
                    }
                }
                else if (opu == 4)
                {
                    // excluir do carrinho
                    if (qtd_itens_carrinho > 0)
                    {
                        printf("\n-------------------------- EXCLUIR DO CARRINHO -----------------------------\n");
                        bool nao_esta;
                        char titulo_excluir[200];
                        int posicao;
                        // aqui é feita a busca para saber se o filme existe ou nao no carrinho
                        printf("Digite o título do filme que deseja excluir: ");
                        nao_esta = true;
                        fgets(titulo_excluir, 200, stdin);
                        // criar função para colocar maiúsculo
                        int tam6 = strlen(titulo_excluir);
                        for (int i = 0; i < tam6; i++)
                        {
                            titulo_excluir[i] = toupper(titulo_excluir[i]);
                        }
                        for (int i = 0; i < qtd_itens_carrinho; i++)
                        {
                            if (strcmp(titulo_excluir, vet_carrinho[i].titulo) == 0)
                            {
                                nao_esta = false;
                                posicao = i;
                            }
                        }
                        if (nao_esta)
                        {
                            printf("Filme não encontrado no carrinho!\n");
                        }
                        else
                        {
                            vet_carrinho[qtd_itens_carrinho] = vet_filmes[posicao];
                            qtd_itens_carrinho--;
                            printf("\n------------------------- EXCLUIDO DO CARRINHO -----------------------------\n");
                        }
                    }
                    else
                    {
                        printf("Não é possível excluir, o carrinho está vazio.\n");
                    }
                }
                else if (opu == 5)
                {
                    // mostrar carrinho
                    printf("\n\n================================= CARRINHO =================================\n");
                    if (qtd_itens_carrinho > 0)
                    {
                        preco_total = 0;
                        for (int i = 0; i < qtd_itens_carrinho; i++)
                        {
                            mostrar_filme(vet_carrinho[i]);
                            preco_total += vet_carrinho[i].preco;
                        }
                        printf("\n\t\t\tVALOR TOTAL: R$%.2lf", preco_total);
                        printf("\n\n============================================================================\n");
                    }
                    else
                    {
                        printf("\n\t\tAinda não foram adcionados filmes no carrinho.\n");
                    }
                }
                else if (opu == 6)
                {
                    // realiza a compra e zera o carrinho
                    if (qtd_itens_carrinho > 0)
                    {
                        printf("\n--------------------------- REALIZAR COMPRA --------------------------------\n");
                        preco_total = 0;
                        for (int i = 0; i < qtd_itens_carrinho; i++)
                        {
                            preco_total += vet_carrinho[i].preco;
                            mostrar_filme(vet_carrinho[i]);
                        }
                        printf("\n\t\t\tVALOR TOTAL: R$%.2lf", preco_total);
                        printf("\n----------------------------------------------------------------------------\n");
                        int confirma;
                        bool opcao_invalida;
                        do
                        {
                            opcao_invalida = false;
                            printf("\nDeseja realizar esta compra?[0-NÃO|1-SIM] ");
                            scanf("%d", &confirma);
                            if (confirma == 0)
                            {
                                printf("\n\t\tCompra não realizada!\n");
                            }
                            else if (confirma == 1)
                            {
                                printf("\nCompra realizada com sucesso!\n");
                                qtd_itens_carrinho = 0;
                            }
                            else
                            {
                                printf("\n\t\tOpção inválida. Tente novamente!\n");
                                opcao_invalida = true;
                            }
                        } while (opcao_invalida);
                    }
                    else
                    {
                        printf("\n\t\tNão é possível realizar a compra. Carrinho vazio.\n");
                    }
                }
                else if (opu == 7)
                {
                    // sair
                    int confirma_sair;
                    do
                    {
                        if (qtd_itens_carrinho > 0)
                        {
                            printf("Há %d item(s) no carriho, deseja mesmo sair sem finalizar sua compra?[0-NÃO|1-SIM] ", qtd_itens_carrinho);
                            scanf("%d", &confirma_sair);
                            if (confirma_sair != 0 && confirma_sair != 1)
                            {
                                printf("\n\t\tOpção inválida!\n");
                            }
                            else if (confirma_sair == 1)
                            {
                                printf("\n\t\tCompra cancelada. Carrinho vazio!\n");
                                printf("\n\n=================== VOLTE SEMPRE PARA MAIS COMPRAS ========================\n");
                                qtd_itens_carrinho = 0;
                                system("clear"); // caso fosse em windows seria cls ao invés de clear, serve para limpar a tela do usuário
                                nome_locadora();
                                break;
                            }
                        }
                        else
                        {
                            printf("\n\n=================== VOLTE SEMPRE PARA MAIS COMPRAS ========================\n");
                            qtd_itens_carrinho = 0;
                            system("clear"); // caso fosse em windows seria cls ao invés de clear, serve para limpar a tela do usuário
                            nome_locadora();
                            break;
                        }
                    } while (confirma_sair != 0 && confirma_sair != 1);
                }
                else
                {
                    printf("\n\t\tOpção inválida. Tente novamente!\n");
                }
            } while (opu != 7);
        }
    }
    return 0;
}
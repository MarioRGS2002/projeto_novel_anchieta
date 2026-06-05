#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "jogo.h"
#include "salvar.h"   /* <-- NOVO: funcoes de salvar/carregar */

void inicializar_cenas(Cena *cenas) {

    /* ── CENA 1 — Acordando ── */
    cenas[0].id = 1;
    strcpy(cenas[0].titulo, "Capsula de Emergencia - Deck B");
    strcpy(cenas[0].arte_ascii,
        "    .-----------.\n"
        "   |  [NEXUS-7]  |\n"
        "   |  * * * * *  |\n"
        "   |  ALERTA BIO |\n"
        "   |  * * * * *  |\n"
        "    '-----------'\n");
    strcpy(cenas[0].texto,
        "Voce abre os olhos. Uma luz vermelha pulsa no teto.\n"
        "Sua cabeca doi. O ar cheira a ozonio e metal frio.\n"
        "Uma voz mecanica repete em loop:\n"
        "'Protocolo de Quarentena ativado. Fique onde esta.'\n"
        "Voce esta dentro de uma capsula de emergencia.\n"
        "A porta esta fechada mas nao travada.");
    strcpy(cenas[0].escolhas[0].descricao, "Abrir a porta da capsula");
    cenas[0].escolhas[0].id_destino = 2;
    strcpy(cenas[0].escolhas[1].descricao, "Verificar o painel interno da capsula");
    cenas[0].escolhas[1].id_destino = 3;
    cenas[0].num_escolhas = 2;
    strcpy(cenas[0].termo_codex, "Protocolo de Quarentena");

    /* ── CENA 2 — Corredor ── */
    cenas[1].id = 2;
    strcpy(cenas[1].titulo, "Corredor Principal - Deck B");
    strcpy(cenas[1].arte_ascii,
        "  |  .    .    .    .  |\n"
        "  |  :    :    :    :  |\n"
        "  |__:____:____:____:__|\n"
        "  |   NEXUS-7  DECK-B  |\n"
        "  |_____________________|\n");
    strcpy(cenas[1].texto,
        "O corredor esta vazio e escuro.\n"
        "Luzes de emergencia piscam nas paredes.\n"
        "Voce ve duas direcoes: o Laboratorio a esquerda\n"
        "e a Sala de Controle a direita.\n"
        "No chao, marcas de arranhao que nao estavam aqui antes.");
    strcpy(cenas[1].escolhas[0].descricao, "Ir para o Laboratorio");
    cenas[1].escolhas[0].id_destino = 4;
    strcpy(cenas[1].escolhas[1].descricao, "Ir para a Sala de Controle");
    cenas[1].escolhas[1].id_destino = 5;
    cenas[1].num_escolhas = 2;
    strcpy(cenas[1].termo_codex, "");

    /* ── CENA 3 — Painel da Capsula ── */
    cenas[2].id = 3;
    strcpy(cenas[2].titulo, "Painel Interno - Capsula de Emergencia");
    strcpy(cenas[2].arte_ascii,
        "  .------------------.\n"
        "  | STATUS: ALERTA   |\n"
        "  | O2:     94%      |\n"
        "  | TEMP:   18C      |\n"
        "  | VIRUS:  DETECTADO|\n"
        "  '------------------'\n");
    strcpy(cenas[2].texto,
        "O painel mostra dados vitais da estacao.\n"
        "Nivel de oxigenio: 94 por cento - aceitavel.\n"
        "Temperatura: 18 graus - normal.\n"
        "Agente biologico: DETECTADO no Deck A.\n"
        "Uma mensagem de texto pisca na tela:\n"
        "'ARIA - IA da estacao - ainda esta online.'");
    strcpy(cenas[2].escolhas[0].descricao, "Sair da capsula pelo corredor");
    cenas[2].escolhas[0].id_destino = 2;
    strcpy(cenas[2].escolhas[1].descricao, "Tentar contatar ARIA pelo painel");
    cenas[2].escolhas[1].id_destino = 6;
    cenas[2].num_escolhas = 2;
    strcpy(cenas[2].termo_codex, "Virus XR-7");

    /* ── CENA 4 — Laboratorio ── */
    cenas[3].id = 4;
    strcpy(cenas[3].titulo, "Laboratorio Biologico - Deck B");
    strcpy(cenas[3].arte_ascii,
        "  .----.  .----.  .----.\n"
        "  | [] |  | [] |  | [] |\n"
        "  '----'  '----'  '----'\n"
        "  [AMOSTRAS BIOLOGICAS] \n"
        "  !! AREA RESTRITA !!   \n");
    strcpy(cenas[3].texto,
        "O laboratorio esta em caos.\n"
        "Tubos de ensaio quebrados no chao.\n"
        "Uma das geladeiras de amostras esta aberta.\n"
        "Voce ve um diario sobre a bancada.\n"
        "Na ultima pagina, escrito as pressas:\n"
        "'O XR-7 nao veio de Europa. Foi criado aqui.'");
    strcpy(cenas[3].escolhas[0].descricao, "Pegar o diario e ler com calma");
    cenas[3].escolhas[0].id_destino = 7;
    strcpy(cenas[3].escolhas[1].descricao, "Voltar ao corredor rapidamente");
    cenas[3].escolhas[1].id_destino = 2;
    cenas[3].num_escolhas = 2;
    strcpy(cenas[3].termo_codex, "Laboratorio Biologico");

    /* ── CENA 5 — Sala de Controle ── */
    cenas[4].id = 5;
    strcpy(cenas[4].titulo, "Sala de Controle - Deck B");
    strcpy(cenas[4].arte_ascii,
        "  .------------------------.\n"
        "  |  [====] [====] [====]  |\n"
        "  |  [====] [====] [====]  |\n"
        "  |     NEXUS-7 CONTROL    |\n"
        "  '------------------------'\n");
    strcpy(cenas[4].texto,
        "Monitores mostram camaras de seguranca.\n"
        "Deck A esta completamente escuro.\n"
        "Deck C mostra algo se movendo nos corredores.\n"
        "Voce encontra um cartao de acesso no chao.\n"
        "O nome no cartao: Dra. Elena Vasquez.\n"
        "Chefe de pesquisa biologica da estacao.");
    strcpy(cenas[4].escolhas[0].descricao, "Usar o cartao para acessar o Deck A");
    cenas[4].escolhas[0].id_destino = 8;
    strcpy(cenas[4].escolhas[1].descricao, "Tentar contatar resgate pelo radio");
    cenas[4].escolhas[1].id_destino = 9;
    cenas[4].num_escolhas = 2;
    strcpy(cenas[4].termo_codex, "Dra. Elena Vasquez");

    /* ── CENA 6 — ARIA ── */
    cenas[5].id = 6;
    strcpy(cenas[5].titulo, "Contato com ARIA - IA da Estacao");
    strcpy(cenas[5].arte_ascii,
        "      .-------.\n"
        "     /  A.R.I.A \\\n"
        "    |  [online]  |\n"
        "     \\  v2.4.1  /\n"
        "      '-------'\n");
    strcpy(cenas[5].texto,
        "Uma voz calma surge do painel:\n"
        "'Ola. Eu sou ARIA. Eu estava esperando voce acordar.'\n"
        "'A situacao e critica. O XR-7 ja contaminou o Deck A.'\n"
        "'Tenho dois protocolos disponiveis.'\n"
        "'Protocolo Lazarus: selar a estacao para sempre.'\n"
        "'Protocolo Exodus: evacuar e arriscar contaminacao externa.'");
    strcpy(cenas[5].escolhas[0].descricao, "Pedir mais informacoes sobre o XR-7");
    cenas[5].escolhas[0].id_destino = 7;
    strcpy(cenas[5].escolhas[1].descricao, "Ativar o Protocolo Lazarus");
    cenas[5].escolhas[1].id_destino = 10;
    strcpy(cenas[5].escolhas[2].descricao, "Ativar o Protocolo Exodus");
    cenas[5].escolhas[2].id_destino = 11;
    cenas[5].num_escolhas = 3;
    strcpy(cenas[5].termo_codex, "ARIA");

    /* ── CENA 7 — Diario / Informacoes XR-7 ── */
    cenas[6].id = 7;
    strcpy(cenas[6].titulo, "Diario da Dra. Vasquez");
    strcpy(cenas[6].arte_ascii,
        "  .------------------.\n"
        "  |  [DIARIO]        |\n"
        "  |  Dra. E. Vasquez |\n"
        "  |  Dia 847         |\n"
        "  |  CONFIDENCIAL    |\n"
        "  '------------------'\n");
    strcpy(cenas[6].texto,
        "Voce le as ultimas paginas do diario.\n"
        "'O XR-7 foi desenvolvido aqui como arma biologica.'\n"
        "'A corporacao sabia. Eles mandaram a gente fazer isso.'\n"
        "'Quando perdemos o controle eles cortaram o contato.'\n"
        "'Se alguem ler isso: nao confie na corporacao.'\n"
        "'ARIA sabe de tudo. Pergunte a ela sobre o Protocolo Lazarus.'");
    strcpy(cenas[6].escolhas[0].descricao, "Ir falar com ARIA");
    cenas[6].escolhas[0].id_destino = 6;
    strcpy(cenas[6].escolhas[1].descricao, "Ir para a Sala de Controle");
    cenas[6].escolhas[1].id_destino = 5;
    cenas[6].num_escolhas = 2;
    strcpy(cenas[6].termo_codex, "Protocolo Lazarus");

    /* ── CENA 8 — Deck A ── */
    cenas[7].id = 8;
    strcpy(cenas[7].titulo, "Deck A - Zona de Contaminacao");
    strcpy(cenas[7].arte_ascii,
        "  !! PERIGO BIOLOGICO !!\n"
        "  .-------------------.\n"
        "  |  * * *  A  * * *  |\n"
        "  |  CONTAMINADO      |\n"
        "  |  ACESSO RESTRITO  |\n"
        "  '-------------------'\n");
    strcpy(cenas[7].texto,
        "O Deck A esta tomado por uma nevoa esverdeada.\n"
        "Voce ve corpos no chao. Eles nao se movem.\n"
        "No centro da sala, um terminal ainda esta ligado.\n"
        "Na tela: coordenadas de uma nave de resgate.\n"
        "Mas para usar o terminal voce precisa ficar aqui.\n"
        "O tempo de exposicao ja esta aumentando.");
    strcpy(cenas[7].escolhas[0].descricao, "Usar o terminal e chamar o resgate");
    cenas[7].escolhas[0].id_destino = 11;
    strcpy(cenas[7].escolhas[1].descricao, "Sair imediatamente do Deck A");
    cenas[7].escolhas[1].id_destino = 5;
    cenas[7].num_escolhas = 2;
    strcpy(cenas[7].termo_codex, "Zona de Contaminacao");

    /* ── CENA 9 — Radio ── */
    cenas[8].id = 9;
    strcpy(cenas[8].titulo, "Tentativa de Contato - Radio");
    strcpy(cenas[8].arte_ascii,
        "  .------------.\n"
        "  |  [RADIO]   |\n"
        "  |  ...---... |\n"
        "  |  SOS NEXUS |\n"
        "  '------------'\n");
    strcpy(cenas[8].texto,
        "Voce tenta todas as frequencias.\n"
        "Estatica. Mais estatica.\n"
        "Entao uma voz fraca surge:\n"
        "'NEXUS-7 aqui e a corporacao Helix.'\n"
        "'Sabemos da situacao. Uma equipe esta a caminho.'\n"
        "'Nao ative nenhum protocolo. Aguarde resgate.'\n"
        "A voz some. Voce lembra do diario da Dra. Vasquez.\n"
        "Nao confie na corporacao.");
    strcpy(cenas[8].escolhas[0].descricao, "Confiar na corporacao e aguardar");
    cenas[8].escolhas[0].id_destino = 12;
    strcpy(cenas[8].escolhas[1].descricao, "Ignorar e ativar o Protocolo Lazarus");
    cenas[8].escolhas[1].id_destino = 10;
    cenas[8].num_escolhas = 2;
    strcpy(cenas[8].termo_codex, "Corporacao Helix");

    /* ── CENA 10 — FINAL A: Contencao ── */
    cenas[9].id = 10;
    strcpy(cenas[9].titulo, "FINAL A - Contencao");
    strcpy(cenas[9].arte_ascii,
        "  .--------------------.\n"
        "  |  PROTOCOLO LAZARUS |\n"
        "  |  [ATIVADO]         |\n"
        "  |  SELANDO ESTACAO   |\n"
        "  |  * * * * * * * *   |\n"
        "  '--------------------'\n");
    strcpy(cenas[9].texto,
        "Voce ativa o Protocolo Lazarus.\n"
        "As escotilhas selam. As comunicacoes sao cortadas.\n"
        "ARIA fala pela ultima vez:\n"
        "'Voce fez a escolha certa. A humanidade esta salva.'\n"
        "'Eu vou manter voce em criostase ate o ar acabar.'\n"
        "'Descanse. Voce e um heroi.'\n"
        "A estacao NEXUS-7 nunca mais foi encontrada.\n"
        "\n*** FIM - VOCE ESCOLHEU CONTER A AMEACA ***");
    cenas[9].num_escolhas = 0;
    strcpy(cenas[9].termo_codex, "");

    /* ── CENA 11 — FINAL B: Fuga ── */
    cenas[10].id = 11;
    strcpy(cenas[10].titulo, "FINAL B - Fuga");
    strcpy(cenas[10].arte_ascii,
        "  .--------------------.\n"
        "  |  PROTOCOLO EXODUS  |\n"
        "  |  [ATIVADO]         |\n"
        "  |  NAVE DE ESCAPE    |\n"
        "  |  >> >> >> >> >>    |\n"
        "  '--------------------'\n");
    strcpy(cenas[10].texto,
        "Voce chega a nave de escape.\n"
        "O motor liga. Voce se afasta da estacao.\n"
        "Pelas janelas, ve a NEXUS-7 encolhendo no espaco.\n"
        "Voce esta livre. Mas algo coca no seu braco.\n"
        "Uma marca vermelha que nao estava la antes.\n"
        "Voce esperou tempo demais no Deck A.\n"
        "\n*** FIM - VOCE FUGIU, MAS A QUE CUSTO? ***");
    cenas[10].num_escolhas = 0;
    strcpy(cenas[10].termo_codex, "");

    /* ── CENA 12 — FINAL C: Corporacao ── */
    cenas[11].id = 12;
    strcpy(cenas[11].titulo, "FINAL C - A Verdade");
    strcpy(cenas[11].arte_ascii,
        "  .--------------------.\n"
        "  |  CORPORACAO HELIX  |\n"
        "  |  [RESGATE]         |\n"
        "  |  BEM VINDO A BORDO |\n"
        "  |  ?? ?? ?? ?? ??    |\n"
        "  '--------------------'\n");
    strcpy(cenas[11].texto,
        "A nave da corporacao Helix chega.\n"
        "Homens de roupa branca entram na estacao.\n"
        "Eles nao parecem surpresos com nada que veem.\n"
        "Um deles se vira para voce e sorri:\n"
        "'Obrigado por preservar as amostras.'\n"
        "Voce percebe tarde demais.\n"
        "Voce nao foi resgatado. Voce foi capturado.\n"
        "\n*** FIM - VOCE CONFIOU EM QUEM NAO DEVIA ***");
    cenas[11].num_escolhas = 0;
    strcpy(cenas[11].termo_codex, "");
}

int main(int argc, char *argv[]) {
    Cena cenas[TOTAL_CENAS];
    EstadoJogo estado;
    char entrada[10];
    int escolha;

    /*
     * Primeira coisa a fazer: resolver o caminho do save.csv.
     * argv[0] e o caminho do proprio executavel — passamos para
     * salvar_inicializar() que extrai a pasta e monta o caminho
     * completo. A partir daqui, salvar/carregar usam esse caminho.
     *
     * O (void)argc evita warning de "parametro nao utilizado".
     */
    (void)argc;
    salvar_inicializar(argv[0]);

    inicializar_cenas(cenas);
    jogo_inicializar(&estado);

    /*
     * MENU INICIAL — exibido antes do jogo comecar.
     *
     * Verificamos PRIMEIRO se existe um save com arquivo_save_existe().
     * Isso evita mostrar a opcao "Continuar" quando nao ha nada salvo,
     * o que confundiria o jogador.
     *
     * A logica e simples:
     *   - Se nao ha save: so mostra "Novo Jogo" e "Sair".
     *   - Se ha save: mostra as tres opcoes.
     * O do-while repete o menu se o jogador digitar algo invalido.
     */
    {
        int save_existe = arquivo_save_existe();
        char op[10];
        int opcao_valida = 0;

        do {
            LIMPAR_TELA();
            imprimir_separador();
            printf("   PROTOCOLO DE QUARENTENA\n");
            printf("   NEXUS-7 // Sistema de Navegacao\n");
            imprimir_separador();
            printf("\n");
            printf("   1. Novo Jogo\n");
            if (save_existe) {
                printf("   2. Continuar\n");
                printf("   3. Sair\n");
            } else {
                printf("   2. Sair\n");
            }
            printf("\n");
            imprimir_separador();
            printf("   Opcao: ");
            fgets(op, sizeof(op), stdin);

            if (op[0] == '1') {
                /* Novo jogo: estado ja foi inicializado na cena 1 acima */
                opcao_valida = 1;

            } else if (op[0] == '2' && save_existe) {
                /*
                 * Continuar: chama carregar_jogo() para reconstruir
                 * a pilha e a BST a partir do arquivo save.csv.
                 * O estado (cena atual, historico, codex) e sobrescrito
                 * com os dados salvos.
                 */
                carregar_jogo(&estado);
                printf("\n  Retomando na cena %d...\n", estado.id_cena_atual);
                DORMIR_MS(1200);
                opcao_valida = 1;

            } else if (op[0] == '3' || (!save_existe && op[0] == '2')) {
                /* Sair direto do menu inicial, sem entrar no jogo */
                jogo_liberar(&estado);
                return 0;
            }

        } while (!opcao_valida);
    }

    while (estado.jogo_ativo) {
        Cena *cena_atual = jogo_buscar_cena(cenas, estado.id_cena_atual);

        if (cena_atual == NULL) {
            printf("Erro: cena nao encontrada!\n");
            break;
        }

        /* Desbloqueia termo no Codex se a cena tiver um */
        if (cena_atual->termo_codex[0] != '\0') {
            bst_inserir(&estado.codex,
                cena_atual->termo_codex,
                "Termo descoberto durante a exploracao.");
        }

        jogo_exibir_cena(cena_atual);

        /* Jogo termina se a cena nao tiver escolhas (cenas de fim) */
        if (cena_atual->num_escolhas == 0) {
            printf("\n  Pressione ENTER para sair...\n");
            getchar();
            estado.jogo_ativo = 0;
            break;
        }

        printf("\n  Sua escolha: ");
        fgets(entrada, sizeof(entrada), stdin);

        if (entrada[0] == 'V' || entrada[0] == 'v') {
            jogo_voltar_cena(&estado);

        } else if (entrada[0] == 'C' || entrada[0] == 'c') {
            jogo_exibir_codex(&estado);

        } else if (entrada[0] == 'S' || entrada[0] == 's') {
            /*
             * NOVO — Salva antes de sair.
             * A unica linha nova aqui e a chamada a salvar_jogo().
             * Todo o resto e igual ao original.
             */
            salvar_jogo(&estado);
            printf("\n  Jogo encerrado. Ate logo, astronauta.\n");
            estado.jogo_ativo = 0;

        } else {
            escolha = entrada[0] - '0';
            jogo_processar_escolha(&estado, cenas, escolha);
        }
    }

    jogo_liberar(&estado);
    return 0;
}

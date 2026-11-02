# Arena 360

Jogo de luta 2D estilo *platform fighter*, desenvolvido com foco no **Xbox 360 desbloqueado (RGH/JTAG)** e no multiplayer local.

> **Estado do projeto:** fase inicial de estruturação. Este repositório é a base oficial do desenvolvimento. Os recursos descritos aqui são metas de projeto e não significam que já estejam implementados.

## Visão geral

Arena 360 busca oferecer partidas dinâmicas para até quatro jogadores no mesmo console, com combate baseado em movimentação, plataformas, armas, habilidades, dano e knockback.

## Plataforma e tecnologia

- **Plataforma-alvo:** Xbox 360 com RGH/JTAG.
- **SDK em avaliação:** [XSDK](https://github.com/xenosworks/xsdk/), voltado ao desenvolvimento homebrew para Xbox 360.
- **Linguagem prevista:** C/C++.
- **Controles:** suporte planejado para até quatro controles locais.
- **Formato de teste:** executável `.xex`, quando houver uma compilação válida.

A compilação depende de um ambiente compatível com o toolchain do XSDK. Transferir arquivos por FTP para o console não compila o jogo: apenas transfere arquivos já gerados.

## Escopo inicial

- Até 4 jogadores em multiplayer local.
- Pelo menos 30 personagens jogáveis.
- Pelo menos 10 arenas.
- 8 categorias de armas previstas.
- Ataques leves e pesados, combos, esquiva, salto e recuperação aérea.
- Sistema de dano, knockback, colisões e arremesso de armas.
- Habilidades especiais, HUD, menus, áudio e modo de treinamento.
- Seleção de personagens e arenas.

## Personagens lendários planejados

| Personagem | Conceito | Estilo |
|---|---|---|
| VÉRAX — O Renegado | Guerreiro de armadura negra e poderes de sombras | Força e resistência |
| DANIX — O Herói do Sul | Espadachim de inspiração sulista brasileira fantástica | Velocidade e destreza |
| ASTRA — A Tempestade | Guerreira com poderes elétricos | Mobilidade |
| MORVAN — O Alquimista | Combatente que usa alquimia e frascos | Controle de área |
| NYX — A Fantasma Digital | Lutadora futurista de energia neon | Mobilidade e alcance |
| DRAKAR — O Herdeiro Dracônico | Guerreiro dracônico com fogo ancestral | Combate agressivo |
| MALZAR — O Lorde Demônio | Combatente de magia infernal | Poder e pressão |
| ELDOR — O Arquimago Primordial | Mago elemental de grande versatilidade | Alcance e controle |

Os demais personagens serão desenvolvidos para complementar o elenco e manter variedade de estilos. Personagens normais e lendários devem permanecer competitivos.

## Arenas planejadas

1. Ilhas Celestiais
2. Trono Abissal
3. Fornalha
4. Templo Carmesim
5. Neo Tokyo
6. Abismo Oceânico
7. Floresta Perdida
8. Estação Ômega
9. Necrópole
10. Dimensão Prisma

## Diretrizes de desenvolvimento

1. Preparar a estrutura do projeto e validar o ambiente de compilação.
2. Implementar inicialização, renderização e leitura dos controles.
3. Criar um protótipo de combate local.
4. Implementar física, plataformas, dano e knockback.
5. Construir a arquitetura de personagens, armas e habilidades.
6. Adicionar menus, HUD, arenas, áudio e conteúdo.
7. Testar no Xbox 360 e corrigir problemas de desempenho e compatibilidade.

O modo Boss fica reservado para uma expansão posterior, depois que a experiência principal estiver estável.

## Diretrizes de conteúdo

- Utilizar personagens, nomes, artes, animações, efeitos e áudio originais.
- Não reutilizar assets protegidos de outros jogos.
- Priorizar desempenho e estabilidade no hardware do Xbox 360.
- Documentar mudanças relevantes e instruções de teste.

## Estado atual

- [x] Repositório oficial criado.
- [x] Escopo inicial documentado.
- [ ] Validar e preparar o ambiente de compilação XSDK.
- [ ] Criar a estrutura inicial do código.
- [ ] Gerar o primeiro executável de teste.
- [ ] Validar execução no console.

---

**Arena 360** — projeto independente de jogo de luta para Xbox 360.

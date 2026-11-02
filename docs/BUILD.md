# Compilação do Arena 360

## Estado do ambiente

O projeto utiliza o XSDK (`https://github.com/xenosworks/xsdk`). A documentação oficial consultada descreve compilação em Linux (Debian) ou Windows 10/11 com WSL 2. Não há, neste momento, um processo oficial confirmado para compilar o XSDK diretamente no Android/Galaxy A22.

## Preparação no PC/WSL

1. Instalar Debian no WSL 2 (Windows) ou usar Debian Linux.
2. Instalar as dependências indicadas no `docs/GETTING_STARTED.md` do XSDK.
3. Clonar e compilar o XSDK seguindo exatamente o guia oficial.
4. Copiar esta pasta para o ambiente Linux.

## Configuração e compilação do Arena 360

Ajustar os caminhos caso o XSDK esteja instalado noutro local:

```sh
cmake -S . -B build -G Ninja \
  -DCMAKE_TOOLCHAIN_FILE="$HOME/xsdk/cmake/xsdk.cmake" \
  -DXSDK_TOOLCHAIN="$HOME/xsdk-gcc" \
  -DCMAKE_BUILD_TYPE=RelWithDebInfo

cmake --build build
```

O resultado esperado é `build/arena360.xex`.

## Teste no Xbox 360

1. Copiar `arena360.xex` para uma pasta própria no HDD do Xbox por FTP.
2. Iniciar o arquivo pelo Aurora.
3. O título deve abrir a tela inicial de vídeo e limpar o ecrã com uma cor escura.
4. Pressionar **Back** para encerrar.
5. Verificar `arena360.log` na pasta do executável, caso seja gerado.

**Importante:** este pacote ainda não foi compilado nem testado num Xbox 360. O resultado acima é o comportamento esperado após uma compilação bem-sucedida.

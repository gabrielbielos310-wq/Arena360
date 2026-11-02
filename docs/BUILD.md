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

<!-- coderabbit-ai-generated:v1 -->

<!-- coderabbit-ai-generated-section:v1:32d8808362871a0b7ba6214c01a642b455cca4ad1738b208075c957788483902 -->

<!-- coderabbit-ai-generated:v1 -->

<!-- coderabbit-ai-generated-section:v1:a94e7e3e5804529dcb133c2002074ce050ce22b50d43834451e28c5048f352c9 -->

## Testes automatizados no PC

Os testes do estado da partida não precisam do XSDK. Use uma pasta de compilação separada da usada para Xbox:

```sh
cmake -S . -B cmake-build-host -DARENA360_BUILD_XBOX=OFF -DBUILD_TESTING=ON
cmake --build cmake-build-host
ctest --test-dir cmake-build-host --output-on-failure
```

O CI executa estes testes no Linux; ele não gera nem valida o XEX.

## Teste no Xbox 360

<!-- /coderabbit-ai-generated:v1 -->

<!-- /coderabbit-ai-generated:v1 -->

1. Copiar `arena360.xex` para uma pasta própria no HDD do Xbox por FTP.
2. Iniciar o arquivo pelo Aurora.
3. O título deve abrir a tela inicial de vídeo e limpar o ecrã com uma cor escura.
4. Pressionar **Back** para encerrar.
5. Verificar `arena360.log` na pasta do executável, caso seja gerado.

<!-- coderabbit-ai-generated:v1 -->

<!-- coderabbit-ai-generated-section:v1:fdc6e56dd4999593f3175fa7b26dff88029e258cc07cf2d4b1b942c838a8e15b -->

**Estado:** o projeto foi compilado com sucesso com o XSDK na revisão `5f6dc726f65f6d171493a3628c2415c03551f27b`. O executável ainda não foi testado num Xbox 360; o comportamento acima é esperado.

<!-- /coderabbit-ai-generated:v1 -->

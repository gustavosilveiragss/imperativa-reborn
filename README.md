# requerimentos

- gcc ou clang
- cmake
- ninja

# instruções de uso

- configure o projeto do cmake usando o compilador que preferir (gcc ou clang)

  ### exemplos:

  `$ cmake --preset gcc`

  `$ cmake --preset clang`

- compile usando um dos presets `{compilador}{debug|release|release_dbginfo}`:

  ### exemplos:

  `$ cmake --build --preset gcc_debug`

  `$ cmake --build --preset clang_release`

  `$ cmake --build --preset gcc_release_dbginfo`

- execute o arquivo desejado com os argumentos apropriados

  ### exemplos:

  `$ ./build/Debug/editor data/data.bin`

  `$ ./build/Debug/generator data/data.txt data/data.bin`

# notas

o processo de consumo do código pode ser simplificado caso opte por usar o vscode - esse projeto vem com tasks pré-configuradas para compilar, executar e depurar individualmente cada uma das 3 executáveis geradas sem precisar executar comandos manuais no terminal.

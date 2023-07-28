# Coreboot README

Coreboot é um projeto de Software Livre que visa substituir o proprietário firmware (BIOS/UEFI) encontrado na maioria dos computadores. coreboot executa o
inicialização de hardware necessária para configurar o sistema e, em seguida, passa controle para um executável diferente, referido no coreboot como o
payload. Na maioria das vezes, a função principal da carga útil é inicializar o sistema operacional (SO).

Com a separação de inicialização de hardware e lógica de inicialização posterior, coreboot é perfeito para uma ampla variedade de situações. Isso pode ser usado
para aplicações especializadas que rodam diretamente no firmware, rodando sistemas operacionais de flash, carregando bootloaders personalizados ou
implementando padrões de firmware, como serviços de BIOS de PC ou UEFI. Esse flexibilidade permite que os sistemas coreboot incluam apenas os recursos
necessário na aplicação de destino, reduzindo a quantidade de código e espaço flash necessário.

## Código Fonte

Todo o código-fonte do coreboot é armazenado no git. Ele é baixado com o comando:

```bash
git clone https://review.coreboot.org/coreboot.git
```

As revisões de código são feitas em [a instância Gerrit do projeto](https://review.coreboot.org/).

O código pode ser navegado via [instância Gitiles do coreboot](https://review.coreboot.org/plugins/gitiles/coreboot/+/refs/heads/master).

O projeto coreboot também mantém um [espelho](https://github.com/coreboot/coreboot) do projeto no github.
Isso é somente leitura, pois o coreboot não aceita solicitações pull do github, mas permite navegar e baixar a fonte do coreboot.

## Cargas úteis (payloads)

Após a inicialização básica do hardware ter sido executada, qualquer "carga útil" desejada pode ser iniciada pelo coreboot.

Consulte <https://doc.coreboot.org/payloads.html> para obter uma lista de alguns dos payloads suportados pelo coreboot.


## Hardware suportado

O projeto coreboot oferece suporte a uma ampla variedade de arquiteturas, chipsets, dispositivos e placas-mãe. Embora nem todos estejam documentados, você pode
encontrar algumas informações no [Architecture-specific documentation](https://doc.coreboot.org/arch/index.html) ou no [SOC-specific documentation](https://doc.coreboot.org/soc/index.html).

Para obter detalhes sobre os dispositivos específicos da placa-mãe suportados pelo coreboot, consulte as páginas [Documentação específica da placa-mãe](https://doc.coreboot.org/mainboard/index.html) ou
[Status das Placas](https://coreboot.org/status/board-status.html).


## Versões Publicadas

Atualmente, os lançamentos são feitos por coreboot a cada trimestre. Os arquivos de lançamento contêm toda a base de código do coreboot desde o momento da
o lançamento, juntamente com quaisquer submódulos externos. Os submódulos contendo binários são separados dos arquivos de lançamento geral. Todos
dos pacotes necessários para construir as cadeias de ferramentas coreboot também são mantidos em coreboot.org caso os sites mudem ou esses pacotes específicos
ficarão indisponíveis no futuro.

Todas as versões estão disponíveis na página [download do coreboot](https://coreboot.org/downloads.html).

Observe que os lançamentos de coreboot são melhor considerados como instantâneos da base de código e atualmente não garantem nenhum tipo de extra estabilidade.

Build Requirements and building coreboot
----------------------------------------

The coreboot build, associated utilities and payloads require many
additional tools and packages to build. The actual coreboot binary is
typically built using a coreboot-controlled toolchain to provide
reproducibility across various platforms. It is also possible, though
not recommended, to make it directly with your system toolchain.
Operating systems and distributions come with an unknown variety of
system tools and utilities installed. Because of this, it isn't
reasonable to list all the required packages to do a build, but the
documentation lists the requirements for a few different Linux
distributions.

To see the list of tools and libraries, along with a list of
instructions to get started building coreboot, go to the [Starting from
scratch](https://doc.coreboot.org/tutorial/part1.html) tutorial page.

That same page goes through how to use QEMU to boot the build and see
the output.


Website and Mailing List
------------------------

Further details on the project, as well as links to documentation and
more can be found on the coreboot website:

  <https://www.coreboot.org>

You can contact us directly on the coreboot mailing list:

  <https://doc.coreboot.org/community/forums.html>



Copyrights and Licenses
---------------------


### Uncopyrightable files

There are many files in the coreboot tree that we feel are not
copyrightable due to a lack of creative content.

"In order to qualify for copyright protection in the United States, a
work must satisfy the originality requirement, which has two parts. The
work must have “at least a modicum” of creativity, and it must be the
independent creation of its author."

  <https://guides.lib.umich.edu/copyrightbasics/copyrightability>

Similar terms apply to other locations.

These uncopyrightable files include:

- Empty files or files with only a comment explaining their existence.
  These may be required to exist as part of the build process but are
  not needed for the particular project.
- Configuration files either in binary or text form. Examples would be
  files such as .vbt files describing graphics configuration, spd files
  as binary .spd or text \*spd\*.hex representing memory chip
  configuration.
- Machine-generated files containing version numbers, dates, hash
  values or other "non-creative" content.

As non-creative content, these files are in the public domain by
default.  As such, the coreboot project excludes them from the project's
general license even though they may be included in a final binary.

If there are questions or concerns about this policy, please get in
touch with the coreboot project via the mailing list.


### Copyrights

The copyright on coreboot is owned by quite a large number of individual
developers and companies. A list of companies and individuals with known
copyright claims is present at the top level of the coreboot source tree
in the 'AUTHORS' file. Please check the git history of each of the
source files for details.


### Licenses

Because of the way coreboot began, using a significant amount of source
code from the Linux kernel, it's licensed the same way as the Linux
Kernel, with GNU General Public License (GPL) Version 2. Individual
files are licensed under various licenses, though all are compatible
with GPLv2. The resulting coreboot image is licensed under the GPL,
version 2. All source files should have an SPDX license identifier at
the top for clarification.

Files under coreboot/Documentation/ are licensed under CC-BY 4.0 terms.
As an exception, files under Documentation/ with a history older than
2017-05-24 might be under different licenses.

Files in the coreboot/src/commonlib/bsd directory are all licensed with
the BSD-3-clause license.  Many are also dual-licensed GPL-2.0-only or
GPL-2.0-or-later.  These files are intended to be shared with libpayload
or other BSD licensed projects.

The libpayload project contained in coreboot/payloads/libpayload may be
licensed as BSD or GPL, depending on the code pulled in during the build
process. All GPL source code should be excluded unless the Kconfig
option to include it is set.


The Software Freedom Conservancy
--------------------------------

Since 2017, coreboot has been a member of [The Software Freedom
Conservancy](https://sfconservancy.org/), a nonprofit organization
devoted to ethical technology and driving initiatives to make technology
more inclusive. The conservancy acts as coreboot's fiscal sponsor and
legal advisor.

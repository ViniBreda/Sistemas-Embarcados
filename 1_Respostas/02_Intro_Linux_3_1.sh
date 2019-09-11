#!/bin/bash
echo Criando arquivos:
for i in {1..100}
do
	echo Arquivo $i
	echo Número do Arquivo = $i >> teste$i.txt
done
echo FIM!

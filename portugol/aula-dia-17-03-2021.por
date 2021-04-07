// Aluno: João Vitor Mendes Pinto dos Santos
programa
{
	inteiro a = 12, b = 19, c = 23, ab, bc, ac, entrada, perimetro
	logico encerrar = falso, triangulo = falso

	funcao selecao()
	{

		escreva("Digite os valores de A, B e C de forma pausada e com valores acima de 0.\n")
		leia(a, b, c)

		se (a == 0 ou b == 0 ou c == 0)
		{
			escreva("Zero não é um valor permitido, o programa será encerrado\n", "\n")
			encerrar = verdadeiro
		}
		senao
		{
			condi_triangulo()
			se (triangulo == verdadeiro)
			{
				escreva("Perimetro do triangulo = ",a+b+c, "\n")
			}
			senao
			{
				escreva("Não foi possível fazer o calclo pois os dados não atendem a condição de existência do triangulo\n",
				"Digite novamente\n","\n")
			}
		}

	}
	funcao condi_triangulo()
	{
		ab = a+b
		bc = b+c
		ac = a+c

		se (ab > c e bc > a e ac > b)
		{
			triangulo = verdadeiro
		}
	}
// funcao principal chamando a funcao para selecionar o calculo	
	funcao inicio()
	{
		enquanto(encerrar == falso)
		{
			selecao()
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 44; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */
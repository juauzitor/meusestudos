programa
{
	inteiro n, num, result
	
	funcao inicio()
	{
		result = 0
		escreva("Digite um número: ")
		leia(num)
		para(n=1;n<=(num-1);n++)
		{
			se(num%n==0)
			{
				escreva(n, " divide ", num, "\n")
				result += n
			}
		}
		se(num == result)
		{
			escreva(num, " é um numero perfeito\n")
		}
		senao
		{
			escreva(num, " não é um numero perfeito\n")
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 97; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */
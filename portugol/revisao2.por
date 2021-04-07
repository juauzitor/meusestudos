programa
{
	real sal, reajuste
	
	funcao inicio()
	{
		escreva("Salário do funcionario: ")
		leia(sal)
		se (sal <= 400)
		{
			reajuste = sal*0.15
			escreva("O reajuste do salário foi de: ", reajuste, ", o novo salário é: ",sal+reajuste)
		}
		senao se(sal >= 400.01 e sal <= 800)
		{
			reajuste = sal*0.12
			escreva("O reajuste do salário foi de: ", reajuste, "o novo salário é:",sal+reajuste)
		}
		senao se(sal >= 800.01 e sal <= 1200)
		{
			reajuste = sal*0.10
			escreva("O reajuste do salário foi de: ", reajuste, "o novo salário é:",sal+reajuste)
		}
		senao se(sal >= 1200.01 e sal <= 2000)
		{
			reajuste = sal*0.07
			escreva("O reajuste do salário foi de: ", reajuste, "o novo salário é:",sal+reajuste)
		}
		senao
		{
			reajuste = sal*0.04
			escreva("O reajuste do salário foi de: ", reajuste, "o novo salário é:",sal+reajuste)
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 57; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */
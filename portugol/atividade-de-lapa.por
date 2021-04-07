// Aluno: João Vitor Mendes Pinto dos Santos
programa
{
	inclua biblioteca Matematica --> m

	real PI = m.PI
	cadeia entrada
	real raio, base, altura
	logico encerrar = falso


// Função de seleção do calculo para deixa mais organizado o codigo
	funcao selecao()
	{

// Etapa para escolher o codigo
// encontrar uma forma para converter , em . e uma forma para gerenciar o erro de entrada para os tipos reais

		escreva(
		"Seja bem vindo ao programa para calcular a área de uma circunferência ou o perímetro de um retângulo\n",
		"Digite 1 para calcular a área de uma circunferêcia\n",
		"Digite 2 para calcular o perímetro de um retângulo\n",
		"Digite q para fechar o programa\n")
		leia(entrada)

// chamar a constante pi e a função de potencia da biblioteca matemática 

		se (entrada == "1")
		{
			escreva("Digite o valor do raio(por favor invés de usar virgula use ponto no lugar):")
			leia(raio)
			escreva(PI*m.potencia(raio,2.0), "\n")	
		}

// quando se usa leia com 2 variaveis é necessário confirmar uma de cada vez

		senao se(entrada == "2")
		{
			escreva(
			"Digite os valores da base e altura(por favor invés de usar virgula use ponto no lugar):\n",
			"Digite a base confirme e depois digite a altura\n")
			leia(base, altura)
			escreva(2*(base+altura), "\n")
		}
		senao se(entrada == "q")
		{
			escreva("O programa será encerrado\n")
			encerrar = verdadeiro
		}
		senao
		{	
			escreva("digite um numero valido\n", "\n")
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
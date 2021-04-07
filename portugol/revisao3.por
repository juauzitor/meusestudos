programa
{
	cadeia nome, vencedor
	real porc_num_total_votos_vencedor, porc_abstencao, votos, num_total_votos_vencedor, votantes, num_total_votos, abstencao
	logico encerrar = falso
	
	
	funcao inicio()
	{
		num_total_votos_vencedor = 0.0
		num_total_votos = 0.0
		enquanto(encerrar == falso)
			{
				escreva("\nDigite o nome do canditado depois os votos\nDigite hifen para de alimentar o programa\n")
				leia(nome)
				se (nome == "-")
				{
					encerrar = verdadeiro	
				}
				senao
				{
					leia(votos)
					num_total_votos += votos
				
					se (votos > num_total_votos_vencedor)
					{
						vencedor = nome
						num_total_votos_vencedor = votos	
					}
				}	
			}
		escreva("Digite a abstenção de votos: ")
		leia(abstencao)
		escreva("\n")
		porc_num_total_votos_vencedor = num_total_votos_vencedor/num_total_votos
		porc_abstencao = abstencao/num_total_votos
		escreva("Vencedor: ",vencedor,"\n",
		"Porcetagem de votos: ", porc_num_total_votos_vencedor,"\n" ,
		"Porcentagem da abstenção de votos: ",porc_abstencao)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 313; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */
#include <stdio.h>

main() {
	
	int opcao_menu;
	int num_conta;
	int senha;
	float valor;
	char operacao;
	int contador = 0;
	
	struct Conta
	{
		char nome_cliente[30];
		int numero;
		int senha;
		float saldo;
	};
	
	struct Conta banco[10]; // lista de contas de um banco
	
	while(true){
		
		puts("############## MENU DE ACOES ################## \n\n");
		puts("PARA ABRIR CONTA, DIGITE 1. \n");
		puts("PARA CONSULTAR SALDO DE CONTA, DIGITE 2. \n");
		puts("PARA DEPOSITAR EM CONTA, DIGITE 3. \n");
		puts("PARA SACAR VALROES, DIGITE 4. \n");
		puts("PARA ENCERRAR CONTA, DIGITE 5 \n");
		puts("PARA SAIR, DIGITE -1. \n\n");
		
		puts("Sua opcao: ");
		scanf("%d", &opcao_menu);
		
		
		struct Conta conta;
		
		switch(opcao_menu){
			
			case -1:
				puts("Programa encerrado.");
				return 0;
			
			case 1:
				puts("CRIANDO CONTA... \n");
				struct Conta nova_conta;
				
				nova_conta.numero = contador;
				printf("O numero da sua conta foi criado automaticamente. Numero: %d\n", nova_conta.numero);
				
				puts("Digite o nome do cliente: ");
				scanf("%s", nova_conta.nome_cliente);
				
				puts("Digite o valor inicial da conta: ");
				scanf(" %f", &nova_conta.saldo);
				
				puts("Defina uma senha de seguranca: ");
				scanf("%d", &nova_conta.senha);
				
				banco[contador] = nova_conta;
				
				printf("CONTA CRIADA COM SUCESSO! Numero: %d - Saldo: %f\n\n", nova_conta.numero, nova_conta.saldo);
				
				contador++;
				break;
			
			case 2:
				puts("Digite o numero da conta a ser consultada: ");
				scanf("%d", &num_conta);
				
				conta = banco[num_conta]; // obtendo a conta digitada da minha lista de contas (banco).
				
				if (conta.numero == num_conta){
					puts("Digite a sua senha: ");
					scanf("%d", &senha);
					
					if (senha == conta.senha){
						printf("Saldo atual da conta %d: %f\n\n", conta.numero, conta.saldo);
					}else {
						puts("Senha incorreta. Operacao cancelada.");
					}
				}else {
					puts("Conta inexistente.\n");
				}
				
				break;
			
			
			case 3:
				puts("Digite o numero da conta onde sera feito o deposito: ");
				scanf("%d", &num_conta);
				
				conta = banco[num_conta]; // obtendo a conta digitada da minha lista de contas (banco).
				
				if (conta.numero == num_conta){ // se a conta digitada existir na lista(banco)
					
					char confirmacao;
					printf("Voce está depositando na conta de %s. Confirma? (s/n)", conta.nome_cliente);
					scanf(" %c", &confirmacao);
					
					if (confirmacao == 's'){
						puts("Digite ao valor do deposito: ");
						scanf("%f", &valor);
						
						banco[num_conta].saldo = conta.saldo + valor;
						
						printf("Deposito feito com sucesso! Seu novo saldo eh: %f\n\n", banco[num_conta].saldo);
						
					}
					
				}else {
					puts("Conta inexistente.\n");
				}
				
				break;
			
			case 4:
				puts("Digite o numero da conta a ser sacada: ");
				scanf("%d", &num_conta);
				
				conta = banco[num_conta]; // obtendo a conta digitada da minha lista de contas (banco).
				
				if (conta.numero == num_conta){
					puts("Digite o valor da retirada: ");
					scanf("%f", &valor);
					puts("Digite a sua senha: ");
					scanf("%d", &senha);
					
					if (senha == conta.senha){
						banco[num_conta].saldo = conta.saldo - valor;
						printf("Saque feito com sucesso! Seu novo saldo eh: %f\n\n", banco[num_conta].saldo);
					}else {
						puts("Senha incorreta. Operacao cancelada.\n\n");
					}
				}else {
					puts("Conta inexistente.\n");
				}
				break;
			
			case 5:
				puts("Digite o numero da conta a ser excluida: ");
				scanf("%d", &num_conta);
				
				conta = banco[num_conta]; // obtendo a conta digitada da minha lista de contas (banco).
				
				if (conta.numero == num_conta){
					puts("Digite a sua senha: ");
					scanf("%d", &senha);
					
					if (senha == conta.senha){
						banco[num_conta].numero = -1; // inutilizando a conta. Com o numero da conta -1, nao poderá ser acessada.
						printf("Conta excluida com sucesso!\n\n");
					}else {
						puts("Senha incorreta. Operacao cancelada.\n\n");
					}
				}else {
					puts("Conta inexistente.\n\n");
				}
				break;
			
			default:
				puts("Opcao invalida. Tente novamente.\n\n");
		}
	}
}

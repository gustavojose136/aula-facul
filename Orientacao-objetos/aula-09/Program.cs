Console.Clear();


ContaEspecial ceXunda = new ContaEspecial("Xunda",500);
Console.WriteLine( ceXunda.mostrarDados() );
Console.WriteLine( ceXunda.recuperarExtrato() );
Console.ReadKey();
ceXunda.fazerRetirada(500,DateTime.Now,"Pagamento escola");
ceXunda.fazerRetirada(230,DateTime.Now,"Pagamento Celesc");
ceXunda.fazerRetirada(150,DateTime.Now,"Pagamento Vivo");
Console.WriteLine( ceXunda.recuperarExtrato() );
Console.ReadKey();
ceXunda.fecharMes();
Console.WriteLine( ceXunda.recuperarExtrato() );
Console.ReadKey();

Console.Clear();

ContaPoupanca cpPaulo = new ContaPoupanca("Paulo",1000);
Console.WriteLine( cpPaulo.mostrarDados() );
Console.WriteLine( cpPaulo.recuperarExtrato() );
Console.ReadKey();
cpPaulo.fazerDeposito(450,DateTime.Now,"Recebimento de frela");
cpPaulo.fazerRetirada(25,DateTime.Now,"Rifa da escola");
Console.WriteLine( cpPaulo.recuperarExtrato() );
Console.ReadKey();
cpPaulo.fecharMes();
Console.WriteLine( cpPaulo.recuperarExtrato() );
Console.ReadKey();

Console.Clear();


ContaMesada cmJulia = new ContaMesada("Julia",100,100);
Console.WriteLine( cmJulia.mostrarDados());
Console.WriteLine( cmJulia.recuperarExtrato());
Console.ReadKey();
cmJulia.fazerRetirada(50,DateTime.Now,"Cinema Homem-Aranha");
Console.WriteLine( cmJulia.recuperarExtrato());
Console.ReadKey();
cmJulia.fazerRetirada(25,DateTime.Now,"Lanche pós cinema");
Console.WriteLine( cmJulia.recuperarExtrato());
Console.ReadKey();
cmJulia.fecharMes();
Console.WriteLine( cmJulia.recuperarExtrato());
Console.ReadKey();




/*
Conta contaXunda = new Conta("Xunda",400);
contaXunda.fazerDeposito(5.50m, DateTime.Now, "Pix da coca-cola");
contaXunda.fazerRetirada(200, DateTime.Now, "Churrasco no fds");
contaXunda.fazerRetirada(105.50m, DateTime.Now, "Conta de luz");
Console.WriteLine( contaXunda.recuperarExtrato() );
Console.ReadKey();

Conta contaCatatau = new Conta("Catatau",100);
contaCatatau.fazerDeposito(500, DateTime.Now, "Jogo do bicho");
contaCatatau.fazerRetirada(250, DateTime.Now, "Agiota");
contaCatatau.fazerRetirada(55, DateTime.Now, "Only fans");
Console.WriteLine( contaCatatau.recuperarExtrato() );
Console.ReadKey();

Conta contaZe = new Conta("Ze Colmeia",180);
Console.WriteLine( contaZe.recuperarExtrato() );
Console.ReadKey();
*/

Console.WriteLine("--------");
Console.WriteLine("Contas criadas : "+ Conta.qtdContasCriadas );
Console.WriteLine("Próxima conta  : "+ Conta.numeroProximaConta );
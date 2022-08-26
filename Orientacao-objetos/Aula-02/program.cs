Cidade c1 = new Cidade("joinville",1000);
Cidade c2 = new Cidade();
Cidade c3 = new Cidade("Jaragua");


Console.Clear();

if (c1.definirArea(1000)){
    Console.WriteLine("Area definidada com sucesso");
}else{
    Console.WriteLine("Erro!! Are muito grande, ou populção muito pequena");
}
Console.WriteLine();

Console.WriteLine( c1.mostrarDados() );
Console.WriteLine( c1.mostrarDados("H") );
Console.WriteLine( c1.mostrarDados("A") );
Console.WriteLine( c1.mostrarDados("T") );



/*
// Criar 2 tipos de objetos tipo Cidade
""
Cidade cid1 = new Cidade (); 
Cidade cid2 = new Cidade ();
Cidade cid3 = new Cidade ();
Correntista pessoa1 = new Correntista();
Correntista pessoa2 = new Correntista();
Correntista pessoa3 = new Correntista();
// Colocar informações sobre cada cidade dos objetos
cid1.nome = "Yokkaichi";
cid1.habitante = 600000;
cid2.nome = "Hinaga";
cid2.habitante = 1200000;
cid3.nome = "Nagashima";
cid3.habitante = 500000;
// Fazer cacda objeto para mostrar seus dados
Console.Clear();
Console.WriteLine( cid1.mostrarDados() );
Console.WriteLine( cid2.mostrarDados() );
Console.WriteLine( cid3.mostrarDados() );
// Colocar informações sobre cada cidade dos objetos
pessoa1.cpf = "123.456.789-10";
pessoa1.nome = "Godofredo Alombado filho";
pessoa1.telefone = "1234-5678";
pessoa2.cpf = "124.357.689-10";
pessoa2.nome = "Eder Ramos Filho";
pessoa2.telefone = "9999-9999";
pessoa3.cpf = "150.999.789-01";
pessoa3.nome = "Animalson dos Santos";
pessoa3.telefone = "7878-8787";
// Fazer cacda objeto para mostrar seus dados
Console.Clear();
Console.WriteLine( pessoa1.mostrarDadosPessoais() );
Console.WriteLine( pessoa2.mostrarDadosPessoais() );
Console.WriteLine( pessoa3.mostrarDadosPessoais() );
*/
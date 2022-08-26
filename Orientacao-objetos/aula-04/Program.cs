Tela tela = new Tela();
int op;

List<string> opcoes = new List<string>();
opcoes.Add("1 - Cadastro de Clientes    ");
opcoes.Add("2 - Cadastro de Contas      ");
opcoes.Add("3 - Registro de movimentação");
opcoes.Add("4 - Ver extrato de conta    ");
opcoes.Add("0 - Sair do sistema         ");

while (true){
    tela.prepararTela(" ^.^ Banco Manseira S/a");
    op = tela.mostrarMenu(5,4,opcoes);

    if (op==0) break;
}
Console.Clear();